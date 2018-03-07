#include<iostream>
#include<vector>
#include<list>

using std::cout; using std::clog; using std::cerr; using std::endl; 
using std::cin;

using std::vector;
using std::list;
//Exercise 9.15: Write a program to determine whether two vector<int>s
//are equal.

//Exercise 9.16: Repeat the previous program, but compare elements in a
//list<int> to a vector<int>.
int main()
{
  vector<int> v1{1,2,3,4};
  vector<int> v2{1,2,3,4,5,6};
  cout << std::boolalpha << (v1==v2) <<endl;

  list<int>l1{1,2,3,4};
  // Relational operators, rhs must have same container and element type as
  // lhs, so we'll build a vector from l1

  cout << std::boolalpha << (vector<int>(l1.begin(),l1.end()) ==v1)
    << endl;

  cout << std::boolalpha << (vector<int>(l1.begin(),l1.end()) ==v2)
    << endl;

  return 0;
}
