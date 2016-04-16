#ifndef __HELPER_H__
#define __HELPER_H__

#include <string>
#include <map>

/* This class contains all helpers method that is needed in the program.
 */
class Helper
{
 public:
 //given a number, convert to hexadecimal. If the number is negative, do two complements of length 32 binary
 //which is length 8 hexadecimal
	string static decToHex(int number);

	//given a file name which contains two parameters in each line in the form "0xppp:0xqqq", breakdown into
	//a map from "ppp" to "qqq"
	map<string,string> static readFileForInstruction(string filename);
	
	//given a file name which contains two parameters in each line in the form "[register number]:0xqqq", breakdown into
	//a map from int registerNumber to "qqq"
	map<int,string> static readFileForRegister(string filename);
};

#endif
