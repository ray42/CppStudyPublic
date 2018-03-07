#include "Folder.h"
#include "Message.h"

#include<iostream>
using std::cout; using std::endl;

#include<string>
using std::string;

#include<set>
using std::set;

void Folder::printall()
{
  cout << getname() << endl;
  cout <<"No. messages: "<<messages.size()<<endl;
  for(auto const&i:messages)
  {
    cout<<"\t"<<i->getcontents()<<endl;
  }
}

void Folder::addMsg(Message *m)
{
  messages.insert(m);
}

void Folder::remMsg(Message *m)
{
  cout << "Hello from Folder: " << name << endl;
  cout << "Removing Message: "<< m << " " << m->contents << endl;
  cout << "messages size is: " << messages.size() << endl;
  cout << "iterating through the set" << endl;
  for(const auto& i:messages)
  {
    cout << i << " " << i->getcontents() << endl;
  }
  cout << "done output from set" << endl;

  // THIS PART BREAKS... WHY?
  messages.erase(m);
  cout << "Done the erase" << endl;
}

string Folder::getname()
{
  return name;
}

