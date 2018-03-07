/*==========================================================================
 * Copyright (c) 2017, Raymon White - All Rights Reserved
 * Author:  Raymon White (ray), rayaxiom42 AT gmail DOT com
 * Code for the exercises from C++ Primer 5th Edition
 *==========================================================================
 */
#include<iostream>
using std::cout; using std::endl;
#include<bitset>
using std::bitset;

template<unsigned long N>
void copy_bitset(bitset<N>& orig, bitset<N>& cpy)
{
  for(decltype(orig.size()) i = 0; i < orig.size(); ++i)
  {
    cpy[i] = orig[i];
  }
}

//Using the sequence 1, 2, 3, 5, 8, 13, 21, initialize a bitset that has a
//1 bit in each position corresponding to a number in this sequence. Default
//initialize another bitset and write a small program to turn on each of the
//appropriate bits.
int main()
{
  bitset<32> bs("100000001000010010111");
  cout << bs << endl;
  bitset<bs.size()> bscpy; // this works because bitset<ul>::size() 
                           // is constexpr
  cout << bscpy << endl;
  
  copy_bitset(bs,bscpy);
  cout << bscpy << endl;

  return 0;
}
