/*
 * =========================================================================
 * Copyright (c) 2017, Raymon White - All Rights Reserved
 * Author:  Raymon White (ray), rayaxiom42 AT gmail DOT com
 * =========================================================================
 */
#include<iostream>
//using std::cout; using std::endl;

#include<complex>

using namespace std;

class Base
{
public:
  virtual ~Base()=default;

  virtual void f(int);
  virtual void f(double);
  virtual void f(complex<double>);
  virtual void g(int i = 10);
};
void Base::f(int)
{
  cout << "Base::f(int)" << endl;
}
void Base::f(double)
{
  cout << "Base::f(double)" << endl;
}
void Base::f(complex<double>)
{
  cout << "Base::f(complex)" << endl;
}
void Base::g(int i)
{
  cout << "Base::g, i = " << i << endl;
}

////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////

class Derived:public Base
{
public:
  virtual ~Derived()=default;

  void f(complex<double>);
  void g(int i = 20);
};
void Derived::f(complex<double>)
{
  cout << "Derived::f(complex)" << endl;
}
void Derived::g(int i)
{
  cout << "Derived::g, i = " << i << endl;
}

////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////

int main()
{
  using namespace std::complex_literals;

  Base    b;
  Derived d;
  Base* pb = new Derived;
  b.f(1.0);   // B::f(double)
  d.f(1.0);   // D::(complex) implicit conversion.
  pb->f(1.0); // D::f(double)

  std::complex<double> z4 = 1. + 2i;
  pb->f(z4); // D::f(complex)
//  pb->Derived::f(z4); // D::f(complex)
//  pb->Derived::g(); // D::f(complex)
  b.g();      // B::g() i = 10
  d.g();      // D::g() i = 20
  pb->g();    // D::g() i = 10 - uses i from base class.
  delete pb;

// Things to note: 
// scope to circumvent virtual binding only works on base class functions
//
// visible functions is determined from the static type, 
// THEN it sees virtuals.
//
// 










  return 0;
}

