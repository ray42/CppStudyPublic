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

#include<vector>
using std::vector;

#include<string>
using std::string;

class Families
{
public:
  Families():Fam(map<string, vector<string> >())
  {
  }

  void addNewFamily(const string& lastname)
  {
    if(Fam.find(lastname) == Fam.end())
    {
      Fam.emplace(lastname,vector<string>());
    }
  }

  void addNewChild(const string& lastname, const string& childname)
  {
    auto it = Fam.find(lastname);
    if(it==Fam.end())
    {
      addNewFamily(lastname);
    }
    
    Fam[lastname].push_back(childname);
  }

  map<string, vector<string> > Fam;
};

//Exercise 11.7: Define a map for which the key is the family’s last name 
//and the value is a vector of the children’s names. Write code to add new
//families and to add new children to an existing family.
int main()
{
  Families someFam;
  someFam.addNewFamily("White");
  someFam.addNewChild("White","Ray");
  someFam.addNewChild("White","Jay");
  someFam.addNewChild("Keljo","Johanna");
  someFam.addNewChild("Keljo","Jenny");

  for(const auto& i : someFam.Fam)
  {
    cout << "Surname: " << i.first << endl;
    for(const auto& j: i.second)
    {
      cout <<j << " ";
    }
    cout << endl;
  }

  return 0;
}
