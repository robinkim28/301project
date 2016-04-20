#include "MathUnit.h"
#include "Helper.h"

MathUnit::MathUnit()
{
	control = "0";
}

MathUnit::MathUnit(vector<string> listOperation)
{
	vector<string> listOperationAllowed = listOperation;
}

void MathUnit::calculate()
{


	if(control == "0")	//multiplexor function
	{
		outNumber = inNumber1;

	}	
	else if(control == "1")	//multiplexor function
	{
		outNumber = inNumber2;
	}
	else if(control  == "ADD")	// add ALU
	{
		int num1 = Helper::hexToDec(inNumber1);
		int num2 = Helper::hexToDec(inNumber2);
		int sum = num1 + num2;
		outNumber = Helper::decToHex(sum);
	}
	else if(control == "SUB")
	{
		int num1 = Helper::hexToDec(inNumber1);
		int num2 = Helper::hexToDec(inNumber2);
		int sum = num1 - num2;
		outNumber = Helper::decToHex(sum);
	}
	else if(control == "EQUAL")
	{	
		int num1 = Helper::hexToDec(inNumber1);
		int num2 = Helper::hexToDec(inNumber2);
		if (num1 != num2)
		{
			outNumber = "1"; // - equal but why 1 if x1> x2 in .h file?
		}
		else
		{
			outNumber = "0";
		}

	}
}
