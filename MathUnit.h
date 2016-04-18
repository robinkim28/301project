#ifndef __MATHUNIT_H__
#define __MATHUNIT_H__

#include "Helper.h"
#include <string>
/* This class creates any unit that can compute a mathematical function given two inputs, and will output
	one number. The operation it does is determined by its control
 */

class MathUnit
{
 public:
	//create the math unit with the control initially set to "0"
  MathUnit();

  //with the current 2 inputs and control, do the operation and put result into the output. This does not change input or control
  //the control determines the operation, so the algorithms is a lot of cases (many if-else checking control value)
  void calculate();

  // bunch of setter method
  void setInNumber1(string num){inNumber1 = num;}
  void setInNumber2(string num){inNumber2 = num;} 
  void setControl(bool controlVal){control = controlVal;}
  
  // bunch of getter method
  string getOutNumber(){return outNumber;} 

 private:
  //input
  string inNumber1; //in hex form, e.g. "0000001a" = 16+10= register 26. Note that there's two complement: "ffffffff" is -1, for example
  string inNumber2;
  //control as a string. Note: this needs to be decided for the form it should be. 
  //It can be string, e.g. "ADD", "SUB", "0", "1", or list of 0,1 like "0010" as in the book
  string control;
  //output
  string outNumber;
};

#endif
