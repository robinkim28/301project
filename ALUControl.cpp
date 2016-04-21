#include "ALUControl.h"
#include "Opcode.h"

ALUControl::ALUControl()
{

}
void ALUControl::printAll()
{
	cout << "ALUControl Unit: " <<endl;
	cout << "Input Type: " << opcodes.getInstType(inALUOp) << endl;
	cout << "Input Inst: " << opcodes.getName(inALUOp) <<endl;
	cout << "Output Inst: " << outALUOperation << endl;

}
void ALUControl::calculate()
{

	if(opcodes.getInstType(inALUOp) == RTYPE)
	{
		// ADD
		if(opcodes.getFunctField(inALUOp) == "100000")
		{
			outALUOperation = "ADD";
		}
		// SUB
		else if(opcodes.getFunctField(inALUOp) == "100010")
		{

			outALUOperation = "SUB"; 
		}
		//SLT
		else if(opcodes.getFunctField(inALUOp) == "101010")
		{
			outALUOperation = "LESSTHAN";
		}
	}
	// LW
	else if(opcodes.getOpcodeField(inALUOp)== "100011")
	{
		outALUOperation = "ADD";
	}
	// SW
	else if(opcodes.getOpcodeField(inALUOp)== "101011")
	{
		outALUOperation = "ADD";
	}
	//BEQ
	else if(opcodes.getOpcodeField(inALUOp)== "000100")
	{
		outALUOperation = "EQUAL";
	}
	// J
	else if(opcodes.getOpcodeField(inALUOp)== "000010")
	{
	}
	// ADDI
	else if(opcodes.getOpcodeField(inALUOp)== "001000")
	{
		outALUOperation = "ADD";
	}
	cout <<"outALUOp: " <<outALUOperation << endl;
} 
