/*
 * =========================================================================
 * Copyright (c) 2017, Raymon White - All Rights Reserved
 * Author:  Raymon White (ray), rayaxiom42 AT gmail DOT com
 * =========================================================================
 */

#include<iostream>
using std::cout; using std::endl;

#include"StrBlobPtrPtr32.h" // change this!
#include"StrBlob30.h" // change this!

int main()
{
  // underlying structure is a pointer to a vector of strings.
  StrBlob sb{"A","BB","C","D"};

  // create the iterator
  StrBlobPtr sbp(sb);

  // This new class...
  StrBlobPtrPtr sbpp(&sbp);

  ++sbp; // increment to point to BB.
  cout << sbpp->size() << endl; // it should locate size from std::string

  return 0;
}
