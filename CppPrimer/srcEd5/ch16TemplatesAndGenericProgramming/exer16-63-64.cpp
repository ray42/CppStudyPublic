/*==========================================================================
 * Copyright (c) 2017, Raymon White - All Rights Reserved
 * Author:  Raymon White (ray), rayaxiom42 AT gmail DOT com
 * Code for the exercises from C++ Primer 5th Edition
 *==========================================================================
 */

#include"./../common/rr.h"
#include<iostream>
using std::cout; using std::endl;
#include<vector>
using std::vector;
#include<string>
using std::string;
#include<cstring>
using std::strcmp;


template<typename T>
size_t my_count(const vector<T>& vec, T val);

template<> // full specialization
size_t my_count(const vector<const char*>& vec, const char* val);


// I'm guessing that I cannot use the std::count function.
template<typename T>
size_t my_count(const vector<T>& vec, T val)
{
  rr::debug = true;
  rr::greet(__PRETTY_FUNCTION__);
  size_t icount = 0;
  for(const auto& i:vec)
    if(i == val) icount++;

  return icount;
}
template<> // full specialization
size_t my_count(const vector<const char*>& vec, const char* val)
{
  rr::debug = true;
  rr::greet(__PRETTY_FUNCTION__);

  size_t icount = 0;
  for(auto &i : vec)
    if(strcmp(i,val)==0) icount++;
  
  return icount;
}


int main()
{
  // exer 16-63
  cout << "exer 16-63" << endl;
  vector<double> dv{0.0,1.1,2.2,1.1,3.3}; // 1.1 2x
  vector<int>iv{5,3,5,6,7,7,3,6,7}; // 7 3x
  vector<string>sv{"a","r","q","b","r","q","e","q","q"}; // q 4x
  cout << my_count(dv,1.1) << endl;
  cout << my_count(iv,7) << endl;
  cout << my_count(sv,string("q")) << endl;

  // exer 16-64
  cout << "\n\nexer 16-64" << endl;
  vector<const char*> cv{"jojo","ray","jojo","hello","jojo","okay","okay"};
  cout << my_count(cv,"jojo") << endl;






  return 0;
}

