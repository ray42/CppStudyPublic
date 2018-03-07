#include<string>
using std::string;

#include<vector>
using std::vector;

#include<fstream>
using std::ifstream;

#include<iostream>
using std::cout; using std::cerr; using std::endl;

//Exercise 8.4: Write a function to open a file for input and read its 
//contents into a vector of strings, storing each line as a separate element 
//in the vector.
void readLineIntoVec(const string& filename, vector<string>& vec)
{
  // clear the vector
  vec.clear();

  ifstream ifs(filename);
  if(ifs)
  {
    string str;
    while(getline(ifs,str)) vec.push_back(str);
  }
  else
  {
    cerr << "Cannot open file " << filename << endl;
  }
}

//Exercise 8.5: Rewrite the previous program to store each word in a
//separate element.
void readWordIntoVec(const string& filename, vector<string>& vec)
{
  // clear the vector
  vec.clear();

  ifstream ifs(filename);
  if(ifs)
  {
    string str;
    while(ifs>>str) vec.push_back(str);
  }
  else
  {
    cerr << "Cannot open file " << filename << endl;
  }
}

int main()
{
  vector<string> vec;
  readLineIntoVec("exer8-4-text.txt",vec);
  for (auto s:vec)
    cout << s << endl;

  readWordIntoVec("exer8-4-text.txt",vec);
  for (auto s:vec)
    cout << s << endl;

  return 0;
}


