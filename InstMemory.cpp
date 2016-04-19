#include "InstMemory.h"
#include <string>
#include <map>

using namespace std;

InstMemory::InstMemory()
{

}

InstMemory::InstMemory(map<string, Instruction> instructionList)
{

	myInstructionList = instructionList;
	
}

void InstMemory::calculate()
{
	outInstruction = myInstructionList[inAddress];
}

