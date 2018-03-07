#include<iostream>
using std::cout; using std::cin; using std::endl;

#include<string>
using std::string;

// return the plural version of word if ctr is greater than 1
inline string make_plural(size_t ctr, const string &word,
                               const string &ending = "s")
{
  return (ctr > 1) ? word + ending : word;
}

int main()
{
  cout << make_plural(1,"success","es") << endl;
  cout << make_plural(2,"success","es") << endl;
  cout << make_plural(1,"failure") << endl;
  cout << make_plural(2,"failure") << endl;
  return 0;
}
