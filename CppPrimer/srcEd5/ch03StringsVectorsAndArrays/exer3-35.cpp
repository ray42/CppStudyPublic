/*
 * =========================================================================
 *
 *       Filename:  exer3-34.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  25/02/17 20:31:38
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
#include<cstddef> // size_t

#include "./../rayheader.h"

using std::cout; using std::clog; using std::cerr; using std::endl; 
using std::cin;

using std::vector;
using std::string;

int main()
{
  // Using pointers, write a program to set the elements in an array to 
  // zero.
  constexpr size_t sz = 10;

  int arr[sz];
  int * aend=arr+sz;
  for(int *abeg=arr; abeg != aend; ++abeg)
  {
    *abeg=0;
  }

  ray::print_sequence(arr);

  return 0;
}
