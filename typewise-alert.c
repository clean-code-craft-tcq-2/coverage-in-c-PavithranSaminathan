#include "typewise-alert.h"
#include <stdio.h>

MessageACK (*AlerterTarget_FP[MAX_ALERTER_TYPE])(BreachType)={sendToController,sendToEmail};


/* This function will alert temperature level */
BreachType inferBreach( BatteryCharacter batteryChar, double temperatureInC) 
{
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
 /*Temperature configuration read from cfg file based on battery configuration*/
  BreachType breachType = inferBreach(batteryChar,temperatureInC);
 /*Alert message will pass to controller or Email */
  MessageACK SentACK =AlerterTarget_FP[alertTarget](breachType);
  
  return SentACK;
}

/*Alerter message passing in to controller*/ 
MessageACK sendToController(BreachType breachType) 
{
  const unsigned short header = 0xfeed;
  printf("%x : %x\n", header, breachType);
  return SENTTOCONTROLLER;
}

void SendEmail(const char* AMessageData ,const char* ARecepient )
{
  printf("To: %s\n", ARecepient);
  printf("%s",AMessageData);
  
}
/*Alerter message passing via Email*/
MessageACK sendToEmail(BreachType breachType) 
{
  const char* recepient = "a.b@c.com";
  SendEmail(AlerterMailContent[breachType],recepient);
  return SENTTOEMAIL;
}
