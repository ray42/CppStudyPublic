/*
 * =========================================================================
 * Copyright (c) 2017, Raymon White - All Rights Reserved
 * Author:  Raymon White (ray), rayaxiom42 AT gmail DOT com
 * =========================================================================
 */
#include<iostream>
using std::cout; using std::endl;
#include<list>
using std::list;
#include<string>
using std::string;
#include<iterator>
using std::ostream_iterator;

//Exercise 10.42: Reimplement the program that eliminated duplicate words
//that we wrote in 10.2.3 to use a list instead of a vector.
void elimDups(list<string>&words)
{
  // sort words alphabetically so we can find the duplicates
  words.sort();

  // unique removes the elements.
  words.unique();
}

int main()
{
  list<string>l{"the", "quick", "red", "fox", "jumps", "over", "the", 
                "slow", "red", "turtle"};
  elimDups(l);

  copy(l.begin(),l.end(),ostream_iterator<string>(cout," "));
  cout << endl;

  return 0;
}
