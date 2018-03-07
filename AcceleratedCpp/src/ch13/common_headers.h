#ifndef COMMON_HEADER_H
#define COMMON_HEADER_H

#include "Core.h"

// comparison functions, required for std::sort
bool compare_names(const Core& c1, const Core& c2)
{
  return c1.name() < c2.name();
}

// comparison functions, required for std::sort
bool compare_grades(const Core& c1, const Core& c2)
{
  return c1.grade() < c2.grade();
}

bool compare_names_ptrs(const Core* cp1, const Core* cp2)
{
  return compare_names(*cp1,*cp2);
}


#endif
