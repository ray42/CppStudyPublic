#include<iostream>
#include<string>
#include<sstream>
#include<cctype>

using std::cout; using std::endl; 
using std::cin;

using std::string;
using std::istringstream;

int main()
{
  istringstream ss("some words repeat repeat like that one. OR OR");
  string prev_word="";
  string current_word;
  bool repeated=false;
  while (ss >> current_word)
  {
    cout << "word is: " << current_word << endl;
    if (std::isupper(current_word[0]))
    {
      if(current_word == prev_word)
      {
        repeated=true;
        break;
      }
      else
      {
        prev_word = current_word;
      }
    }
  }

  cout << ( repeated ? (current_word + " was repeated")
                     : "No repeated words" ) << endl;
  return 0;
}
