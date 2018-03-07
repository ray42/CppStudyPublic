#include<iostream>
using std::cout; using std::endl;

#include<stdexcept>
using std::domain_error;

unsigned fact(unsigned val)
{
  try{
    if(val > 12) throw domain_error("val! for val > 12 will overflow");

    unsigned ret = 1;
    while (val > 1)
    {
      ret *= val--;
    }
    return ret;

  } catch(domain_error err){
    std::cerr << "On no: " << err.what() << endl;
    return -1;
  }
}

int main()
{
  cout << fact(0) << endl;
  cout << fact(1) << endl;
  cout << fact(2) << endl;
  cout << fact(3) << endl;
  cout << fact(4) << endl;
  cout << fact(5) << endl;
  cout << fact(6) << endl;
  cout << fact(7) << endl;
  cout << fact(8) << endl;
  cout << fact(9) << endl;
  cout << fact(10) << endl;
  cout << fact(11) << endl;
  cout << fact(12) << endl;
  cout << fact(13) << endl;
  cout << fact(14) << endl;
  return 0;
}
