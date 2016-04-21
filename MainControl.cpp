#include "MainControl.h"
#include <iostream>

using namespace std;

MainControl::MainControl(){

};

MainControl::calculate()
{
  bool outRegDst; 
  bool outJump;
  bool outBranch;
  bool outMemRead;
  bool outMemtoReg; //to multiplexor
  Opcode outALUOp; //special one. See note above
  bool outMemWrite;
  bool outALUSrc; //to multiplexor
  bool outRegWrite;
};
	if (inOpcode.getInstType() == RTYPE)
	{
		outRegDst = true;
		outJump = false;
		outBranch = false;
		outMemRead = false;
		outMemtoReg = false
		outAluOp = inOpcode;
		outMemWrite = 0;
		outALUSrc = false;
		outRegWrite = true;

	} else if (inOpcode.getOpcode() == LW) {

		outRegDst = false;
		outJump = false;
		outBranch = false;
		outMemRead = true;
		outMemtoReg = true;
		outAluOp = inOpcode;
		outMemWrite = false;
		outALUSrc = true;
		outRegWrite = true;
		
	} else if (inOpcode.getOpcode() == SW) {

		outRegDst = false;
		outJump = false;
		outBranch = false;
		outMemRead = false;
		outMemtoReg = false;
		outAluOp = inOpcode;
		outMemWrite = true;
		outALUSrc = true;
		outRegWrite = false;

	} else if (inOpcode.getOpcode() == BEQ) {

		outRegDst = false;
		outJump = false;
		outBranch = true;
		outMemRead = false;
		outMemtoReg = false;
		outAluOp = inOpcode;
		outMemWrite = false;
		outALUSrc = false;
		outRegWrite = false;

	} else if (inOpcode.getOpcode() == J) {

		outRegDst = false;
		outJump = true;
		outBranch = false;
		outMemRead = false;
		outMemtoReg = false;
		outAluOp = inOpcode;
		outMemWrite = false;
		outALUSrc = false;
		outRegWrite = false;

	}

};