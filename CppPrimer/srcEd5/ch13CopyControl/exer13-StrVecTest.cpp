/*
 * =========================================================================
 * Copyright (c) 2017, Raymon White - All Rights Reserved
 * Author:  Raymon White (ray), rayaxiom42 AT gmail DOT com
 * =========================================================================
 */
#include"StrVec.h"

#include<iostream>
using std::cout; using std::endl;

int main()
{
  StrVec sv;
  sv.printall();
  sv.push_back("Text1");
  sv.printall();

  sv.push_back("Text2");
  sv.printall();
  sv.push_back("Text3");
  sv.printall();
  sv.push_back("Text4");
  sv.printall();
  sv.push_back("Text5");
  sv.printall();

  sv.reserve(2);
  sv.printall();

  sv.reserve(12);
  sv.printall();
  
  cout<<endl;
  sv.resize(4);
  sv.printall();

  sv.resize(6,"newText");
  sv.printall();
  sv.reserve(6);
  sv.resize(8,"newnewText");
  sv.printall();
  
  cout<<endl;
  StrVec sv2(sv);
  StrVec sv3;
  sv3 = sv;
  sv2.printall();
  sv3.printall();

  cout<<endl;
  StrVec sv4{"One", "Two", "Three"};
  sv4.printall();
  return 0;
}

