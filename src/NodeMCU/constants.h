/*
 *    @author  : Maxime Chretien (MixLeNain) && Zoomacom / OpenFactory
 *    @mail    : mchretien@linuxmail.org
 *    @project : HerbBox 2.0
 *    @summary : All the constants used in the system.
 *    @version : 1.0
 */

// Automatic control parameters
// Plant 1
#define PLANT1_DRY_SOIL      66
#define PLANT1_WET_SOIL      85
#define PLANT1_TIME_PUMP_ON  15000L

// Plant 2
#define PLANT2_DRY_SOIL      66
#define PLANT2_WET_SOIL      85
#define PLANT2_TIME_PUMP_ON  15000L

// Plant 3
#define PLANT3_DRY_SOIL      66
#define PLANT3_WET_SOIL      85
#define PLANT3_TIME_PUMP_ON  15000L

// All plants
#define COLD_TEMP     12
#define HOT_TEMP      22
#define TIME_LAMP_ON  15000L

// DHT
#define DHT_PIN D3
#define DHT_TYPE DHT11

// Buttons
#define LAMP_BTN D5
#define PUMP_BTN D4
#define SENSORS_BTN D6

// Blynk
#define WIFI_SSID ""
#define WIFI_PASSWD ""
#define BLYNK_TOKEN ""

// Timer
#define TM_READ_BTN 1000L
#define TM_READ_DHT 2000L
#define TM_GET_SOIL 5000L
#define TM_UPDATE_DISPLAY 2000L
#define TM_SEND_BLYNK 10000L
#define TM_AUTO_CTRL 10000L
#define TM_AUTO_CTRL_CHECK 60000L
