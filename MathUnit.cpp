#include "MathUnit.h"
#include "Helper.h"
#include <sstream>

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
		long sum = num1 + num2;
		if (sum > 2147483647 || sum < -2147483647)
		{
			cerr << "overflow" << endl;
		}
		outNumber = Helper::decToHex((int)sum);
		
	}
	else if(control == "SUB")
	{
		int num1 = Helper::hexToDec(inNumber1);
		int num2 = Helper::hexToDec(inNumber2);
		long sum = num1 - num2;
		if (sum > 2147483647 || sum < -2147483647)
		{
			cerr << "overflow" << endl;
		}
		outNumber = Helper::decToHex((int)sum);
	}
	else if(control == "EQUAL")
	{	
		int num1 = Helper::hexToDec(inNumber1);
		int num2 = Helper::hexToDec(inNumber2);
		if (num1 != num2)
		{
			outNumber = "1"; 
		}
		else
		{
			outNumber = "0";
		}

	}
	else if (control == "LESSTHAN")
	{
		int num1 = Helper::hexToDec(inNumber1);
		int num2 = Helper::hexToDec(inNumber2);
		if(num1 < num2)
		{

			outNumber = "1";
		}
		else
		{
			outNumber ="0";
		}
	}
	else if (control == "SL2")
	{
		int num1 = Helper::hexToDec(inNumber1);
		int newNum = num1 * 4;
		outNumber = Helper::decToHex(newNum);
		// did not check for length because it does not matter when dealing with signextention or memory address calculation	

	}
	else if (control == "SIGNEXTEND")
	{
 		int num1 = Helper::hexToDec(inNumber1);
		stringstream ss;
		if(num1 <0)
		{
			ss << "ffff" << inNumber1;
			outNumber = ss.str();
		}
		else
		{
			ss << "0000" << inNumber1;
			outNumber = ss.str();

		}
	}
}
