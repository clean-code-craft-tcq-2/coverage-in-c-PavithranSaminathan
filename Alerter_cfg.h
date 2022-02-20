

typedef enum {
  PASSIVE_COOLING,
  HI_ACTIVE_COOLING,
  MED_ACTIVE_COOLING,
  MAX_COOLING_TYPE
} CoolingType;


struct TempConfig
{
  int LowerLimit;
  int UpperLimit;
};

extern const struct TempConfig TempConfig_A[MAX_COOLING_TYPE];
