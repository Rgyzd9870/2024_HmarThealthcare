#ifndef __ESP8266_H
#define __ESP8266_H

void ESP8266_Init(void);
uint8_t ESP8266_MQTTPUB(char *DATA);
void ESP8266_MQTTSUB(void);
uint8_t ESP8266_MQTTPUB_Create(char *DATA);
void ESP8266_MQTTPUB_Send(double BloodOxygen , double Droplet,double PulseFrequency);

#endif
