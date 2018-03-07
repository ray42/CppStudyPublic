#include<iostream>

using std::cout; using std::clog; using std::cerr; using std::endl; 

template <typename T> T fref(const T(&a)[10], const T(&b)[10])
{
  return 1;
}

int main()
{
  int a[10], b[10];

  // why is this not deduced to
  // const int (&)[10]
  fref(a,b);
  return 0;
}
