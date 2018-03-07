#include<iostream>

using std::cout; using std::endl;

template<typename T> T abs(T val)
{
  return val > -val ? val : -val;
}

int main()
{
  cout << abs(42) << endl;
  cout << abs(-42) << endl;
  return 0;
}
