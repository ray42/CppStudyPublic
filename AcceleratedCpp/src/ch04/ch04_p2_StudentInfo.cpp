#include<iostream> // std::cout std::endl std::cin
#include<string> // std::string
#include<vector> //std::vector
#include<stdexcept> // std::domain_error
#include<algorithm> // std::sort std::max
#include<iomanip> // std::setprecision
#include<ios> // std::streamsize
#include "median.h"


using std::cout; using std::endl; using std::cin;
using std::vector;
using std::string;
using std::istream;
using std::domain_error;
using std::sort; using std::max;
using std::setprecision;
using std::streamsize;


struct Student_info
{
  string name;
  double midterm, final;
  vector<double> homework;
}; // note the semicolon its required

bool compare(const Student_info& x, const Student_info& y)
{
  return x.name < y.name;
}

// compute the median of a vector<double>
// bite that calling this function copies the enter argument vector
// RRR: We are using call by value, where the arguments passed to the
// the median(...) function is copied into its parameter vec. 
// This is the correct thing to do since the function changes vec by sorting
// it with std::sort().
//double median(vector<double> vec)
//{
//  typedef vector<double>::size_type vec_sz;
//
//  vec_sz size = vec.size();
//  if(size == 0)
//  {
//    throw domain_error("median of an empty vector");
//  }
//
//  sort(vec.begin(),vec.end());
//
//  vec_sz mid = size/2;
//
//  return size%2==0?(vec[mid-1]+vec[mid])/2:vec[mid];
//}



// compute a student's overall grade from midterm and final grades
// and homework grade
double grade(const double& midterm, const double& final,
             const double& homework)
{
  return 0.2*midterm+0.4*final+0.4*homework;
}

// compute a student's overall grade from midterm and final exam grades
// and vector of homework grades.
// this function does not copy its arguments, because median does so for us.
double grade(const double& midterm, const double& final,
             const vector<double>& hw)
{
  if(hw.size()==0)
  {
    throw domain_error("student has done no homework");
  }
  return grade(midterm,final,median(hw));
}

double grade(const Student_info& s)
{
  return grade(s.midterm,s.final,s.homework);
}





// read homework grades from an input stream into a vector<double>
istream& read_hw(istream& in, vector<double>&hw)
{
  // if the input stream is already in an error state, we leave it alone.
  if(in)
  {
    // get id of previous content
    hw.clear();

    // read homework grades
    double x;
    while(in>>x)
    {
      hw.push_back(x);
    }

    // clear the stream so that input will work for the next student
    // since the while loop will only end if in is in an error state.
    in.clear();
  }
  return in;
}


istream& read(istream& is, Student_info& s)
{
  // read and store the student's name and midterm and final exam grades
  is >> s.name >> s.midterm >> s.final;

  // read and store all the student's homework grades
  read_hw(is,s.homework); 
  return is;
}



int main(int argc, char** argv)
{
  vector<Student_info> students;
  Student_info record;
  string::size_type maxlen = 0;

  cout << "Got into main" << endl;

  // read and store all the records, and find the length of the longest name
  while(read(cin,record))
  {
    maxlen = max(maxlen,record.name.size());
    students.push_back(record);
  }

  cout << "After while" << endl;
  // alphabetize the records
  sort(students.begin(),students.end(),compare);

  cout << "After sort" << endl;
  for(vector<Student_info>::size_type i = 0;
      i!= students.size(); ++i)
  {
    // write the name, passed on the right to maxlen+1 characters
    cout << students[i].name 
      << string(maxlen+1 - students[i].name.size(),' ');

    // compute and write the grade
    try{
      double final_grade = grade(students[i]);
      streamsize prec = cout.precision();
      cout << setprecision(3) << final_grade
        << setprecision(prec);
    }catch(domain_error e){
      cout << e.what();
    }
    cout << endl;
  }

  cout << "After output" << endl;
  return 0;
}
