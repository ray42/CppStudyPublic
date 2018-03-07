#include <vector>
#include <string>
#include <iostream>

int main()
{
  // this uses c++11
    std::vector<std::string> v{"Hello, ", "Cruel ", "World!"};
    std::string result;
    for (auto const& s : v) { result += s; }
    std::cout << result; // Will print "Hello, Cruel World!"
}
