/*
 * =========================================================================
 * Copyright (c) 2017, Raymon White - All Rights Reserved
 * Author:  Raymon White (ray), rayaxiom42 AT gmail DOT com
 * =========================================================================
 */
#include<iostream>
using std::cout; using std::endl;


// Example 2: Will this compile?
//
// In some library header:
namespace N { class C {}; 

int operator+(int i, N::C) { return i+1; }
}
// A mainline to exercise it:
#include <numeric>
int main()
{
  N::C a[10];
  std::accumulate(a, a+10, 0);
}



