#include<iostream> // std::cout, std::endl, std::cin std::istream
#include<string> // std::string
#include<algorithm> // std::sort
#include<vector> // std::vector
#include<stdexcept> // std::domain_error
#include<iomanip> // std::setprecision
#include<ios> //std::streamsize


using std::cout; using std::endl; using std::cin; using std::istream;
using std::string;
using std::sort;
using std::vector;
using std::domain_error;
using std::streamsize;
using std::setprecision; // Apparently this works without the <ios> header.

// Interesting read on 1) pass by value, 2) pass by reference and 
// 3) pass by const reference:
// http://stackoverflow.com/questions/5060137/passing-as-const-and-by-reference-worth-it


// compute a student's overall grade from midterm and final grades
// and homework grade
double grade(const double& midterm, const double& final,
             const double& homework)
{
  return 0.2*midterm+0.4*final+0.4*homework;
}


// compute the median of a vector<double>
// bite that calling this function copies the enter argument vector
// RRR: We are using call by value, where the arguments passed to the
// the median(...) function is copied into its parameter vec. 
// This is the correct thing to do since the function changes vec by sorting
// it with std::sort().
double median(vector<double> vec)
{
  typedef vector<double>::size_type vec_sz;

  vec_sz size = vec.size();
  if(size == 0)
  {
    throw domain_error("median of an empty vector");
  }

  sort(vec.begin(),vec.end());

  vec_sz mid = size/2;

  return size%2==0?(vec[mid-1]+vec[mid])/2:vec[mid];
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

int main(int argc, char **argv)
{
  // ask for and read the student's name
  cout << "Please enter your first name: ";
  string name;
  cin >> name;
  cout << "Hello, " << name << "!" << endl;

  // ask for and read the midterm and final grades
  cout << "Please enter your midterm and final exam grades: ";
  double midterm, final;
  cin >> midterm >> final;

  // ask for the homework grades
  cout << "Enter all your homework grades, "
          "followed by DOF: ";

  vector<double> homework;

  // read the homework grades
  read_hw(cin,homework);

  // compute and generate the final grade, if possible.
  try
  {
    double final_grade = grade(midterm,final,homework);
    streamsize prec = cout.precision();
    cout << "Your final grade is " << setprecision(3)
         << final_grade << setprecision(prec) << endl;
  }
  catch (domain_error)
  {
    cout << endl << "You must enter your grades. "
         "Please try again." << endl;
    return 1;
  }
  return 0;
}
