/*
 * =========================================================================
 *
 *       Filename:  exer3-32.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  25/02/17 16:33:44
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Dr. Raymon White (Zwei), quatrezwei@gmail.com
 *   Organization:  
 *
 * =========================================================================
 */
#include<iostream>
#include<vector>
#include<string>
#include<algorithm> // copy
#include<iterator> // begin() end()

using std::cout; using std::clog; using std::cerr; using std::endl; 
using std::cin;

using std::vector;
using std::string;

template<typename It> void printvec(It beg, It end)
{
  for(It it=beg; it!= end; ++it)
  {
    cout << *it << " ";
  }
  cout << endl;
}

// Copy the array you defined in the previous exercise into another array.
// Rewrite your program to use vectors.
int main()
{
  constexpr size_t arr_size = 10;
  int intArr[arr_size]={}; // Use value initialization
  for(size_t i = 0; i < arr_size; ++i)
  {
    intArr[i]=i;
  }

  // Copy into another array.
  int anotherIntArr[arr_size]; // elements are undefined.
  std::copy(std::begin(intArr), std::end(intArr), 
            std::begin(anotherIntArr));

  cout << "intArr:" << endl;
  printvec(std::begin(intArr), std::end(intArr));

  cout << "anotherIntArr:" << endl;
  printvec(std::begin(anotherIntArr), std::end(anotherIntArr));

  vector<int> intvec(10,0);
  for(decltype(intvec.size()) i = 0; i < intvec.size(); ++i)
  {
    intvec[i]=i;
  }

  cout << "intvec: " << endl;
  printvec(intvec.cbegin(),intvec.cend());

  return 0;
}
