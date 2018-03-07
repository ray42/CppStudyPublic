#include<iostream>
#include<vector>
#include<string>

using std::cout; using std::clog; using std::cerr; using std::endl; 
using std::cin;

using std::vector;
using std::string;

int main(int argc, char** argv)
{

//  // p197 testing modulo and signs
//  cout << "21 % 6 = " << (21%6) << endl;
//  cout << "21 % -6 = " << (21%(-6)) << endl;
//  cout << "-21 % 6 = " << ((-21)%6) << endl;
//  cout << "-21 % -6 = " << ((-21)%(-6)) << endl;
//
//  cout << endl;
//  cout << "21 / 6 = " << (21/6) << endl;
//  cout << "21 / -6 = " << (21/(-6)) << endl;
//  cout << "-21 / 6 = " << ((-21)/6) << endl;
//  cout << "-21 / -6 = " << ((-21)/(-6)) << endl;

//  string s = "word";
//  s == 's';
//  string pl = s + s[s.size() - 1];// == 's' ? "" : "s" ;

////////////////////////////////////////////////////////////////////////////
//  cout << (~'q'<<6)  << endl;

  int ival=43432472;
  int * ip = &ival;
  char* cp = reinterpret_cast<char*>(ip);


//  char c = 'h';
//  char cp[3] = {'h', 'e', 'l'};
  string str(cp);
  cout << str << endl;
//  cout << 

//////////////////////////////////////////////////////////////////////////
  std::cout << "argc: " << argc << ", argv[0]: " << argv[0] << std::endl;
  return 0;
}
