#include<iostream>
using std::cout; using std::clog; using std::cerr; using std::endl; 
using std::cin;
#include<vector>
using std::vector;
#include<string>
using std::string;
#include<tuple>



int main(int, char*[])
{
  std::tuple<int,double> t1(42,3.14);     // OK, old syntax
  std::tuple<int,double> t2{42,3.14};     // OK, new syntax
  std::tuple<int,double> t3 = {42,3.14};  // ERROR


  


  return 0;
}
