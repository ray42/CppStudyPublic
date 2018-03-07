/*
 * =========================================================================
 * Copyright (c) 2017, Raymon White - All Rights Reserved
 * Author:  Raymon White (ray), rayaxiom42 AT gmail DOT com
 * =========================================================================
 */
#include<iostream>
using std::cout; using std::endl;

#include"StrBlob.h"

//Exercise 13.3: What happens when we copy a StrBlob? What about
//StrBlobPtrs?
int main()
{
  StrBlob sb{"Ray1", "Ray2", "Ray3"};
  cout << "sb.use_count: " << sb.use_count() << endl;
  cout << "sb.printAll: " << sb.printAll() << endl;

  StrBlob sb2(sb);
  cout << "sb2.use_count: " << sb2.use_count() << endl;
  cout << "sb2.printAll: " << sb2.printAll() << endl;

  StrBlobPtr sbptr(sb2);
  cout << "sbptr.use_count: " << sbptr.use_count() << endl;

  StrBlobPtr sbptr2(sbptr);
  cout << "sbptr2.use_count: " << sbptr2.use_count() << endl;

  return 0;
}
