#include<iostream>

using std::cout; using std::endl;

template<typename T> void swap(T*lhs_pt, T* rhs_pt)
{
  T temp(*lhs_pt);
  *lhs_pt=*rhs_pt;
  *rhs_pt=temp;
}

int main()
{
  int i=2,j=3;
  swap(&i,&j);
  cout << i << ", " << j << endl;
  return 0;
}
