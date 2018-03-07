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

// Write three different versions of a program to print the elements of ia. 
// One version should use a range for to manage the iteration, the other two
// should use an ordinary for loop in one case using subscripts and in the 
// other using pointers. In all three programs write all the types directly.
// That is, do not use a type alias, auto, or decltype to simplify the code.
int main()
{
  constexpr size_t rowCnt=3, colCnt=4;
  int ia[rowCnt][colCnt] = {
    {0,1,2,3},
    {4,5,6,7},
    {8,9,10,11}};

  // range for
  for(const int (&i)[colCnt] : ia)
  {
    for(const int& j : i)
      cout << j << " ";
    cout << endl;
  }

  cout << endl;

  // traditional for loop with subscripts
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
  for(int (*i)[colCnt] = ia; i != ia+rowCnt; ++i)
  {
    for(int *j = *i; j != *i+colCnt; ++j)
    {
      cout << *j << " ";
    }
    cout << endl;
  }

  cout << endl;
  
  // Or instead, we can use begin and end to make life easier:
  for(int (*i)[colCnt] = std::begin(ia); i != std::end(ia); ++i)
  {
    for(int *j = std::begin(*i); j!=std::end(*i); ++j)
    {
      cout << *j << " ";
    }
    cout << endl;
  }
  return 0;
}
