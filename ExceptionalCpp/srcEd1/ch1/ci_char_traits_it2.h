/*==========================================================================
 * Copyright (c) 2017, Raymon White - All Rights Reserved
 * Author:  Raymon White (ray), rayaxiom42 AT gmail DOT com
 * Code for the exercises from Exceptional C++
 *==========================================================================
 */
#include<string> //char_traits basic_string
#include<cctype> // toupper


int memicmp(const void *s1, const void *s2, size_t n)
{
  const char *sc1 = (const char *) s1;
  const char *sc2 = (const char *) s2;
  const char *sc2end = sc2 + n;

  while (sc2 < sc2end && std::toupper(*sc1) == std::toupper(*sc2))
    sc1++, sc2++;
  if (sc2 == sc2end)
    return 0;
  return (int) (std::toupper(*sc1) - std::toupper(*sc2));
}

// just inherit all the other functions that
// we don't need to replace
struct ci_char_traits : public std::char_traits<char>
{
  static bool eq(char c1, char c2) // override - doesn't work? :(
  {
    return std::toupper(c1) == std::toupper(c2);
  }

  static bool lt(char c1, char c2) // override - doesn't work? :(
  {
    return std::toupper(c1) < std::toupper(c2);
  }

  static int compare(const char* s1,
                     const char* s2,
                     size_t n) // override - doesn't work? :(
  {
           // if available on your platform,
           // otherwise roll your own.
    return memicmp(s1,s2,n);
  }

  // what is this function for?
  static const char*
  find(const char* s, int n, char a) // override - doesn't work? :(
  {
    while(n-- > 0 && std::toupper(*s) != std::toupper(a))
    {
      ++s;
    }
    return n>=0? s:0;
  }
};

using ci_string = std::basic_string<char,ci_char_traits>;


