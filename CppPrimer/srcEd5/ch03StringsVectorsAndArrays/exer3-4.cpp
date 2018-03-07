#include<iostream>
#include<string>

using std::cout; using std::endl; using std::cin;
using std::string;

int main()
{
  // Write a program to read two strings and report whether the strings are
  // equal. If not, report which of the two is larger. Now, change the 
  // program to report whether the strings have the same length, and if not,
  // report which is longer.
  string str1, str2;

  // read two strings
  cin >> str1 >> str2;

  // Are they equal?
  if(str1 == str2)
  {
    cout << "Strings are equal" << endl;
  }
  else
  {
    // print out the larger of the two
    cout << "Larger: " << (str1 > str2 ? str1 : str2) << endl;
  }

  // Are they same size?
  if(str1.size() == str2.size())
  {
    cout << "They have the same length" << endl;
  }
  else
  {
    cout << "Longer: " << (str1.size() > str2.size() ? str1 : str2) << endl;
  }
  return 0;
}
