#include <iostream>
#include <string>

int main()
{
  std::cout << "What is your name?";
  std::string name;
  std::cin >> name;
  std::cout << "Hello, " << name
            << std::endl << "And what is yours?";
  std::cin >> name;
  std::cout << "Hello, " << name
            << "; nice to meet you too!" << std::endl;
  return 0;
}
/*
$ ./run.bash ch01_ex6
g++ -c -Wall ch01_ex6.cpp -o ch01_ex6.o
g++  ch01_ex6.o -o ../bin/ch01_ex6
What is your name?qqqqq wwwww
Hello, qqqqq
And what is yours?Hello, wwwww; nice to meet you too!
*/
