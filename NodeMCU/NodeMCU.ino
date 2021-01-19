/*
 *    @author  : Maxime Chretien (MixLeNain) && Zoomacom / OpenFactory
 *    @mail    : mchretien@linuxmail.org && TODO
 *    @project : HerbBox 2.0
 *    @summary : An automatic system to control the growth of 3 plants.
 *		It's build around two microcontrollers communicating.
 *		This is the NodeMCU part.
 *		See TODO for more informations.
 *    @version : 0.1
 */

#include <SimpleTimer.h>

#include "blynk.h"
#include "constants.h"
#include "display.h"
#include "sensors.h"
#include "serialCom.h"

SimpleTimer timer;

void localControl();

void setup() {
	initSerial();
	initSensors();
	initDisplay();

	timer.setInterval(TM_READ_BTN, localControl);
	timer.setInterval(TM_READ_DHT, updateDHT);
	timer.setInterval(TM_UPDATE_DISPLAY, updateDisplay);
	timer.setInterval(TM_GET_SOIL, getSerialSensors);
}

void loop() {
	timer.run();
}

void localControl() {
	updateBtns();

	if (getLampBtn()) {
		setSerialLamp(!getSerialLamp());
	}

	if (getPumpBtn()) {
		setSerialPump(0, !getSerialPump(0));
	}

	if (getSensorsBtn()) {
		//TODO
		changeDisplayState();
	}
}
