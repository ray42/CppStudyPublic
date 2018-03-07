#include<iostream>

int main(int argc, char** argv)
{
  // Exercise 1.9: Write a program that uses a while to sum the numbers from
  // 50 to 100.
  unsigned sum = 0;
  for(int count=50; count <=100; ++count)
  {
    sum+=count;
  }

  std::cout << "sum from 50 to 100 is: " << sum << std::endl;

  // Exercise 1.10: Use the decrement operator to write a while that prints
  // the numbers from ten down to zero.
  std::cout << "Countdown from 10 to zero: " << std::endl;
  for(int count=10; count>0; --count)
  {
    std::cout << count << std::endl;
  }
  return 0;
}
