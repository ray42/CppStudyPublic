#include<iostream>
using std::cout; using std::endl;

#include<algorithm>
using std::partition;

#include<list>
using std::list;

#include<string>
using std::string;

//Exercise 10.13: The library defines an algorithm named partition that
//takes a predicate and partitions the container so that values for which the
//predicate is true appear in the first part and those for which the predicate is
//false appear in the second part. The algorithm returns an iterator just past
//the last element for which the predicate returned true. Write a function that
//takes a string and returns a bool indicating whether the string has five
//characters or more. Use that function to partition words. Print the elements
//that have five or more characters.
bool fiveOrMoreChars(const string&s)
{
  return s.size()>=5;
}

int main()
{
  list<string> ls{"www","qqqqq","ww","qqqqqq"};
  auto part_end = partition(ls.begin(),ls.end(),fiveOrMoreChars);
  for(const auto&i:ls)
    cout << i << " ";
  cout << endl;

  cout << "More than 5 chars:"<<endl;
  for(auto b=ls.begin(); b!=part_end; ++b)
    cout << *b<< " ";
  cout << endl;

  return 0;
}
