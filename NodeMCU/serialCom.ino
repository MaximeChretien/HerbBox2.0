/*
 *    @author  : Maxime Chretien (MixLeNain) && Zoomacom / OpenFactory
 *    @mail    : mchretien@linuxmail.org && TODO
 *    @project : HerbBox 2.0
 *    @summary : Implementation of functions used to control the serial communication
 *		between the two microcontrollers.
 *    @version : 0.1
 */

#include "serialCom.h"

bool lampState;
bool tempLampState;
bool pumpState[3];
bool tempPumpState[3];
float soilTemp[3];
float soilHum[3];

void initSerial() {
	Serial.begin(9600);

	lampState = false;
	for (int i = 0; i < 3; i++) {
		pumpState[i] = false;
		soilTemp[i] = 0;
		soilHum[i] = 0;
	}
}

void getSerialSensors() {
	int startIndex, endIndex;

	// Request values
	Serial.print("SR");

	// Result formating : S(P1)(P2)(P3)(L)#(T1)#(T2)#(T3)#(H1)#(H2)#(H3)E
	// Px : Pump number x state (0 or 1)
	// L : Lamp state (0 or 1)
	// Tx : Soil temperature number x (float value)
	// Hx : Soil humidity number x (float value)
	String result = Serial.readStringUntil('E');

	if (result.charAt(0) != 'S')
		return;

	for (int i = 0; i < 3; i++) {
		tempPumpState[i] = result.substring(i+1, i+2).toInt();
	}

	tempLampState = result.substring(4,5).toInt();

	startIndex = result.indexOf('#');
	endIndex = result.indexOf('#', startIndex+1);

	soilTemp[0] = result.substring(startIndex+1, endIndex).toFloat();

	startIndex = result.indexOf('#', endIndex+1);
	endIndex = result.indexOf('#', startIndex+1);

	soilTemp[1] = result.substring(startIndex+1, endIndex).toFloat();

	startIndex = result.indexOf('#', endIndex+1);
	endIndex = result.indexOf('#', startIndex+1);

	soilTemp[2] = result.substring(startIndex+1, endIndex).toFloat();

	startIndex = result.indexOf('#', endIndex+1);
	endIndex = result.indexOf('#', startIndex+1);

	soilHum[0] = result.substring(startIndex+1, endIndex).toFloat();

	startIndex = result.indexOf('#', endIndex+1);
	endIndex = result.indexOf('#', startIndex+1);

	soilHum[1] = result.substring(startIndex+1, endIndex).toFloat();

	startIndex = result.indexOf('#', endIndex+1);
	endIndex = result.indexOf('E', startIndex+1);

	soilHum[2] = result.substring(startIndex+1, endIndex).toFloat();

	checkResults();
}

void setSerialPump(int nb, bool state) {
	pumpState[nb] = state;
	Serial.print("P" + String(nb) + String(state));
}

void setSerialLamp(bool state) {
	lampState = state;
	Serial.print("L" + String(state));
}

void checkResults() {
	if (tempLampState != lampState) {
		setSerialLamp(lampState);
	}

	for (int i = 0; i < 3; i++) {
		if (tempPumpState[i] != pumpState[i]) {
			setSerialPump(i, pumpState[i]);
		}
	}

	//TODO
}

float getSerialSoilTemp(int nb) {
	return soilTemp[nb];
}

float getSerialSoilHum(int nb) {
	return soilHum[nb];
}

bool getSerialPump(int nb) {
	return pumpState[nb];
}

bool getSerialLamp() {
	return lampState;
}
