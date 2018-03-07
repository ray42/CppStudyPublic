/*
 * =========================================================================
 * Copyright (c) 2017, Raymon White - All Rights Reserved
 * Author:  Raymon White (ray), rayaxiom42 AT gmail DOT com
 * =========================================================================
 */
#include<iostream>
using std::cout; using std::endl; using std::ostream;
#include<string>
using std::string;

class base {
public:
  base() = default;
  virtual ~base() = default;

  string name() { return basename; }
  virtual void print(ostream &os = std::cout) const
  { os <<"Base " << basename; }
private:
  string basename = "Hello";
};

class derived : public base {
public:
  derived() = default;
  ~derived() = default;
  void print(ostream &os = std::cout) const override final
  { base::print(os); os << "Derived " << i; }
private:
  int i=42;
};

int main()
{
  base bobj;     base *bp1 = &bobj;   base &br1 = bobj;
  derived dobj;  base *bp2 = &dobj;   base &br2 = dobj;
  
  // object therefore compile time.
  bobj.print();
  cout << endl;
  // object therefore compile time.
  dobj.print();
  cout << endl;

  // name is not virtual, compile time.
  bp1->name();
  cout << endl;
  bp2->name();
  cout << endl;

  // runtime
  br1.print(); // base::print()
  cout << endl;
  br2.print(); // derived::print()
  cout << endl;

  return 0;
}

