#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_COLOUR_NONE
#include <iostream>
#include "catch.hpp"
#include "XMLParser.hpp"

using namespace std;

// TODO Implement tests of your Stack class and XMLParser class here

TEST_CASE( "Test Bag add", "[XMLParser]" )
{
	   INFO("Hint: testing Bag add()");
		// Create a Bag to hold ints
		Bag<int> intBag;
		int testSize = 2;
		int bagSize;
		bool success;
		for (int i=0; i<testSize; i++) {
			success = intBag.add(i);
			REQUIRE(success);
			bagSize = intBag.size();
			success = (bagSize == (i+1));
			REQUIRE(success);
		}
}

TEST_CASE( "Test Stack push", "[XMLParser]" )
{
	   INFO("Hint: testing Stack push()");
		// Create a Stack to hold ints
		Stack<int> intStack;
		int testSize = 3;
		int stackSize;
		bool success;
		for (int i=0; i<testSize; i++) {
			success = intStack.push(i);
			REQUIRE(success);
			stackSize = intStack.size();
			success = (stackSize == (i+1));
			REQUIRE(success);
		}
}

TEST_CASE( "Test XMLParser tokenizeInputString", "[XMLParser]" )
{
	   INFO("Hint: tokenize single element test of XMLParse");
		// Create an instance of XMLParse
		XMLParser myXMLParser;
		string testString = "<test>stuff</test>";
		bool success;
		success = myXMLParser.tokenizeInputString(testString);
		REQUIRE(success);
	
		string testString1= "<test>stuff</test>";
		REQUIRE(myXMLParser.tokenizeInputString(testString1));
		
		string testString2 = "<test>stuff</test>";
		REQUIRE(myXMLParser.tokenizeInputString(testString2));
		
			string testString3="<a><b>";
		REQUIRE(myXMLParser.tokenizeInputString(testString3));
			string testString4="<a><b></b></a>";
		REQUIRE(myXMLParser.tokenizeInputString(testString4));
			string testString5="<a><b>c>";
		REQUIRE(!myXMLParser.tokenizeInputString(testString5));
			string testString6="<?xml version=1.0 encoding=UTF-8?><note><to>Tove</to><from name=test, joe=teddy>Jani</from><heading>Reminder</heading><note/><body>Don't forget me this weekend!</body></note>";
		REQUIRE(myXMLParser.tokenizeInputString(testString6));
}


TEST_CASE( "Test XMLParser parseTokenizedInput", "[XMLParser]" )
{
		// Create an instance of XMLParse
		XMLParser myXMLParser;
		string testString = "<test>stuff</test>";
		REQUIRE(myXMLParser.tokenizeInputString(testString));
		REQUIRE(myXMLParser.parseTokenizedInput());
		string testString1="<a><b></b></a>";
		REQUIRE(myXMLParser.tokenizeInputString(testString1));
		REQUIRE(myXMLParser.parseTokenizedInput());
		string testString2="<c><b></b></a>";
		REQUIRE(myXMLParser.tokenizeInputString(testString2));
		REQUIRE(!myXMLParser.parseTokenizedInput());
	
}