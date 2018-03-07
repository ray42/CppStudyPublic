/*
 * =========================================================================
 * Copyright (c) 2017, Raymon White - All Rights Reserved
 * Author:  Raymon White (ray), rayaxiom42 AT gmail DOT com
 * =========================================================================
 */
#include<iostream>
using std::cout; using std::endl;

#include<vector>
using std::vector;


struct X
{
  // default constructor
  X(){std::cout<<this<<": X()"<<std::endl;}
  // copy constructor
  X(const X& x){ std::cout<<this<<": X(const X&)"<<std::endl;}
  // copy assignment operator
  X& operator=(const X& x)
  {std::cout<<this<<": X& operator=(const X& x)"<<std::endl;return *this;}
  ~X(){std::cout<<this<<": ~X()"<<endl;}
};

void byvalue(const X x)
{
  cout << "Hi from byvalue()" << endl;
}

void byref(const X& x)
{
  cout << "Hi from byref()" << endl;
}


int main()
{
  cout << "Start exer13-13\n" << endl;
  
  {
    cout << "T1: init, copy construct, copy assign, destruct" << endl;
    cout << "\nX x;" << endl;
    X x;
    cout << "\nX x2(x);" << endl;
    X x2(x);
    cout << "\nX x3=x;" << endl;
    X x3=x;
    cout <<"\nGoing out of scope" << endl;
  }

  {
    cout << "\n\nT2: by value and by reference:" << endl;
    cout << "\nX x;"<< endl;
    X x;
    cout << "\nbyvalue(x)" << endl;
    byvalue(x);
    cout <<"\nbyref(x)"<< endl;
    byref(x);
    cout<<"\nGoing out of scope" << endl;
  }

  {
    cout << "\n\nT3: dynamic allocation" << endl;
    cout << "X *x = new X" << endl;
    X *x = new X;
    cout << "delete x" << endl;
    delete x;
  }

  {
    cout << "\n\nT4: vector" << endl;
    cout << "\nX x;"<< endl;
    X x;
    cout << "vector<X>vx(3,x)" << endl;
    vector<X> vx(3,x);
    cout<<"\nGoing out of scope" << endl;
  }

  
  cout << "\nEnd exer13-13" << endl;
  return 0;
}
