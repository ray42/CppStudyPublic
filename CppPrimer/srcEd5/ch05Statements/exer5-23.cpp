#include<iostream>
using std::cout; using std::endl; using std::cin;


// Write a program that reads two integers from the standard input and
// prints the result of dividing the first number by the second.
int main()
{
  int i=0, j = 0;

  while(cin>>i>>j)
  {
    cout << i/j << endl;
  }
  return 0;
}
