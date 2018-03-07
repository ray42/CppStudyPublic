#ifndef GUARD_WINDOW_MGR_H
#define GUARD_WINDOW_MGR_H

#include<vector>
#include "Screen.h"
#include<string>

class Window_mgr
{
public:
  // location ID for each screen on the window
  using ScreenIndex = std::vector<Screen>::size_type;
  // reset the Screen at the given position to all blanks
  void clear(ScreenIndex);

  // add a Screen to the window and returns its index
  ScreenIndex addScreen(const Screen&);
  
private:
  // Screens this Window_mgr is tracking
  // by default, a Window_mgr has one standard sized blank screen.
  std::vector<Screen> screens{Screen(24,80,' ')};
};

void Window_mgr::clear(ScreenIndex i)
{
  // s is a reference to the Screen we want to clear
  Screen &s = screens[i];
  // reset the contents of that Screen to all blanks
  s.contents = std::string(s.height*s.width, ' ');
}

// return type is seen before we're in the scope of Window_mgr

Window_mgr::ScreenIndex
Window_mgr::addScreen()
{
  screens.push_back(s); // pushes back a copy of s
  return screens.size()-1;
}

#endif
