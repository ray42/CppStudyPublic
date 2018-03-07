#include<string>
using std::string;

#include<iostream>
using std::cerr; using std::endl; using std::cout; using std::cin;

#include<fstream>
using std::ifstream;

#include<sstream>
using std::istringstream;

#include<vector>
using std::vector;

//Exercise 8.10: Write a program to store each line from a file in a
//vector<string>. Now use an istringstream to read each element from
//the vector a word at a time.
int main()
{
  vector<string> vecstr;
  string filename("exer8-4-text.txt");
  ifstream ifs(filename);
  if(ifs)
  {
    string line;
    while(getline(ifs,line)) vecstr.push_back(line);
  }
  else
  {
    cerr << "Cannot open " << filename << endl;
  }

  for(auto s: vecstr)
  {
    istringstream iss(s);
    string word;
    while(iss>>word) cout << word << endl;
  }
  return 0;
}
