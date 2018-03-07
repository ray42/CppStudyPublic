#include <iostream>
#include <string>
#include <map>

using std::cout; using std::endl; using std::cin;
using std::string;
using std::map;

int main(int argc, char** argv)
{
  // the current word
  string s;

  // store each word and an associated counter
  map<string,int> counters;

  // read the input, keeping track of each word and how often we see it
  while(cin >> s)
    ++counters[s];

  // write the words and associated counts
  for(map<string,int>::const_iterator it = counters.begin();
      it != counters.end(); ++it)
  {
    cout << it->first << "\t" << it->second << endl;
  }
  return 0;
}
