/*
 * =========================================================================
 * Copyright (c) 2017, Raymon White - All Rights Reserved
 * Author:  Raymon White (ray), rayaxiom42 AT gmail DOT com
 * =========================================================================
 */
#include<iostream>
using std::cout; using std::endl;

class Class{
  public:
  Class(){
    cout << "Hi from Class" << endl;
  }
};
class Base : public Class {
  public:
  Base(){
    cout << "Hi from Base" << endl;
  }
};
class D1 : virtual public Base {
  public:
  D1(){
    cout << "Hi from D1" << endl;
  }
};
class D2 : virtual public Base {
  public:
  D2(){
    cout << "Hi from D2" << endl;
  }
};
class MI : public D1, public D2 {
  public:
  MI(){
    cout << "Hi from MI" << endl;
  }
};
class Final : public MI, public Class {
  public:
  Final(){
    cout << "Hi from Final" << endl;
  }
};


int main()
{ 
  Base *pb;    Class *pc;       MI *pmi;     D2 *pd2;
//  pb = new Class;
//pc = new Final;
//pmi = pb;
pd2 = pmi;

  return 0;
}

