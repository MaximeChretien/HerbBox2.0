/*
 *    @author  : Maxime Chretien (MixLeNain) && Zoomacom / OpenFactory
 *    @mail    : mchretien@linuxmail.org
 *    @project : HerbBox 2.0
 *    @summary : An automatic system to control the growth of 3 plants.
 *		It's build around two microcontrollers communicating.
 *		This is the NodeMCU part.
 *		See TODO for more informations.
 *    @version : 1.0
 */

#include "blynk.h"
#include "constants.h"
#include "display.h"
#include "sensors.h"
#include "serialCom.h"

#include <SimpleTimer.h>
SimpleTimer timer;

void localControl();
void autoControlChecks();
void autoControl();

bool autoControlLampStatus = false;
long autoControlLampTime = 0;
bool autoControlPump1Status = false;
long autoControlPump1Time = 0;
bool autoControlPump2Status = false;
long autoControlPump2Time = 0;
bool autoControlPump3Status = false;
long autoControlPump3Time = 0;

void setup() {
	initBlynk();
	initDisplay();
	initSensors();
	initSerial();

	timer.setInterval(TM_AUTO_CTRL, autoControl);
	timer.setInterval(TM_AUTO_CTRL_CHECK, autoControlChecks);
	timer.setInterval(TM_READ_BTN, localControl);
	timer.setInterval(TM_READ_DHT, updateDHT);
	timer.setInterval(TM_GET_SOIL, getSerialSensors);
	timer.setInterval(TM_SEND_BLYNK, sendBlynkDatas);
	timer.setInterval(TM_UPDATE_DISPLAY, updateDisplay);
}

void loop() {
	timer.run();
	runBlynk();
}

void localControl() {
	updateBtns();

	if (getLampBtn()) {
		setSerialLamp(!getSerialLamp());
		updateBlynkLeds();
	}

	if (getPumpBtn()) {
		int nb = getDisplayState();
		if(nb) {
			setSerialPump(nb-1, !getSerialPump(nb-1));
		}
		updateBlynkLeds();
	}

	if (getSensorsBtn()) {
		changeDisplayState();
	}
}

void autoControlChecks() {
	if (getSerialSoilTemp(0) < COLD_TEMP || getSerialSoilTemp(1) < COLD_TEMP || getSerialSoilTemp(2) < COLD_TEMP ) {
		autoControlLampStatus = true;
		autoControlLampTime = millis();
	}

	if (getSerialSoilHum(0) < DRY_SOIL) {
		autoControlPump1Status = true;
		autoControlPump1Time = millis();
	}

	if (getSerialSoilHum(1) < DRY_SOIL) {
		autoControlPump2Status = true;
		autoControlPump2Time = millis();
	}

	if (getSerialSoilHum(2) < DRY_SOIL) {
		autoControlPump3Status = true;
		autoControlPump3Time = millis();
	}
}

void autoControl() {
	if(autoControlLampStatus && !getSerialLamp()) {
		setSerialLamp(true);
	} else if (getSerialLamp() && autoControlLampStatus && (millis() - autoControlLampTime) > TIME_LAMP_ON) {
		setSerialLamp(false);
		autoControlLampStatus = false;
	}

	if(autoControlPump1Status && !getSerialPump(0)) {
		setSerialPump(0, true);
	} else if (getSerialPump(0) && autoControlPump1Status && (millis() - autoControlPump1Time) > TIME_PUMP_ON) {
		setSerialPump(0, false);
		autoControlPump1Status = false;
	}

	if(autoControlPump2Status && !getSerialPump(1)) {
		setSerialPump(1, true);
	} else if (getSerialPump(1) && autoControlPump2Status && (millis() - autoControlPump2Time) > TIME_PUMP_ON) {
		setSerialPump(1, false);
		autoControlPump2Status = false;
	}

	if(autoControlPump3Status && !getSerialPump(2)) {
		setSerialPump(2, true);
	} else if (getSerialPump(2) && autoControlPump3Status && (millis() - autoControlPump3Time) > TIME_PUMP_ON) {
		setSerialPump(2, false);
		autoControlPump3Status = false;
	}
}
