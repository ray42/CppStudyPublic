#include<iostream>
#include<string>

int main()
{
  // I want to do a quick test to see
  int intvar;
  std::cin >> intvar;
  std::cout << "Int works: " << intvar << std::endl;

  char charvar;
  std::cin >> charvar;
  std::cout << "Char also works: " << charvar << std::endl;

  std::string stringvar;
  std::cin >> stringvar;
  std::cout << "String works: " << stringvar << std::endl;

}
