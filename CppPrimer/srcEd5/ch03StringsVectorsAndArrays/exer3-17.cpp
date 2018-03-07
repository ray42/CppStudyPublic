#include<iostream>
#include<vector>
#include<string>
#include<cctype>

using std::cin; using std::cout; using std::endl;
using std::vector;
using std::string;

int main()
{
  // Read a sequence of words from cin and store the values a vector. After 
  // you've read all the words, process the vector and change each word to 
  // uppercase. Print the transformed elements, eight words to a line.
  string currentword;
  vector<string> words;
  while(cin >> currentword)
  {
    words.push_back(currentword);
  }

  // Loop through elements in the vector
  for(auto& word : words)
  {
    // loop through the characters in the word
    for(auto& c : word)
    {
      c=toupper(c);
    }
  }

  // Loop through and print out new line every 8 lines
  for(decltype(words.size()) i = 0; i < words.size(); ++i)
  {
    cout << words[i] << " ";
    if(i!=0 && i % 8 == 0)
      cout << endl;
  }

  return 0;
}
