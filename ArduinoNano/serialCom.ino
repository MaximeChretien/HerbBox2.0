/*
 *    @author  : Maxime Chretien (MixLeNain) && Zoomacom / OpenFactory
 *    @mail    : mchretien@linuxmail.org
 *    @project : HerbBox 2.0
 *    @summary : Implementation of functions used to control the serial communication
 *		between the two microcontrollers.
 *    @version : 1.0
 */

#include "serialCom.h"

#include "relays.h"
#include "sensors.h"

void initSerial() {
	// Init Serial communication
	Serial.begin(9600);
}

void getSerial() {
	// If there's no waiting messages, go out of the function
	if(!Serial.available()) {
		return;
	}

	// Read Serial message
	String result = Serial.readStringUntil('E');

	// React to the message with the right function
	switch (result.charAt(0)) {
		case 'S':
			sendSerialData();
			break;
		case 'P':
			setPump(result.substring(1,2).toInt(), result.substring(2,3).toInt());
			break;
		case 'L':
			setLamp(result.substring(1,2).toInt());
			break;
	}
}

// Send all sensors values in a specific format
void sendSerialData() {
	Serial.print(	"S" + String(getPump(0)) +
			String(getPump(1)) +
			String(getPump(2)) +
			String(getLamp()) +
			"#" + String(getSoilTemp(0)) +
			"#" + String(getSoilTemp(1)) +
			"#" + String(getSoilTemp(2)) +
			"#" + String(getSoilHum(0)) +
			"#" + String(getSoilHum(1)) +
			"#" + String(getSoilHum(2)) +
			"E");
}
