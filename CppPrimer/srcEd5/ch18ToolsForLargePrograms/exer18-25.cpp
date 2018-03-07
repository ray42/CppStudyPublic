/*
 * =========================================================================
 * Copyright (c) 2017, Raymon White - All Rights Reserved
 * Author:  Raymon White (ray), rayaxiom42 AT gmail DOT com
 * =========================================================================
 */
#include<iostream>
using std::cout; using std::endl;

class B1{
public:
  virtual ~B1()
  {
    cout << "~B1" << endl;
  }
};
class B2{
public:
  ~B2() // virtual taken out!
  {
    cout << "~B2" << endl;
  }
};
class D1 : public B1
{public:
//  virtual ~D1()
  ~D1()
  {
    cout << "~D1" << endl;
  }
};
class D2 : public B2
{public:
//  virtual ~D2()
  ~D2()
  {
    cout << "~D2" << endl;
  }
};

class MI : public D1, public D2
{public:
//  virtual ~MI()
  ~MI()
  {
    cout << "~MI" << endl;
  }
};


int main()
{
  B1 *pb1 = new MI;
  B2 *pb2 = new MI;
  D1 *pd1 = new MI;
  D2 *pd2 = new MI;

//  delete pb1;
  delete pb2;
//  delete pd1;
//  delete pd2;




  return 0;
}

