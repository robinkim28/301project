#ifndef __MAINCONTROL_H__
#define __MAINCONTROL_H__

#include "Helper.h"
#include <string>
#include <vector>
/* This class creates an instance of the main control unit
 */

class MainControl
{
 public:
	//create the control unit
  MainControl();
  //Given an input, calculate all output.
  //Note: if some output does not matter, then it should not change that output datafield
  //If it matters, then change it (to 0,1 or string for ALUOp line)
  void calculate();

  // bunch of setter method
  //please add more here
  
  // bunch of getter method
  //please add more here

 private:
  //input
  string inOpcode; //in binary form of length 6, e.g. "000000" is R type, or "010001"
  //output
  //All string output will be "RTYPE" for ALU, or if it is not, the name of operation in uppercase, e.g. "B", "LW", "ADDI", etc.
  //The motivation for this is that ALU control will receive this, and able to figure out exactly later 
  //what ALU operation should be.
  //For output sending signal to a multiplexor, string output control line will be "0" or "1"
  string outRegDst; //to multiplexor, so it is string as "0" or "1"
  string outJump;
  bool outBranch;
  bool outMemRead;
  string outMemtoReg; //to multiplexor
  string outALUOp; //special one. See note above
  bool outMemWrite;
  string outALUSrc; //to multiplexor
  bool outRegWrite;
};

#endif