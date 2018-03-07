#include<iostream>

using std::cout; using std::endl;

#include "Screen.h"

#include "Window_mgr.h"

int main()
{
  Screen myscreen;
  char ch = myscreen.get(); // Calls Screen::get()

  Window_mgr mywindows;

  return 0;
}
