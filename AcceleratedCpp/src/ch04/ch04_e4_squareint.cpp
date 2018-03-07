#include<iostream>
#include<string>
#include<iomanip>

using std::cout; using std::endl; using std::cin;
using std::string;
using std::setw;

// return the number of digits in number.
unsigned num_of_digits(double number)
{
  unsigned digits = 0;
  // If the size is negative, then we start at 1 for the minus sign.
  if(number == 0.0)
  {
    return 1;
  }

  if(number < 0) 
  {
    digits = 1;
  }
  while(number>0.1)
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
  const double size = 1000;
  const double sizesq = size*size;

  const unsigned valw = num_of_digits(size);
  const unsigned sqw = num_of_digits(sizesq);

  cout << "valw: " << valw << ", sqw: " << sqw << endl;

  // Invariant: we have outputted i squared to far.
  for (double i = 0; i < size; i++) 
  {
    cout << setw(valw) << i << " " << setw(sqw) << i*i << endl;
  }
  return 0;
}
