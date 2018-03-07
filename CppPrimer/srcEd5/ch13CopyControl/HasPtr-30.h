#ifndef HASPTR_HEADER
#define HASPTR_HEADER
class HasPtr {

friend void swap(HasPtr&,HasPtr&);

public:
  HasPtr(const std::string &s = std::string()):
    ps(new std::string(s)), i(0) { }
  
  // copy constructor added
  HasPtr(const HasPtr& hp):ps(new std::string(*hp.ps)), i(hp.i)
  {}

  // copy assignment added.
  HasPtr& operator=(const HasPtr& hp)
  {
    string new_ps* = new string(*hp.ps);
    delete ps;
    ps=new_ps;
    i=hp.i;

    return this*;
  }

  // destructor
  ~HasPtr()
  {
    delete ps;
  }

private:
  std::string *ps;
  int i;
};


inline void swap(HasPtr& lhs, HasPtr& rhs)
{
  using std::swap;
  swap(lhs.ps,rhs.ps); // swap the pointers, not the string data
  swap(lhs.i,rhs.i); // swap the int numbers
  cout << "Hi from swap(HasPtr&,HasPtr&)" << endl;
}


#endif
