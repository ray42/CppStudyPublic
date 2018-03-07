/*
 * =========================================================================
 * Copyright (c) 2017, Raymon White - All Rights Reserved
 * Author:  Raymon White (ray), rayaxiom42 AT gmail DOT com
 * =========================================================================
 */
#include<iostream>
using std::cout; using std::endl;

#include<map>
using std::map;
using std::multimap;

#include<vector>
using std::vector;

#include<string>
using std::string;

class Families
{
public:
  Families():Fam(multimap<string, string>())
  {
  }

  void addNewChild(const string& lastname, const string& childname)
  {
    Fam.insert({lastname,childname});
  }

  multimap<string, string> Fam;
};

//Exercise 11.7: Define a map for which the key is the family’s last name 
//and the value is a vector of the children’s names. Write code to add new
//families and to add new children to an existing family.
int main()
{
  Families someFam;
  someFam.addNewChild("White","Ray");
  someFam.addNewChild("White","Jay");
  someFam.addNewChild("Keljo","Johanna");
  someFam.addNewChild("Keljo","Jenny");

  for(const auto& i : someFam.Fam)
  {
    cout << i.first <<" "<< i.second << endl;
  }

  return 0;
}
