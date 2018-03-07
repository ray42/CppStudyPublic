#ifndef HASPTR_HEADER
#define HASPTR_HEADER
class HasPtr {

friend void swap(HasPtr&,HasPtr&);
friend bool operator<(const HasPtr&, const HasPtr&);

public:
  HasPtr(const std::string &s = std::string()):
    ps(new std::string(s)), i(0) { }
  
  // copy constructor added
  HasPtr(const HasPtr& hp):ps(new std::string(*hp.ps)), i(hp.i)
  {}

//  // copy assignment added. OLD METHOD
//  HasPtr& operator=(const HasPtr& hp)
//  {
//    string new_ps* = new string(*hp.ps);
//    delete ps;
//    ps=new_ps;
//    i=hp.i;
//
//    return this*;
//  }

  // copy assignment using copy-swap idiom, since we've defined swap.
  HasPtr& operator=(HasPtr tmp) // uses COPY constructor here.
  {
    this->swap(tmp); // uses SWAP here.
    return *this;
  }// tmp is destroyed. EASY!

  void swap(HasPtr &rhs)
  {
    using std::swap;
    swap(ps,rhs.ps);
    swap(i,rhs.i);
    std::cout << "Hi from swap(HasPtr&)" << endl;
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
  lhs.swap(rhs);
}

bool operator<(const HasPtr &lhs, const HasPtr &rhs)
{
  return *lhs.ps < *rhs.ps;
}

#endif
