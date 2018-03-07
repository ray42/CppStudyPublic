#include<iostream>
#include<vector>
#include<string>

class A;
class B;

class A
{

  public:
  B b;
}

class B
{
  public:
    A a;
}


using std::cout; using std::clog; using std::cerr; using std::endl; 
using std::cin;

using std::vector;
using std::string;

int main(int argc, char** argv)
{


  std::cout << "argc: " << argc << ", argv[0]: " << argv[0] << std::endl;
  return 0;
}
