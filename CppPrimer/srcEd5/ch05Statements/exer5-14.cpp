#include<iostream>
#include<string>
#include<sstream>

using std::cout; using std::endl;
using std::string;
using std::istringstream;

// Exercise 5.14: Write a program to read strings from standard input
// looking for duplicated words. The program should find places in the input
// where one word is followed immediately by itself. Keep track of the 
// largest number of times a *single* repetition occurs and which word is 
// repeated. Print the maximum number of duplicates, or else print a message
// saying that no word was repeated. For example, if the input is
//   how now now now brown cow cow
// the output should indicate that the word now occurred three times.
int main()
{
  // test data
  istringstream ss("how now now now brown cow cow");

  string word;
  unsigned maxWordCnt = 0;
  string repeatedWord;

  unsigned currentWordCnt=0;
  string previousWord;
  while(ss >> word)
  {
    // have we seen this word previously?
    if(word == previousWord)
    {
      ++currentWordCnt;
    }
    else
    {
      previousWord = word;
      currentWordCnt = 1;
    }

    // Update the max word count and repeated word if required:
    if(currentWordCnt > maxWordCnt)
    {
      maxWordCnt = currentWordCnt;
      repeatedWord = word;
    }
  }

  cout << "The word '" << repeatedWord 
       << "' occurred " << maxWordCnt << " times." << endl;

  return 0;
}
