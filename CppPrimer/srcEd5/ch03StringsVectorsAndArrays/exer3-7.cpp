#include<iostream>
#include<string>

using std::cout; using std::endl; using std::cin;
using std::string;

int main()
{
  // Use a range for to change all the characters in a string to X .
  // What would happen if you define the loop control variable in the 
  // previous exercise as type char ? Predict the results and then change 
  // your program to use a char.
  // to see if you were right.
  string str("Hello World!");
  for(char c : str)
    c='X';
  cout << str << endl;
  return 0;
}
