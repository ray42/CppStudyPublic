/*
 * =========================================================================
 *         Author:  Dr. Raymon White (Zwei), quatrezwei@gmail.com
 * =========================================================================
 */
#include<iostream>
#include<vector>
#include<string>
#include<cstring>

using std::cout; using std::clog; using std::cerr; using std::endl; 
using std::cin;

using std::vector;
using std::string;

int main()
{
  // Write a program to define two character arrays initialized from string
  // literals. Now define a third character array to hold the concatenation
  // of the two arrays. Use strcpy and strcat to copy the two arrays into 
  // the third.

  const char ca1[]="Hello ";
  const char ca2[]="World";

  constexpr size_t sz=strlen(ca1)+strlen(ca2)+1; // add 1 for null.

  char ca3[sz];

  strcpy(ca3,ca1); // copies ca1 into ca3
  strcat(ca3,ca2); // concatenates ca2 to the end of ca3.

  printf("%s\n",ca3);

  return 0;
}

