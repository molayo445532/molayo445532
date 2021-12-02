#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "dynamic_bag.hpp"

// force template expansion for ints
template class DynamicBag<int>;

TEST_CASE("Constructor test", "[DynamicBag]"){
  DynamicBag<int> b;

 REQUIRE(b.isEmpty()==true);
}
TEST_CASE("add test", "[DynamicBag]"){
  DynamicBag<int> b;

 REQUIRE(b.add(2)==true);
REQUIRE(b.getCurrentSize()==1);
}

TEST_CASE("remove test", "[DynamicBag]"){
  DynamicBag<int> b;
b.add(1);
b.add(1);
b.add(1);
REQUIRE(b.getCurrentSize()==3);
b.remove(1);
REQUIRE(b.getCurrentSize()==2);
  }

TEST_CASE("isEmpty test", "[DynamicBag]"){
  DynamicBag<int> b;
 REQUIRE(b.add(2));
REQUIRE(!b.isEmpty());
  }

TEST_CASE("getCurrentSize test", "[DynamicBag]"){
  DynamicBag<int> b;
 
   REQUIRE(b.add(1));
 REQUIRE(b.add(1));
 REQUIRE(b.getCurrentSize()==2);
  }

  TEST_CASE("clear test", "[DynamicBag]"){
  DynamicBag<int> b;
 for(int i=0;i<5;i++){
REQUIRE(b.add(1));
 }
   b.clear();
 REQUIRE(b.getCurrentSize()==0);
  }

TEST_CASE("getFrequencyOf test", "[DynamicBag]"){
  DynamicBag<int> b;
REQUIRE(b.add(1));
REQUIRE(b.add(1));
REQUIRE(b.add(1));
 REQUIRE(b.getFrequencyOf(1)==3);
  }

TEST_CASE("contains test", "[DynamicBag]"){
  DynamicBag<int> b;
REQUIRE(b.add(1));
REQUIRE(b.add(1));
REQUIRE(b.add(1));
 REQUIRE(b.contains(1));
  }
 