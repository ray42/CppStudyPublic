#include<iostream>
using std::cout; using std::clog; using std::cerr; using std::endl; 
using std::cin;
#include<vector>
using std::vector;
#include<string>
using std::string;

int main(int argc, char** argv)
{
  int i = 0;
  ++(++(++(i)))=42;
  cout << i << endl; // outputs 42
  (i++)++; // error: lvalue required as increment operand


  std::cout << "argc: " << argc << ", argv[0]: " << argv[0] << std::endl;
  return 0;
}
