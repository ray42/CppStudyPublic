/*
 * =========================================================================
 * Copyright (c) 2017, Raymon White - All Rights Reserved
 * Author:  Raymon White (ray), rayaxiom42 AT gmail DOT com
 * =========================================================================
 */
#include<iostream>
using std::cout; using std::endl;
#include<bitset>
using std::bitset;
#include<string>
using std::string;


// exer17-11
template<unsigned long NQ> // template the number of questions
class Quiz
{
public:

  bitset<NQ> answers;

  Quiz():answers(bitset<NQ>())
  {}

  Quiz(string ans):answers(bitset<NQ>(ans))
  {}

  // ex 17-12
  void set_ans(unsigned long i, bool val)
  {
    answers.set(i,val);
  }

  auto grade(bitset<NQ> correct_answers) -> decltype(answers.count())
  {
    //XOR shows that it outputs true whenever the inputs differ
    return (answers ^ correct_answers).flip().count();
//    return (answers & correct_answers).count();
  }

};


int main()
{
  Quiz<10> myquestions;
  cout << myquestions.answers << endl;
  myquestions.set_ans(1,true);
  cout << myquestions.answers << endl;

  string correctans="01010101";
  string myans="01010100";

  Quiz<8> myquizz(myans);
  bitset<8> correctansbs(correctans);
  cout << myquizz.grade(correctansbs) << endl;


  return 0;
}

