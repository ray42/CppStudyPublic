#include"StrBlob16.h"
#include<iostream>
using std::cout; using std::ostream; using std::endl;

#include<algorithm>
using std::transform;

#include<iterator>
using std::ostream_iterator;

#include<string>
using std::string;

////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////

bool StrBlob::raydebug = false;

/////////////////////////////////////////////////////////////////////////////
//copy control

bool operator==(const StrBlob& lhs, const StrBlob& rhs)
{
  return *lhs.data_spt == *rhs.data_spt;
}

bool operator!=(const StrBlob& lhs, const StrBlob& rhs)
{
  return !(lhs==rhs);
}

/////////////////////////////////////////////////////////////////////////////
//copy control

// copy assignment op, needs valuelike behaviour.
StrBlob& StrBlob::operator=(const StrBlob& rhs)
{
  if(raydebug)
  {
    std::cout<<"Hi: "<<this<<", "<< __PRETTY_FUNCTION__ <<std::endl;
  }

  data_spt = make_shared<vector<string>>(*rhs.data_spt);
  return *this; // return this (the lhs)
}

// move assignment op, needs valuelike behaviour.
StrBlob& StrBlob::operator=(StrBlob&& rhs) noexcept
{
  if(raydebug)
  {
    std::cout<<"Hi: "<<this<<", "<< __PRETTY_FUNCTION__ <<std::endl;
  }

  if(this != &rhs)
  {
    data_spt = std::move(rhs.data_spt);
    rhs.data_spt = nullptr; // remember to leave rhs in a valid state.
  }

  return *this; // return the lhs (this).
}


////////////////////////////////////////////////////////////////////////////
// StrBlob members

// printing everything for checking and debugging.
ostream& StrBlob::printall(ostream& os) const
{
  os << "emp " << this->empty() << ", size " << this->size() << ": ";
  transform(data_spt->begin(),data_spt->end(),
            ostream_iterator<string>(os," "),
            [](const string& s)->string
            {return s;});
  return os;
}

// Check if i is in [0, size), if i >= size, throw error.
// No need to check negative, since size_type is unsigned
void StrBlob::check(size_type i, const std::string &msg) const
{
  if( i >= data_spt->size())
    throw std::out_of_range(msg);
}

// Removes the last element, the element at the back. We have to make sure
// that there is at least one element.
void StrBlob::pop_back()
{
  // How does this work? Well, check(i,msg) will throw an error 
  // if i >= size. Thus, if 0 >= size, then it must be that size == 0, since
  // size cannot be negative. If this is not true (i.e. there is at least 
  // one element in StrBlob), then we can safely continue.
  check(0,"pop_back on empty StrBlob");
  return data_spt->pop_back();
}

// access the first element.
string& StrBlob::front()
{
  if(raydebug)
  {
    std::cout<<"Hi: "<<this<<", "<< __PRETTY_FUNCTION__ <<std::endl;
  }

  check(0,"front on empty StrBlob");
  return data_spt->front();
}

// access the last element.
string& StrBlob::back()
{
  if(raydebug)
  {
    std::cout<<"Hi: "<<this<<", "<< __PRETTY_FUNCTION__ <<std::endl;
  }

  check(0,"back on empty StrBlob");
  return data_spt->back();
}

// access the first element.
const string& StrBlob::front() const
{
  if(raydebug)
  {
    std::cout<<"Hi: "<<this<<", "<< __PRETTY_FUNCTION__ <<std::endl;
  }

  check(0,"front on empty StrBlob");
  return data_spt->front();
}

// access the last element.
const string& StrBlob::back() const
{
  if(raydebug)
  {
    std::cout<<"Hi: "<<this<<", "<< __PRETTY_FUNCTION__ <<std::endl;
  }

  check(0,"back on empty StrBlob");
  return data_spt->back();
}

////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////

bool operator==(const StrBlobPtr& lhs, const StrBlobPtr& rhs)
{
  return lhs.curr == rhs.curr;
}

bool operator!=(const StrBlobPtr& lhs, const StrBlobPtr& rhs)
{
  return !(lhs == rhs);
}

bool operator==(const ConstStrBlobPtr& lhs, const ConstStrBlobPtr& rhs)
{
  return lhs.curr == rhs.curr;
}

bool operator!=(const ConstStrBlobPtr& lhs, const ConstStrBlobPtr& rhs)
{
  return !(lhs == rhs);
}

////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////


StrBlobPtr StrBlob::begin()
{
  return StrBlobPtr(*this);
}
StrBlobPtr StrBlob::end()
{
  return StrBlobPtr(*this, size());
}

ConstStrBlobPtr StrBlob::cbegin()
{
  return ConstStrBlobPtr(*this);
}
ConstStrBlobPtr StrBlob::cend()
{
  return ConstStrBlobPtr(*this, size());
}





