#include<iostream>
#include "Vec.h"
#include "./../rayheader.h"



using std::cout; using std::cin; using std::endl;

int main(int argc, char** argv)
{
  Vec<int> v;
  v.push_back(1);
  v.push_back(2);
  v.push_back(3);
  v.push_back(4);

  cout << ray::print_container(v.begin(),v.end()) << endl;
  cout << "size is: " << v.size() << endl;

  Vec<int>::iterator it = v.erase(v.begin()+3);
  cout << ray::print_container(v.begin(),v.end()) << endl;
  cout << "size is: " << v.size() << endl;
  cout << "Value at it is: " << (*it) << endl;

//  Vec<int>::iterator it = v.erase(v.begin()+4,v.begin()+6);
//  cout << ray::print_container(v.begin(),v.end()) << endl;
//  cout << "size is: " << v.size() << endl;
//  cout << "Value at it is: " << (*it) << endl;


  v.clear();
  cout << ray::print_container(v.begin(),v.end()) << endl;
  cout << "size is: " << v.size() << endl;

  return 0;
}




