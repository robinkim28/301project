#ifndef __ALUCONTROL_H__
#define __ALUCONTROL_H__

#include "Helper.h"
#include <string>
#include <vector>
/* This class creates an instance of the ALU control unit
 */

class MainControl
{
 public:
	//create the control unit
  MainControl();
  //Given an input, calculate all output.
  //This means given a control from Main Control Unit, and function field (bit 5 - 0 of instruction)
  //find an appropriate ALU math operation
  void calculate();

  // bunch of setter method
  void setInFunctField(string functField);
  void setInALUOp(string ALUOp);
  
  // bunch of getter method
  string getOutALUOperation();

 private:
  //input
  string inFunctField; //in binary form of length 6, e.g. "001100", "000000"
  string inALUOp; //as "RTYPE" or instruction, e.g. "ADD", "SUB", etc. See Main Control Class for more information
  //output
  string outALUOperation; //for ALU unit, so it is "0","1","SUB","ADD","EQUAL"
};

#endif