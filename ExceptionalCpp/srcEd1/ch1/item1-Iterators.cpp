/*
 * =========================================================================
 * Copyright (c) 2017, Raymon White - All Rights Reserved
 * Author:  Raymon White (ray), rayaxiom42 AT gmail DOT com
 * =========================================================================
 */
#include<iostream>
using std::cout; using std::endl;

auto retint()
{ return int(42); }

int main()
{
  // Error: lvalue required as increment operand
  ++retint();

  // Okay, operator+ reads the rvalue, not write to it.
  // e.g. a = b+c, b and c are read, not modified
  retint()+1;

  return 0;
}
