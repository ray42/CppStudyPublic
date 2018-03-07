#ifndef STRBLOBPTRPTR_H
#define STRBLOBPTRPTR_H

#include"../common/cpp_primer_common.h"
#include"../common/rr.h"
#include"StrBlob30.h" // change this.

class StrBlobPtrPtr
{
public:
  StrBlobPtrPtr() = default;

  StrBlobPtrPtr(StrBlobPtr* p)
    : sbp(p)
  {}

  StrBlobPtr& operator*() const;
  // Here we are returning the object! This is because StrBlobPtr defines
  // the operator-> function.
  StrBlobPtr& operator->() const;

private:
  StrBlobPtr* sbp = nullptr;
};

#endif
