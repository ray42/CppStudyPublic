/*
 * =========================================================================
 * Copyright (c) 2017, Raymon White - All Rights Reserved
 * Author:  Raymon White (ray), rayaxiom42 AT gmail DOT com
 * =========================================================================
 */
#include<iostream>
using std::cout; using std::endl;
#include"StrBlob.h"

int main()
{
  const StrBlob csb{ "hello", "world", "Ray" };
  StrBlob sb{ "hello", "world", "Johanna" };

  std::cout << csb.front() << " " << csb.back() << std::endl;
  sb.back() = "Another Ray";
  std::cout << sb.front() << " " << sb.back() << std::endl;
  return 0;
}
