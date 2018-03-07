/*
 * =========================================================================
 * Copyright (c) 2017, Raymon White - All Rights Reserved
 * Author:  Raymon White (ray), rayaxiom42 AT gmail DOT com
 * =========================================================================
 */
#include<iostream>
using std::cout; using std::endl;
#include<algorithm>
using std::max;
#include<string>
using std::string;

template<typename T>
int compare(const T& v1, const T& v2)
{
  if(v1<v2) return -1;
  if(v2<v1) return 1;
  return 0;
}

int main()
{
  // exer37
  cout << max<double>(1,2.0) << endl;

  // exer38
  cout << compare<string>("aaa","bbb") << endl;


  return 0;
}
