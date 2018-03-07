/*
 * =========================================================================
 *        Created:  25/02/17 20:50:31
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
#include<cstddef> // size_t
#include<iterator> // begin, end

using std::cout; using std::clog; using std::cerr; using std::endl; 
using std::cin;

using std::vector;
using std::string;

// Write a program to compare two arrays for equality. 
// Write a similar program to compare two vectors.

template<typename It>
bool equal(It beg1, It end1, It beg2, It end2)
{
  // First check if the sizes are the same
  if((end1-beg1) != (end2-beg2))
  {
    return false;
  }
  else
  {
    for(It i=beg1, j=beg2; (i != end1) && (j != end2); ++i, ++j)
    {
      if(*i != *j) return false;
    }
  }

  return true;
}

template<typename T, std::size_t N>
bool equal(const T (&arr1)[N], const T (&arr2)[N])
{
  return equal(std::begin(arr1),std::end(arr1),
               std::begin(arr2),std::end(arr2));
}

template<typename T>
bool equal(const vector<T>& vec1,const vector<T>& vec2)
{
  return equal(vec1.cbegin(), vec1.cend(),
               vec2.cbegin(), vec2.cend());
}

int main()
{

  int arr1[]={0,2,3,4,5,6};
  int arr2[]={0,2,3,4,5,1};

  cout << equal(arr1,arr1) << endl;
  cout << equal(arr1,arr2) << endl;
  
  vector<unsigned> vec1 = {0,1,2,3};
  vector<unsigned> vec2 = {0,1,2,1};

  cout << equal(vec1,vec1) << endl;
  cout << equal(vec1,vec2) << endl;

  return 0;
}
