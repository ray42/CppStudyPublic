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
#include<memory>
using std::unique_ptr;
using std::make_unique;
#include<utility>
using std::move;

#include<functional>
using std::bind;

int main()
{
  unique_ptr<string> sp = make_unique<string>("Hello");
  auto alambda = [sp = std::move(sp)]()
                 { *sp+=", oh my...";
                   cout << *sp << endl;
                 };
  alambda();


  {
  string str="Hello!";
  auto bobject = bind([](string& s){
      s+=" Hi!";
      cout << s << endl;
      },str);
  bobject();
  bobject();
  cout << "str is: " << str << endl;
  }
  cout << endl;
  {
  string str="Hello!";
  auto bobject = bind([](string& s){
      s+=" Hi!";
      cout << s << endl;
      },std::move(str));
  bobject();
  bobject();
  cout << "str is: " << str << endl;
  }



  cout << endl;
  {
    string astr = "hello!";
    auto alambda = [&astr=astr](string s){
      s="Oh my, I've changed";
      cout << s << endl;
      astr = "I've changed too";
      cout << astr << endl;
    };

    alambda(string("hello"));
    cout << "astr is: " << astr << endl;
  }


  return 0;
}
