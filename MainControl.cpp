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
		outMem
				outAluOp = inOpcode;
		outALUSrc = false;
	}

};