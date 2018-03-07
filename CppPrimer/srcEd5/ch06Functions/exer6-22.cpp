#include<iostream>
using std::cout; using std::endl;

// Function to swap pointer values.
// Thus, I need to call by reference: int* & lhs
// However, I do not want to modify the value pointed at by the pointer:
// const int* & lhs
//
// So why won't this work:
// void swap(const int* & lhs,const int* &rhs)
// OH, because references does not ignore low level const,
// so I must have give it a const int.
// See exer6-999.cpp
// I'll just remove the const for now.
void swap(int* & lhs,int* &rhs)
{ // Note: it works when I take out the const.
  
  auto temp = lhs;
  lhs=rhs;
  rhs=temp;
}

int main()
{
  int i=1,j=2;

  int *ipt=&i, *jpt=&j;

  swap(ipt,jpt);

  cout << *ipt << ", " << *jpt << endl;

  return 0;
}
