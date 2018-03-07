/*
 * =========================================================================
 *
 *       Filename:  exer9-testvecmem.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  18/03/17 04:58:23
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Dr. Raymon White (Zwei), quatrezwei@gmail.com
 *   Organization:  
 *
 * =========================================================================
 */
#include<iostream>
#include<vector>
#include<string>

using std::cout; using std::clog; using std::cerr; using std::endl; 
using std::cin;

using std::vector;
using std::string;

int main()
{
  vector<int> v;
  cout << "v.capacity: " << v.capacity() << endl;
  cout << "v.size: "<<v.size() <<endl<< endl;

  v.assign(5,0);
  cout << "v.capacity: " << v.capacity() << endl;
  cout << "v.size: "<<v.size() <<endl<< endl;

  v.push_back(3);
  cout << "v.capacity: " << v.capacity() << endl;
  cout << "v.size: "<<v.size() << endl<<endl;

  v.reserve(5);
  cout << "v.capacity: " << v.capacity() << endl;
  cout << "v.size: "<<v.size() << endl<<endl;

  v.reserve(11);
  cout << "v.capacity: " << v.capacity() << endl;
  cout << "v.size: "<<v.size() << endl<<endl;

  v.shrink_to_fit();
  cout << "v.capacity: " << v.capacity() << endl;
  cout << "v.size: "<<v.size() << endl<<endl;

  v.push_back(1);
  cout << "v.capacity: " << v.capacity() << endl;
  cout << "v.size: "<<v.size() << endl<<endl;


  return 0;
}

