/*
 * =========================================================================
 * Copyright (c) 2017, Raymon White - All Rights Reserved
 * Author:  Raymon White (ray), rayaxiom42 AT gmail DOT com
 * =========================================================================
 */
#include<iostream>
using std::cout; using std::endl;
#include<string>
using std::string;

class Foo
{
public:
  Foo():spt(new string("Ayy")),str("More Ayyy")
  {}

  string *poin()
  {
    return spt;
  }
  string *poinconst() const
  {
    return spt;
  }
  const string *constpoinconst() const
  {
    return spt;
  }

  string& ref()
  {
    return str;
  }
//  string& refconst() const // this gives an error, I have to put const here
//  {
//    return str;
//  }
  const string& constrefconst() const
  {
    return str;
  }

  void print()
  {
    cout << *spt << endl;
  }

  void printstr()
  {
    cout << str << endl;
  }


private:
  string * spt;
  string str;
};


int main()
{
  Foo f;
  f.print();
  string* sp = f.poinconst();
  *sp = "Oh well...";
  f.print();
  const string* sp2 = f.constpoinconst();

  //*sp2 = "More Oh well..."; // this give error
  
  f.printstr();
  


  return 0;
}
