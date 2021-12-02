#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_COLOUR_NONE
#include "catch.hpp"
#include "FindPalindrome.hpp"

// There should be at least one test per FindPalindrome method

TEST_CASE( "Test FindPalindrome add a non-allowable word", "[FindPalindrome]" )
{
	INFO("Hint: add a single non-allowable word");
	FindPalindrome b;
	REQUIRE(!b.add("kayak1"));
}
TEST_CASE( "Test FindPalindrome add allowable word", "[FindPalindrome]" )
{
	INFO("Hint: add a single allowable word");
	FindPalindrome b;
		REQUIRE(b.add("molayo"));
}

TEST_CASE( "Test cuttest1", "[FindPalindrome]" )
{
	FindPalindrome b;
	std::vector<std::string> candidate={"hello","molayo"};
		REQUIRE(b.cutTest1(candidate));
			REQUIRE(!b.cutTest1({"aa","bb","cc"}));
			REQUIRE(!b.cutTest1({"aa","bbb","cc"}));
			REQUIRE(b.cutTest1({"aaa","bbb","ccc"}));
			REQUIRE(b.cutTest1({"a","bbb","cc"}));
			REQUIRE(b.cutTest1({"a","b","cc"}));
			REQUIRE(!b.cutTest1({"aa","b","cc"}));
			REQUIRE(!b.cutTest1({"aa","bb","cc"}));
}

TEST_CASE("cutTest2 test","[FindPalindrome]"){
	FindPalindrome x;
	REQUIRE(x.cutTest2({"Ka"},{"ak"})==false);
	REQUIRE(!x.cutTest2({"Kay"},{"ak"}));
	REQUIRE(x.cutTest2({"May"},{"ak"}));
}

TEST_CASE("add vector test","[FindPalindrome]"){
	FindPalindrome x;
	std::vector<std::string> candidate={"hello","molayo"};
	REQUIRE(x.add(candidate));
	REQUIRE(x.number()==0);
	std::vector<std::string> s={"1hello","molayo"};
	REQUIRE(!x.add(s));
	REQUIRE(!x.add(candidate));
}
TEST_CASE("constructor test","[FindPalindrome]"){
	FindPalindrome x;
	REQUIRE(x.number()==0);
}

TEST_CASE("FindPalindrome test","[FindPalindrome]"){
	FindPalindrome x;
	std::vector<std::string> s={"Never","Odd"};
	std::vector<std::string> y={"or","even"};
REQUIRE(x.add(s));
REQUIRE(x.add(y));
	REQUIRE(x.number()==1);
}




