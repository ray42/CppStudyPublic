/*
 * =========================================================================
 * Copyright (c) 2017, Raymon White - All Rights Reserved
 * Author:  Raymon White (ray), rayaxiom42 AT gmail DOT com
 * =========================================================================
 */
#include<iostream>
using std::cout; using std::endl; using std::cin;

#include<fstream>
using std::ifstream;

#include<iterator>
using std::istream_iterator;
using std::ostream_iterator;

#include<vector>
using std::vector;

#include<string>
using std::string;

#include<algorithm>
using std::copy;

//Exercise 10.29: Write a program using stream iterators to read a text file
//into a vector of strings.
void ex29()
{
  ifstream ifs("./../common/loremipsum-9para.txt");
  istream_iterator<string> is_iter(ifs), isiterend;

  // Can do this this way:
//  vector<string> v(is_iter,isiterend);
  
  // Or this way:
  vector<string> v;
  while(is_iter != isiterend)
  {
    v.push_back(*is_iter++);
  }

  cout << "v.size(): " << v.size() << endl;

}

//Exercise 10.30: Use stream iterators, sort, and copy to read a sequence
//of integers from the standard input, sort them, and then write them back 
//to the standard output.
void ex30()
{
  istream_iterator<int> isiter(cin), isiter_end;
  vector<int>v(isiter,isiter_end);
  sort(v.begin(),v.end());
  copy(v.cbegin(),v.cend(),ostream_iterator<int>(cout," "));
  cout << endl;
}

int main()
{
  ex29();

  ex30();

  return 0;
}
