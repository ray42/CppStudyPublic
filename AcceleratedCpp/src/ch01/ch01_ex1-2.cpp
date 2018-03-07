#include <iostream>
#include <string>

int main()
{
  // Below works, because string+string literal = string.
  const std::string hello = "Hello";
  const std::string message = hello + ", world"+"!";

  // Below is not valid since it contains the concatenation of two
  // string literals:
  const std::string exclaim = "!";
  const std::string message2 = "Hello"+", world"+exclaim;

  return 0;
}


