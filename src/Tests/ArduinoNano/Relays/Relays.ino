#define PUMP1_PIN 12
#define PUMP2_PIN 11
#define PUMP3_PIN 9
#define LAMP_PIN 10

void setup() {
	// Init all pins to output
	pinMode(PUMP1_PIN, OUTPUT);
	pinMode(PUMP2_PIN, OUTPUT);
	pinMode(PUMP3_PIN, OUTPUT);
	pinMode(LAMP_PIN, OUTPUT);

	// Put all pins to a low state
	digitalWrite(PUMP1_PIN, LOW);
	digitalWrite(PUMP2_PIN, LOW);
	digitalWrite(PUMP3_PIN, LOW);
	digitalWrite(LAMP_PIN, LOW);
}

void loop() {
	// Enable pump 1 for 1 second
	digitalWrite(PUMP1_PIN, HIGH);
	delay(1000);
	digitalWrite(PUMP1_PIN, LOW);

	// Enable pump 2 for 1 second
	digitalWrite(PUMP2_PIN, HIGH);
	delay(1000);
	digitalWrite(PUMP2_PIN, LOW);

	// Enable pump 3 for 1 second
	digitalWrite(PUMP3_PIN, HIGH);
	delay(1000);
	digitalWrite(PUMP3_PIN, LOW);

	// Enable lamp for 1 second
	digitalWrite(LAMP_PIN, HIGH);
	delay(1000);
	digitalWrite(LAMP_PIN, LOW);

	// Wait 2 seconds
	delay(2000);
}
