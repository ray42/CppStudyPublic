#include<iostream>
using std::cout; using std::endl;

#include<algorithm>
using std::count;

#include<vector>
using std::vector;

#include<list>
using std::list;

#include<string>
using std::string;

//Exercise 10.1: The algorithm header defines a function named count
//that, like find, takes a pair of iterators and a value. count returns a 
//count of how often that value appears. Read a sequence of ints into a vector
//and print the count of how many elements have a given value.
//Exercise 10.2: Repeat the previous program, but read values into a list of
//strings.
int main()
{
  vector<int> iv{1,2,2,3,3,3,4,4,4,4};
  cout << count(iv.begin(),iv.end(),3) << endl;

  list<string> sl{"hi","hi","bye","bye","bye","bye","ok"};
  cout << count(sl.begin(),sl.end(),"bye") << endl;

  return 0;
}
