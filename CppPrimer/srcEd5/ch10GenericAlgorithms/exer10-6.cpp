#include<iostream>
#include<vector>
#include<algorithm>

//Exercise 10.6: Using fill_n, write a program to set a sequence of int
//values to 0.
int main()
{
  std::vector<int> v{0,1,2,3,4,4,5,6};
  std::fill_n(v.begin(),v.size(),0);
  for(auto i:v)
    std::cout << i << " ";
  std::cout << std::endl;
  return 0;
}
