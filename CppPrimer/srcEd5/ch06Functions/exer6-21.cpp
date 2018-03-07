#include<iostream>
using std::cout; using std::endl;

int get_larger(const int& lhs, const int * const rhs)
{
  return (lhs > *rhs)? lhs: *rhs ;
}

int main()
{
  int i = 1,j=2;
  cout << get_larger(i,&j) << endl;
  return 0;
}
