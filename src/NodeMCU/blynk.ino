/*
 *    @author  : Maxime Chretien (MixLeNain) && Zoomacom / OpenFactory
 *    @mail    : mchretien@linuxmail.org
 *    @project : HerbBox 2.0
 *    @summary : Implementation of functions used to send datas to the Blynk system.
 *    @version : 1.2
 */

#include "blynk.h"

#include "constants.h"
#include "sensors.h"
#include "serialCom.h"

// Define Blynk leds
WidgetLED PUMP1(V0);
WidgetLED PUMP2(V1);
WidgetLED PUMP3(V2);
WidgetLED LAMP(V3);

void initBlynk() {
	// Init WiFi and Blynk connections
	BLYNK_LOG2(BLYNK_F("Connecting to "), WIFI_SSID);
        WiFi.mode(WIFI_STA);
	WiFi.begin(WIFI_SSID, WIFI_PASSWD);

	int initCounter = 0;

	// Wait for WiFi for 30s
	while(WiFi.status() != WL_CONNECTED) {
		if (initCounter > 60) {
			return;
		}

		delay(500);
		BLYNK_LOG1(BLYNK_F("."));
		initCounter++;
	}

	BLYNK_LOG1(BLYNK_F("Connected to WiFi"));
        IPAddress myip = WiFi.localIP();
        (void)myip;
        BLYNK_LOG_IP("IP: ", myip);

	Blynk.config(BLYNK_TOKEN, "blynk-cloud.com", 8080);
	bool status = Blynk.connect(30000);
	if(!status) {
		Blynk.disconnect();
	}

	// Disable leds
	PUMP1.off();
	PUMP2.off();
	PUMP3.off();
	LAMP.off();
}

void runBlynk() {
	Blynk.run();
}

// If an actuator is enabled, enable the coresponding led
void updateBlynkLeds() {
	if (getSerialPump(0)) {
		PUMP1.on();
	} else {
		PUMP1.off();
	}

	if (getSerialPump(1)) {
		PUMP2.on();
	} else {
		PUMP2.off();
	}

	if (getSerialPump(2)) {
		PUMP3.on();
	} else {
		PUMP3.off();
	}

	if (getSerialLamp()) {
		LAMP.on();
	} else {
		LAMP.off();
	}
}

// Write sensors values to the app virtual ports
void sendBlynkDatas() {
	Blynk.virtualWrite(10, getAirTemp());
	Blynk.virtualWrite(11, getAirHum());
	Blynk.virtualWrite(12, getSerialSoilTemp(0));
	Blynk.virtualWrite(13, getSerialSoilHum(0));
	Blynk.virtualWrite(14, getSerialSoilTemp(1));
	Blynk.virtualWrite(15, getSerialSoilHum(1));
	Blynk.virtualWrite(16, getSerialSoilTemp(2));
	Blynk.virtualWrite(17, getSerialSoilHum(2));
}
