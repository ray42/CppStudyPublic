#include<iostream>
using std::cout; using std::endl;

#include"Message.h"
#include"Folder.h"

Message::Message(const Message&m):
  contents(m.contents), folders(m.folders)
{
  cout << "Hi from copy constructor" << endl;
  add_to_Folders(m); // add this Message to the Folders that point to m.
  cout << "By from copy constructor" << endl;
}

// The call to remove_from_Folders ensures that no Folder has a pointer to
// the Message we are destroying. The compiler automatically invokes the 
// string and the set destructor to clean up memory used by contents and 
// folders, respectively.
Message::~Message()
{
  cout << "Hi from ~Message" << endl;
  remove_from_Folders();
  cout << "bye from ~Message" << endl;
}

Message& Message::operator=(const Message& rhs)
{
  // handle self-assignment by removing pointers before inserting them.
  // Note: This does NOT clear the set folders, the book told me to
  // put folders.clear() inside remove_from_Folders, but it is a mistake and
  // will cause a bug. Since if we clear the folders set, then it is lost 
  // from both the rhs and lhs if they are the same. Thus we cannot 
  // re-insert them into the rhs since the set is cleared!
  remove_from_Folders(); // update the existing Folders in folders.
  contents = rhs.contents; // copy message contents from rhs
  folders = rhs.folders; // copy Folder pointers from rhs
  add_to_Folders(rhs); // add THIS Message to those (rhs) Folders.
  return *this;
}

void Message::printall()
{
  cout<<"contents: "<<contents<<endl;
  cout<<"folders size: "<<folders.size()<<endl;
  for(const auto &i:folders)
  {
    cout << "\t"<< i->getname()<<endl;
  }
}

void Message::save(Folder& f)
{
  folders.insert(&f);// add the given Folder to our list of Folders.
  f.addMsg(this);    // add this Message to f's set of Messages
}

void Message::remove(Folder& f)
{
  folders.erase(&f); // take the given Folder out of our list of Folders.
  f.remMsg(this);    // remove this Message from f's set of Messages
}

// add this Message to Folders that point to m
void Message::add_to_Folders(const Message &m)
{
  for(auto f:m.folders) // for each Folder that holds m
    f->addMsg(this); // add a pointer to this Message to that Folder.
}

// remove this Message from the corresponding Folders
void Message::remove_from_Folders()
{
  for(auto f:folders) // for each pointer in folders
  {
    cout << "Removing msg " << this->contents 
         << " from folder " << f->getname()<<endl;
    f->remMsg(this); // remove this Message from that Folder.
  }

// From Moophy:
// The book added one line here: folders.clear(); 
//
// but I think it is redundant and more importantly, it will cause a bug:
// - In Message::operator=(), in the case of self-assignment, it first calls
//   remove_from_Folders() and its folders.clear() clears the data member of
//   lhs(rhs), and there is no way we can assign it back to lhs.

//   Refer to: http://stackoverflow.com/questions/29308115/protection-again-self-assignment

// - Why is it redundant? As its analogous function 
// Message::add_to_Folders(), Message::remove_from_Folders() should ONLY
// take care of the bookkeeping in Folders but not touch the Message's own 
// data members - makes it much clearer and easier to use. As you can see in
// the 2 places where we call Message::remove_from_Folders(): in 
// Message::operator=, folders.clear() introduces a bug as illustrated 
// above; in the destructor ~Message(), the member "folders" will be 
// destroyed anyways, why do we need to clear it first?
}
