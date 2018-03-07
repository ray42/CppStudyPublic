#include<iostream>
#include<string>
#include<vector>

using std::cout; using std::endl;
using std::string; using std::vector;

int sum_string_int(const vector<string> &s)
{
  int i=0;
  for(const auto& ii:s)
  {
    i+=std::stoi(ii);
  }

  return i;
}

float sum_string_float(const vector<string> &s)
{
  float i=0;
  for(const auto& ii:s)
  {
    i+=std::stof(ii);
  }

  return i;
}

int main()
{
  vector<string> s{"1","2","3","4.2"};
  cout << sum_string_int(s) << endl;
  cout << sum_string_float(s) << endl;
  return 0;
}
