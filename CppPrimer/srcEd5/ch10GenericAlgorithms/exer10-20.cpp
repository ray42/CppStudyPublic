#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

#include"./../common/cpp_primer_common.h"

using std::cout; using std::endl;

using std::string;
using std::vector;

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
  auto wc=stable_partition(
    words.begin(),words.end(), // changed to use partition
    [sz](const string&a)
    {
      return a.size()>=sz;
    });

  // compute the number of elements with size >= sz.
  // for partition, those elements which are true are put first.
//  auto count = std::distance(words.begin(),wc);
  
  //Exercise 10.20: The library defines an algorithm named count_if. Like
  //find_if, this function takes a pair of iterators denoting an input range
  //and a predicate that it applies to each element in the given range. 
  //count_if returns a count of how often the predicate is true. Use 
  //count_if to rewrite the portion of our program that counted how many 
  //words are greater than length 6.
  auto count = count_if(words.begin(),words.end(),
                        [sz](const string& a)->bool
                        {
                          return a.size()>=sz;
                        });

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
  biggies(vs,6);
  return 0;
}
