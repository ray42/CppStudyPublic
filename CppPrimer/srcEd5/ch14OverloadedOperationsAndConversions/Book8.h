#ifndef BOOK8_H
#define BOOK8_H

#include<iostream>
#include<string>

class Book
{
  friend std::istream& operator>>(std::istream&, Book&);
  friend std::ostream& operator<<(std::ostream&, const Book&);
  friend bool operator==(const Book&, const Book&);
  friend bool operator!=(const Book&, const Book&);


public:

  // edition, title, author, publication date
  Book(unsigned ed=0, std::string title="", 
       std::string author="", std::string date="")
  : ed_(ed), title_(title), author_(author), pubdate_(date)
  {/*empty*/}

  Book(std::istream&in):ed_(0), title_(""), author_(""), pubdate_("")
  {in >> *this;}

  std::ostream& printall(std::ostream& os=std::cout);


private:
  unsigned ed_;        // edition
  std::string title_;  // title of book
  std::string author_; // author
  std::string pubdate_;// publication date
};

// declaration for input, output, ==, !=
std::istream& operator>>(std::istream&, Book&);
std::ostream& operator<<(std::ostream&, const Book&);
bool operator==(const Book&, const Book&);
bool operator!=(const Book&, const Book&);

#endif
