#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "deque.hpp"
#include "linked_list.hpp"
#include <cassert>

TEST_CASE( "Tests", "[deque]" ) {
Deque<int, LinkedList<int>> deque;

REQUIRE(deque.isEmpty());
deque.pushFront(23);
deque.pushFront(25);
deque.pushFront(27);
REQUIRE(!deque.isEmpty());

REQUIRE(deque.front()==27);
REQUIRE(deque.back()==23);
deque.popBack();
deque.popFront();

REQUIRE(deque.front()==25);
REQUIRE(deque.back()==25);
deque.popFront();
REQUIRE(deque.isEmpty());
}
