#include<iostream>
using std::cout; using std::endl;

#include<string>
using std::string;

#include<vector>
using std::vector;

//Exercise 9.41: Write a program that initializes a string from a
//vector<char>.

//Exercise 9.42: Given that you want to read a character at a time into a
//string, and you know that you need to read at least 100 characters, how
//might you improve the performance of your program?
int main()
{
  vector<char> cv{'H','e','l','l','o'};
  string s1(cv.begin(),cv.end());
  cout << s1 << endl;

  string s2;
  s2.reserve(100);
  cout << s2.capacity() << endl;

  return 0;
}
