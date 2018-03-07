#include<iostream>
using std::cout; using std::clog; using std::cerr; using std::endl; 
using std::cin;
#include<vector>
using std::vector;
#include<string>
using std::string;


class Window{
public:
  Window()=default;
  virtual ~Window()=default;
  virtual void onResize()
  {
    windowResizeStr+="BaseWindow";
  }
  string windowResizeStr;
};

class SpecialWindow: public Window{
public:

  SpecialWindow()=default;
  virtual ~SpecialWindow()=default;

  virtual void onResize()
  {
    cout << "Got into onResize before cast" << endl;
    static_cast<Window&>(*this).onResize();
    cout << "Got into onResize after cast" << endl;
    specialWindowResizeStr+="SpecialWindow";
  }

  string specialWindowResizeStr;
};


int main(int argc, char** argv)
{
  SpecialWindow sw;
  sw.onResize();
//  cout << sw.specialWindowResizeStr << endl;
//  cout << sw.windowResizeStr << endl;


  std::cout << "argc: " << argc << ", argv[0]: " << argv[0] << std::endl;
  return 0;
}
