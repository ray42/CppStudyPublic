#include<string>
using std::string;

#include<deque>
using std::deque;

#include<iostream>
using std::cin; using std::cout; using std::endl;

#include<list>
using std::list;

//Exercise 9.18: Write a program to read a sequence of strings from the
//standard input into a deque. Use iterators to write a loop to print the
//elements in the deque.
//
//Exercise 9.19: Rewrite the program from the previous exercise to use a
//list. List the changes you needed to make.

int main()
{
  string word;
  cout << endl << "Now with list:" << endl;
  {
    list<string> c;
    while(cin >>word) c.push_back(word);

    for(auto it=c.cbegin(); it != c.cend(); ++it)
    {
      cout << *it << " ";
    }
  }

  return 0;
}
