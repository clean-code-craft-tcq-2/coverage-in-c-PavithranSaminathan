

#define PASSIVE_COOLING_TEMP_LOWER_LIMIT         0U
#define PASSIVE_COOLING_TEMP_UPPER_LIMIT         35U
#define HI_ACTIVE_COOLING_TEMP_LOWER_LIMIT       0U
#define HI_ACTIVE_COOLING_TEMP_UPPER_LIMIT       45U
#define MID_ACTIVE_COOLING_TEMP_LOWER_LIMIT      0U
#define MID_ACTIVE_COOLING_TEMP_UPPER_LIMIT      40U

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
