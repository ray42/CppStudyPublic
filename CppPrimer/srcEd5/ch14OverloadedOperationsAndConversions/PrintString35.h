#ifndef PRINTSTRING_H
#define PRINTSTRING_H
#include<iostream> // ostream, cout


class PrintString
{
public:
  PrintString(std::ostream &o = std::cout, char c = ' '):
    os(o), sep(c){ /* empty */}
  void operator()(const string& s) const
  {
    os << s << sep;
  }

private:
  std::ostream& os; // stream on which to write
  char sep;         // character to print each output
};
#endif
