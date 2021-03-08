#define MOIST1_DATA A5
#define MOIST2_DATA A6
#define MOIST3_DATA A7
#define MOIST1_ALIM 2
#define MOIST2_ALIM 3
#define MOIST3_ALIM 4
#define MOIST_N 3 // Number of measures to get the average value

void setup() {
	Serial.begin(9600);

	// Init Moisture sensors power pins
	pinMode(MOIST1_ALIM, OUTPUT);
	pinMode(MOIST2_ALIM, OUTPUT);
	pinMode(MOIST3_ALIM, OUTPUT);

	// Put all pins to low to disable the sensors
	digitalWrite(MOIST1_ALIM, LOW);
	digitalWrite(MOIST2_ALIM, LOW);
	digitalWrite(MOIST3_ALIM, LOW);
}

void loop() {
	float soilHum[3];

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

	// Get a pourcentage from the value
	soilHum[0] = map(soilHum[0], 780, 317, 0, 100);
	soilHum[1] = map(soilHum[1], 780, 317, 0, 100);
	soilHum[2] = map(soilHum[2], 780, 317, 0, 100);

	// Display the values in the Serial monitor
	for(int i = 0; i < 3; i++) {
		Serial.println("Sensor " + String(i+1) + ": " + String(soilHum[i]) + "%");
	}

	// Wait 1 second
	delay(1000);
}
