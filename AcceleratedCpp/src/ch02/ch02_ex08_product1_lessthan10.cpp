#include<iostream>

int main()
{
  for (unsigned i = 1; i < 10; i++) 
  {
    for (unsigned j = 1; j < 10; j++) 
    {
      std::cout << i*j << " ";
    }
    std::cout << std::endl; 
  }
  return 0;
}
