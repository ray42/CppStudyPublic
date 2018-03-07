#include<iostream>
#include<string>
using std::cout; using std::endl;
using std::string;

//Exercise 9.43: Write a function that takes three strings, s, oldVal, and
//newVal. Using iterators, and the insert and erase functions replace all
//instances of oldVal that appear in s by newVal. Test your function by
//using it to replace common abbreviations, such as “tho” by “though” and
//“thru” by “through”.
void Replace(string& s, const string& oldVal, const string& newVal)
{
  // First step is to determine the oldVal within s.
  // So we need to step through s one char at a time, and see if
  // and see if the current char until oldVal.size() is the same as oldVal.
  // Furthermore, we cannot advance pass 
  // s.size() - current char index >= oldVal.size(), since we would go beyond
  // the end of the string.
  string::size_type oldValSize = oldVal.size();
  string::iterator currIt = s.begin();
  while(std::distance(currIt,s.end()) >= int(oldValSize))
  {
    if(string(currIt,currIt+oldValSize) == oldVal)
    {
      currIt=s.erase(currIt,currIt+oldValSize);
      // iterator pointing to the character last 
      // (or currIt+oldValSize in this case) pointed to before the 
      // erase, or end() if no such character exists
      currIt=s.insert(currIt,newVal.begin(),newVal.end());
      std::advance(currIt,newVal.size());
    }
    else
    {
      std::advance(currIt,1);
    }
  }
}

//Exercise 9.44: Rewrite the previous function using an index and replace.
void ReplaceReplace(string& s, const string& oldVal, const string& newVal)
{
  // For this version, I'll use find and replace.
  // size_t find (const string& str, size_t pos = 0) const noexcept;
  // The position of the first character of the first match.
  // If no matches were found, the function returns string::npos.
  string::size_type pos= 0;
  while((pos=s.find(oldVal,pos)) != string::npos)
  {
    s.replace(pos,oldVal.size(),newVal);
    pos+=newVal.size();
  }
}

int main()
{
  //Tests: 1)beginning, 2)end, 3)middle and 4)not found:
  string s="tho1234567";
  Replace(s,"tho","though");
  cout << s << endl;
 
  s="123tho4567";
  Replace(s,"tho","though");
  cout << s << endl;

  s="1234567tho";
  Replace(s,"tho","though");
  cout << s << endl;

  s="1234567";
  Replace(s,"tho","though");
  cout << s << endl;

  // Do the same thing but with thru/through
  s="thru1234567";
  Replace(s,"thru","through");
  cout << s << endl;
 
  s="123thru4567";
  Replace(s,"thru","through");
  cout << s << endl;

  s="1234567thru";
  Replace(s,"thru","through");
  cout << s << endl;

  s="1234567";
  Replace(s,"thru","through");
  cout << s << endl;


  //Tests: 1)beginning, 2)end, 3)middle and 4)not found:
  s="tho1234567";
  ReplaceReplace(s,"tho","though");
  cout << s << endl;
 
  s="123tho4567";
  ReplaceReplace(s,"tho","though");
  cout << s << endl;

  s="1234567tho";
  ReplaceReplace(s,"tho","though");
  cout << s << endl;

  s="1234567";
  ReplaceReplace(s,"tho","though");
  cout << s << endl;

  // Do the same thing but with thru/through
  s="thru1234567";
  ReplaceReplace(s,"thru","through");
  cout << s << endl;
 
  s="123thru4567";
  ReplaceReplace(s,"thru","through");
  cout << s << endl;

  s="1234567thru";
  ReplaceReplace(s,"thru","through");
  cout << s << endl;

  s="1234567";
  ReplaceReplace(s,"thru","through");
  cout << s << endl;



  return 0;
}
