#include <iostream>
#include <vector>
#include <string>
#include <cctype> //std::isalnum
#include <algorithm> //std::find

#include "ray_string.h"

using std::cout; using std::endl; using std::cin;
using std::vector;
using std::string;
using std::isalnum;
using std::find;



// yield false if c is a letter, digit or any of the characters in url_ch.
// if c is any other value, the function returns true.
bool not_url_char(char c)
{
  // character, in addition to alphanumerics, that can appear in a URL
  static const string url_ch = "~;/?:@=&$-_.+!*'(),";

  // see whether c can appear in a URL and return the negative
  return !(isalnum(c) ||
    find(url_ch.begin(),url_ch.end(),c) != url_ch.end());
}

string::const_iterator
url_end(string::const_iterator b, string::const_iterator e)
{
  return find_if(b,e,not_url_char);
}


string::const_iterator
url_beg(string::const_iterator b, string::const_iterator e)
{
  static const string sep="://";

  typedef string::const_iterator iter;

  // i marks where the separator was found.
  iter i = b;

  while( (i = search(i,e,sep.begin(),sep.end())) != e)
  {
    // make sure the separator isn't at the beginning or end of the line
    if(i != b && i+sep.size() != e)
    {
      // beg marks the beginning of the protocol-name
      // think of beg[-1] has *(beg-1)
      iter beg = i;
      while(beg != b && isalpha(beg[-1]))
        --beg;

      // is there at least one appropriate character before and after the 
      // separator?
      if(beg != i && !not_url_char(i[sep.size()]))
        return beg;
    }
    // the separator we found wasn't part of a URL advance i past this 
    // separator
    i+=sep.size();
  }
  return e;
}


// Finding URLs:
// Use a function by creating a single string that holds the entire contents 
// of a document. The function would then scan the document and find all the
// URLs in it. A URL is a sequence of characters of the form
//
// protocol-name://resource-name
//
// where protocol-name contains only letters, and resource-name may consist 
// of letters, digits and certain punctuation characters.  Our function will
// take a string argument and will look for instances of :// in that string.
// Each time we find such an instance, we'll look for the protocol-name that
// precedes it, and the resource-name that follows it.
//
// Because we want out function to find all the URLs in its input, we'll 
// want it to return a vector<string>, with one element for each URL. The 
// function executes by moving the iterator b through the string, looking 
// for the characters :// that might be a part of a URL. If we find these 
// characters, it looks backwards to find the protocol-name and it looks 
// forward to find the resource-name.
vector<string>find_urls(const string& s)
{
  vector<string> ret;
  typedef string::const_iterator iter;
  iter b = s.begin(), e = s.end();

  // look through the entire input
  while(b!=e)
  {
    // look for one or more letters followed by ://
    b = url_beg(b,e);

    // if we found it
    if(b != e)
    {
      // get the rest of the URL
      iter after = url_end(b,e);

      // remember the URL
      ret.push_back(string(b,after));

      // advance b and check for more URLs on this line
      b = after;
    }
  }
  return ret;
}


int main(int argc, char** argv)
{
  cout << "Hello World!" << endl;
}
