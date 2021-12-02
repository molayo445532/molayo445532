#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_COLOUR_NONE
#include "catch.hpp"

#include "dynamic_array_list.h"
#include "sorted_list.h"
#include "priority_queue.h"

TEST_CASE("Testing Priority Queue", "[priority queue]") {

  typedef SortedList<int, DynamicArrayList<int> > SortedListType;
  typedef PriorityQueue<int, SortedListType>  PriorityQueueType;

  PriorityQueueType pq;
  for(int i=0;i<=5;i++){

  pq.add(i+20);
  std::cout<<pq.peek();
  }
  pq.add(30);
  REQUIRE(!pq.isEmpty());
   REQUIRE(pq.peek()==30);
   pq.remove();
pq.add(27);
pq.add(22);
 REQUIRE(pq.peek()==27);
 pq.remove();
  REQUIRE(pq.peek()==25);
  pq.remove();
REQUIRE(pq.peek()==24);
pq.remove();
REQUIRE(pq.peek()==23);
pq.remove();
REQUIRE(pq.peek()==22);
pq.remove();
REQUIRE(pq.peek()==22);
pq.remove();
REQUIRE(pq.peek()==21);
pq.remove();
REQUIRE(pq.peek()==20);
  REQUIRE(!pq.isEmpty());
}
