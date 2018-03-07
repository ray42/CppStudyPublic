#include<iostream>
#include<vector>
#include<string>

using std::cout; using std::clog; using std::cerr; using std::endl; 
using std::cin;

using std::vector;
using std::string;

// From p395
class NoDefault {
public:
NoDefault(const std::string&);
// additional members follow, but no other constructors
};
struct A { // my_mem is public by default; see 7.2
NoDefault my_mem;
};
// error: cannot synthesize a constructor for A
struct B {
B() {} // error: no initializer for b_member
//NoDefault b_member;
NoDefault b_member{""};
};


int main()
{

A a;
B b;
  return 0;
}

