/*
 * =========================================================================
 * Copyright (c) 2017, Raymon White - All Rights Reserved
 * Author:  Raymon White (ray), rayaxiom42 AT gmail DOT com
 * =========================================================================
 */
#include<iostream>
using std::cout; using std::endl;
#include<memory>
using std::unique_ptr;
#include<string>
using std::string;

int main()
{
  unique_ptr<string> s_upt(new string("Ray"));

  // error: use of deleted function ‘std::unique_ptr<_Tp, _Dp>
  //unique_ptr<string> s2_upt(s_upt);

  unique_ptr<string> s3_upt;

  // same thing: Error: Call to implicitly-deleted copy constructor of 'unique_ptr<string>'
  s3_upt = s_upt;

  return 0;
}
