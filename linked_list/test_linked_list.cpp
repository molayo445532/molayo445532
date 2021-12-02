#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "linked_list.hpp"

template class LinkedList<int>;

TEST_CASE("Test Constructor", "[LinkedList]" ) {
  LinkedList<int> x;
  REQUIRE(x.getLength() == 0);
  
}




TEST_CASE("Test Copy constructor", "[LinkedList]") {
  LinkedList<int> x;
  for(int i = 1; i < 10; i++) {
    REQUIRE(x.insert(i,6));
  }

  LinkedList<int> y(x);
  for(int i = 1; i < 10; i++) {
    REQUIRE(y.getEntry(i) == 6);
  }
}


TEST_CASE("Test Insert", "[LinkedList]") {
    LinkedList<int> x;
    REQUIRE(x.insert(1,5));
    REQUIRE(x.insert(2,2));
    REQUIRE(x.getLength() == 2);
}

TEST_CASE("Test Remove", "[LinkedList]") {
  LinkedList<int> l;
  REQUIRE(l.insert(1,5));
  REQUIRE(l.remove(1));
  REQUIRE(l.isEmpty());
  REQUIRE(l.getLength() == 0);

}


TEST_CASE("Test Clear", "[LinkedList]") {
  LinkedList<int> x;
  REQUIRE(x.insert(1,2));
  x.clear();
  REQUIRE(x.getLength() == 0);
  REQUIRE(x.isEmpty());
}

TEST_CASE("Test Swap", "[LinkedList]") {
    LinkedList<int> x;
    LinkedList<int> y;
    for(int i = 1; i < 10; i++) {
      x.insert(i,1);
    }
    for(int j = 1; j < 10; j++) {
      y.insert(j,4);
    }
    x.swap(x,y);
    for(int i = 1; i < 10; i++) {
      REQUIRE(x.getEntry(i) == 4);
    }
}

TEST_CASE("Test getEntry", "[LinkedList]") {
  LinkedList<int> x;
  for(int i = 1; i < 10; i++) {
    REQUIRE(x.insert(i,3));
    REQUIRE(x.getEntry(i) == 3);
  }
}

TEST_CASE("Test setEntry", "[LinkedList]") {
  LinkedList<int> x;
  for(int i =1; i < 10; i++) {
    REQUIRE(x.insert(i,9));
  }
  x.setEntry(3,3);
  REQUIRE(x.getEntry(3) == 3);
}




