/*
 * =========================================================================
 *         Author:  Zwei, quatrezwei@gmail.com
 * =========================================================================
 */
#include<iostream>
#include<vector>
#include<string>

using std::cout; using std::clog; using std::cerr; using std::endl; 
using std::cin;

using std::vector;
using std::string;

// Write a program to use a conditional operator to find the elements in a
// vector<int> that have odd value and double the value of each such 
// element.
int main()
{
  vector<int> ivec={0,1,2,3,4,5,6,7,8,9};
  for(auto& i : ivec)
  {
    i= (i%2)?(i*2):i;
  }

  // check
  for(const auto& i: ivec)
  {
    cout << i << " ";
  }
  cout << endl;

  return 0;
}
