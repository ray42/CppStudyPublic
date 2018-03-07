/*
 * =========================================================================
 * Copyright (c) 2017, Raymon White - All Rights Reserved
 * Author:  Raymon White (ray), rayaxiom42 AT gmail DOT com
 * =========================================================================
 */


// iter/frontinserter1.cpp

#include <list>
#include <algorithm>
#include <iterator>
//#include "print.hpp"
#include<iostream>
using namespace std;

template<typename C>
void PRINT_ELEMENTS(const C& c)
{
  for(const auto& ele: c)
    cout << ele << " ";
  cout << endl;
}

int main()
{
  list<int> coll;

  // create front inserter for coll
  // - inconvenient way
  front_insert_iterator<list<int> > iter(coll);

  // insert elements with the usual iterator interface
  *iter = 1; // inserts at front
  iter++;    // no-op, returns iter.
  *iter = 2; // inserts at front
  iter++;    // no-op, returns iter.
  *iter = 3; // inserts at front

  PRINT_ELEMENTS(coll);

  // create front inserter and insert elements
  // - convenient way
  front_inserter(coll) = 44;
  front_inserter(coll) = 55;

  PRINT_ELEMENTS(coll);

  // use front inserter to insert all elements again
  copy (coll.begin(), coll.end(),     // source
        front_inserter(coll));        // destination

  PRINT_ELEMENTS(coll);
}


