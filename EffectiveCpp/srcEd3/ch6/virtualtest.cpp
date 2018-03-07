/*
 * =========================================================================
 * Copyright (c) 2017, Raymon White - All Rights Reserved
 * Author:  Raymon White (ray), rayaxiom42 AT gmail DOT com
 * =========================================================================
 */
#include<iostream>
using std::cout; using std::endl;


class Base
{
public:
  Base() = default;
  virtual ~Base() = default;

  void callf()
  {
    cout << "calling f from base" << endl;
    f();
  }
  void callp()
  {
    cout << "calling p from base" << endl;
    p();
  }

  virtual void f()
  {
    cout << "Base f" << endl;
  }

private:
  virtual void p()
  {
    cout << "Base p" << endl;
  }

};

class Derived: public Base
{
public:
  Derived() = default;
  virtual ~Derived()=default;

  void callf()
  {
    cout << "calling f from derived"<<endl;
    Base::callf();
  }

  void f()
  {
    cout << "Derived f" << endl;
  }
private:
//  virtual void p()
//  {
//    cout << "Derived p" << endl;
//  }

};



int main()
{
  Base* pb = new Derived;
  pb->callf();
  cout << "\n";
  pb->callp();


  return 0;
}

