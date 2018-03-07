/*
 * =========================================================================
 * Copyright (c) 2017, Raymon White - All Rights Reserved
 * Author:  Raymon White (ray), rayaxiom42 AT gmail DOT com
 * =========================================================================
 */
#include<iostream>
using std::cout; using std::endl;


class Screen {
public:
  typedef std::string::size_type pos;
  char get_cursor() const { return contents[cursor]; }
  char get() const
  {
    cout << "hi from get()" << endl;
    return 'c';
  }
  char get(pos ht, pos wd) const
  {
    cout << "hi from get()" << endl;
    char cc = char(ht+wd);
    return cc;
  }
private:
  std::string contents;
  pos cursor;
  pos height, width;
};


int main()
{
  Screen s;

  auto pmf = &Screen::get_cursor;
  pmf = &Screen::get;
  (s.*pmf)();


  return 0;
}

