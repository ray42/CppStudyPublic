#include<iostream>
#include<string>
#include<algorithm>

using std::cout; using std::endl;
using std::string;
using std::transform;

//Exercise 9.47: Write a program that finds each numeric character and then
//each alphabetic character in the string "ab2c3d7R4E6". Write two versions
//of the program. The first should use find_first_of, and the second
//find_first_not_of.
void locate_alpha_numeric(const string& s="")
{
  // locate numeric characters.
  string numbers("0123456789");
  string alphabet("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
  
  cout << "Locating numerics for " << s << endl;
  for(decltype(numbers.size()) pos=0;        
      (pos=s.find_first_of(numbers,pos)) != string::npos; ++pos)
  {
    cout << s[pos] << " at " << pos << endl;
  }

  cout << "Locating alphabet for " << s << endl;
  for(decltype(numbers.size()) pos=0;        
      (pos=s.find_first_of(alphabet,pos)) != string::npos; ++pos)
  {
    cout << s[pos] << " at " << pos << endl;
  }
}

void locate_alpha_numericv2(const string& s="")
{
  // locate numeric characters.
  string numbers("0123456789");
  string alphabet("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
  
  cout << "Locating numerics for " << s << endl;
  // to use find_first_not_of, we simply find first not of alphabet, this 
  // would imply find_first_of numbers.
  for(decltype(numbers.size()) pos=0;
      (pos=s.find_first_not_of(alphabet,pos)) != string::npos; ++pos)
  {
    cout << s[pos] << " at " << pos << endl;
  }

  cout << "Locating alphabet for " << s << endl;
  for(decltype(numbers.size()) pos=0;        
      (pos=s.find_first_not_of(numbers,pos)) != string::npos; ++pos)
  {
    cout << s[pos] << " at " << pos << endl;
  }
}
int main()
{ 
  //                    012345678910
  locate_alpha_numeric("ab2c3d7R4E6");
  locate_alpha_numericv2("ab2c3d7R4E6");
  return 0;
}
