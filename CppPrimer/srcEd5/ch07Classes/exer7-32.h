
// From pezy:
//
//
//  ex7_32.h
//  Exercise 7.32
//
//  Created by pezy on 11/18/14.
//  Copyright (c) 2014 pezy. All rights reserved.
//
//  @See ex7_27.h

// Notes: We have the declare but not define clear().
// Then we define the class Screen, including the friend declaration of clear.
// Finally we can define clear, which uses screen.
// see page 382 of my C++ primer notes.
//
// It seems like if we want to make a friend function, we have to write 
// everything in one file. Or we put the include "Screen.h" 
// (in the Window_mgr file) AFTER we have declared clear, then and only then
// can we define clear. This is a bit messy, I'll stick to making the whole
// class a friend.


#ifndef CP5_ex7_32_h
#define CP5_ex7_32_h

#include <vector>
#include <string>
#include <iostream>

class Screen;

class Window_mgr {
public:
    using ScreenIndex = std::vector<Screen>::size_type;
    inline void clear(ScreenIndex);

private:
    std::vector<Screen> screens;
};

class Screen {
    friend void Window_mgr::clear(ScreenIndex);

public:
    using pos = std::string::size_type;

    Screen() = default; // 1
    Screen(pos ht, pos wd) : height(ht), width(wd), contents(ht * wd, ' ') {} // 2
    Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht * wd, c)
    {
    } // 3

    char get() const { return contents[cursor]; }
    char get(pos r, pos c) const { return contents[r * width + c]; }
    inline Screen& move(pos r, pos c);
    inline Screen& set(char c);
    inline Screen& set(pos r, pos c, char ch);

    const Screen& display(std::ostream& os) const
    {
        do_display(os);
        return *this;
    }
    Screen& display(std::ostream& os)
    {
        do_display(os);
        return *this;
    }

private:
    void do_display(std::ostream& os) const { os << contents; }

private:
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;
};

inline void Window_mgr::clear(ScreenIndex i)
{
    if (i >= screens.size()) return; // judge for out_of_range.
    Screen& s = screens[i];
    s.contents = std::string(s.height * s.width, ' ');
}

inline Screen& Screen::move(pos r, pos c)
{
    cursor = r * width + c;
    return *this;
}

inline Screen& Screen::set(char c)
{
    contents[cursor] = c;
    return *this;
}

inline Screen& Screen::set(pos r, pos c, char ch)
{
    contents[r * width + c] = ch;
    return *this;
}

#endif

