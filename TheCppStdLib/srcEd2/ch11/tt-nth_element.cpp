/*
 * =========================================================================
 * Copyright (c) 2017, Raymon White - All Rights Reserved
 * Author:  Raymon White (ray), rayaxiom42 AT gmail DOT com
 * =========================================================================
 */


#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

template<typename C>
void PRINTELEMENTS(const C& c, const string& str="")
{
  if(!str.empty())
    std::cout << str << std::endl;
  
  for(const auto& ele:c)
  {
    std::cout << ele << " ";
  }
  std::cout << std::endl;
}
 
int main()
{
  std::vector<int> v{5, 6, 4, 3, 2, 6, 7, 9, 3};
  auto v2(v);

  std::sort(v2.begin(),v2.end());
  PRINTELEMENTS(v2,"v2:");
  
 
  std::nth_element(v.begin(), v.begin() + v.size()/2, v.end());
  PRINTELEMENTS(v,"v:");
  std::cout << "The median is " << v[v.size()/2] << '\n';
 
  std::nth_element(v.begin(), v.begin()+1, v.end(), std::greater<int>());
  std::cout << "The second largest element is " << v[1] << '\n';
  PRINTELEMENTS(v,"v:");
}




