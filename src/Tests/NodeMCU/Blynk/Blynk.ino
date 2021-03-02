#include <BlynkSimpleEsp8266.h>

#define WIFI_SSID ""
#define WIFI_PASSWD ""
#define BLYNK_TOKEN ""

// Define Blynk leds
WidgetLED PUMP1(V0);
WidgetLED PUMP2(V1);
WidgetLED PUMP3(V2);
WidgetLED LAMP(V3);

void setup() {
	// Init WiFi and Blynk connections
	Blynk.begin(BLYNK_TOKEN, WIFI_SSID, WIFI_PASSWD);

	// Disable leds
	PUMP1.off();
	PUMP2.off();
	PUMP3.off();
	LAMP.off();
}

void loop() {
	unsigned long time = millis();

	bool ledStatus = time%2;
	if(ledStatus) {
		PUMP1.on();
		PUMP2.off();
		PUMP3.on();
		LAMP.off();
	} else {
		PUMP1.off();
		PUMP2.on();
		PUMP3.off();
		LAMP.on();
	}

	Blynk.virtualWrite(10, time%50);
	Blynk.virtualWrite(11, time%15);
	Blynk.virtualWrite(12, time%37);
	Blynk.virtualWrite(13, time%49);
	Blynk.virtualWrite(14, time%33);
	Blynk.virtualWrite(15, time%27);
	Blynk.virtualWrite(16, time%18);
	Blynk.virtualWrite(17, time%21);

	Blynk.run();
}
