#pragma once

#include "Alerter_cfg.h"

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
} BatteryCharacter;


BreachType inferBreach( BatteryCharacter batteryChar, double temperatureInC);
BreachType classifyTemperatureBreach(CoolingType coolingType, double temperatureInC);

MessageACK checkAndAlert(AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC);

MessageACK sendToController(BreachType breachType);
MessageACK sendToEmail(BreachType breachType);

