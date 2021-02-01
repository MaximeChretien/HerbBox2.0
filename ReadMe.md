# HerbBox 2.0

HerbBox is an automatic system to control the humidity and the temperature of three plants.

This system use two microcontrollers talking together, an Arduino Nano and a NodeMCU v3 (This is because we already had them so it was better than buying a bigger microcontroller)

## Schematics
![schematics](/schematics/schematics.png)

## NodeMCU
### Required arduino libraries
- DallasTemperature (Version from Arduino IDE)
- OneWire (Version from Arduino IDE)
- SimpleTimer (This particular version is needed : https://github.com/schinken/SimpleTimer)

### Attached sensors / actuators
- 3x DS18B20
- 3x Capacitive Soil Moisture Sensor v1.2
- 4x Relays

TODO

## Arduino Nano
### Required arduino libraries
- ACROBOTIC SSD1306 (Version from Arduino IDE)
- Blynk (Version from Arduino IDE)
- DHT sensor library (Version from Arduino IDE)
- SimpleTimer (This particular version is needed : https://github.com/schinken/SimpleTimer)

### Attached sensors / actuators
- DHT11
- 3x push button
- SSD1306 OLED display

TODO

## Automatic control settings
All settings for the automatic control are stored in src/NodeMCU/constants.h . It means that the NodeMCU program needs to be reuploaded when you want to make changes to the settings.

### Soil settings
- **PLANT1_DRY_SOIL**: Value of the soil humidity under which the soil is considered dry. Value between 0% and 100% (Default: 66).
- **PLANT1_WET_SOIL**: Value of the soil humidity over which the soil is considered wet. Value between 0% and 100% (Default: 85).
- **PLANT1_TIME_PUMP_ON**: Duration during which the pump is powered on to water the plant if the soil is dry. Value in ms with a L at the end (Default: 15000L).

For plant 2 and plant 3, just change the one with a 2 or a 3 in the name instead of a 1.

### Air settings
- **COLD_TEMP**: Value of the air temperature under which the air is considered cold. Value in Celsius degree (Default: 12).
- **HOT_TEMP**: Value of the air temperature over which the air is considered hot. Value in Celsuis degree (Default: 22).
- **TIME_LAMP_ON**: Duration during which the lamp is powered on to warm up the plants if the temperature is cold. Value in ms with a L at the end (Default: 15000L).
