#include<iostream>

int main(int argc, char** argv)
{
  // Exercise 1.9: Write a program that uses a while to sum the numbers from
  // 50 to 100.
  unsigned sum = 0, count = 50;
  while(count <= 100)
  {
    sum+=count;
    count++;
  }

  std::cout << "sum from 50 to 100 is: " << sum << std::endl;

  // Exercise 1.10: Use the decrement operator to write a while that prints
  // the numbers from ten down to zero.
  std::cout << "Countdown from 10 to zero: " << std::endl;
  count=10;
  while(count >0)
  {
    std::cout << count << std::endl;
    --count;
  }

  // Exercise 1.11: Write a program that prompts the user for two integers. 
  // Print each number in the range specified by those two integers using 
  // while.
  std::cout << "Please enter two numbers\n"
            << "first number smaller than second number." << std::endl;
  unsigned x,y;
  std::cin >>x>>y;
  while(y >= x)
  {
    std::cout << y << std::endl;
    --y;
  }

  return 0;
}
