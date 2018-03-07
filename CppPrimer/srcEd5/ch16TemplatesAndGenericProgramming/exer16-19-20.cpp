/*==========================================================================
 * Copyright (c) 2017, Raymon White - All Rights Reserved
 * Author:  Raymon White (ray), rayaxiom42 AT gmail DOT com
 * Code for the exercises from C++ Primer 5th Edition
 *==========================================================================
 */
#include<iostream>
using std::cout; using std::endl; using std::ostream;

#include<vector>
using std::vector;

// exer19
template<typename Container>
ostream& print_container(const Container& c, ostream& os=cout)
{
  typename Container::size_type sz = c.size();
  for(typename Container::size_type i = 0; i < sz; ++i)
  {
    os << c[i] << " ";
  }
  return os;
}

// exer20
template<typename Container>
ostream& print_container2(const Container& c, ostream& os=cout)
{
  for(auto beg = c.begin(); beg != c.end(); ++beg)
  {
    cout << *beg << " ";
  }
  return os;
}

int main()
{
  vector<unsigned> vu{0,1,2,3,4,5};
  print_container(vu) << endl;
  print_container2(vu) << endl;


  return 0;
}
