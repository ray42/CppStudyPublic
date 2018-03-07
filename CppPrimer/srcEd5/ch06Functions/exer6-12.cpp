#include<iostream>

using std::cout; using std::endl;

template<typename T> void swap(T &lhs, T& rhs)
{
  T temp(lhs);
  lhs=rhs;
  rhs=temp;
}

int main()
{
  int i=2,j=3;
  swap(i,j);
  cout << i << ", " << j << endl;
  return 0;
}
