#include "ALUControl.h"


ALUControl::ALUControl()
{

}

void ALUControl::calculate()
{
	if(Opcode::getInstType(inALUOp) == RTYPE)
	{
		// ADD
		if(Opcode::getFunctField(inALUOp) == "100000")
		{
			outALUOperation = "ADD";
		}
		// SUB
		else if(Opcode::getFunctField(inALUOp) == "100010")
		{

			outALUOperation = "SUBTRACT"; 
		}
		//SLT
		else if(Opcode::getFunctField(inALUOp) == "101010")
		{
			outALUOperation = "LESSTHAN";
		}
	}
	// LW
	else if(Opcode::getOpcodeField(inALUOp)== "100011")
	{
		outALUOperation = "ADD";
	}
	// SW
	else if(Opcode::getOpcodeField(inALUOp)== "101011")
	{
		outALUOperation = "ADD";
	}
	//BEQ
	else if(Opcode::getOpcodeField(inALUOp)== "000100")
	{
		outALUOperation = "EQUAL";
	}
	// J
	else if(Opcode::getOpcodeField(inALUOp)== "000010")
	{
	}
	// ADDI
	else if(Opcode::getOpcodeField(inALUOp)== "001000")
	{
		outALUOperation = "ADD";
	}

} 
