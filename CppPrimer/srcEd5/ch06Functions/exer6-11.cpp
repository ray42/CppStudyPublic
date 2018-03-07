#include<iostream>
using std::cout; using std::endl;

template<typename T> void reset(T &val)
{
  val = 0;
}


int main()
{
  int j = 42;
  reset(j);
  cout << "j = " << j << endl;
  return 0;
}
