#include<iostream>
#include<vector>

using std::cout; using std::endl;
using std::vector;

// Exercise 5.17: Given two vectors of ints, write a program to determine
// whether one vector is a prefix of the other. For vectors of unequal 
// length, compare the number of elements of the smaller vector. 
//
// For example, given the vectors containing 
//   0, 1, 1, 2,  and 
//   0, 1, 1, 2, 3, 5, 8, 
// respectively, your program should return true.
int main()
{
  vector<int> v1={0,1,1,2};
  vector<int> v2={0,1,1,2,3,5,8};

  // determine the smallest size
  auto size = v1.size() < v2.size() ? v1.size() : v2.size();

  for(decltype(v1.size()) i = 0; i != size; ++i)
  {
    if(v1[i] != v2[i])
    {
      cout << "Not equal" << endl;
      return 0;
    }
  }

  cout << "Equal" << endl;

  return 0;
}
