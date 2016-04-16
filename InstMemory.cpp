#include "InstMemory.h"


using namespace std;

InstMemory::InstMemory()
{
	inAddress = "";
	outInstruction = "";
	myInstructionList;
}

InstMemory::InstMemory(map<string, string> instructionList)
{
	inAddress = "";
	outInstruction = "";
	myInstructionList = instructionList;
}

void InstMemory::calculate()
{

}


