

typedef enum {
  PASSIVE_COOLING,
  HI_ACTIVE_COOLING,
  MED_ACTIVE_COOLING,
  MAX_COOLING_TYPE
} CoolingType;

typedef enum {
  NORMAL,
  TOO_LOW,
  TOO_HIGH,
  MAX_BREACH_TYPE
} BreachType;

struct TempConfig
{
  int LowerLimit;
  int UpperLimit;
};

extern const char *AlerterMailContent[MAX_BREACH_TYPE];
extern const struct TempConfig TempConfig_A[MAX_COOLING_TYPE];
