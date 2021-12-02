#include <string>
#include <stack>
using std::string;

#include <iostream>

#include <cctype> // for isalpha

#include "algebraic_expressions.hpp"

bool isoperator(char ch) {
  return ((ch == '+') || (ch == '-') || (ch == '/') || (ch == '*'));
}

int endPost(string s, int last) {
  int first = 0;

  if ((first > last)) {
    return -1;
  }

  char ch = s[last];
  if (isalpha(ch)) {
    return last;
  } else {
    if (isoperator(ch)) {
      int lastEnd = endPost(s, last - 1);
      if (lastEnd > -1) {
        return endPost(s, lastEnd - 1);
      } else {
        return -1;
      }
    } else {
      return -1;
    }
  }
}

bool isPost(string s) {
  int firstChar = endPost(s, s.size() - 1);

  return (firstChar == 0);
}

void convert(string &postfix, string &prefix) {
std::stack<string> s;
for(int i=0;i<postfix.length();i++){
  if(isoperator(postfix[i])){
   string op1=s.top();
   s.pop();
   string op2=s.top();
s.pop();
   string temp=postfix[i]+op2+op1;
   s.push(temp);}
   else{
     s.push(string(1,postfix[i]));}
   }
   prefix=s.top();
}
