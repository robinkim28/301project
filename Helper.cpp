#include "Helper.h"

using namespace std;


//given a number, convert to hexadecimal. If the number is negative, do two complements of length 32 binary
 //which is length 8 hexadecimal
string Helper::decToHex(int number)
{
	stringstream getHex;
    getHex << showbase << hex << number;
    return getHex.str();
}

int Helper::hexToDec(string hexRep)
{
	stringstream getHex;
    getHex << dec << stoi(hexRep,NULL,16); //see std::stoi, stoi converts hexRep string to integer hex
    return stoi(getHex.str()); //std::stoi default base is 10
}

map<string, Instruction>  Helper::readFileForInstruction(string filename)
{
	map<string,Instruction> instructionMap;
	ASMParser *parser = new ASMParser(filename);
	string index = "0x400000";

  	if(parser->isFormatCorrect() == false)
  	{

    	cerr << "Format of input file is incorrect " << endl;
    	exit(1);

  	}

  	Instruction i;

  	//Iterate through instructions, printing each encoding.
  	i = parser->getNextInstruction();

  	while( i.getOpcode() != UNDEFINED)
  	{
    	instructionMap[index]=i;
    	//cout << index << " " << i.getEncoding() << endl;
    	stringstream updateIndex;
    	updateIndex << showbase << hex << (stoi(index,NULL,16) + stoi("0x4",NULL,16));
    	index = updateIndex.str();
    	i = parser->getNextInstruction();
  	}
  
  	delete parser;

	return instructionMap;
}

//given a file name which contains two parameters in each line in the form "0xppp:0xqqq", breakdown into
//a map from "ppp" to "qqq"
map<string,string> Helper::readFileForDataMemory(string filename)
{
	ifstream infile(filename.c_str());
	string line;
	map<string,string> memoryMap;

	while (getline(infile, line))
	{
	   int index = line.find(':');
	   string key = line.substr(0,index);
	   string data = line.substr(index,line.size()-1);
	   cout << key << data << endl;
	   memoryMap[key] = data;
	}

	return memoryMap;
}

//given a file name which contains two parameters in each line in the form "[register number]:0xqqq", breakdown into
//a map from int registerNumber to "qqq"
map<int,string> Helper::readFileForRegister(string filename)
{
	ifstream infile(filename.c_str());
	string line;
	RegisterTable registers;
	map<Register,string> registerMap;

	while (getline(infile, line))
	{
	   int index = line.find(':');
	   string key = line.substr(0,index);
	   string data = line.substr(index,line.size()-1);
	   Register reg = registers.getNum("$"+key);
	   //cout << reg << data << endl;
	   registerMap[reg] = data;
	}

	return registerMap;
}


