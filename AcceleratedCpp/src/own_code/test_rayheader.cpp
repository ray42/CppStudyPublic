#include<iostream>
#include<vector>
#include<string>

#include "./../rayheader.h"

using std::cout; using std::cin; using std::endl;
using std::vector;
using std::string;

int main(int argc, char** argv)
{

  double darray[] = {1,2,3,4,5};
  vector<double> doublevec(darray, darray+sizeof(darray)/sizeof(darray[0]));

  string s = ray::print_container(doublevec.begin(),doublevec.end());
  cout << s << endl;
  
  cout << "Got to end" << endl;
  
  return 0;
}




