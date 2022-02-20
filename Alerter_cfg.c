#include "Alerter_cfg.h"

const char *AlerterMailContent[MAX_BREACH_TYPE]={"Hi, the temperature is too low\n",
                                                 "Hi, the temperature is too high\n",
                                                 "Hi, the temperature is Normal\n"
                                                 };

const struct TempConfig TempConfig_A[MAX_COOLING_TYPE]={
  {0,35},
  {0,45},
  {0,40}
};
