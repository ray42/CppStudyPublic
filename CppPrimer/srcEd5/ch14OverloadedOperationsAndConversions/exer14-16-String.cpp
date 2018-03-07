#include"String16.h"
#include<iostream>
using std::cout; using std::endl;
#include<string>
using std::string;

int main()
{
  String s("Hello");
  cout << s <<", size: "<< s.size() << endl;

  String s1;
  cout << s1 <<", size: "<< s1.size() << endl;

  string str("hello");
  cout << str <<", size: "<< str.size() << endl;

  cout << "s==s, " << (s==s) << endl;
  cout << "s!=s, " << (s!=s) << endl;
  cout << "s==s1, " << (s==s1) << endl;
  cout << "s!=s1, " << (s!=s1) << endl;

  return 0;
}
