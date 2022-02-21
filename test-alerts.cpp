#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "typewise-alert.h"

TEST_CASE("infers the breach according to limits") {
  batteryChar.coolingType = PASSIVE_COOLING;
  REQUIRE(inferBreach(BatteryCharacter batteryChar, 55) == TOO_HIGH);
}
