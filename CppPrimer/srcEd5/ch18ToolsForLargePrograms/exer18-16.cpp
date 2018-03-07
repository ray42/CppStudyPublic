/*
 * =========================================================================
 * Copyright (c) 2017, Raymon White - All Rights Reserved
 * Author:  Raymon White (ray), rayaxiom42 AT gmail DOT com
 * =========================================================================
 */
#include<iostream>
using std::cout; using std::endl;

namespace Exercise{
  int ivar = 1;
  double dvar = 2;
  const int limit = 1000;
}

int ivar = 10; 

// position 1

void manip()
{
  // position 2
using namespace Exercise;

  double dvar = 3.1416; // redeclaration error
  cout << "dvar: " << dvar << endl; // 2
  int iobj = limit+1; // Exercise::limit
  cout << "iobj: " << iobj << endl; // 1001
//  ++ivar; // ambiguous
//  cout << "ivar: " << ivar << endl; ambiguous
  ++::ivar; // ::ivar
  cout << "::ivar: " << ::ivar << endl; // 11
}

int main()
{

  manip();
  cout << dvar << endl;
  return 0;
}

