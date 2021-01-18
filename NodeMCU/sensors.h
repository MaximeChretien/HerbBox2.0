/*
 *    @author  : Maxime Chretien (MixLeNain) && Zoomacom / OpenFactory
 *    @mail    : mchretien@linuxmail.org && TODO
 *    @project : HerbBox 2.0
 *    @summary : Defines of functions used to control the sensors.
 *    @version : 1.0
 */

void initSensors();
void updateBtns();
void updateDHT();

float getAirTemp();
float getAirHum();

bool getLampBtn();
bool getPumpBtn();
bool getSensorsBtn();
