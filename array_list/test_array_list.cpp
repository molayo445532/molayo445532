#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "array_list.hpp"

//force class expansion
template class ArrayList<int>;

TEST_CASE( "insert Test", "[ArrayList]" ) {

  ArrayList<int> list;
  REQUIRE(list.insert(1,45)); 
  REQUIRE(list.getEntry(1)==45);
}


TEST_CASE( "getlenght Test", "[ArrayList]" ) {

  ArrayList<int> list;
  REQUIRE(list.insert(1,45));
  REQUIRE(list.getLength()==10);
}

TEST_CASE( "clear Test", "[ArrayList]" ) {

  ArrayList<int> list;
  REQUIRE(list.insert(1,45));
  list.clear();
  REQUIRE(list.isEmpty());
}
TEST_CASE( "getEntry Test", "[ArrayList]" ) {

  ArrayList<int> list;
  REQUIRE(list.insert(1,45));
  REQUIRE(list.getEntry(1)==45);
}
TEST_CASE( "setEntry Test", "[ArrayList]" ) {

  ArrayList<int> list;
  REQUIRE(list.insert(1,45));
  list.setEntry(1,12);
  REQUIRE(list.getEntry(1)==12);
}