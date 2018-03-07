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

#include<utility>
using std::pair;
using std::make_pair;

#include<vector>
using std::vector;

#include<sstream>
using std::istringstream;

//Exercise 11.12: Write a program to read a sequence of strings and ints,
//storing each into a pair. Store the pairs in a vector.
void ex11_12()
{
  vector<pair<string,int> > pv;
  istringstream iss;
  iss.str("A 1 B 2 C 3 D 4 E 5 F 6 G 7 H 8");

  string word;
  int num=0;
  while((iss >> word)&&(iss >> num))
  {
    pv.push_back({word,num}); // list initialize
  }

  for(const auto &i : pv)
  {
    cout << i.first << " " << i.second << endl;
  }
}

//Exercise 11.13: There are at least three ways to create the pairs in the
//program for the previous exercise. Write three versions of that program,
//creating the pairs in each way. Explain which form you think is easiest to
//write and understand, and why.
void ex11_13()
{
  vector<pair<string,int> > pv;
  istringstream iss;
  iss.str("A 1 B 2 C 3 D 4 E 5 F 6 G 7 H 8");

  string word;
  int num=0;
  while((iss >> word)&&(iss >> num))
  {
    pv.push_back(pair<string,int>(word,num)); // explicit construction
    pv.push_back(make_pair(word,num)); // makepair
    pv.push_back({word,num}); // list initialize
  }

  for(const auto &i : pv)
  {
    cout << i.first << " " << i.second << endl;
  }
}

int main()
{
  ex11_12();
  ex11_13();

  return 0;
}

