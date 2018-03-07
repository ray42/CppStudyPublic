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
#include<sstream>
using std::istringstream;

#include<memory>
using std::shared_ptr;
using std::make_shared;

//Exercise 12.6: Write a function that returns a dynamically allocated
//vector of ints. Pass that vector to another function that reads the 
//standard input to give values to the elements. Pass the vector to another
//function to print the values that were read. Remember to delete the vector
//at the appropriate time.
vector<int>* ex6()
{
  return new vector<int>();
}

void ex6read(vector<int>* iv_pt)
{
  istringstream iss("1 2 3 4 5 6 7");
  int i=0;
  while(iss >> i)
  {
    iv_pt->push_back(i);
  }
}

void ex6print(vector<int>* iv_pt)
{
  for(decltype(iv_pt->size()) i=0; i < iv_pt->size();++i )
  {
    cout << iv_pt->operator[](i) << " ";
  }
}



//Exercise 12.7: Redo the previous exercise, this time using shared_ptr.
auto ex7getvec() -> shared_ptr<vector<int>>
{
  return make_shared<vector<int>>(vector<int>());
}

void ex7read(shared_ptr<vector<int>> iv_spt)
{
  istringstream iss("2 4 6 8 10");
  int i=0;
  while(iss >>i)
  {
    iv_spt->push_back(i);
  }
}

void ex7print(shared_ptr<vector<int>> iv_spt)
{
  for(auto i:*iv_spt)
  {
    cout << i << " ";
  }
}

int main()
{
  vector<int>* iv_pt=ex6();
  ex6read(iv_pt);
  ex6print(iv_pt);
  cout << endl;
  delete iv_pt; iv_pt=0;

  shared_ptr<vector<int>> iv_spt = ex7getvec();
  ex7read(iv_spt);
  ex7print(iv_spt);
  cout << endl;
  return 0;
}
