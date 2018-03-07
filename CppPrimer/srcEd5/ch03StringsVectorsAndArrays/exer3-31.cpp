/*
 * =========================================================================
 *
 *       Filename:  exer3-31.cpp
 *
 *        Version:  1.0
 *        Created:  25/02/17 15:44:18
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Dr. Raymon White (rayray), quatrezwei@gmail.com
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

// Write a program to define an array of ten ints. Give each
// element the same value as its position in the array.
int main()
{
  constexpr size_t arr_size = 10;
  int intarr[arr_size]={}; // Use value initialization
  for(size_t i = 0; i < arr_size; ++i)
  {
    intarr[i]=i;
  }

  // print it out to test
  for(auto i : intarr)
  {
    cout << i << " ";
  }
  cout << endl;

  return 0;
}
