#include<iostream>
#include<string>
#include<iomanip>

using std::cout; using std::endl; using std::cin;
using std::string;
using std::setw;

// Program to calculate the square of int values up to 100.
// The program should write two columns:
// 1) The first list the value;
// 2) the second contains the square of that value.
// Use setw(...) to manage the output so that the values line up in columns.
int main(int argc, char** argv)
{
  const int size = 101;

  // Invariant: we have outputted i squared to far.
  for (int i = 0; i < size; i++) 
  {
    cout << setw(3) << i << " " << setw(5) << i*i << endl;
    
  }
  return 0;
}
