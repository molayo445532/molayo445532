// Project 3 -- XML Parsing Project

/** XML parsing class implementation.
    @file XMLParser.cpp */

#include <string>
#include <assert.h>
#include "XMLParser.hpp"

// TODO: Implement the constructor here
XMLParser::XMLParser()
{
	elementNameBag=new Bag<std::string>();
	parseStack=new Stack<std::string>();
}  // end default constructor

// TODO: Implement the destructor here
XMLParser::~XMLParser()
{
	delete elementNameBag;
	delete parseStack;
	elementNameBag=nullptr;
	parseStack=nullptr;
}  // end destructor


// TODO: Implement the tokenizeInputString method
bool XMLParser::tokenizeInputString(const std::string &inputString)
{
	TokenStruct temp;
	bool b=true;
	if(inputString[0]!='<'||inputString[inputString.size()-1]!='>'){
		b=false;
		tokenizedInputVector.clear();
	}
	else{
		for(int i=0;i<inputString.size()-1;i++)
			if(inputString[i]=='<'){
				if(inputString[i+1]=='<'){b=false;
				break;}
			}
			else if(inputString[i]=='>'){
				if(inputString[i+1]=='>'){
					b=false;
				}
				break;
			}

		}
		for(int i=0;i<inputString.size();i++){
			temp.tokenString="";
			if(inputString[i]=='<'){
				for(int j=i;j<inputString.size();j++){
					if(inputString[j]=='>'){
						for(int k=i+1;k<j;k++){
							if(inputString[k]=='<'){
								b=false;
								break;
							}
							else if(inputString[k]==' ') {
								for(int l=j+1;l<k;l++){
								temp.tokenString+=inputString[l];
								}
								break;
							}
							else{
									temp.tokenString+=inputString[k];
							}
						}
						
						
							if(temp.tokenString.at(0)=='/'){
								temp.tokenType=END_TAG;
								temp.tokenString.erase(0,1);
							}
							else if(temp.tokenString[temp.tokenString.size()-1]=='/'){
								temp.tokenType=EMPTY_TAG;
								temp.tokenString.erase(temp.tokenString.size()-1,1);
							}
							else if(temp.tokenString[0]=='?'){
								temp.tokenType=DECLARATION;
								temp.tokenString.erase(0,1);

							}
							else temp.tokenType=START_TAG;
							
						tokenizedInputVector.push_back(temp);
						temp.tokenString="";

						for(int m=j+1;m<inputString.size();m++){
							if(inputString[m]=='<'){
								for(int n=j+1;n<m;n++){
									temp.tokenString+=inputString[n];
								}
								if(temp.tokenString==""){
									break;
								}
								temp.tokenType=CONTENT;
								tokenizedInputVector.push_back(temp);
								break;
							}
						}
						break;
					}
				}				
		
			}
			else if(inputString[i]=='>'){
				for(int j=i;j>=0;j--){
					if(inputString[j]=='<'){
						for(int k=j+1;k<i;k++){
							if(inputString[k]=='>'){
								b=false;
								break;
							}
						}
						break;
					}
				}	
			}
		
		}
	if(b==false){
		tokenizedInputVector.clear();
	}
	return b;
	}

// TODO: Implement a helper function to delete attributes from a START_TAG
// or EMPTY_TAG string (you can change this...)


// TODO: Implement the parseTokenizedInput method here
bool XMLParser::parseTokenizedInput()
{
	if(tokenizedInputVector.empty()){
		return false;
	}
	for (int i=0;i<tokenizedInputVector.size();i++){
		if(tokenizedInputVector[i].tokenType==1){
		parseStack->push(tokenizedInputVector[i].tokenString);
		elementNameBag->add(tokenizedInputVector[i].tokenString);
		}
		else if(tokenizedInputVector[i].tokenType==2){
			if(parseStack->peek()==tokenizedInputVector[i].tokenString){
				parseStack->pop();
			}
			elementNameBag->add(tokenizedInputVector[i].tokenString);
		}
			else {
				elementNameBag->add(tokenizedInputVector[i].tokenString);
			}

	}
	if(parseStack->isEmpty()){
		return true;
	}
	else return false;

}
/*bool XMLParser::parseTokenizedInput()
{
	bool b=false;
	for(int i=0;i<tokenizedInputVector.size();i++){
		TokenStruct temp=tokenizedInputVector.at(i);
		std::string tempString=temp.tokenString;
		std::string temps;
		temps=deleteAttributes(tempString);
		parseStack->push(temps);
	}
	int i=0;
	while(!parseStack->isEmpty()){
		TokenStruct temp=tokenizedInputVector[i];
		std::string tempString=temp.tokenString;
			std::string temps;
		temps=deleteAttributes(tempString);
		if(parseStack->peek()==temps){
			b=true;
		}
		parseStack->pop();
		i++;
	}
	return b;
}*/

// TODO: Implement the clear method here
void XMLParser::clear()
{
	delete elementNameBag;
	delete parseStack;
	
}

vector<TokenStruct> XMLParser::returnTokenizedInput() const
{	

	return tokenizedInputVector;
}

// TODO: Implement the containsElementName method
bool XMLParser::containsElementName(const std::string &inputString) const
{
	return elementNameBag->contains(inputString);
}

// TODO: Implement the frequencyElementName method
int XMLParser::frequencyElementName(const std::string &inputString) const
{
	return elementNameBag->getFrequencyOf(inputString);
}

