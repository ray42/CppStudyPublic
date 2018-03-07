#ifndef PIC_HEADER_H
#define PIC_HEADER_H

#include<vector>
#include<string>
#include<iostream>
#include<ostream>

#include "Ptr.h"

// forward declaration
class Picture;


// * Pic_base begin
// String_Pic: public Pic_base
// Frame_Pic : public Pic_base
// VCat_Pic : public Pic_base
// HCat_Pic : public Pic_base
// Picture
// Picture associated operations
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////

// private classes for use in the implementation only
class Pic_base 
{
  friend std::ostream& operator<<(std::ostream&, const Picture&);
  friend class Frame_Pic;
  friend class HCat_Pic;
  friend class VCat_Pic;
  friend class String_Pic;

  // no public interface. By default, the visibility is private
  
  // height is the size of the vector containing the strings.
  typedef std::vector<std::string>::size_type ht_sz;

  // width is the size of the string.
  typedef std::string::size_type wd_sz;

  // This is an abstract class, no implementation
  virtual wd_sz width() const = 0;
  virtual ht_sz height() const = 0;
  virtual void display(std::ostream&, ht_sz, bool) const = 0;

protected:
  static void pad(std::ostream&, wd_sz, wd_sz);
};


////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////

void Pic_base::pad(std::ostream& os, 
                   Pic_base::wd_sz beg, Pic_base::wd_sz end)
{
  while(beg != end)
  {
    os << "@";
    ++beg;
  }
}


// * Pic_base END
// * String_Pic: public Pic_base BEGIN
// Frame_Pic : public Pic_base
// VCat_Pic : public Pic_base
// HCat_Pic : public Pic_base
// Picture
// Picture associated operations
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
class String_Pic : public Pic_base
{
  friend class Picture;

  std::vector<std::string> data;
  String_Pic(const std::vector<std::string>& v):data(v){}

  // To determine the width of a String_Pic, we need to look at each element
  // in data to see which is the longest.
  wd_sz width() const;

  // This makes sense, since each data is a vector of strings.
  ht_sz height() const;

  void display(std::ostream&, ht_sz, bool) const;
};

////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////


Pic_base::wd_sz String_Pic::width() const
{
  Pic_base::wd_sz n = 0;

  // Loop through the strings in data and find the longest string
  for(Pic_base::ht_sz i = 0; i != data.size(); ++i)
  {
    n = std::max(n,data[i].size());
  }

  return n;
}

Pic_base::ht_sz String_Pic::height() const
{
  return data.size();
}

void String_Pic::display(std::ostream& os, 
                         Pic_base::ht_sz row, bool do_pad) const
{
  // Where to start the padding.
  wd_sz start = 0;

  // write the row if we're still in range
  if (row < height()){
    os << data[row];
    start = data[row].size();
  }

  // pad the output if necessary
  if(do_pad)
    pad(os,start,width());
}



// Pic_base
// * String_Pic: public Pic_base END
// * Frame_Pic : public Pic_base BEGIN
// VCat_Pic : public Pic_base
// HCat_Pic : public Pic_base
// Picture
// Picture associated operations
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////

class Frame_Pic : public Pic_base
{
  // no public interface (managed by Picture)

  friend Picture frame(const Picture&);

  Ptr<Pic_base> p;

  Frame_Pic(const Ptr<Pic_base>&pic):p(pic){}

  wd_sz width() const;
  ht_sz height() const;
  void display(std::ostream&, ht_sz, bool) const;
};

////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////

Pic_base::wd_sz Frame_Pic::width() const
{
  return p->width()+4;
}

Pic_base::ht_sz Frame_Pic::height() const
{
  return p->height()+4;
}

void Frame_Pic::display(std::ostream& os, 
                        Pic_base::ht_sz row, bool do_pad) const
{
  if(row >= height())
  {
    // out of range
    if(do_pad)
    {
      pad(os,0,width());
    }
    else
    {
      if(row==0 || row==height()-1)
      {
        // top or bottom row
        os << std::string(width(), '*');
      }
      else if(row == 1 || row == height() - 2)
      {
        // second from top or bottom row
        os << "*";
        pad(os, 1, width() - 1);
        os << "*";
      }
      else
      {
        // interior row
        os << "* ";
        p->display(os, row - 2, true);
        os << " *";
      }
    }
  }

}





// Pic_base
// String_Pic: public Pic_base
// * Frame_Pic : public Pic_base END
// * VCat_Pic : public Pic_base BEGIN
// HCat_Pic : public Pic_base
// Picture
// Picture associated operations
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////

class VCat_Pic: public Pic_base
{
  friend Picture vcat(const Picture&, const Picture&);

  Ptr<Pic_base> top, bottom;
  VCat_Pic(const Ptr<Pic_base>& t, const Ptr<Pic_base>& b):
    top(t),bottom(b)
  {}

  wd_sz width() const;
  ht_sz height() const;
  void display(std::ostream&, ht_sz, bool) const;
};


////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////

// The width (max length) of vertically concatenated pictures.
// It makes sense that it's the largest of the two sub pics, since they're
// stacked on top of each other
Pic_base::wd_sz VCat_Pic::width() const
{
  return std::max(top->width(), bottom->width());
}

// The height of two pictures stacked on top of each other is the sum of
// both the heights.
Pic_base::ht_sz VCat_Pic::height() const
{
  return top->height() + bottom->height();
}

void VCat_Pic::display(std::ostream& os, 
                       Pic_base::ht_sz row, bool do_pad) const
{
  // contain the width of the current row, in case we need it for padding
  Pic_base::wd_sz w = 0;

  // check whether we're in the top component, by testing row against the 
  // height of the TOP picture. If we're in range, then we invoke display
  // to write the top component, passing the bool that we were given to
  // indicate whether to pad the output.
  if(row < top->height())
  {
    // we are in the top subpicture

    // Remember that display is virtual, so this call will invoke whatever
    // he appropriate display function is for this kind of Pic_base
    // to which top actually refers.
    top->display(os,row,do_pad);

    // Once we've written the given row, we remember its width in w.
    w = top->width();
  }
  // if we're not in top, we might be in bottom. If we get to this else test,
  // then we know that row is greater than top->height(), so we check 
  // whether row is within the overall range of this picture.
  else if(row < height())
  {
    // we are in the bottom subpicture

    // offset the row number to adjust for having already written as many 
    // rows as are in top.
    bottom->display(os,row - top->height(),do_pad);
    w = bottom->width();
  }

  // note that if row is out of range (i.e. > height()), then w remains 0.
  // When we're done writing the row, we check whether padding is needed. 
  // If so, we pad from the width that we remembered in w to the full width
  // of our own picture.
  if(do_pad)
    pad(os,w,width());
}

// Pic_base
// String_Pic: public Pic_base
// Frame_Pic : public Pic_base
// * VCat_Pic : public Pic_base END
// * HCat_Pic : public Pic_base BEGIN
// Picture
// Picture associated operations
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////

class HCat_Pic: public Pic_base
{
  friend Picture hcat(const Picture&, const Picture&);

  Ptr<Pic_base> left, right;

  HCat_Pic(const Ptr<Pic_base>& l, const Ptr<Pic_base>&r):
    left(l),right(r)
  {}

  wd_sz width() const;
  ht_sz height() const;
  void display(std::ostream&, ht_sz, bool) const;
};

////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////

// We're concatenating two pictures size by size. The width is the sum of
// the components width.
Pic_base::wd_sz HCat_Pic::width() const
{
  return left->width()+right->width();
}

// We're concatenating two pictures size by size. The height is the greater
// of the two heights.
Pic_base::ht_sz HCat_Pic::height() const
{
  return std::max(left->height(),right->height());
}

// The display function is simpler than the corresponding one from VCat_Pic,
// because we delegate managing whether the row is in range to the 
// component pictures:
void HCat_Pic::display(std::ostream& os, 
                       Pic_base::ht_sz row, bool do_pad) const
{
  // First we write the requested row from the left by calling display,
  // asking to write the given row.
  //
  // We pad this row if we were asked to pad our own output, OR if we're on 
  // a row that is within the (HEIGHT) range of the right-hand picture (in 
  // which case we must pad each row of the left-hand picture to ensure that
  // the corresponding row of the right-hand picture begins at the right 
  // place in the output line).
  //
  // If the row is out of range for left , then the display function 
  // executed on left will deal with that problem.
  left->display(os, row, do_pad || row < right->height());

  // Similarly, we delegate writing the requested row from right to the
  // display function on right. This time we pass along the do_pad value 
  // that we were given, because there is no reason to force padding on the 
  // right-hand side.
  right->display(os,row,do_pad);
}


// Pic_base
// String_Pic: public Pic_base
// Frame_Pic : public Pic_base
// VCat_Pic : public Pic_base
// * HCat_Pic : public Pic_base END
// * Picture BEGIN
// Picture associated operations
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////

// public interface class and operations
class Picture 
{
  friend std::ostream& operator<<(std::ostream&, const Picture&);
  friend Picture frame(const Picture&);
  friend Picture hcat(const Picture&, const Picture&);
  friend Picture vcat(const Picture&, const Picture&);

  public:
    Picture(const std::vector<std::string>& v =
            std::vector<std::string>() ):p(new String_Pic(v)){}

    // Constructor which takes a Pic_base*
    Picture(Pic_base* ptr):p(ptr){}

  private:
    Ptr<Pic_base> p;
};

////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////


// Pic_base
// String_Pic: public Pic_base
// Frame_Pic : public Pic_base
// VCat_Pic : public Pic_base
// HCat_Pic : public Pic_base
// * Picture END
// * Picture associated operations BEGIN
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////

Picture frame(const Picture&);
Picture hcat(const Picture&, const Picture&);
Picture vcat(const Picture&, const Picture&);

// remember to make this a friend in the Picture class
// Actually, it may not be required to make this a friend
// If we declared a global operator>>(), then this would need to be a 
// friend of Picture, since we might be changing the members of Picture.
std::ostream& operator<<(std::ostream&, const Picture&);

////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////


/// Implementation
Picture frame(const Picture& pic)
{
  // 1) We're using pointers now? I thought the whole point of Ptr<T> is so 
  // that we never have to invoke new and delete...
  //
  // 2) Note that pic.p is a Ptr<Pic_base>
  //
  // 3) and yes, the Frame_Pic constructor takes a const Ptr<Pic_base>&
  // All Frame_Pic does is copy the Ptr<Pic_base> as its private member p.
  //Pic_base* ret = new Frame_Pic(pic.p);
  
  // What do we return?
  // we have added a constructor to Picture which takes Pic_base*
  // Thus, we can return a new Frame_pic directly, and we comment out
  // the above code.
  //
  // The one line below has the same effect as:
  //
  // //create the new Frame_Pic
  // Pic_base* temp1 = new Frame_Pic(pic.p);
  //
  // // construct a Picture from a Pic_base*
  // Picture temp2(temp1);
  //
  // return the Picture, which will invoke the Picture copy constructor
  // return temp2;

  return new Frame_Pic(pic.p);
}

Picture hcat(const Picture& l, const Picture& r)
{
  return new HCat_Pic(l.p,r.p);
}

Picture vcat(const Picture& t, const Picture& b)
{
  return new VCat_Pic(t.p,b.p);
}

std::ostream& operator<<(std::ostream& os, const Picture& picture)
{
  const Pic_base::ht_sz ht = picture.p->height();

  for(Pic_base::ht_sz i=0; i != ht; ++i)
  {
    // recall that i refers to the row to print, and the bool refers to the 
    // padding.
    picture.p->display(os,i,false);
  }
}

#endif
