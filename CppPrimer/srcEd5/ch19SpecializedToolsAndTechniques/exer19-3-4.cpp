/*
 * =========================================================================
 * Copyright (c) 2017, Raymon White - All Rights Reserved
 * Author:  Raymon White (ray), rayaxiom42 AT gmail DOT com
 * =========================================================================
 */
#include<iostream>
using std::cout; using std::endl;

#include<typeinfo>
using std::bad_cast;

class A 
{
public:
  A()=default;
  virtual ~A()=default;
};
class B : public A
{
public:
  B()=default;
  virtual ~B()=default;
};
class C : public B
{
public:
  C()=default;
  virtual ~C()=default;
};
//class D : public B, public A
//{
//public:
//  D()=default;
//  virtual ~D()=default;
//};



int main()
{
{
  A *pa = new C;
  if(B *pb = dynamic_cast<B*>(pa))
  {
    cout << "(a) ok" << endl;
  }
  else
  {
    cout << "(a) failed" << endl;
  }
}

{
  B *pb = new B;
  if(C *pc = dynamic_cast< C* >(pb))
  {
    cout << "(b) ok" << endl;
  }
  else
  {
    cout << "(b) failed" << endl;
  }
}

// We cannot create an object of type D due to ambiguous base A.
//A *pa = new D;
//B *pb = dynamic_cast< B* >(pa);

//exer19-4 convert the expression *pa to the type C&
//if (C *pc = dynamic_cast< C* >(pa))
//  // use C's members
//} else {
//  // use A's members
//}
{
  A *pa = new C;
  try{
    C& rc = dynamic_cast<C&>(*pa);
    cout << "Cast succeeded" << endl;
  }catch(std::bad_cast){
    std::cerr << "Cannot cast from *pa to rc&" << endl;
  }
}


return 0;
}

