/*
 * =========================================================================
 *         Author:  Dr. Raymon White (Zwei), quatrezwei@gmail.com
 * =========================================================================
 */
#include<iostream>
#include<vector>
#include<string>
#include<cstring> // c style string functions like strcmp
#include<cstdio> // printf

using std::cout; using std::clog; using std::cerr; using std::endl; 
using std::cin;

using std::vector;
using std::string;

// Write a program to compare two strings. Now write a program to compare
// the values of two C-style character strings.
int main()
{
  string str1="Hello";
  string str2="World";

  if(str1 == str2)
  {
    cout << str1 << " == " << str2 << endl;
  }
  else if(str1 < str2)
  {
    cout << str1 << " < " << str2 << endl;
  }
  else
  {
    cout << str1 << " > " << str2 << endl;
  }

  const char ca1[]="Hello";
  const char ca2[]="World";
  int res=std::strcmp(ca1,ca2);
  if(res==0)
  {
    printf("%s == %s \n", ca1, ca2);
  }
  else if(res < 0)
  {
    printf("%s < %s \n", ca1, ca2);
  }
  else
  {
    printf("%s > %s \n", ca1, ca2);
  }
  return 0;
}
