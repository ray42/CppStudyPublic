#include"String18.h"
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

  cout << "T1 equality" << endl;
  cout << "s==s, " << (s==s) << endl;
  cout << "s!=s, " << (s!=s) << endl;
  cout << "s==s1, " << (s==s1) << endl;
  cout << "s!=s1, " << (s!=s1) << endl;
  cout << "\n"<<endl;

  {
    cout << "T2 relational" << endl;
    String s1("ABB");
    String s2("ABC");
    cout << "s1<s1: " << (s1<s1) << endl;
    cout << "s1<s2: " << (s1<s2) << endl;
    cout << "s2<s1: " << (s2<s1) << endl;
    cout << endl;
    cout << "s1>s1: " << (s1>s1) << endl;
    cout << "s1>s2: " << (s1>s2) << endl;
    cout << "s2>s1: " << (s2>s1) << endl;
    cout << endl;
    cout << "s1<=s1: " << (s1<=s1) << endl;
    cout << "s1<=s2: " << (s1<=s2) << endl;
    cout << "s2<=s1: " << (s2<=s1) << endl;
    cout << endl;
    cout << "s1>=s1: " << (s1>=s1) << endl;
    cout << "s1>=s2: " << (s1>=s2) << endl;
    cout << "s2>=s1: " << (s2>=s1) << endl;
  }

  return 0;
}
