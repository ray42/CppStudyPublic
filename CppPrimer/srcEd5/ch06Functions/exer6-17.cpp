#include<iostream>
using std::cout; using std::endl;

#include<string>
using std::string;

#include<cctype>

bool contains_upper(const string& str)
{
  for(const auto& ch: str)
  {
    if(isupper(ch))
      return true;
  }
  
  return false;
}

string& to_lower(string& str)
{
  for(auto& ch: str)
    if(isupper(ch)) ch = tolower(ch);

  return str;
}

//Exercise 6.17: Write a function to determine whether a string contains
//any capital letters. Write a function to change a string to all lowercase.
//Do the parameters you used in these functions have the same type? If so, 
//why? If not, why not?
int main()
{
  cout << contains_upper("upper?") << endl;
  cout << contains_upper("uPper?") << endl;
  string str = "uPper?";
  cout << to_lower(str) << endl;
  return 0;
}
