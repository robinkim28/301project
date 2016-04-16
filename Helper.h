#ifndef __HELPER_H__
#define __HELPER_H__

#include <string>
#include <map>
#include <iostream>
#include <sstream>
#include <fstream>
#include <stdlib.h>
#include <math.h>
using namespace std;
/* This class contains all helpers method that is needed in the program.
 */
class Helper
{
 public:
 //given a number, convert to hexadecimal. If the number is negative, do two complements of length 32 binary
 //which is length 8 hexadecimal
	static	string decToHex(int number);

	//given a file name which contains two parameters in each line in the form "0xppp:0xqqq", breakdown into
	//a map from "ppp" to "qqq"
	static map<string,string> readFileForInstruction(string filename);
	
	//given a file name which contains two parameters in each line in the form "[register number]:0xqqq", breakdown into
	//a map from int registerNumber to "qqq"
	static map<int,string> readFileForRegister(string filename);
};

#endif
