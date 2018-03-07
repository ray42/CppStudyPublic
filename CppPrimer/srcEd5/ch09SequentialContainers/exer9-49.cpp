#include<iostream>
#include<string>
#include<fstream>

using std::cout; using std::endl;
using std::string;
using std::ifstream;

int main()
{
  string filename("exer9-49data.txt");
  ifstream ifdata(filename);

  // plain letters do not have acenders nor decenders
  string plain_letters("acemnorsuvwxz");
  string longest_plain_word="";

  string word;
  while(ifdata >> word)
  {
    if ((word.find_first_not_of(plain_letters) == string::npos) &&
        (word.size() > longest_plain_word.size()))
    {
      longest_plain_word=word;
    }
  }

  cout << longest_plain_word << endl;

  return 0;
}
