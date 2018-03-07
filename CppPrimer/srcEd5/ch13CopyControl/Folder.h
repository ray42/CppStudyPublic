#ifndef FOLDER_H
#define FOLDER_H

#include<string>
#include<set>
#include<iostream>
using std::cout; using std::endl;

class Message;

class Folder
{
friend class Message;

public:
  
  Folder(const std::string &n=""):
    name(n),messages(std::set<Message*>())
  {}

  std::string getname();

  void addMsg(Message *m);

  void remMsg(Message *m);

  void printall();

private:
  std::string name;
  std::set<Message*> messages;

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
//  create(std::string contents);

  // add a message to a specified folder.
//  save(Folder); // addMsg(Message) // add Msg to this folder.

  // remove a message from a specified folder.
//  remove(Folder); // remMsg() // Remove Message to this folder.

};
#endif
