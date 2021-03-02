#define DHT_PIN D3
#define DHT_TYPE DHT11

#include <DHT.h>
// Init DHT sensor
DHT dht(DHT_PIN, DHT_TYPE);

void setup() {
	// Init DHT communication
	dht.begin();

	Serial.begin(115200);
}

void loop() {
	// Print sensors values on the serial monitor
	Serial.println("Temperature : " + String(dht.readTemperature()) + " C");
	Serial.println("Humidity : " + String(dht.readHumidity()) + " %");

	// Wait 1 second
	delay(1000);
}
