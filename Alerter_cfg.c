#include "Alerter_cfg.h"

/*configured alerter message content  */

const char *AlerterMailContent[MAX_BREACH_TYPE]={"Hi, the temperature is too low\n",
                                                 "Hi, the temperature is too high\n",
                                                 "Hi, the temperature is Normal\n"
                                                 };


/*Configuring temperature limit according to battery type*/

const struct TempConfig TempConfig_A[MAX_COOLING_TYPE]={
  {PASSIVE_COOLING_TEMP_LOWER_LIMIT    ,  PASSIVE_COOLING_TEMP_UPPER_LIMIT},
  {HI_ACTIVE_COOLING_TEMP_LOWER_LIMIT  ,  HI_ACTIVE_COOLING_TEMP_UPPER_LIMIT},
  {MID_ACTIVE_COOLING_TEMP_LOWER_LIMIT ,  MID_ACTIVE_COOLING_TEMP_UPPER_LIMIT}
};
