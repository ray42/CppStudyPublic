#include<iostream>
#include<vector>

using std::endl; using std::cout;
using std::vector;

int main()
{
  // Write a program to create a vector with ten int elements. Using an
  // iterator, assign each element a value that is twice its current value.
  // Test your program by printing the vector.
  vector<int> vec={0,1,2,3,4,5,6,7,8,9};

  for(auto it=vec.begin(); it!=vec.end(); ++it)
  {
    (*it) *=2;
  }

  for(const auto& i : vec)
  {
    cout << i << endl;
  }
  return 0;
}
