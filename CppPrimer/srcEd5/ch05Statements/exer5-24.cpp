#include<iostream>
using std::cout; using std::endl; using std::cin;

#include<stdexcept>
using std::domain_error;

// Exercise 5.24: Revise your program to throw an exception if the second 
// number is zero. Test your program with a zero input to see what happens 
// on your system if you don't catch an exception.
int main()
{
  int i=0, j = 0;

  while(cin>>i>>j)
  {
    if(j == 0) throw domain_error("zero denominator");
    cout << i/j << endl;
  }
  return 0;
}
