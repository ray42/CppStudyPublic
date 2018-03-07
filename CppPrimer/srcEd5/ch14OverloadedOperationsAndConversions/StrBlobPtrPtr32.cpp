#include"StrBlobPtrPtr32.h" // change this!

StrBlobPtr& StrBlobPtrPtr::operator*() const
{
  return *sbp;
}

StrBlobPtr& StrBlobPtrPtr::operator->() const
{
  return *sbp;
}
