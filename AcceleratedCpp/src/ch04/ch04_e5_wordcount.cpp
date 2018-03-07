#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<stdexcept>


using std::cout; using std::endl; using std::cin; using std::istream;
using std::string;
using std::vector;
using std::sort;
using std::domain_error;

// Write a function that reads words from an input stream and store them in
// a vector. Use that function both 
// 1) count the number of words in the input and
// 2) count how many times each word occurred.
istream& wordcount(istream& in)
{
  // if the input stream is in error state, we leave it.
  if(in)
  {
    // vector to store the word
    vector<string> words;
    string current_word;
    while(in >> current_word)
    {
      words.push_back(current_word);
    }

    // Now in is in error state. Reset it.
    in.clear();

    // How many words?
    typedef vector<string>::size_type vecstrsz;
    vecstrsz size = words.size();
    if(size == 0)
    {
      throw domain_error("No words detected.");
    }

    cout << "Total number of words: " << size << endl;

    // sort the words and get the number of multiplicity:
    sort(words.begin(),words.end());
    vector<string> unique_words;
    vector<unsigned> multiplicity;

    // Insert first word so we have something to compare to.
    unique_words.push_back(words[0]);
    multiplicity.push_back(1);

    for (vecstrsz i = 1; 
        i < size; i++)
    {
      // If this word is the same as the previously, increase multiplicity
      if(unique_words.back().compare(words[i]) == 0)
      {
        multiplicity.back()++;
      }
      else
      {
        unique_words.push_back(words[i]);
        multiplicity.push_back(1);
      }
    }

    // output.
    vecstrsz uni_size = unique_words.size();
    for (vecstrsz i = 0; i < uni_size; i++) 
    {
      cout << unique_words[i] << " appears "
        << multiplicity[i] << " times." << endl;
    }
  }
  return in;
}

int main()
{
  cout << "Please enter some words, followed by EOF: " << endl;
  try{
    wordcount(cin);
  }catch(domain_error e){
    cout << e.what() << endl;
  }

  return 0;
}
