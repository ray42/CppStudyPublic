#include<iostream>
#include<string>
#include<sstream>

using std::cout; using std::endl; 
using std::cin;

using std::string;
using std::istringstream;

int main()
{
  istringstream ss("some words repeat repeat like that one.");
  string prev_word="";
  string current_word;
  while (ss >> current_word)
  {
    if(current_word == prev_word)
    {
      break;
    }
    else
    {
      prev_word = current_word;
    }
  }

  cout << ( ss.eof() ? "No repeated words" 
                     : (current_word + " was repeated") ) << endl;
  return 0;
}
