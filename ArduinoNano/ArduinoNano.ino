/*
 *    @author  : Maxime Chretien (MixLeNain) && Zoomacom / OpenFactory
 *    @mail    : mchretien@linuxmail.org && TODO
 *    @project : HerbBox 2.0
 *    @summary : An automatic system to control the growth of 3 plants.
 *		It's build around two microcontrollers communicating.
 *		This is the Arduino Nano part.
 *		See TODO for more informations.
 *    @version : 0.1
 */

#include <SimpleTimer.h>

#include "constants.h"
#include "relays.h"
#include "sensors.h"
#include "serialCom.h"

SimpleTimer timer;

void setup() {
	initSensors();
	initSerial();

	timer.setInterval(TM_READ_TEMP, updateTempSensors);
	timer.setInterval(TM_READ_HUM, updateHumSensors);
	timer.setInterval(TM_READ_SERIAL, getSerial);
}

void loop() {
	timer.run();
}
