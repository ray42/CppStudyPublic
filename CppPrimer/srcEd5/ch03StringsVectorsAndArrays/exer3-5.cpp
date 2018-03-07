#include<iostream>
#include<string>

using std::cin; using std::cout; using std::endl;
using std::string;

int main(int argc, char** argv)
{
  // Write a program to read strings from the standard input, concatenating
  // what is read into one large string. Print the concatenated 
  // string. 
  // Next, change the program to separate adjacent inputstrings by a space.
  string concat="";
  string concatspace="";

  string word;
  while(cin >> word)
  {
    concat+=word;
    concatspace+=word+" ";

    // Note: There is an extra whitespace at the end of 
    // concatspace. To get rid of it, you can take out character
    // off at the end, or do this:
    // concatspace += (concatspace.empty() ? "" : " ") + word);
    // which does not put a space at the first word, since concatspace would
    // be empty.
  }

  cout << "concat: " << concat << endl;
  cout << "with whitespace: " << concatspace << endl;
  return 0;
}
