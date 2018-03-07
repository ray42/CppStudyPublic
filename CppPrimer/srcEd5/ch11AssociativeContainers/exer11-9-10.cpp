/*
 * =========================================================================
 * Copyright (c) 2017, Raymon White - All Rights Reserved
 * Author:  Raymon White (ray), rayaxiom42 AT gmail DOT com
 * =========================================================================
 */
#include<iostream>
using std::cout; using std::endl;

#include<map>
using std::map;

#include<list>
using std::list;

#include<vector>
using std::vector;

#include<string>
using std::string;


int main()
{
  //Exercise 11.9: Define a map that associates words with a list of line
  //numbers on which the word might occur.
  map<string,list<unsigned> > wordlinenum;

  //Exercise 11.10: Could we define a map from vector<int>::iterator to
  //int? What about from list<int>::iterator to int? In each case, if
  //not, why not?
  map<vector<int>::iterator,int> m1;
  map<list<int>::iterator,int >m2; // why is this okay? 

  // yes, both works because vector<T>::iterator is a RandomAccessIterator
  // list<T>::iterator is a BidirectionalIterator, so I'm surprised that it
  // works.... why? I'm not sure.

  return 0;
}
