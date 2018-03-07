/*
 * =========================================================================
 * Copyright (c) 2017, Raymon White - All Rights Reserved
 * Author:  Raymon White (ray), rayaxiom42 AT gmail DOT com
 * =========================================================================
 */
#include<iostream>
using std::cout; using std::endl;
#include<algorithm>
using std::replace_if;
#include<vector>
using std::vector;
using std::copy;
#include<iterator>
using std::ostream_iterator;
#include<string>
using std::string;

template<typename T> 
class isEqual
{
public:
  isEqual(T v):val(v)
  {}

  bool operator()(const T& rhs) const
  {
    return val == rhs;
  }

private:
  T val = T();
};


int main()
{
  vector<int> vi{1,2,3,4,5,6,7,8,9};
  std::ostream_iterator<int> out_it (std::cout,", ");
  copy(vi.begin(),vi.end(),ostream_iterator<int>(cout," "));
  cout << endl;
  replace_if(vi.begin(),vi.end(),isEqual<char>(4),42);
  copy(vi.begin(),vi.end(),ostream_iterator<int>(cout," "));
  cout << endl;

  return 0;
}
