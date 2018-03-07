/*
 * =========================================================================
 * Copyright (c) 2017, Raymon White - All Rights Reserved
 * Author:  Raymon White (ray), rayaxiom42 AT gmail DOT com
 * =========================================================================
 */
#include<iostream>
using std::cout; using std::endl;

// forward declaration
bool operator==(const Base&, const Base&);

class Base{
  friend bool operator==(const Base&, const Base&);

public:
  // interface members for Base

protected:
  virtual bool equal(const Base&) const;
  // data and other implementation members of Base
};

bool Base::equal::(const Base &rhs)
{
  // do whatever is required to compare two Base objects
}

bool operator=(const Base&lhs, const Base &rhs)
{
  // returns false if typeid are different; otherwise makes a virtual call
  // to equal
  // We need to make sure that the lhs and rhs have the same dynamic types
  // first, in order to be able to test them for equality.
  return typeid(lhs) == typeid(rhs) && lhs.equal(rhs);
}

////////////////////////////////////////////////////////////////////////////

class Derived: public Base{
public 
  // other interface members for Derived
protected:
  bool equal(const Base&) const;
  // data and other implementation members of Derived
};

bool Derived::equal(const Base& rhs) const
{
  // we know the types are equal, so the cast won't throw
  auto r = dynamic_cast<const Derived&>(rhs);
  // do the work to compare two Derived objects and return the result.
}

////////////////////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////////////////////

int main()
{
  return 0;
}

