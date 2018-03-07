#include"Book8.h"
#include<iostream>
using std::ostream;
using std::istream;
using std::cout;
using std::endl;
using std::cin;

ostream& Book::printall(ostream& os)
{
  os << ed_ << " "
     << title_ << " "
     << author_ << " "
     << pubdate_;
  return os;
}

istream& operator>>(istream& is, Book& book)
{
  is >> book.ed_ 
     >> book.title_ 
     >> book.author_
     >> book.pubdate_;
  return is;
}

ostream& operator<<(ostream& os, const Book& book)
{
  os << book.ed_ << " "
     << book.title_ << " "
     << book.author_ << " "
     << book.pubdate_;
  return os;
}

bool operator==(const Book& lhs, const Book& rhs)
{
  return lhs.ed_ == rhs.ed_ &&
         lhs.title_ == rhs.title_ &&
         lhs.author_ == rhs.author_ &&
         lhs.pubdate_ == rhs.pubdate_;
}

bool operator!=(const Book& lhs, const Book& rhs)
{
  return !(lhs == rhs);
}


