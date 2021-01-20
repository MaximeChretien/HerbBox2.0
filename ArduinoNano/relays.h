/*
 *    @author  : Maxime Chretien (MixLeNain) && Zoomacom / OpenFactory
 *    @mail    : mchretien@linuxmail.org && TODO
 *    @project : HerbBox 2.0
 *    @summary : Defines of functions used to control the relays.
 *    @version : 1.0
 */

void initRelays();

void setPump(int nb, bool state);
void setLamp(bool state);

bool getPump(int nb);
bool getLamp();
