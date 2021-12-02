#include <string>
#include <vector>
#include <iostream>
#include <locale> 
#include "FindPalindrome.hpp"

using namespace std;

//------------------- HELPER FUNCTIONS -----------------------------------------

// non-class helper functions go here, should be declared as "static" so that
// their scope is limited

// helper function to convert string to lower case
static void convertToLowerCase(string & value)
{
	locale loc;
	for (int i=0; i<value.size(); i++) {
		value[i] = tolower(value[i],loc);
	}
}

//------------------- PRIVATE CLASS METHODS ------------------------------------

// private recursive function. Must use this signature!
void FindPalindrome::recursiveFindPalindromes(vector<string>
        candidateStringVector, vector<string> currentStringVector)
{
	std::vector<std::string> temp;
	std::string temp_string = "";
	if(currentStringVector.size() == 0) {
		for(int i = 0; i < candidateStringVector.size(); i++) {
			temp_string += candidateStringVector[i];
		}
		//checking if it is a palindrome sentence
		if(isPalindrome(temp_string) == true) {
			numberOfPalindromes++;
			palindromes.push_back(candidateStringVector);
		}
	} else {
		for(int i = 0; i < currentStringVector.size(); i++) {
			temp.push_back(currentStringVector[i]);
		}
		for(int i = 0; i < candidateStringVector.size(); i++) {
			temp.push_back(candidateStringVector[i]);
		}
		if(!cutTest1(temp)) {
			for(int i = 0; i < currentStringVector.size(); i++) {
				candidateStringVector.push_back(currentStringVector[i]);
				currentStringVector.erase(currentStringVector.begin() + i);
				
				if(!cutTest2(candidateStringVector,currentStringVector)) {	
					recursiveFindPalindromes(candidateStringVector,currentStringVector);
				}
				
				currentStringVector.insert(currentStringVector.begin() + i, candidateStringVector.back());
				candidateStringVector.pop_back();
			}
		}
	}
}

// private function to determine if a string is a palindrome (given, you
// may change this if you want)
bool FindPalindrome::isPalindrome(string currentString) const
{
	locale loc;
	// make sure that the string is lower case...
	convertToLowerCase(currentString);
	// see if the characters are symmetric...
	int stringLength = currentString.size();
	for (int i=0; i<stringLength/2; i++) {
		if (currentString[i] != currentString[stringLength - i - 1]) {
			return false;
		}
	}
	return true;
}

//------------------- PUBLIC CLASS METHODS -------------------------------------

FindPalindrome::FindPalindrome()
{
	current={};
	candidate={};
	numberOfPalindromes=0;
}

FindPalindrome::~FindPalindrome()
{
}

int FindPalindrome::number() const
{
	return numberOfPalindromes;
}

void FindPalindrome::clear()
{
	candidate.clear();
	current.clear();
	numberOfPalindromes=0;
	palindromes.clear();
}

bool FindPalindrome::cutTest1(const vector<string> & stringVector)
{
//returns false if valid
	std:string temp = "";
	int temparr[26];
	for(int i = 0; i < 26; i++) {
		temparr[i] = 0;
	}
	for(int i = 0; i < stringVector.size(); i++) {
		temp += stringVector[i];
	}
	convertToLowerCase(temp);
	//counting frequnecy of each character
	for(int i = 0; i < temp.length(); i++) {
		++temparr[temp[i] - 97];
	}

	int flag = 2;

	for(int i = 0; i < 26; i++) {
		//checking if its odd
		if(temparr[i] % 2 == 1) {
			if(!(--flag)) {
				return true;
			}
		}
	}
	return false;
}

bool FindPalindrome::cutTest2(const vector<string> & stringVector1,
                              const vector<string> & stringVector2)
{//returns false if valid
	int freq_equal = 0;
	int freq_small = 0;
	bool cut = false;
	std::string str1 = "", str2 = "";
	for(int i = 0; i < stringVector1.size(); i++) {
		str1 += stringVector1[i];
	}
	for(int j = 0; j < stringVector2.size(); j++) {
		str2 += stringVector2[j];
	}
	convertToLowerCase(str1);
	convertToLowerCase(str2);
	//checking which vector had a greater length
	if(str1.length() > str2.length()) {
		//counting how many times the smaller size string has each character in the larger string and making sure its equal to the number of times it appears in the smaller string
		for(int i = 0; i < str2.length(); i++) {
			for(int j = 0; j < str1.length(); j++) {
				if(str2[i] == str1[j]) {
					freq_equal++;
				}
			}
		}
		for(int i = 0; i < str2.length(); i++) {
			for(int j = 0; j < str2.length(); j++) {
				if(str2[i] == str2[j]) {
					freq_small++;
				}
			}
		}
		if(freq_equal >= freq_small) {
			cut = false;
		} else {
			cut = true;
		}
	} else {
		//same process for string2 > string1
		for(int i = 0; i < str1.length(); i++) {
			for(int j = 0; j < str2.length(); j++) {
				if(str1[i] == str2[j]) {
					freq_equal++;
				}
			}
		}
		for(int i = 0; i < str1.length(); i++) {
			for(int j = 0; j < str1.length(); j++) {
				if(str1[i] == str1[j]) {
					freq_small++;
				}
			}
		}
		if(freq_equal >= freq_small) {
			cut = false;
		} else {
			cut = true;
		}
	}
	return cut;
}

bool FindPalindrome::add(const string & value)
{
	char c; 
	for(int j = 0; j < value.length(); j++) {
		c = value[j];
		//making sure it's a valid character
		if(!((c >= 'a' && c<= 'z') || (c>= 'A' && c <= 'Z'))) {
			return false;
		}
	}
	//making sure word is unique
	for(int i = 0; i < current.size(); i++) {
		if(current[i] == value) {
			return false;
		}
	}
	current.push_back(value);
	//clearing vectors and resetting count
	palindromes.clear();
	numberOfPalindromes = 0;
	//calling cutTest1
	if(!cutTest1(current)) {
		recursiveFindPalindromes(candidate,current);
	}
	return true;
}

bool FindPalindrome::add(const vector<string> & stringVector)
{
	int counting = 0;
	std:string temp = "";
	char c;
	for(int i=0;i<stringVector.size();i++){
		current.push_back(stringVector[i]);
		convertToLowerCase(current.back());
		temp += stringVector[i];
	}
	for(int i = 0; i < temp.length(); i++) {
		c = temp[i];
		if(!((c >= 'a' && c<= 'z') || (c>= 'A' && c <= 'Z')))//checking if valid 
		{
			return false;
		}
	}
	for(int j = 0; j < current.size(); j++) {
		counting = 0;
		for(int k = 0; k < current.size(); k++) {
			if(current[j] == current[k]) {//checking if strings are repeated
				counting++;
			}
			
			if(counting >= 2) {
				return false;
			}
		}
	}
	//clearing vectors and resetting count
	palindromes.clear();
	numberOfPalindromes = 0;
	//checking cutTest1
	if(!cutTest1(current)) {
		recursiveFindPalindromes(candidate,current);
	}
	return true;
}

vector< vector<string> > FindPalindrome::toVector() const
{
	// TODO need to implement this...
	vector<vector<string>> returnThingie;
	//setting private variable equal to returnThingie
	returnThingie = palindromes;
	return returnThingie;
}

