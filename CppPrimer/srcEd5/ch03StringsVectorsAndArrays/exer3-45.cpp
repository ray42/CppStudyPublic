/*
 * =========================================================================
 *         Author:  Dr. Raymon White (Zwei), quatrezwei@gmail.com
 * =========================================================================
 */
#include<iostream>
#include<vector>
#include<string>
#include<iterator> // begin, end

using std::cout; using std::clog; using std::cerr; using std::endl; 
using std::cin;

using std::vector;
using std::string;

// Rewrite the programs again, this time using auto.
int main()
{
  constexpr size_t rowCnt=3, colCnt=4;
  int ia[rowCnt][colCnt] = {
    {0,1,2,3},
    {4,5,6,7},
    {8,9,10,11}};

  // range for with auto
  for(const auto& i : ia)
  {
    for(const auto& j : i)
      cout << j << " ";
    cout << endl;
  }

  cout << endl;

  // traditional for loop with subscripts, no change
  for(size_t i=0; i != rowCnt; ++i)
  {
    for(size_t j=0; j != colCnt; ++j)
      cout << ia[i][j] << " ";
    cout << endl;
  }

  cout << endl;

  // traditional for loop with pointers
  // This is an interesting one. We want to loop through the outer loop,
  // which consist of three arrays, hence we loop until i!=ia+rowCnt.
  //
  // However, i denotes the first array, so incrementing i makes it point to
  // the next array, NOT the next int.
  //
  // i is a pointer to four ints (i.e. the inner array type).
  //
  // The inner for loop: i points to an array. To get the actual array, we
  // need to deference it, hence we initialize int *j to the first element 
  // in an inner array by deferencing i, because i is a POINTER to an inner
  // array, not the array itself.
  for(auto i = ia; i != ia+rowCnt; ++i)
  {
    for(auto j = *i; j != *i+colCnt; ++j)
    {
      cout << *j << " ";
    }
    cout << endl;
  }

  cout << endl;
  
  // Or instead, we can use begin and end to make life easier:
  for(auto i = std::begin(ia); i != std::end(ia); ++i)
  {
    for(auto j = std::begin(*i); j!=std::end(*i); ++j)
    {
      cout << *j << " ";
    }
    cout << endl;
  }
  return 0;
}
