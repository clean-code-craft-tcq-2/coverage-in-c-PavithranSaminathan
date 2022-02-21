#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "typewise-alert.h"

TEST_CASE("Battery char belongs to PASSIVE COOLING -Too high")
{
 BatteryCharacter batteryChar = {PASSIVE_COOLING};
  REQUIRE(inferBreach(batteryChar, 55) == TOO_HIGH);
}
TEST_CASE("Battery char belongs to PASSIVE COOLING -Too Low") 
{
 BatteryCharacter batteryChar = {PASSIVE_COOLING};
  REQUIRE(inferBreach(batteryChar, -10) == TOO_LOW);
}
TEST_CASE("Battery char belongs to PASSIVE COOLING -Normal") 
{
 BatteryCharacter batteryChar = {PASSIVE_COOLING};
  REQUIRE(inferBreach(batteryChar, 10) == NORMAL);
}
