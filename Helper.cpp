#include "Helper.h"

using namespace std;


//given a number, convert to hexadecimal. If the number is negative, do two complements of length 32 binary
 //which is length 8 hexadecimal
string Helper::decToHex(int number, int length)
{
	stringstream getHex;
	if (length == -1)
	{
		getHex << "0x" << setfill('0') << setw(8) << hex << number;
	} else {
    	getHex << "0x" << setfill('0') << setw(length) << hex << number;
	}
    return getHex.str();
}

int Helper::hexToDec(string hexRep)
{
	stringstream getHex;
    getHex << dec << stol(hexRep,NULL,16); //see std::stoi, stoi converts hexRep string to integer hex
    return stol(getHex.str()); //std::stoi default base is 10
}
string Helper::hexToBinary(string hexrep)
{
	stringstream ss;
    ss << hex << s;
    unsigned n;
    ss >> n;
    bitset<g_unMaxBits> b(n);

    unsigned x = 0;
    if (boost::starts_with(s, "0x") || boost::starts_with(s, "0X")) x = 2;
    return b.to_string().substr(32 - 4*(s.length()-x));

}
string Helper::boolToStr(bool val)
{
	if (val == true)
	{
		return "1";
	}
	else
	{
		return "0";
	}

}
string Helper::binaryToHex(string binary, int length)
{
	stringstream getHex;
	if(length == -1)
	{
		getHex << "0x" << setfill('0') << setw(32) << hex << stol(binary,NULL,2); //see std::stoi, stoi converts hexRep string to integer hex
	} else {
		getHex << "0x" << setfill('0') << setw(length) << hex << stol(binary,NULL,2); //see std::stoi, stoi converts hexRep string to integer hex
	}
    
    return getHex.str(); //std::stoi default base is 10
}

/**string Helper::hexToBinary(string hexString, int length)
{

}**/

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
    	cout << index << " " << i.getEncoding() << endl;
    	stringstream updateIndex;
    	updateIndex << showbase << hex << (hexToDec(index)+4);;
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
map<Register,string> Helper::readFileForRegister(string filename)
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


