/*
 *    @author  : Maxime Chretien (MixLeNain) && Zoomacom / OpenFactory
 *    @mail    : mchretien@linuxmail.org
 *    @project : HerbBox 2.0
 *    @summary : Implementation of functions used to control the sensors.
 *    @version : 1.0
 */

#include "sensors.h"

#include <DallasTemperature.h>
#include <OneWire.h>

float soilTemp[3];
float soilHum[3];

// Init OneWire and DS18B20 communication system
OneWire oneWire(ONEWIRE_BUS);
DallasTemperature DS18B20(&oneWire);

void initSensors() {
	// Init Moisture sensors power pins
	pinMode(MOIST1_ALIM, OUTPUT);
	pinMode(MOIST2_ALIM, OUTPUT);
	pinMode(MOIST3_ALIM, OUTPUT);

	// Put all pins to low to disable the sensors
	digitalWrite(MOIST1_ALIM, LOW);
	digitalWrite(MOIST2_ALIM, LOW);
	digitalWrite(MOIST3_ALIM, LOW);

	// Start DS18B20 communication system
	DS18B20.begin();

	for (int i = 0; i < 3; i++) {
		soilTemp[i] = 0;
		soilHum[i] = 0;
	}
}

void updateTempSensors() {
	// Send a request to the DS18B20 sensors to get new values 
	DS18B20.requestTemperatures();

	for (int i = 0; i < 3; i++) {
		soilTemp[i] = DS18B20.getTempCByIndex(i);
	}
}

void updateHumSensors() {
	for (int i = 0; i < 3; i++) {
		soilHum[i] = 0;
	}

	// Enable all the moisture sensors
	digitalWrite(MOIST1_ALIM, HIGH);
	digitalWrite(MOIST2_ALIM, HIGH);
	digitalWrite(MOIST3_ALIM, HIGH);

	delay (500); // Wait a bit to let them power on

	// read sensor "MOIST_N" times and get the average
	for(int i = 0; i < MOIST_N; i++) {
		soilHum[0] += analogRead(MOIST1_DATA);
		soilHum[1] += analogRead(MOIST2_DATA);
		soilHum[2] += analogRead(MOIST3_DATA);
		delay(150);
	}

	// Disable all the sensors
	digitalWrite(MOIST1_ALIM, LOW);
	digitalWrite(MOIST2_ALIM, LOW);
	digitalWrite(MOIST3_ALIM, LOW);

	// Compute the average value
	soilHum[0] /= MOIST_N;
	soilHum[1] /= MOIST_N;
	soilHum[2] /= MOIST_N;
}

float getSoilTemp(int nb) {
	return soilTemp[nb];
}

float getSoilHum(int nb) {
	return soilHum[nb];
}

