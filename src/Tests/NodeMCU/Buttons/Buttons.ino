#define LAMP_BTN D5
#define PUMP_BTN D4
#define SENSORS_BTN D6

void setup() {
	// Init buttons pins
	pinMode(LAMP_BTN, INPUT_PULLUP);
	pinMode(PUMP_BTN, INPUT_PULLUP);
	pinMode(SENSORS_BTN, INPUT_PULLUP);

	Serial.begin(115200);
}

void loop() {
	// Display buttons state on the serial monitor
	Serial.println("Lamp button : " + String(!digitalRead(LAMP_BTN)));
	Serial.println("Pump button : " + String(!digitalRead(PUMP_BTN)));
	Serial.println("Sensors button : " + String(!digitalRead(SENSORS_BTN)));

	// Wait 1 second
	delay(1000);
}
