/*
 *    @author  : Maxime Chretien (MixLeNain) && Zoomacom / OpenFactory
 *    @mail    : mchretien@linuxmail.org
 *    @project : HerbBox 2.0
 *    @summary : Implementation of functions used to control the sensors.
 *    @version : 1.0
 */

#include "sensors.h"

#include <DHT.h>

#include "constants.h"

// Init DHT sensor
DHT dht(DHT_PIN, DHT_TYPE);

float airTemp = 0;
float airHum = 0;

bool lampBtnStatus = false;
bool pumpBtnStatus = false;
bool sensorsBtnStatus = false;

void initSensors() {
	// Init DHT communication
	dht.begin();

	// Init buttons pins
	pinMode(LAMP_BTN, INPUT_PULLUP);
	pinMode(PUMP_BTN, INPUT_PULLUP);
	pinMode(SENSORS_BTN, INPUT_PULLUP);
}

void updateBtns() {
	// Get buttons values
	lampBtnStatus = !digitalRead(LAMP_BTN);
	pumpBtnStatus = !digitalRead(PUMP_BTN);
	sensorsBtnStatus = !digitalRead(SENSORS_BTN);
}

void updateDHT() {
	// Get DHT values
	airTemp = dht.readTemperature();
	airHum = dht.readHumidity();
}

float getAirTemp() {
	return airTemp;
}

float getAirHum() {
	return airHum;
}

bool getLampBtn() {
	return lampBtnStatus;
}

bool getPumpBtn() {
	return pumpBtnStatus;
}

bool getSensorsBtn() {
	return sensorsBtnStatus;
}

