#include"headercommon.h"

bool foonamespace::debug = true;

std::ostream& foonamespace::greet(std::ostream& os)
{
  if(foonamespace::debug)
  {
    os << "Hello!" << std::endl;
  }
  return os;
}




