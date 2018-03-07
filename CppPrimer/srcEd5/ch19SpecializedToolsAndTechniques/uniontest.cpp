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

union Token
{
  ~Token()=default;
  string s;
  int i;
};

int main()
{
  Token t={string("Hello")};
  return 0;
}

