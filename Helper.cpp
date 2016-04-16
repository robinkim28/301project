#include <string>      // std::string
#include <iostream>     // std::cout
#include <sstream>      // std::stringstream, std::stringbuf
#include <fstream>      //std::ifstream
#include <map>			//std::map
#include "helper.h"
using namespace std;

string Helper::decToHex(int number)
{
	stringstream getHex;
    getHex << uppercase << hex << number;
    return getHex.str();
}

map<string,string> Helper::readFileForInstruction(string filename)
{
	ifstream infile(filename);
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
