#include "InstMemory.h"
#include <string>
#include <map>

using namespace std;

InstMemory::InstMemory()
{

}

InstMemory::InstMemory(map<string, string> instructionList)
{
	inAddress = "";
	outInstruction = "";
	myInstructionList = instructionList;
}

void InstMemory::calculate()
{
	outInstruction = myInstructionList[inAddress];
}

