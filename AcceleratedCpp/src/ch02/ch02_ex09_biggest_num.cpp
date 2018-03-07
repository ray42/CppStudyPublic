#include<iostream>

int main()
{
  std::cout << "Please provide two numbers" << std::endl;
  
  double num1, num2;
  std::cin >> num1 >> num2;
  if(num1 > num2)
  {
    std::cout << num1 <<" > " << num2 << std::endl; 
  }
  else if(num2 > num1)
  {
    std::cout << num2 <<" > " << num1 << std::endl; 
  }
  else
  {
    std::cout << num1 << " == " << num2 << std::endl; 
  }
  return 0;
}
