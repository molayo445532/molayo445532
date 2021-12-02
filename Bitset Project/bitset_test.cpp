#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_COLOUR_NONE
#include "catch.hpp"

#include "bitset.hpp"



TEST_CASE( "Test bitset construction", "[bitset]" ) {

    Bitset b;  
    REQUIRE(b.size() == 8);
    REQUIRE(b.good());
}

TEST_CASE("size test", "[bitset]" ) {

    Bitset b;  
    REQUIRE(b.size() == 8);
}
TEST_CASE( "good test", "[bitset]" ) {

    Bitset b;
    b.set(9);
    REQUIRE(b.size() == 8);
    REQUIRE(b.good()==false);
}
TEST_CASE( "set test", "[bitset]" ) {

    Bitset b;  
    b.set(0);
    REQUIRE(b.size() == 8);
    REQUIRE(b.good());
    REQUIRE(b.test(0));
}
TEST_CASE( "reset test", "[bitset]" ) {

    Bitset b;  
    b.reset(3);
    REQUIRE(b.size() == 8);
    REQUIRE(b.good());
    REQUIRE(b.test(3)==false);
}
TEST_CASE( "toggle test", "[bitset]" ) {

    Bitset b; 
    b.set(0);
    b.toggle(0); 
    REQUIRE(b.size() == 8);
    REQUIRE(b.good());
    REQUIRE(b.test(0)==false);
}
TEST_CASE("test method test", "[bitset]" ) {

    Bitset b;  
    b.set(0);
    REQUIRE(b.size() == 8);
    REQUIRE(b.good());
    REQUIRE(b.test(0));
}
