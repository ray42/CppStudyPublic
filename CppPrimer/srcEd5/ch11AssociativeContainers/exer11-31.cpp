/*
 * =========================================================================
 * Copyright (c) 2017, Raymon White - All Rights Reserved
 * Author:  Raymon White (ray), rayaxiom42 AT gmail DOT com
 * =========================================================================
 */
#include<iostream>
using std::cout; using std::endl;
#include<map>
using std::multimap;
#include<string>
using std::string;
#include<utility>
using std::pair;


//Exercise 11.31: Write a program that defines a multimap of authors and
//their works. Use find to find an element in the multimap and erase that
//element. Be sure your program works correctly if the element you look for
//is not in the map.
void ex31()
{
  multimap<string,string> m{{"Ray","Ray1"},
                            {"Ray","Ray3"},
                            {"Johanna","Jo1"},
                            {"Johanna","Jo2"},
                            {"Johanna","Jo3"},
                            {"Ray","Ray2"}};
  string author("Ray");
  string work("Ray3");

  for(pair<multimap<string,string>::iterator,
           multimap<string,string>::iterator> pos=m.equal_range(author);
      pos.first != pos.second; ++pos.first)
  {
    if(pos.first->second == work)
      m.erase(pos.first);
  }

  //Exercise 11.32: Using the multimap from the previous exercise, write a
  //program to print the list of authors and their works alphabetically.
  for(const auto& i: m)
  {
    cout << i.first << " " << i.second << endl;
  }
}

int main()
{
  ex31();
  return 0;
}
