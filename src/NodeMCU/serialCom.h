/*
 *    @author  : Maxime Chretien (MixLeNain) && Zoomacom / OpenFactory
 *    @mail    : mchretien@linuxmail.org
 *    @project : HerbBox 2.0
 *    @summary : Defines of functions used to control the serial communication
 *		between the two microcontrollers.
 *    @version : 1.0
 */

void initSerial();
void getSerialSensors();
void setSerialPump(int nb, bool state);
void setSerialLamp(bool state);
void checkResults();

float getSerialSoilTemp(int nb);
float getSerialSoilHum(int nb);
bool getSerialPump(int nb);
bool getSerialLamp();
