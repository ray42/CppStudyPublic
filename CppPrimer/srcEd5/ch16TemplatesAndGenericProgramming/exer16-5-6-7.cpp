/*==========================================================================
 * Copyright (c) 2017, Raymon White - All Rights Reserved
 * Author:  Raymon White (ray), rayaxiom42 AT gmail DOT com
 * Code for the exercises from C++ Primer 5th Edition
 *==========================================================================
 */
#include<iostream>
using std::cout; using std::endl;

#include<iterator> // begin, end, ostream_iterator

#include<algorithm> // transform

#include<cstddef> // size_t

// T is the type of the array, N is the size
template<typename T, size_t N>
void print(const T (&arr)[N])
{
  std::transform(std::begin(arr),std::end(arr),
                 std::ostream_iterator<T>(cout," "),
                 [](const T &val)
                 {return val;});
}

// Note: std::begin and std::end are overloaded for array and containers.
// Here we present only the array version. The container version returns
// c.begin() and c.end(), where c is the container.
template<typename T, size_t N>
T* mybegin(T (&arr)[N] )
{
  return arr;
}

template<typename T, size_t N>
T* myend(T (&arr)[N])
{
  return arr+N;
}

// T is the type of the array, N is the size
// We use the mybegin and myend functions
template<typename T, size_t N>
void myprint(const T (&arr)[N])
{
  std::transform(mybegin(arr),myend(arr),
                 std::ostream_iterator<T>(cout," "),
                 [](const T &val)
                 {return val;});
}


template<typename T, size_t N>
constexpr auto sizeofarray(const T(&arr)[N])->size_t
{
  return N;
}

int main()
{
  cout << "E5 - printing arrays" << endl;
  unsigned arru[]={1,2,3,4,5,6};
  print(arru);
  cout << endl;
  char arrc[] = {'H', 'I'};
  print(arrc);
  cout << endl;
  cout << endl;

  cout << "E6 - printing arrays with mbegin and myend" << endl;
  myprint(arru);
  cout << endl;
  myprint(arrc);
  cout << endl;
  cout << endl;

  cout << "E7 - size of array:" << endl;
  cout << sizeofarray(arru) << endl;
  cout << sizeofarray(arrc) << endl;

  return 0;
}
