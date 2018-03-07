/*
 * =========================================================================
 * Copyright (c) 2017, Raymon White - All Rights Reserved
 * Author:  Raymon White (ray), rayaxiom42 AT gmail DOT com
 * =========================================================================
 */
#include<iostream>
using std::cout; using std::endl;
#include<string>
using std::string;


class Token
{
public:
  // copy control needed because our class has a union with a string member
  // defining the move constructor and move-assignment operator is left as
  // an exercise
  Token(): tok(INT), ival{0}{}
  Token(const Token &t): tok(t.tok){copyUnion(t);}
  Token &operator=(const Token&);

  //if the union holds a string, we must destroy it; see 19.1.2
  ~Token()
  {
    if(tok==STR) sval.~string();
  }

  // assignment operators to set the differing members of the union
  Token &operator=(const std::string&);
  Token &operator=(char);
  Token &operator=(int);
  Token &operator=(double);
private:
  enum{INT, CHAR, DBL, STR} tok; // discriminant
  union{
    char        cval;
    int         ival;
    double      dval;
    std::string sval; 
  }; // each Token object has an unnamed member of this unnamed union type
  
  // check the discriminant and copy the union member as appropriate
  void copyUnion(const Token&);
};

Token &Token::operator=(int i)
{
  if(tok == STR) sval.~string(); // if we have a string, free it
  ival = i;
  tok = INT;
  return *this;
}

// do char and double op=

Token &Token::operator=(const std::string &s)
{
  if(tok == STR) // if we already hold a string, just do an assignment
    sval = s;
  else
    new(&sval) string(s); // otherwise construct a string

  tok = STR; // update the discriminant
  return *this;
}

int main()
{
  return 0;
}

