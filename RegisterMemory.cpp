#include "RegisterMemory.h"
#include <map>

RegisterMemory::RegisterMemory(map<int,string> registerList)
{

	myregisterList = registerList;
}

void RegisterMemory::read()
{
	outReadData1 = myregisterList[Helper::hexToDec(inReadRegister1)];
	outReadData2 = myregisterList[Helper::hexToDec(inReadRegister2)];
}

void RegisterMemory::write()
{
	if(conRegWrite == true)
	{
		myregisterList[Helper::hexToDec(inWriteRegister)] = inWriteData;		
	}
	else
	{
		// do nothing
	}
}

