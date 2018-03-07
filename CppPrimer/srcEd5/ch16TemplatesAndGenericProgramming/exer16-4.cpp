/*==========================================================================
 * Copyright (c) 2017, Raymon White - All Rights Reserved
 * Author:  Raymon White (ray), rayaxiom42 AT gmail DOT com
 * Code for the exercises from C++ Primer 5th Edition
 *==========================================================================
 */
#include<iostream>
using std::cout; using std::endl;

#include<list>
using std::list;
#include<vector>
using std::vector;

// First we look at the precise specification of find:
//template <class InputIterator, class T>
//InputIterator find (InputIterator first, InputIterator last, const T& val);
//
//Find value in range
//
//Returns an iterator to the first element in the range [first,last) that 
//compares equal to val. If no such element is found, the function returns 
//last.
//
// The function uses operator== to compare the individual elements to val.

// For reference see: http://en.cppreference.com/w/cpp/algorithm/find
template<typename InputIt, typename T>
InputIt myfind(InputIt beg, InputIt end, const T& val)
{
  for(;beg!=end;++beg)
    if(*beg == val) return beg;

  return end;
}

int main()
{
  vector<unsigned>vu{1,2,3,4,5,6,7,8,9};
  list<double>lu{1.1,2.2,3.3,4.4,5.5,6.6,7.7,8.8,9.9};

  vector<unsigned>::iterator vit = myfind(vu.begin(),vu.end(),unsigned(4));
  cout << *vit << endl;
  auto lit = myfind(lu.begin(),lu.end(),8.8);
  cout << *lit << endl;
  return 0;
}
