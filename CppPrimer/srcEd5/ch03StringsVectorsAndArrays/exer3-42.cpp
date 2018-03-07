/*
 * =========================================================================
 *
 *       Filename:  exer3-42.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  26/02/17 01:20:59
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
#include<algorithm> // copy
#include<iterator> // begin end

using std::cout; using std::clog; using std::cerr; using std::endl; 
using std::cin;

using std::vector;
using std::string;

int main()
{
  // Write a program to copy a vector of ints into an array of ints.
  const vector<int> intVec={0,1,2,3,4,5,6,7};
//  const size_t sz=intVec.size();


  int intArr[8]; // Note: We cannot use sz here because:
  // The size of an array must be known at compile time, i.e. it must be
  // declared as constexpr. However, neither vector<T>, nor the size funtion
  // can be declared as constexpr. We can use std::array:
  //   constexpr array<int, 8> intVec={0,1,2,3,4,5,6,7};
  //   constexpr size_t sz=intVec.size();

  // We can do this (now commented out):
  // for(size_t i = 0; i != sz; ++i)
  //   intArr[i] = intVec[i];

  // Or we can use std::copy which is a better approach:
  std::copy(intVec.cbegin(), intVec.cend(), std::begin(intArr));

  for(auto i : intArr) 
    cout << i << " ";
  
  cout << endl;

  return 0;
}

