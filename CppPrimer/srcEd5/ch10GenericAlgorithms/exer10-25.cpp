#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

#include"./../common/cpp_primer_common.h"

using std::cout; using std::endl;

using std::string;
using std::vector;

#include<functional>
using std::bind; using namespace std::placeholders;


template<typename T>
bool check_size(const T &s, typename T::size_type sz)
{
  return s.size() >= sz;
}

// lets practice trailing return types
template<typename T>
auto elimDups(vector<T>&vec)->vector<T>&
{
  // first sort
  std::sort(vec.begin(),vec.end());
  vec.erase(std::unique(vec.begin(),vec.end()),vec.end());
  return vec;
}

bool isShorter(const string&s1, const string&s2)
{
  return s1.size() < s2.size();
}

//Exercise 10.16: Write your own version of the biggies function using
//lambdas.
// biggies is a function to:
// 1) report how many words are of a given size or greater
// 2) prints the words of a given length or greater.
void biggies(vector<string>&words,
             vector<string>::size_type sz)
{
  //put words into alphabetical order and remove duplicates
  elimDups(words);

  // sort words by size, but 
  // maintain alphabetical order for words of the same size
  stable_sort(words.begin(),words.end(),
              [](const string&a,const string&b)
              {
                return  a.size()<b.size();
              });

  // get an iterator to the first element whose size() >= sz
  auto wc=partition(words.begin(),words.end(), // changed to use bind and checksize
    bind(check_size<string>,_1,sz));

  // compute the number of elements with size >= sz.
  // for partition, those elements which are true are put first.
  auto count = std::distance(words.begin(),wc);

  // output the number of elements.
  cout << count << " " << cppp::make_plural(count,"word","s")
       << " of length " << sz << " or longer" << endl;

  // print words of the given size or longer, each one followed by a space.
  for_each(words.begin(),wc,
    [](const string &s)
    {
      cout << s << " ";
    });
  cout << endl;
}

int main()
{
  std::vector<std::string> vs{"the","quick","red","fox","jumps","over", 
                              "the", "slow", "red", "turtle"};
  biggies(vs,5);
  return 0;
}
