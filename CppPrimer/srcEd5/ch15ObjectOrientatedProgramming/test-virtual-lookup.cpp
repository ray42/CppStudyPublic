/*
 * =========================================================================
 * Copyright (c) 2017, Raymon White - All Rights Reserved
 * Author:  Raymon White (ray), rayaxiom42 AT gmail DOT com
 * =========================================================================
 */
#include<iostream>
using std::cout; using std::endl;

struct Base{
  virtual ~Base()=default;
  virtual void memfcn(){cout<<"memfcn from Base"<<endl;}
  virtual void hello(){cout<<"hello from Base"<<endl;}
};
struct D1 : public Base{
  virtual ~D1()=default;
  virtual void memfcn() override{cout<<"memfcn from D1"<<endl;}
  virtual void hello() override{cout<<"hello from D1"<<endl;}
};
struct D2 : public D1{
  virtual ~D2()=default;
  virtual void memfcn() override{cout<<"memfcn from D2"<<endl;}
};

int main()
{
  Base b; D1 d1; D2 d2;
  // Base pointer to Base
  Base * bpb = &b;
  // Base pointer to D1
  Base * bpd1 = &d1;
  // Base pointer to D2
  Base * bpd2 = &d2;

  bpb->memfcn(); // resolved dynamically, memfcn is found.
  bpd1->memfcn();// resolved dynamically, memfcn is found.
  bpd2->memfcn();// resolved dynamically, memfcn is found.
  bpb->hello(); // resolved dynamically, hello is found.
  bpd1->hello();// resolved dynamically, hello is found.
  // resolved dynamically, hello is not found, look up the hierarchy.
  // found in D1
  bpd2->hello();

  // Output:
  //memfcn from Base
  //memfcn from D1
  //memfcn from D2
  //hello from Base
  //hello from D1
  //hello from D1
  return 0;
}
