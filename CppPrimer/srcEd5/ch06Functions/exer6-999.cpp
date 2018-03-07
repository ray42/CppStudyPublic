#include<iostream>

int main()
{
  int i=42;
  int* ip = &i;
  const int*& cip = ip;

  return 0;
}
