#include "MainControl.h"
#include <iostream>

using namespace std;

MainControl::MainControl(){

};

void MainControl::calculate(){
	OpcodeTable opcodeTable;
	if (opcodeTable.getInstType(inOpcode) == RTYPE)
	{
		outRegDst = true;
		outJump = false;
		outBranch = false;
		outMemRead = false;
		outMemtoReg = false;
		outALUOp = inOpcode;
		outMemWrite = 0;
		outALUSrc = false;
		outRegWrite = true;

	} else if (inOpcode == LW) {

		outRegDst = false;
		outJump = false;
		outBranch = false;
		outMemRead = true;
		outMemtoReg = true;
		outALUOp = inOpcode;
		outMemWrite = false;
		outALUSrc = true;
		outRegWrite = true;

	} else if (inOpcode == SW) {

		outRegDst = false;
		outJump = false;
		outBranch = false;
		outMemRead = false;
		outMemtoReg = false;
		outALUOp = inOpcode;
		outMemWrite = true;
		outALUSrc = true;
		outRegWrite = false;

	} else if (inOpcode == BEQ) {

		outRegDst = false;
		outJump = false;
		outBranch = true;
		outMemRead = false;
		outMemtoReg = false;
		outALUOp = inOpcode;
		outMemWrite = false;
		outALUSrc = false;
		outRegWrite = false;

	} else if (inOpcode == J) {

		outRegDst = false;
		outJump = true;
		outBranch = false;
		outMemRead = false;
		outMemtoReg = false;
		outALUOp = inOpcode;
		outMemWrite = false;
		outALUSrc = false;
		outRegWrite = false;

	}

};