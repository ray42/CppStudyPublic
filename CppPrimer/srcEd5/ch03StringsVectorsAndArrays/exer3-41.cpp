/*
 * =========================================================================
 *         Author:  Dr. Raymon White (Zwei), quatrezwei@gmail.com
 * =========================================================================
 */
#include<iostream>
#include<vector>
#include<string>
#include<iterator> // begin end

using std::cout; using std::clog; using std::cerr; using std::endl; 
using std::cin;

using std::vector;
using std::string;

int main()
{
  // Write a program to initialize a vector from an array of ints.
  const int intArr[]={0,1,2,3,4,5,6,7};

  vector<int> intVec(std::begin(intArr),std::end(intArr));

  for(auto i : intVec) cout << i << " ";
  cout << endl;

  return 0;
}
