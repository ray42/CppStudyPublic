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

#include<utility>
using std::pair;

class Families
{
public:
  Families():Fam(map<string, vector<pair<string,string> > >())
  {
  }

  void addNewFamily(const string& lastname)
  {
    if(Fam.find(lastname) == Fam.end())
    {
      Fam.emplace(lastname,vector<pair<string,string> >());
    }
  }

  void addNewChild(const string& lastname, const string& childname,
      const string& bd)
  {
    auto it = Fam.find(lastname);
    if(it==Fam.end())
    {
      addNewFamily(lastname);
    }
    
    Fam[lastname].push_back({childname,bd});
  }

  auto getFam()->map<string,vector<pair<string,string> > >
  {
    return Fam;
  }

private:

  map<string, vector<pair<string,string> > > Fam;
};

//Exercise 11.7: Define a map for which the key is the family’s last name 
//and the value is a vector of the children’s names. Write code to add new
//families and to add new children to an existing family.
int main()
{
  Families someFam;
  someFam.addNewFamily("White");
  someFam.addNewChild("White","Ray","Wed");
  someFam.addNewChild("White","Jay","Fri");
  someFam.addNewChild("Keljo","Johanna","Sat");
  someFam.addNewChild("Keljo","Jenny","Sun");

  for(const auto& i : someFam.getFam())
  {
    cout << "Surname: " << i.first << endl;
    for(const auto& j: i.second)
    {
      cout <<j.first << " " << j.second << endl;
    }
    cout << endl;
  }

  return 0;
}
