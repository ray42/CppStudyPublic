/*
 * =========================================================================
 *
 *       Filename:  exer6-sometest.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  06/03/17 16:17:24
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Dr. Raymon White (Zwei), quatrezwei@gmail.com
 *   Organization:  
 *
 * =========================================================================
 */
#include<iostream>
#include<vector>
#include<string>

using std::cout; using std::clog; using std::cerr; using std::endl; 
using std::cin;

using std::vector;
using std::string;
char &get_val(string &str, string::size_type ix)
{
  return str[ix]; // get_val assumes the given index is valid
}
int main()
{
  string s("a value");
  cout << s << endl;   // prints a value
  get_val(s, 0) = 'A'; // changes s[0] to A
  cout << s << endl;   // prints A value
  return 0;
}

