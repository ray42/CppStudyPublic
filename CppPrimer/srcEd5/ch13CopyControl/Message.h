#ifndef MESSAGE_HEADER
#define MESSAGE_HEADER

#include<set>
#include<string>

class Folder;

class Message
{
  friend class Folder;
public:
  // folders is implicitly initialized to the empty set
  explicit Message(const std::string &str = ""):
    contents(str), folders(std::set<Folder*>())
  {}

  // copy control to manage pointers to this Message
  Message(const Message&); // copy constructor
  Message& operator=(const Message&); // copy assignment operator
  ~Message();                       // destructor

  // add/remove this Message from the specified Folder's set of messages
  void save(Folder&);
  void remove(Folder&);

  std::string getcontents()
  {
    return contents;
  }

  // test function
  void printall();

private:
  std::string contents; // actual message text
  std::set<Folder*> folders; // Folders that have this Message

  // utility functions used by copy constructor, assignment, and destructor
  // add this Message to the Folders that point to the parameter
  void add_to_Folders(const Message&);

  // remove this Message from every Folder in folders
  void remove_from_Folders();


  // when we copy Message, the copy and the original will be distinct 
  // (deep copies), which implies both should appear in the same set of 
  // Folders. Thus:
  // Must copy the contents
  // Must copy the set of Folder pointers
  // Must add the newly created Message to each of those Folders 
  //   (iterate through the set of pointers and invoke ther add function on 
  //   *this).
//  copy-constructor

  // Assign another Msg to this Msg =>
  //   replace contents of this Msg with the RHS.
  //   Update the set of Folder pointers, removing the LHS and adding the RHS.
//  copy-assignment-operator?

  // When we destroy a Message, this Message no longer exists
  //  - remove pointers to this Message from Folders that contain this Msg.
//  ~Message()
//  {}

  // create - provide contents but no folder.
  // to put into folder, use save()
  // create(std::string contents); ?? not needed? - I guess this is the string
  // constructor.

  // add a message to a specified folder.
//  save(Folder);

  // remove a message from a specified folder.
//  remove(Folder);

};

#endif
