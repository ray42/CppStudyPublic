#include<iostream>
using std::cout; using std::endl;
#include<string>
using std::string;

template <typename T> class Stack 
{
public:
  Stack() = delete;
  Stack(T i):foo(i) {}

  void print()
  {cout << foo << endl;}

  T foo;
};

int main() {

  string s1("hi!"), s2;
  s2 = std::move(string("bye!")); // ok: moving from an rvalue
  s2 = std::move(s1); //ok: but after the assigment s1 has indeterminate value

  cout << s1 << endl;


//  Stack<string> foo(string("Hello"));
///  foo.print();

}
