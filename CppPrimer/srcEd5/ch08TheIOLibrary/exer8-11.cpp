#include<string>
using std::string;

#include<vector>
using std::vector;

#include<iostream>
using std::cin; using std::cout; using std::endl;

#include<sstream>
using std::istringstream;

// members are public by default; see § 7.2 (p. 268)
struct PersonInfo {
  string name;
  vector<string> phones;
};

int main()
{
  string line, word;  // will hold a line and word from input, respectively

  vector<PersonInfo> people; // will hold all the records from the input
  // read the input a line at a time until cin hits end-of-file 
  // (or another error)
  istringstream record;
  while (getline(cin, line)) 
  {
    PersonInfo info;      // create an object to hold this record's data
    record.clear(); // This clears any iostate flags that are set in the 
                    // previous iteration or by setting the string.
    record.str(line); // bind record to the line we just read
    record >> info.name;  // read the name
    while (record >> word)        // read the phone numbers
        info.phones.push_back(word);  // and store them
    people.push_back(info); // append this record to people
  }
  
  for (auto& p : people)
  {
    std::cout << p.name << " ";
    for (auto& s : p.phones) std::cout << s << " ";
    std::cout << std::endl;
  }
  return 0;
}
