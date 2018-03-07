#include<iostream>
#include<string>
#include<sstream>


#include "StrChar.h"

using std::cout; using std::cin; using std::endl;
using std::string;
using std::istringstream;

int main()
{
  StrChar s1;
  StrChar s2(6,'q');
  StrChar s3("s3");
  string ss = "s4";
  StrChar s4(ss.begin(),ss.end());
  StrChar s5 = "s5";
  StrChar s6; s6 = "s6";


  cout << "s1: " << s1.to_string() << endl;
  cout << "s2: " << s2.to_string() << endl;
  cout << "s3: " << s3.to_string() << endl;
  cout << "s4: " << s4.to_string() << endl;
  cout << "s5: " << s5.to_string() << endl;
  cout << "s6: " << s6.to_string() << endl;
  cout << "s6.[1] = " << s6[1] << endl;
  cout << "s6.size() = " << s6.size() << endl;

  cout << "\n Now testing input/output" << endl;
  std::string sentence="qq ww ee rr tt"; // 5 words
  unsigned nwords=5;
  std::istringstream iss(sentence);
  StrChar s7;
  for(unsigned i = 0; i < nwords; ++i)
  {
    iss >> s7;
    cout << "i = "<< i << " " << s7 << endl;
  }

  s5+=s6;
  cout << "s5+=s6: " << s5 << endl;
  cout << "s3+s4: " << s3+s4 << endl;
  StrChar s8 = "My anaconda " + s2 + " don't!";
  cout << s8 << endl;



  cout << "End test" << endl;
  return 0;
}





