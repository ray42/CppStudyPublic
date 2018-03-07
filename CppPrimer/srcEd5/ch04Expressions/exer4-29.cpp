/*
 * =========================================================================
 * Zwei
 * =========================================================================
 */
#include<iostream>
#include<vector>
#include<string>

using std::cout; using std::clog; using std::cerr; using std::endl; 
using std::cin;

using std::vector;
using std::string;
int main()
{
  int x[10];   int *p = x;
  cout << sizeof(x) << endl;
  cout << sizeof(*x) << endl;
  cout << sizeof(x)/sizeof(*x) << endl;
  cout << sizeof(p) << endl;
  cout << sizeof(*p) << endl;
  cout << sizeof(p)/sizeof(*p) << endl;
  return 0;
}
