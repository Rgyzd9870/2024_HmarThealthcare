#ifndef __ESP8266_H
#define __ESP8266_H

void ESP8266_Init(void);
uint8_t ESP8266_MQTTPUB(char *DATA);
void ESP8266_MQTTSUB(void);

void ESP8266_MQTTPUB_linshi(double BatteryPercentage , double Droplet);

#endif
