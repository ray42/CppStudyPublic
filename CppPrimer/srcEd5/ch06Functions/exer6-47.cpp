#include<iostream>
using std::cout; using std::endl;

#include<vector>

template<typename T>
void printvec(T beg, T end)
{
#ifndef NDEBUG
  cout << end - beg << endl;
#endif
  if(beg != end)
  {
    cout << *beg << endl;
    printvec(std::next(beg),end);
  }
}

// Write a recursive function to print the contents of a vector.
// conditionally print information about its
// execution. For example, you might print the size of the vector on each
// call.  Compile and run the program with debugging turned on and again 
// with it turned off.
int main()
{
  std::vector<int>v{-2,-10,-1,0,9,-3};
  printvec(v.begin(),v.end());

  return 0;
}
