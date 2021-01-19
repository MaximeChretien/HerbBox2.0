/*
 *    @author  : Maxime Chretien (MixLeNain) && Zoomacom / OpenFactory
 *    @mail    : mchretien@linuxmail.org && TODO
 *    @project : HerbBox 2.0
 *    @summary : Implementation of functions used to control the display.
 *    @version : 0.1
 */

#include "display.h"

#include <ACROBOTIC_SSD1306.h>
#include <SPI.h>
#include <Wire.h>

#include "sensors.h"
#include "serialCom.h"

bool enabled = false;

void initDisplay() {
	Wire.begin();
	oled.init();                      // Initialze SSD1306 OLED display
	clearDisplay();
	//oled.setFont(font5x7);            // Set font type (default 8x8)
	oled.clearDisplay();              // Clear screen
	oled.setTextXY(0,0);
	oled.putString("   HerbBox 2.0");
	oled.setTextXY(7,0);
	oled.putString("Sensor Key ==>>");
}

void updateDisplay() {
	if (enabled) {
		displayDatas();
	} else {
		clearDisplay();
	}
}

void changeDisplayState() {
	enabled = !enabled;
	updateDisplay();
}

void displayDatas(void)
{
	oled.setTextXY(0,0);
	oled.putString("   HerbBox 2.0");

	oled.setTextXY(3,0);
	oled.putString("AirTmp [C] ");
	oled.setTextXY(3,11);
	oled.putString("     ");
	oled.setTextXY(3,11);
	oled.putString(String(getAirTemp()));

	oled.setTextXY(4,0);
	oled.putString("AirHum [%] ");
	oled.setTextXY(4,11);
	oled.putString("     ");
	oled.setTextXY(4,11);
	oled.putString(String(getAirHum()));

	oled.setTextXY(5,0);
	oled.putString("SoilTmp[C] ");
	oled.setTextXY(5,11);
	oled.putString("     ");
	oled.setTextXY(5,11);
	oled.putString(String(getSerialSoilTemp(0)));

	oled.setTextXY(6,0);
	oled.putString("SoilHum[%] ");
	oled.setTextXY(6,11);
	oled.putString("     ");
	oled.setTextXY(6,11);
	oled.putString(String(getSerialSoilHum(0)));

	oled.setTextXY(7,0);
	oled.putString("PUMP: ");
	oled.setTextXY(7,6);
	oled.putString(String(getSerialPump(0)));

	oled.setTextXY(7,7);
	oled.putString("  LAMP: ");
	oled.setTextXY(7,15);
	oled.putString(String(getSerialLamp()));
}

void clearDisplay()
{
	oled.setFont(font8x8);
	oled.setTextXY(0,0);
	oled.putString("                ");
	oled.setTextXY(1,0);
	oled.putString("                ");
	oled.setTextXY(2,0);
	oled.putString("                ");
	oled.setTextXY(3,0);
	oled.putString("                ");
	oled.setTextXY(4,0);
	oled.putString("                ");
	oled.setTextXY(5,0);
	oled.putString("                ");
	oled.setTextXY(6,0);
	oled.putString("                ");
	oled.setTextXY(7,0);
	oled.putString("                ");
	oled.setTextXY(0,0);
	oled.putString("                ");
}

