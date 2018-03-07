#include<iostream>
#include<string>

using std::cout; using std::endl; using std::cin;
using std::string;
// Exercise 5.19: Write a program that uses a do while loop to repetitively
// request two strings from the user and report which string is less than
// the other.
int main()
{
  string rsp;
  do
  {
    cout << "Please enter two strings" << endl;
    string str1, str2;
    cin >> str1 >> str2;

    cout<<(str1<str2?(str1+"<"+str2):(str2+">="+str1))<< endl;

    cout << "Again? y/n" << endl;
    cin >> rsp;
  }while(!rsp.empty() && rsp[0] != 'n');
  return 0;
}
