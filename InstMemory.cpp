#include "InstMemory.h"
#include <string>
#include <map>

using namespace std;

InstMemory::InstMemory()
{
	startIndex = "0x400000";
}

InstMemory::InstMemory(map<string, Instruction> instructionList)
{

	myInstructionList = instructionList;
	startIndex = "0x400000";

}

void InstMemory::calculate()
{
	outInstruction = myInstructionList[inAddress];
}

void InstMemory::printMemoryContent()
{

	for (int i = 0; i < myInstructionList.size()*4; i =i+4)
	{
		cout << Helper::decToHex(Helper::hexToDec(startIndex) + i,6) << ":" << myInstructionList[Helper::decToHex(Helper::hexToDec(startIndex) + i,6)].getEncoding() << endl;
	}

}
