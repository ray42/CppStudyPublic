/*
 * =========================================================================
 * Copyright (c) 2017, Raymon White - All Rights Reserved
 * Author:  Raymon White (ray), rayaxiom42 AT gmail DOT com
 * =========================================================================
 */
#include<iostream>
using std::cout; using std::endl; using std::cin;

#include<map>
using std::map;

#include<set>
using std::set;

#include<string>
using std::string;

#include<algorithm>
using std::transform;

//Exercise 11.3: Write your own version of the word-counting program.
void wordcount()
{
  // count the number of times each word occurs in the input.
  map<string,string::size_type> word_count;
  set<string> exclude = {"The","But","And","Or","An","A",
                         "the","but","and","or","an","a"};

  string word;
  while(cin >> word)
  {
    // count only words that are not in exclude
    if(exclude.find(word)==exclude.end())
    {
      ++word_count[word]; // fetch and increment the counter for word
    }
  }

  for (const auto&w : word_count) // for each element in the map
  {
    // print the results
    cout << w.first << " occurs " << w.second
         << ( (w.second > 1) ? " times.":" time.") << endl;
  }
}

//Exercise 11.4: Extend your program to ignore case and punctuation. For 
//example, “example.” “example,” and “Example” should all increment the same
//counter.
void wordcount2()
{
  map<string,string::size_type> word_count;
  set<string> exclude = {"the","but","and","or","an","a"};

  string word;
  while(cin >> word)
  {
    // make word lowercase
    transform(word.begin(),word.end(),word.begin(),::tolower);
    
    // strip off punctuation.
    word.erase(std::remove_if(word.begin(),word.end(),::ispunct),
               word.end());

    // Now we can put the word into the map.
    // if == end(), then it is not in the exclude list.
    if(exclude.find(word) == exclude.end())
    {
      ++word_count[word];
    }
  }

  for (const auto&w : word_count) // for each element in the map
  {
    // print the results
    cout << w.first << " occurs " << w.second
         << ( (w.second > 1) ? " times.":" time.") << endl;
  }
}

int main(int argc, char** argv)
{
  if(argc > 1)
  {
    wordcount2();
  }
  else
  {
    wordcount();
  }
  return 0;
}
