#define ONEWIRE_BUS 5

#include <DallasTemperature.h>
#include <OneWire.h>

OneWire oneWire(ONEWIRE_BUS);
DallasTemperature DS18B20(&oneWire);

void setup() {
	DS18B20.begin();
	Serial.begin(9600);
}

void loop() {
	DS18B20.requestTemperatures();

	// Display all values on the serial monitor
	for(int i = 0; i < 3; i++) {
		Serial.println("Capteur " + String(i+1) + ": " + DS18B20.getTempCByIndex(i) + " C");
	}

	delay(1000);
}
