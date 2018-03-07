#include<iostream>
using std::cout; using std::clog; using std::cerr; using std::endl; 
using std::cin;
#include<vector>
using std::vector;
#include<string>
using std::string;

void t1()
{
  // p19 - this is illegal because, cannot assign to rvalue.
//  int a=1,b=2,c=3;
//  a*b=c;
}


////////////////////////////////////////////////////////////////////////////
struct referenceconst
{
  referenceconst():str("initstring")
  {}

  string getstr() const
  {
    return str;
  }

  string str;
};



int main(int argc, char** argv)
{
  t1();

  std::cout << "argc: " << argc << ", argv[0]: " << argv[0] << std::endl;
  return 0;
}
