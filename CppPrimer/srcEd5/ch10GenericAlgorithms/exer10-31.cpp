/*
 * =========================================================================
 * Copyright (c) 2017, Raymon White - All Rights Reserved
 * Author:  Raymon White (ray), rayaxiom42 AT gmail DOT com
 * =========================================================================
 */
#include<iostream>
using std::cout; using std::endl; using std::cin;

#include<iterator>
using std::istream_iterator;
using std::ostream_iterator;

#include<algorithm>
using std::sort;
using std::unique_copy;

#include<deque>
using std::deque;


//Exercise 10.31: Update the program from the previous exercise so that it
//prints only the unique elements. Your program should use unqiue_copy
int main()
{
  istream_iterator<int>isiter(cin), isiterend;
  deque<int> ideque(isiter,isiterend);
  sort(ideque.begin(),ideque.end());
  unique_copy(ideque.begin(),ideque.end(),ostream_iterator<int>(cout," "));
  cout << endl;

  return 0;
}
