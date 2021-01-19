/*
 *    @author  : Maxime Chretien (MixLeNain) && Zoomacom / OpenFactory
 *    @mail    : mchretien@linuxmail.org && TODO
 *    @project : HerbBox 2.0
 *    @summary : All the constants used in the system.
 *    @version : 0.1
 */

// Moisture sensors
#define MOIST1_DATA A5
#define MOIST2_DATA A6
#define MOIST3_DATA A7
#define MOIST1_ALIM 3
#define MOIST2_ALIM 4
#define MOIST3_ALIM 5
#define MOIST_N 3 // Number of measures to get the average value

// DS18B20
#define ONEWIRE_BUS 2

// Relays
#define PUMP1_PIN 12
#define PUMP2_PIN 11
#define PUMP3_PIN 9
#define LAMP_PIN 10

// Timer
#define TM_READ_HUM 8000L
#define TM_READ_TEMP 4000L
#define TM_READ_SERIAL 500L
