#include<iostream> // std::endl, std::cin, std::cout
#include<string> // std::string
#include<vector> // std::vector
#include<algorithm> // std::sort

using std::string; using std::vector;
using std::cout; using std::cin; using std::endl;
using std::sort;

// 3.3 Write a program to count how many times each distinct word appears
// in its input.
//
// First read all words into a vector<string>
// sort the vector
// loop through:
//   Keep track of unique word
//   increment a counter for each unique word
//
int main()
{
  cout << "Please enter words, followed by EOF:" << endl;
  // storage for the strings
  string currentword;
  vector<string> words;

  // invariant: words contains the words read in so far.
  while(cin >> currentword)
  {
    words.push_back(currentword);
  }
  sort(words.begin(),words.end());

  typedef vector<string>::size_type strvec_sz;
  strvec_sz words_size = words.size();

  if(words_size == 0)
  {
    cout << "Please enter some words, try again!" << endl;
    return 1;
  }

  vector<string> unique_words;
  vector<unsigned> unique_words_multiplicity;

  unique_words.push_back(words[0]);
  unique_words_multiplicity.push_back(1);

  // invariant: unique_words contain the unique words processed so far and
  for (unsigned i = 1; i < words_size; i++) 
  {
    if(unique_words.back().compare(words[i]) == 0)
    {
      unique_words_multiplicity.back()++;
    }
    else
    {
      unique_words.push_back(words[i]);
      unique_words_multiplicity.push_back(1);
    }
  }

  strvec_sz n_unique_words = unique_words.size();
  for (unsigned i = 0; i < n_unique_words; i++) 
  {
    cout << unique_words[i] << " appears " 
                            << unique_words_multiplicity[i]
                            << " times." << endl;
  }

  return 0;
}



