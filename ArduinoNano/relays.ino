/*
 *    @author  : Maxime Chretien (MixLeNain) && Zoomacom / OpenFactory
 *    @mail    : mchretien@linuxmail.org && TODO
 *    @project : HerbBox 2.0
 *    @summary : Implementation of functions used to control the relays.
 *    @version : 0.1
 */

#include "relays.h"

void initRelays() {
	pinMode(PUMP1_PIN, OUTPUT);
	pinMode(PUMP2_PIN, OUTPUT);
	pinMode(PUMP3_PIN, OUTPUT);
	pinMode(LAMP_PIN, OUTPUT);

	digitalWrite(PUMP1_PIN, LOW);
	digitalWrite(PUMP2_PIN, LOW);
	digitalWrite(PUMP3_PIN, LOW);
	digitalWrite(LAMP_PIN, LOW);
}

void setPump(int nb, bool state) {
	switch(nb) {
		case 0:
			digitalWrite(PUMP1_PIN, state);
			break;
		case 1:
			digitalWrite(PUMP2_PIN, state);
			break;
		case 2:
			digitalWrite(PUMP3_PIN, state);
			break;
	}
}

void setLamp(bool state) {
	digitalWrite(LAMP_PIN, state);
}

bool getPump(int nb) {
	switch(nb) {
		case 0:
			return digitalRead(PUMP1_PIN);
			break;
		case 1:
			return digitalRead(PUMP2_PIN);
			break;
		case 2:
			return digitalRead(PUMP3_PIN);
			break;
	}
}

bool getLamp() {
	return digitalRead(LAMP_PIN);
}
