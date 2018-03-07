#include<iostream> // std::cout, std::endl; std::cin
#include<string> //std::string
#include<vector> // std::vector

using std::cout; using std::endl; using std::cin;
using std::string;
using std::vector;

// 3-4 Write a program to report the length of the longest and shortest 
// string in its input.
//
// I'll only output the first shortest and first longest
int main(int argc, char **argv)
{
  // storage for the words
  vector<string> words;
  string currentword;

  // invariant: words contain the words read in so far
  while(cin >> currentword)
  {
    words.push_back(currentword);
  }

  typedef vector<string>::size_type strvec_sz;
  strvec_sz words_size= words.size();
  if(words_size == 0)
  {
    cout << "Please provide some words." << endl;
    return 1;
  }

  typedef string::size_type str_sz;
  str_sz longest_len = 0;
  str_sz shortest_len = words[0].max_size();
  string longest_word;
  string shortest_word;
  for (unsigned i = 0; i < words_size; i++)
  {
    // get longest work
    str_sz curr_word_len = words[i].length();

    if(curr_word_len > longest_len)
    {
      longest_word = words[i];
      longest_len = curr_word_len;
    }
    if(curr_word_len < shortest_len)
    {
      shortest_word = words[i];
      shortest_len = curr_word_len;
    }
  }

  cout << "Longest word: " << longest_word 
       << ", len: " << longest_len << endl;
  cout << "Shortest word: " << shortest_word 
       << ", len: " << shortest_len << endl;

  return 0;
}
