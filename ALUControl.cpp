#include "ALUControl.h"


ALUControl::ALUControl()
{

}

void ALUControl::calculate()
{
	if(inALUOp == "RYPE")
	{
		if(inFunctField == "100000")
		{
			outALUOperation = "ADD";
		}
		else if((inFunctField == "100010")
		{

			outALUOperation = "SUBTRACT"; 
		}
	}
	else if(inALUOp == "SLT")
	{
		outALUOperation = "LESSTHAN";
	}
	else if(inALUOp == "LW")
	{
		outALUOperation = "ADD";
	}
	else if(inALUOp == "SW")
	{
		outALUOperation = "ADD";
	}
	else if(inALUOp == "BEQ")
	{
		outALUOperation = "EQUAL";
	}
	else if(inALUOp == "J")
	{
	}
	else if(inALUOp == "ADDI")
	{
		outALUOperation = "ADD";
	}

} 
