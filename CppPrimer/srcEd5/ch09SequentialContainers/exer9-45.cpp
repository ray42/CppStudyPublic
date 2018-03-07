#include<iostream>
#include<string>

using std::cout; using std::endl;
using std::string;


//Exercise 9.45: Write a function that takes a string representing a name
//and two other strings representing a prefix, such as “Mr.” or “Ms.” and a
//suffix, such as “Jr.” or “III”. Using iterators and the insert and append
//functions, generate and return a new string with the suffix and prefix
//added to the given name.
string presuffix(const string& name, const string& prefix="",
                                     const string& suffix="")
{
  string ret(name);
  ret.insert(ret.begin(),prefix.begin(),prefix.end());
  return ret.append(suffix);
}

//Exercise 9.46: Rewrite the previous exercise using a position and length 
//to manage the strings. This time use only the insert function.
string presu(const string& name, const string& pre="",
                                 const string& su="")
{
  string ret(name);
  ret.insert(0,pre);
  return ret.insert(ret.size(),su);
}

int main()
{
  cout << presuffix("Ray","Dr","Jr") << endl;
  cout << presu("Ray","Dr","Jr") << endl;
  return 0;
}
