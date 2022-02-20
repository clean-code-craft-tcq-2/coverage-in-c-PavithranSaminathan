#include "typewise-alert.h"
#include <stdio.h>

void (*AlerterTarget_FP)[2](BreachType)={sendToController,sendToEmail};

BreachType inferBreach(TempConfig_A ATempConfig, double temperatureInC) {
  if(TempConfig_A.LowerLimit > temperatureInC) 
  {
    return TOO_LOW;
  }
  if(TempConfig_A.UpperLimit < temperatureInC) 
  {
    return TOO_HIGH;
  }
  return NORMAL;
}

void checkAndAlert(AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC) 
{
 //Temperature configuration read from cfg file based on cooling type
  BreachType breachType = inferBreach(TempConfig_A[batteryChar.coolingType], temperatureInC);
 //
  AlerterTarget_FP[alertTarget](breachType);
}

void sendToController(BreachType breachType) {
  const unsigned short header = 0xfeed;
  printf("%x : %x\n", header, breachType);
}

void SendEmail(const char* AMessageData ,const char* ARecepient )
{
  printf("To: %s\n", ARecepient);
  printf("%s",AMessageData);
}
void sendToEmail(BreachType breachType) 
{
  const char* recepient = "a.b@c.com";
  SendEmail(AlerterMailContent[breachType],recepient);
}
