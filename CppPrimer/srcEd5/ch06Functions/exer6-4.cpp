#include<iostream>
using std::cout; using std::endl; using std::cin;

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
    throw domain_error("Please help.");
//    return -1;
  }
}

void fact_with_interaction()
{
  cout << "Please enter integers [0,12) and I'll compute fact." << endl;
  unsigned val=0;
  while(cin >> val)
  {
    try{
      cout << val << "! = " << fact(val) << endl;
    }catch(domain_error err)
    {
      char ch;
      cout << "Again? y/n" << endl;
      cin >> ch;
      if(!cin || ch == 'n')
        break;
    }
  }
}

int main()
{
  fact_with_interaction();
  return 0;
}
