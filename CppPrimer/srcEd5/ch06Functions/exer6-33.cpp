#include<iostream>
using std::cout; using std::endl;

#include<vector>

template<typename T>
void printvec(T beg, T end)
{
  if(beg != end)
  {
    cout << *beg << endl;
    printvec(std::next(beg),end);
  }
}

// Write a recursive function to print the contents of a vector.
int main()
{
  std::vector<int>v{-2,-10,-1,0,9,-3};
  printvec(v.begin(),v.end());

  return 0;
}
