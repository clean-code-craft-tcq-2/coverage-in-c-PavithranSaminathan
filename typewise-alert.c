#include "typewise-alert.h"
#include <stdio.h>

MessageACK (*AlerterTarget_FP[MAX_ALERTER_TYPE])(BreachType)={sendToController,sendToEmail};

BreachType inferBreach( BatteryCharacter batteryChar, double temperatureInC) {
  if(TempConfig_A[batteryChar.coolingType].LowerLimit > temperatureInC) 
  {
    return TOO_LOW;
  }
  if(TempConfig_A[batteryChar.coolingType].UpperLimit < temperatureInC) 
  {
    return TOO_HIGH;
  }
  return NORMAL;
}

MessageACK checkAndAlert(AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC) 
{
 //Temperature configuration read from cfg file based on cooling type
  BreachType breachType = inferBreach(batteryChar,temperatureInC);
 //
  MessageACK SentACK =AlerterTarget_FP[alertTarget](breachType);
  
  return SentACK;
}

MessageACK sendToController(BreachType breachType) {
  const unsigned short header = 0xfeed;
  printf("%x : %x\n", header, breachType);
  return SENTTOCONTROLLER;
}

void SendEmail(const char* AMessageData ,const char* ARecepient )
{
  printf("To: %s\n", ARecepient);
  printf("%s",AMessageData);
  
}
MessageACK sendToEmail(BreachType breachType) 
{
  const char* recepient = "a.b@c.com";
  SendEmail(AlerterMailContent[breachType],recepient);
  return SENTTOEMAIL;
}
