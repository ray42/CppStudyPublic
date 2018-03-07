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
using std::shared_ptr;

class Widget
{
  public:
  ~Widget()
  {
    cout << "Called destructor" << endl;
  }
};

auto wdel = [](Widget* pw)
            {
              cout << "Called custom deleter" << endl;
              delete pw;
            };

int main()
{
//  {
//    unique_ptr<Widget,decltype(wdel)> pw(nullptr,wdel);
//    pw.reset(new Widget);
//    cout << "Done reset" << endl;
//    unique_ptr<Widget,decltype(wdel)> pw2(nullptr,wdel);
//    pw2 = pw;
//  }

  {
    shared_ptr<Widget> pw(nullptr,wdel);
    pw.reset(new Widget);
    cout << "Done reset" << endl;
    shared_ptr<Widget> pw2(nullptr,wdel);
//    pw2.reset(pw);
    pw=pw2;
  }

  return 0;
}
