#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_COLOUR_NONE
#include "catch.hpp"

#include "dynamic_array_list.h"
#include "sorted_list.h"

TEST_CASE("Testing Sorted List", "[sorted list]") 
{
  typedef SortedList<int, DynamicArrayList<int>> slst;
  
  slst sorted;
  REQUIRE(sorted.isEmpty());
  REQUIRE(sorted.getLength() == 0);

  for(int i = 0; i < 10; i++) {
    sorted.insert(i);
    REQUIRE(sorted.getEntry(i) == i);
    REQUIRE(sorted.getPosition(i) == i);
  }

  REQUIRE_FALSE(sorted.isEmpty());
  REQUIRE(sorted.getLength() == 10);

  sorted.remove(0);

  REQUIRE(sorted.getLength() == 9);
  REQUIRE(sorted.getEntry(0) == 1);
  

  sorted.remove(1);

  REQUIRE(sorted.getLength() == 8);
  REQUIRE(sorted.getEntry(0) == 2);

  sorted.remove(2);

  REQUIRE(sorted.getLength() == 7);
  REQUIRE(sorted.getEntry(0) == 3);

  sorted.remove(3);

  REQUIRE(sorted.getLength() == 6);
  REQUIRE(sorted.getEntry(0) == 4);

  sorted.remove(4);

  REQUIRE(sorted.getLength() == 5);
  REQUIRE(sorted.getEntry(0) == 5);

  sorted.remove(5);

  REQUIRE(sorted.getLength() == 4);
  REQUIRE(sorted.getEntry(0) == 6);

  sorted.remove(6);

  REQUIRE(sorted.getLength() == 3);
  REQUIRE(sorted.getEntry(0) == 7);

  sorted.remove(7);

  REQUIRE(sorted.getLength() == 2);
  REQUIRE(sorted.getEntry(0) == 8);

  sorted.remove(8);

  REQUIRE(sorted.getLength() == 1);
  REQUIRE(sorted.getEntry(0) == 9);

  sorted.remove(9);

  REQUIRE(sorted.getLength() == 0);
  REQUIRE(sorted.isEmpty());

}

TEST_CASE("copy assignment", "[copy assignment]") {
  typedef SortedList<int, DynamicArrayList<int>> slst;

  slst sorted;


  for(int i = 0; i < 10; i++) {
    sorted.insert(i);
    REQUIRE(sorted.getEntry(i) == i);
    REQUIRE(sorted.getPosition(i) == i);
  }

  REQUIRE_FALSE(sorted.isEmpty());
  REQUIRE(sorted.getLength() == 10);

  slst sorted2;

  sorted2 = sorted;

  for(int i = 0; i < 10; i++) {
    REQUIRE(sorted.getEntry(i) == i);
    REQUIRE(sorted.getPosition(i) == i);
  }

  REQUIRE_FALSE(sorted.isEmpty());
  REQUIRE(sorted.getLength() == 10);
}


TEST_CASE("copy constructor", "[copy constructor]") {
  typedef SortedList<int, DynamicArrayList<int>> slst;

  slst sorted;


  for(int i = 0; i < 10; i++) {
    sorted.insert(i);
    REQUIRE(sorted.getEntry(i) == i);
    REQUIRE(sorted.getPosition(i) == i);
  }

  REQUIRE_FALSE(sorted.isEmpty());
  REQUIRE(sorted.getLength() == 10);

  slst sorted2(sorted);

  for(int i = 0; i < 10; i++) {
    REQUIRE(sorted.getEntry(i) == i);
    REQUIRE(sorted.getPosition(i) == i);
  }

  REQUIRE_FALSE(sorted.isEmpty());
  REQUIRE(sorted.getLength() == 10);
}

TEST_CASE("removeAt", "[removeAt]") {
  typedef SortedList<int, DynamicArrayList<int>> slst;

  slst sorted;


  for(int i = 0; i < 10; i++) {
    sorted.insert(i);
    REQUIRE(sorted.getEntry(i) == i);
    REQUIRE(sorted.getPosition(i) == i);
  }

  REQUIRE_FALSE(sorted.isEmpty());
  REQUIRE(sorted.getLength() == 10);

  for(int i = 0; i < 10; i++) {
    sorted.removeAt(0);
  }
  
  REQUIRE(sorted.getLength() == 0);
  REQUIRE(sorted.isEmpty() == true);
}


TEST_CASE("clear", "[clear]") {
  typedef SortedList<int, DynamicArrayList<int>> slst;

  slst sorted;


  for(int i = 0; i < 10; i++) {
    sorted.insert(i);
    REQUIRE(sorted.getEntry(i) == i);
    REQUIRE(sorted.getPosition(i) == i);
  }

  REQUIRE_FALSE(sorted.isEmpty());
  REQUIRE(sorted.getLength() == 10);

  sorted.clear();
  REQUIRE(sorted.isEmpty());
  REQUIRE(sorted.getLength() == 0);
}