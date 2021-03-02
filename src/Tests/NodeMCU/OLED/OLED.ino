#include <ACROBOTIC_SSD1306.h>
#include <SPI.h>
#include <Wire.h>

void setup() {
	// Init display connection
	Wire.begin();
	oled.init(); // Initialze SSD1306 OLED display
	oled.clearDisplay(); // Clear screen

	// Put some text
	oled.setTextXY(0,0);
	oled.putString("abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ 1234567890");

	delay(5000);
}

void loop() {
	// Display the output of millis
	oled.putString(String(millis()));

	// Wait 167 ms
	delay(167);
}
