#include <iostream>
#include "Counter.h"
#include "InstMemory.h"
#include "Helper.h"
#include <sstream>
#include <fstream>
#include <string>
#include <cstdlib>


using namespace std;

/* The main method for simulating a non-pipeline process of intrustions. Require 5 classes that represents
	pieces of the arhitecture
*/

int main(int argc, char *argv[])
{
	if(argc < 2){
		cerr << "Need to specify an input file which contains all the parameters."<<endl;
		exit(1);
	}
	
	//cont here!
	/*
	string filename = argv[1];
	
	ifstream in;
	in.open(filename.c_str());
	if(in.bad() || in.fail())
	{
		cerr << "Need to specify a valid input file to decode."<<endl;
		exit(1);
	}	
	
	//next, for each line, check to make sure it is valid 32 bits input
	string line;
    while( getline(in, line))
	{
		//for testing
		//cout << line << endl << line[31] << endl << (int) line[32];
		if ( line.length() != (unsigned)CODE_LENGTH +1) //add 1 because there's the end with some terminating character
		{
			if (!(line.length() == (unsigned)CODE_LENGTH && in.eof())) //(line.length() == CODE_LENGTH && line.eof()) means the last line miss \n at the end. This is ok.
			{
				cerr << "Input line has length not appropiate. Invalid input."<<endl;
				exit(1);
			}
		}
		//check that all character should be '0' or '1', except terminating character at the end
		for (int i=0; (unsigned)i<line.length(); i++)
		{
			if (line[i] != '0' && line[i] != '1' && !((unsigned)i == line.length()-1 && (int) line[i] == ASCII_INPUT_NEWLINE_VALUE) )
				//the !(i == line.length()-1 && line[i] == ASCII_INPUT_NEWLINE_VALUE) is to prevent the case when line contains some ternimating character
			{
				cerr << "Input line has nonbinary character. Invalid input."<<endl;
				exit(1);
			}
		}
		//input is binary of length 32. This construct the instruction using MIPS 0-1 codes.
		Instruction thisIntruction(line);
	  	//for checking
		//cout << "check: " << thisIntruction.getString() << endl;	
		
		//if field says function is not valid
		if (thisIntruction.getOpcode() == UNDEFINED)
		{
			cerr << "Input line has encoding ASM function that is not supported."<<endl;
			exit(1);
		}
		
		//when some field is present that should not
		if (thisIntruction.isValid() == false)
		{
			cerr << "Input line has an encoding that is invalid because a field that is not expected is present (as nonzero number)."<<endl;
			exit(1);
		}
		//print decoding of each instruction
		cout << thisIntruction.decode() << endl;
	}
	*/
}
		