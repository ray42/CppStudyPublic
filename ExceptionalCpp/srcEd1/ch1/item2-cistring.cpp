/*
 * =========================================================================
 * Copyright (c) 2017, Raymon White - All Rights Reserved
 * Author:  Raymon White (ray), rayaxiom42 AT gmail DOT com
 * =========================================================================
 */
#include<iostream>
using std::cout; using std::endl;
#include<cassert>
#include<cstring>
using std::strcmp;

#include"ci_char_traits_it2.h"


int main()
{
  cout << "Hello" << endl;
  ci_string s( "AbCdE" );

  // case insensitive
  assert( s == "abcde" );
  assert( s == "ABCDE" );

  // still case-preserving, of course
  assert( strcmp( s.c_str(), "AbCdE" ) == 0 );
  assert( strcmp( s.c_str(), "abcde" ) != 0 );
  cout << "Done" << endl;

  return 0;
}

