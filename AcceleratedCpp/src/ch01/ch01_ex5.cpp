#include <iostream>
#include <string>

int main()
{
  // Won't work because x is in the inner scope, thus cannot be used
  // outside.
  // Error is: ‘x’ was not declared in this scope
  {std::string s = "a string";
  {std::string x = s + ", really";
  std::cout << s << std::endl; }
  std::cout << x << std::endl;
  }
  return 0;
}
