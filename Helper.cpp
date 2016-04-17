#include "Helper.h"
using namespace std;


//given a number, convert to hexadecimal. If the number is negative, do two complements of length 32 binary
 //which is length 8 hexadecimal
string Helper::decToHex(int number)
{
	stringstream getHex;
    getHex << uppercase << hex << number;
    return getHex.str();
}

int Helper::decToHex(string hexRep)
{
	return 0;
}

//given a file name which contains two parameters in each line in the form "0xppp:0xqqq", breakdown into
//a map from "ppp" to "qqq"
map<string,string> Helper::readFileForInstruction(string filename)
{
	ifstream infile(filename.c_str());
	string line;
	map<string,string> instructionMap;

	while (std::getline(infile, line))
	{
	   int index = line.find(':');
	   string key = line.substr(0,index);
	   string data = line.substr(index,line.size()-1);
	   instructionMap[key] = data;
	}

	return instructionMap;
}

//given a file name which contains two parameters in each line in the form "[register number]:0xqqq", breakdown into
//a map from int registerNumber to "qqq"
map<int,string> Helper::readFileForRegister(string filename)
{
	ifstream infile(filename.c_str());
	string line;
	map<int,string> registerMap;

	while (std::getline(infile, line))
	{
	   int index = line.find(':');
	   int key = stoi(line.substr(0,index));
	   string data = line.substr(index,line.size()-1);
	   registerMap[key] = data;
	}

	return registerMap;
}
