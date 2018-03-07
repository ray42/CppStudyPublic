#include<iostream>
#include<string>
#include<iomanip>

using std::cout; using std::endl; using std::cin;
using std::string;
using std::setw;

// return the number of digits in number.
unsigned num_of_digits(int number)
{
  unsigned digits = 0;
  // If the size is negative, then we start at 1 for the minus sign.
  if(number < 0) 
  {
    digits = 1;
  }
  while(number)
  {
    number /= 10;
    digits++;
  }
  return digits;
}


// Program to calculate the square of int values up to 100.
// The program should write two columns:
// 1) The first list the value;
// 2) the second contains the square of that value.
// Use setw(...) to manage the output so that the values line up in columns.
int main(int argc, char** argv)
{
  const int size = 1000;
  const int sizesq = size*size;

  const unsigned valw = num_of_digits(size);
  const unsigned sqw = num_of_digits(sizesq);

  // Invariant: we have outputted i squared to far.
  for (int i = 0; i < size; i++) 
  {
    cout << setw(valw) << i << " " << setw(sqw) << i*i << endl;
  }
  return 0;
}
