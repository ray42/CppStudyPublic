/*
 * =========================================================================
 * Copyright (c) 2017, Raymon White - All Rights Reserved
 * Author:  Raymon White (ray), rayaxiom42 AT gmail DOT com
 * =========================================================================
 */
#include<iostream>
using std::cout; using std::endl;

#include<string>
using std::string;

#include<memory>
using std::allocator;
using std::uninitialized_fill_n;

#include<cstddef> // for size_t

#include<sstream>
using std::istringstream;

// Exercise 12.26: Rewrite the program on page 481 using an allocator.
int main()
{
  // test data
  istringstream iss("test1 test2 test3");

  size_t n = 10;

  allocator<string> alloc;

//  string *const p = new string[n]; // construct n empty strings
  string * const p = alloc.allocate(n);

  string s;
  string *q = p; // q points to the first string
  while (iss >> s && q!=p+n)
  {
    uninitialized_fill_n(q++,1,s); // assign a new value to *q
  }

  const size_t size = q-p; // remember how many strings we read.
  
  q=p; // reset to point to the first string.
  // We we can use p directly, but I choose this was since YEEAH.
  // use the array
  for(size_t i = 0; i < size; ++i)
  {
    cout << *q++ << endl;
  }

  q=p; // reset to point to the first string.
  // need to destroy, then deallocate.
  for(size_t i = 0; i < size; ++i)
  {
    alloc.destroy(q++);
  }

  alloc.deallocate(p,n);

  return 0;
}
