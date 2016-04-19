#include "DataMemory.h"
#include <string>
#include <map>

using namespace std;

DataMemory::DataMemory()
{

}

DataMemory::DataMemory(map<string, string> dataList)
{
	mydataList = dataList;
}

