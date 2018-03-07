#include<iostream>
#include<vector>
#include<string>

#include<tuple> // tuple
using std::tuple;

using std::cout; using std::clog; using std::cerr; using std::endl; 
using std::cin;

using std::vector;
using std::string;

#include<algorithm>
using std::equal_range;

#include<utility>
using std::pair;

#include<random>
using std::default_random_engine;


int main(int argc, char** argv)
{
//  tuple<int,int> t1(1,2);
//  tuple<int,int> t2{1,2};
//  tuple<int,int> t3 = {1,2}; // this works although it should not work.
//  // the library implementation is incorrect. C++ Primer is correct.
//  tuple<int,int> t4({1,2});

  vector<string> sv{"A","B","B","B","B","B","B","C"};
  auto found = equal_range(sv.cbegin(),sv.cend(),"B");
//      [](const string& lhs, const string& rhs)
//      {
//        return lhs==rhs;
//      });
  cout << "number found: " << found.second - found.first << endl;


  default_random_engine e;  // generates random unsigned integers
  for (size_t i = 0; i < 10; ++i)
    // e() "calls" the object to produce the next random number
    cout << e() << " ";
  cout << endl;

  cout << std::uppercase << std::showbase << std::hex
     << "printed in hexadecimal: " << 20 << " " << 1024
     << std::nouppercase << std::noshowbase << std::dec << std::endl;



  std::cout << "argc: " << argc << ", argv[0]: " << argv[0] << std::endl;
  return 0;
}
