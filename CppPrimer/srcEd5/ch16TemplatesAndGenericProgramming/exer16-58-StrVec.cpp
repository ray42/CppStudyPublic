/*
 * =========================================================================
 * Copyright (c) 2017, Raymon White - All Rights Reserved
 * Author:  Raymon White (ray), rayaxiom42 AT gmail DOT com
 * =========================================================================
 */
#include"StrVec58.h"

#include<iostream>
using std::cout; using std::endl;
#include<string>
using std::string;

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
    ss.printall()<<"\n"<<endl;
  }

  {
    cout << "T5: subscript operators" << endl;
    const StrVec cs{"c1", "c2", "c3"};
    StrVec s{"1", "2", "3"};
//    cs[1] = "hello"; // this has error, as expected.
    s[1] = "hello";
    cs.printall()<<endl;
    s.printall()<<endl;

  }

  {
    cout << "T6 emplace_back" << endl;
    StrVec sv;

    string str("hello");
    sv.emplace_back(str);
    sv.printall() << endl;
  }

  return 0;
}
