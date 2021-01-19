/*
 *    @author  : Maxime Chretien (MixLeNain) && Zoomacom / OpenFactory
 *    @mail    : mchretien@linuxmail.org && TODO
 *    @project : HerbBox 2.0
 *    @summary : Defines of functions used to control the sensors.
 *    @version : 0.1
 */

void initSensors();
void updateTempSensors();
void updateHumSensors();

float getSoilTemp(int nb);
float getSoilHum(int nb);
