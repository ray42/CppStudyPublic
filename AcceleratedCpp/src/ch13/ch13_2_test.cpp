#include<iostream>
#include<vector>
#include<string>
#include<sstream>

#include "average.h"
#include "median.h"
#include "grade.h"

#include "./../rayheader.h"

#include "Core.h"
#include "Grad.h"
#include "High.h"

#include "common_headers.h"

using std::cout; using std::endl; using std::cin;
using std::vector;
using std::string;
using std::istringstream;

// Testing which functions the compiler would use. This one uses Core, Core.
void testout(const Core& c1, const Core& c2)
{
  cout << "Core, Core" << endl;
}

// Testing which functions the compiler would use. This one uses Core, Grad.
void testout(const Core& c1, const Grad& g1)
{
  cout << "Core, Grad" << endl;
}

int main(int argc, char** argv)
{
  // Testing average.h and median.h
  vector<double> vec1 = {1,2,3,4,5,6};
  vector<double> vec2 = {6,2,3,4,5,6};
  vector<double> vec3 = {6,6,3,4,5,6};

  cout << "vec1: " << ray::print_vec(vec1) << endl;
  cout << "vec2: " << ray::print_vec(vec2) << endl;
  cout << "vec3: " << ray::print_vec(vec3) <<"\n"<< endl;

  cout << "avg1: " << average(vec1) << endl;
  cout << "avg2: " << average(vec2) << endl;
  cout << "avg3: " << average(vec3) <<"\n"<< endl;
  
  cout << "med1: " << median(vec1) << endl;
  cout << "med2: " << median(vec2) << endl;
  cout << "med3: " << median(vec3) <<"\n"<<endl;

  cout << "avggrade1: " << average_grade(2,3,vec1) << endl;
  cout << "avggrade2: " << average_grade(4,5,vec2) << endl;
  cout << "avggrade3: " << average_grade(6,7,vec3) <<"\n"<< endl;

  cout << "medgrade1: " << median_grade(2,3,vec1) << endl;
  cout << "medgrade2: " << median_grade(4,5,vec2) << endl;
  cout << "medgrade3: " << median_grade(6,7,vec3) <<"\n"<< endl;

  //////////////////////////////////////////////////////////////////////////
  // Testing constructors for Core and Grad
  //////////////////////////////////////////////////////////////////////////
  
  // Core default constructor
  Core c1;
  cout << c1.to_string() << "\n" << endl;

  // Core stream constructor
  string str = "Q 2 3 1 2 3 4 5 6";
  istringstream iss;
  iss.str(str);
  Core c2(iss);
  cout << "c2 str: " << c2.to_string() << endl;

  // Core grade function
  cout << "c2 grade: " << c2.grade() << "\n"<< endl;

  /////////////////////////////
  //grad default constructor
  Grad grad1;
  cout << "g1 str: " << grad1.to_string() << "\n"<< endl;

  // grad stream constructor
  str = "W 2 3 4 1 2 3 4 5 6";
  iss.str(str);
  Grad g2(iss);
  cout << "g2 str: " << g2.to_string() << endl;

  // grad grade function
  cout << "g2 grade: " << g2.grade() << "\n"<< endl;

  //////////////////////////////////////////////////////////////////////////
  
  // Testing compare function (defined above, not in the objects)

  // Recall that:
  //      core: name, midterm, final,         homework....
  //      grad: name, midterm, final, thesis, homework....
  str="A 1 2 3 4 5";
  iss.str(str);
  Grad g3(iss);

  str="C 1 2 3 4 5";
  iss.str(str);
  Grad g4(iss);

  str="B 1 2 3 4 5";
  iss.str(str);
  Core c3(iss);

  str="D 1 2 3 4 5";
  iss.str(str);
  Core c4(iss);
   
  cout << "compare_names(g3,g4): " << compare_names(g3,g4) << endl;
  cout << "compare_names(c3,c4): " << compare_names(c3,c4) << endl;
  cout << "compare_names(c3,g3): " << compare_names(g3,c3) << endl;
  cout << "\n";

  cout << "compare_grades(c3,g3): " << compare_grades(c3,g3) << endl;
  
  testout(c3,c3);
  testout(c3,g3);
  testout(g3,c3);
  testout(g3,g3);


  cout << "\n" << endl;
  cout << "Testing new dynamic binding" << endl;
  str="D 1 2 3 4 5 6 7";
  iss.str(str);

  High h1(iss);

  cout << h1.to_string() << endl;

  Core& t1 = h1;
  Grad& t2 = h1;
  High& t3 = h1;

  // Seems like it always uses the most derived type.
  t1.grade();
  t2.grade();
  t3.grade();

  cout << "\nGot to end of prog" << endl;

  return 0;
}
