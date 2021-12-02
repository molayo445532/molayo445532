#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "fancyPower.hpp"

// write your test cases here
TEST_CASE("Test case", "fancyPower"){

  REQUIRE(true);
  
}
TEST_CASE("Test recurssion base case", "fancyPower"){

  REQUIRE(fancyPower(2,3)==9);
  
}
TEST_CASE("Test recurssion", "fancyPower"){

  REQUIRE(fancyPower(3,2)==8);
  
}