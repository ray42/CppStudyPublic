#ifndef STRBLOB_HEADER
#define STRBLOB_HEADER

#include<vector>
#include<string>
#include<memory> // make_shared
#include<utility> 
#include<initializer_list> // initializer_list
#include<stdexcept> // out_of_range
#include<sstream> // ostringstream

class StrBlobPtr;

class StrBlob
{
friend class StrBlobPtr;

public:
  typedef std::vector<std::string>::size_type size_type;

  StrBlob();
  StrBlob(std::initializer_list<std::string> il);

  StrBlobPtr begin();

  StrBlobPtr end();

  // copy constructor - value-like
  StrBlob(const StrBlob& sb):
    data_pt(std::make_shared<std::vector<std::string>>(*sb.data_pt))
  {}


  // copy assignment operator - value-like
  StrBlob& operator=(const StrBlob& rhs)
  {
//    // copy rhs into temp
//    std::shared_ptr<std::vector<std::string>> p 
//      = std::make_shared<std::vector<std::string>>(*rhs.data_pt);
//    // delete this, // copy temp into this
//    data_pt.reset(p);
//    return *this;
//
    // Moophy has this, which is better:
    data_pt = std::make_shared<std::vector<std::string>>(*rhs.data_pt);
    return *this;
    // Why don't we need to do the three step of: 
    // copy into temp; 
    // delete this
    // copy temp into this
    // ??
    // Because if rhs is this, then copying it with make_shared will copy
    // the data over but will only free the dynamic memory if the use_count
    // goes to 0... in this case, we see that when we use make_shared, then 
    // the use_count is not zero yet, since the assignment happens, the 
    // use_count is decreased by 1, the free happens if it goes to 0, but at 
    // this point we already have a copy of the required data.
  }
  
  // returns the number of elements
  size_type size() const
  {
    return data_pt->size();
  }

  // checks whether the container is empty 
  bool empty() const
  {
    return data_pt->empty();
  }

  // adds an element to the end 
  void push_back(const std::string &t) &
  {
    data_pt->push_back(t);
  }

  // adds an element to the end Exer13-55 
  void push_back(const std::string &t) &&
  {
    data_pt->push_back(t);
  }

  void push_back(string &&s) { data->push_back(std::move(s)); }

  // removes the last element
  void pop_back();

  // access the first element
  std::string& front();

  // access the first element
  const std::string& front() const;

  // access the last element
  std::string& back();

  // access the last element
  const std::string& back() const;

  // I need a way to print all the elements (getting to the middle) without
  // using pop_back.
  const std::string printAll()
  {
    std::ostringstream oss;
    oss << "emp " << this->empty() << ", size " << this->size() << ": ";
    for(auto const& i: *data_pt)
    {
      oss << i << " ";
    }
    return oss.str();
  }


private:
  std::shared_ptr<std::vector<std::string> > data_pt;

  // throws msg if data_pt[i] isn't valid
  void check(size_type i, const std::string&msg) const;
};

StrBlob::StrBlob():data_pt(std::make_shared<std::vector<std::string> >()){}

StrBlob::StrBlob(std::initializer_list<std::string>il):
  data_pt(std::make_shared<std::vector<std::string> >(il)){}

// Check if i in [0,size), if i >= size, throw error
void StrBlob::check(size_type i, const std::string &msg) const
{
  if(i >= data_pt->size())
    throw std::out_of_range(msg);
}

std::string& StrBlob::front()
{
  // if the vector is empty, check will throw
  // i.e. we try if the 0th element is there.
  check(0,"front on empty StrBlob");
  return data_pt->front();
}

const std::string& StrBlob::front() const
{
  // if the vector is empty, check will throw
  // i.e. we try if the 0th element is there.
  check(0,"front on empty StrBlob");
  return data_pt->front();
}

std::string& StrBlob::back()
{
  check(0,"back on empty StrBlob");
  return data_pt->back();
}

const std::string& StrBlob::back() const
{
  check(0,"back on empty StrBlob");
  return data_pt->back();
}

void StrBlob::pop_back()
{
  check(0,"pop_back on empty StrBlob");
  return data_pt->pop_back();
}
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////

// StrBlobPtr throws an exception on attempts to access a nonexistent 
// element
class StrBlobPtr
{
public:
  StrBlobPtr(): wptr(std::weak_ptr<std::vector<std::string>>()), curr(0){}

  StrBlobPtr(StrBlob &a, size_t sz=0):
    wptr(a.data_pt), curr(sz){}

  bool operator!=(const StrBlobPtr& p) { return p.curr != curr; }
  std::string& deref() const;

  StrBlobPtr& incr(); // prefix version

private:
  // check returns a shared_ptr to the vector if the check succeeds.
  std::shared_ptr<std::vector<std::string>>
    check(std::size_t, const std::string&) const;

  // store a weak_ptr, which means the underlying vector might be destroyed.
  std::weak_ptr<std::vector<std::string>> wptr;
  std::size_t curr; // current position within the array
};

std::shared_ptr<std::vector<std::string>>
StrBlobPtr::check(std::size_t i, const std::string &msg) const
{
  auto ret = wptr.lock(); // is the vector still around?
  if(!ret)
    throw std::runtime_error("unbound StrBlobPtr");

  if(i >= ret->size())
    throw std::out_of_range(msg);

  return ret; // otherwise, return a shared_ptr to the vector
}

std::string& StrBlobPtr::deref() const
{
  auto p = check(curr, "dereference past end");
  return (*p)[curr];  // (*p) is the vector to which this object points
}

// prefix: return a reference to the incremented object
StrBlobPtr& StrBlobPtr::incr()
{
  // if curr already points past the end of the container, can't increment it
  check(curr, "increment past end of StrBlobPtr");
  ++curr;       // advance the current state
  return *this;
}


StrBlobPtr StrBlob::begin()
{
  return StrBlobPtr(*this);
}

StrBlobPtr StrBlob::end()
{
  auto ret = StrBlobPtr(*this,data_pt->size());
  return ret;
}


#endif
