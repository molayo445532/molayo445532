#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <vector>
#include "bag.hpp"

// force template expansion
template class Bag<int>;

TEST_CASE("Empty Test", "[Bag]"){
  REQUIRE(true);
}

TEST_CASE("isEmpty tEST", "[Bag]"){
  Bag <std::string> a;
  a.add("phone");
  REQUIRE(a.isEmpty()==false);
}

TEST_CASE("get current size test", "[Bag]"){
  Bag <std::string> a;
  REQUIRE(a.getCurrentSize()==0);
}

TEST_CASE("additem test", "[Bag]"){
  Bag <std::string> a;
  std::string item="phone";
  REQUIRE(a.add(item)==true);
}

TEST_CASE("removeitem test", "[Bag]"){
  Bag <std::string> a;
  std::string item="phone";
  a.remove(item);
  REQUIRE(a.remove(item)==false);
}

TEST_CASE("clear test", "[Bag]"){
  Bag <std::string> a;
  std::string item="phone";
  a.add(item);
  a.add(item);
  a.clear();
  REQUIRE(a.getCurrentSize()==0);
}

TEST_CASE("contains test", "[Bag]"){
  Bag <std::string> a;
  std::string item="phone";
  REQUIRE(a.contains(item)==false);
}

TEST_CASE("getFrequencyOf test", "[Bag]"){
  Bag <std::string> a;
  std::string item="phone";
  a.add(item);
  a.remove(item);
  REQUIRE(a.getFrequencyOf(item)==0);
}