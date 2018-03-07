/*
 * =========================================================================
 * Copyright (c) 2017, Raymon White - All Rights Reserved
 * Author:  Raymon White (ray), rayaxiom42 AT gmail DOT com
 * =========================================================================
 */
#include"StrVec23.h"

#include<iostream>
using std::cout; using std::endl;

int main()
{
  StrVec sv;
  sv.printall() << endl;
  sv.push_back("Text1");
  sv.printall() << endl;

  sv.push_back("Text2");
  sv.printall()<<endl;
  sv.push_back("Text3");
  sv.printall()<<endl;
  sv.push_back("Text4");
  sv.printall()<<endl;
  sv.push_back("Text5");
  sv.printall()<<endl;

  sv.reserve(2);
  sv.printall()<<endl;

  sv.reserve(12);
  sv.printall()<<endl;
  
  cout<<endl;
  sv.resize(4);
  sv.printall()<<endl;

  sv.resize(6,"newText");
  sv.printall()<<endl;
  sv.reserve(6);
  sv.resize(8,"newnewText");
  sv.printall()<<endl;
  
  cout<<endl;
  StrVec sv2(sv);
  StrVec sv3;
  sv3 = sv;
  sv2.printall()<<endl;
  sv3.printall()<<endl;

  cout<<endl;
  StrVec sv4{"One", "Two", "Three"};
  sv4.printall()<<endl<<endl;

  cout << "T1 equality and equal:"<<endl;
  cout << "sv==sv: " << (sv == sv) << endl;
  cout << "sv!=sv: " << (sv != sv) << endl;
  cout << "sv==sv4: " << (sv == sv4) << endl;
  cout << "sv!=sv4: " << (sv != sv4) << endl;
  cout << "\n"<<endl;

  {
    cout << "T3: inequality:" << endl;
    StrVec s1{"A", "B", "B"}; // this is less
    StrVec s2{"A", "B", "C"}; // this is greater
    cout << "s1<s1: " << (s1<s1) << endl;
    cout << "s1<s2: " << (s1<s2) << endl;
    cout << "s2<s1: " << (s2<s1) << endl;
    cout << endl;
    cout << "s1>s1: " << (s1>s1) << endl;
    cout << "s1>s2: " << (s1>s2) << endl;
    cout << "s2>s1: " << (s2>s1) << endl;
    cout << endl;
    cout << "s1<=s1: " << (s1<=s1) << endl;
    cout << "s1<=s2: " << (s1<=s2) << endl;
    cout << "s2<=s1: " << (s2<=s1) << endl;
    cout << endl;
    cout << "s1>=s1: " << (s1>=s1) << endl;
    cout << "s1>=s2: " << (s1>=s2) << endl;
    cout << "s2>=s1: " << (s2>=s1) << endl;
    cout << "\n"<<endl;
  }

  {
    cout << "T4: initializer list assignment" << endl;
    StrVec ss;
    ss={"One", "Two", "Three"};
    ss.printall()<<endl;
  }

  return 0;
}
