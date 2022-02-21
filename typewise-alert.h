#pragma once

#include "Alerter_cfg.h"

//typedef enum {
//  PASSIVE_COOLING,
//  HI_ACTIVE_COOLING,
//  MED_ACTIVE_COOLING
//} CoolingType;


typedef enum {
  SENTTOCONTROLLER,
  SENTTOEMAIL
}MessageACK;

typedef enum {
  TO_CONTROLLER,
  TO_EMAIL,
  MAX_ALERTER_TYPE
} AlertTarget;

typedef struct {
  CoolingType coolingType;
//  char brand[48];
} BatteryCharacter;


BreachType inferBreach( BatteryCharacter batteryChar, double temperatureInC);
//BreachType inferBreach(double value, double lowerLimit, double upperLimit);
BreachType classifyTemperatureBreach(CoolingType coolingType, double temperatureInC);



void checkAndAlert(AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC);

MessageACK sendToController(BreachType breachType);
MessageACK sendToEmail(BreachType breachType);

//void (*AlerterTarget_FP[MAX_ALERTER_TYPE])(BreachType);

//void (*MailAlertType_FP[MAX_BREACH_TYPE])(BreachType);
