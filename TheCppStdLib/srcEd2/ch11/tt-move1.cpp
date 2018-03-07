/*
 * =========================================================================
 * Copyright (c) 2017, Raymon White - All Rights Reserved
 * Author:  Raymon White (ray), rayaxiom42 AT gmail DOT com
 * =========================================================================
 */

// algo/move1.cpp

#include "./../algostuff.hpp"
using namespace std;

int main()
{
  vector<string> coll1 = { "Hello", "this", "is", "an", "example" };
  list<string> coll2;

  // copy elements of coll1 into coll2
  // - use back inserter to insert instead of overwrite
  // - use copy() because the elements in coll1 are used again
  copy (coll1.cbegin(), coll1.cend(),            // source range
        back_inserter(coll2));                   // destination range

  // print elements of coll2
  // - copy elements to cout using an ostream iterator
  // - use move() because these elements in coll2 are not used again
  move (coll2.cbegin(), coll2.cend(),            // source range
        ostream_iterator<string>(cout," "));     // destination range
  cout << endl;

  // copy elements of coll1 into coll2 in reverse order
  // - now overwriting (coll2.size() still fits)
  // - use move() because the elements in coll1 are not used again
  move (coll1.crbegin(), coll1.crbegin()+1,          // source range
        coll2.begin());                          // destination range

  // print elements of coll2 again
  // - use move() because the elements in coll2 are not used again
  move (coll2.cbegin(), coll2.cend(),            // source range
        ostream_iterator<string>(cout," "));     // destination range
  cout << endl;
}




