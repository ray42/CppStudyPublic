#include<iostream>
#include<string>
#include<vector>
#include<sstream>

using std::cout; using std::endl; using std::cin;
using std::string;
using std::vector;
using std::istringstream;

int main()
{

  vector<string> text;

  text.push_back("Lorem ipsum dolor sit amet, mea te vivendo albucius.");
  text.push_back("Vivendo expetenda principes nam ei, mea quot illum putant ad, suas graecis ut eum.");
  text.push_back("Mandamus ocurreret efficiantur at vim, labore voluptua est no, pri oporteat referrentur deterruisset in.");
  text.push_back("Et est possit pertinax, in nam sumo elit dissentias.");
  text.push_back("");

  // Loop through each sentence.
  for (auto it = text.begin();
       it != text.end() && !it->empty(); ++it)
  {
    // Loop through each character
    for(auto &c : *it)
    {
      if(isalpha(c)) c = toupper(c);
    }
  }

  // Now print.
  // Loop through sentence
  for (auto it = text.cbegin();
       it != text.end() && !it->empty(); ++it)
  {
    cout << *it << endl;
  }

  return 0;
}
