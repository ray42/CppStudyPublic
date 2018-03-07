/*
 * =========================================================================
 * Copyright (c) 2017, Raymon White - All Rights Reserved
 * Author:  Raymon White (ray), rayaxiom42 AT gmail DOT com
 * =========================================================================
 */
#include"StrBlob16.h"
#include<iostream>
using std::cout; using std::endl;

int main()
{
  StrBlob::raydebug = true;

  {
    cout << "T1: default constructor" << endl;
    StrBlob sb;
    sb.printall() << endl << endl;
  }

  {
    cout << "T2: il constructor" << endl;
    StrBlob sb{"Hello", "There", "How", "Are", "You?"};
    sb.printall() << endl << endl;
  }

  {
    cout << "T3: copy constructor and pop_back" << endl;
    cout << "Copy constructor is defined to have valuelike behaviour"<<endl;
    StrBlob sb1{"Hello", "There", "How", "Are", "You?"};
    StrBlob sb2(sb1);
    sb1.printall() << endl;
    sb2.printall() << endl;
    cout << "Calling pop_back on sb2"<<endl;
    sb2.pop_back();
    sb1.printall() << endl;
    sb2.printall() << endl << endl;
  }

  {
    cout << "T4: copy assignment" << endl;
    StrBlob sb1{"Hello", "There", "How", "Are", "You?"};
    StrBlob sb2;
    sb2 = sb1;
    sb1.printall() << endl;
    sb2.printall() << endl;
    cout << "Calling pop_back on sb2"<<endl;
    sb2.pop_back();
    sb1.printall() << endl;
    sb2.printall() << endl << endl;
  }

  {
    cout << "T5: move constructor" << endl;
    // Note: if we do this, the temporary is optimized away
//    StrBlob sb1(StrBlob{"sum", "wan", "wan"});
    // to all the move c-tor, we need:
    StrBlob sb1(std::move(StrBlob{"sum", "wan", "wan"}));
    sb1.printall() << endl << endl;
  }

  {
    cout << "T6: move assign op" << endl;
    StrBlob sb1;
    sb1 = StrBlob{"sum", "wan", "wan"};
    sb1.printall() << endl << endl;
  }

  {
    StrBlob::raydebug = false;
    cout << "T7: front and back, first nonconst, then const" << endl;
    StrBlob sb{"one", "two", "three"};
    const StrBlob csb{"cone", "ctwo", "cthree"};
    StrBlob::raydebug = true;
    sb.printall() << endl;
    cout << sb.front() << ", " << sb.back() << endl;
    csb.printall() << endl;
    cout << csb.front() << ", " << csb.back() << endl<<endl;
  }

  {
    StrBlob::raydebug = false;
    cout << "T8: Testing op== and op!=" << endl;
    StrBlob sb{"one", "two", "three"};
    const StrBlob csb{"cone", "ctwo", "cthree"};
    cout << (sb == sb) << endl;
    cout << (sb != sb) << endl;
    cout << (csb == sb) << endl;
    cout << (csb != sb) << endl;
  }

  {
    StrBlob sb{"Hello", "Ray", "Hello", "World"};

    for (ConstStrBlobPtr iter = sb.cbegin(); iter != sb.cend(); iter.incr())
    {
        std::cout << iter.deref() << " ";
    }
    std::cout << std::endl;
  }

  return 0;
}
