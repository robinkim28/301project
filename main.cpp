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
//put all the parameters (debug mode, bach mode, etc.) here

int main(int argc, char *argv[])
{
	//CONFIGURATION FILE PARAMETERS

	//provides the name of the input file containing MIPS assembly code.
	string config_program_input;

	//provides the name of the input file that contains the contents of the main memory module at the beginning of execution.
	string config_memory_contents_input;

	//provides the name of the input file that contains the contents of the register file at the beginning of execution.
	string config_register_file_input;

	//determines whether the user wishes to step through the simulation one instruction at a time, 
	//or simply execute the simulation of the entire assembly program all at once.
	enum outputMode {SINGLE_STEP, BATCH};
	outputMode config_output_mode;

	//If true, any debugging output should be displayed (whatever the programmer decides that debugging output is). 
	//If false, no debugging output should be displayed.
	bool config_debug_mode;

	//If true, each output event should print out the current contents of the entire register file and the entirety of memory.
	bool config_print_memory_contents;

	if(argc < 2){
		cerr << "Need to specify an input file which contains all the parameters."<<endl;
		exit(1);
	}
	
	//in reading input file, it should read the parameters in any order. For each parameter,
	//we can go through each line and find the line containing that parameter
	bool validConfig = true;
	ifstream configFile(argv[1]);
	configFile >> skipws;
	string line;

	if(configFile.is_open())
	{
		while(getline(configFile,line) && validConfig == true)
		{
			 line.erase(remove_if(line.begin(), line.end(), [](char x){return std::isspace(x);}), line.end());
			cout << line << endl;
			if(!(line.size() == 0))
			{
				if(!(line[0] == '#') )
				{
					int index = line.find('=');
		   			string parameter = line.substr(0,index);
		   			string value = line.substr(index+1,line.size()-parameter.size()-1);

		   			if (parameter == "program_input")
		   			{

		   				config_program_input = value;

		   			} else if (parameter == "memory_contents_input") {

		   				config_memory_contents_input = value;

		   			} else if (parameter == "register_file_input") {

		   				config_register_file_input = value;

		   			} else if (parameter == "output_mode") {

		   				if(value.compare("single_step")==0)
		   				{

		   					config_output_mode = SINGLE_STEP;

		   				} else if (value.compare("batch")==0) {

		   					config_output_mode = BATCH;

		   				} else {

		   					validConfig = false;
		   					cout << value << endl;
		   					cout << value.size() << endl;
		   					cerr << "ERROR READING CONFIGURATION FILE: output_mode. output_mode must be single_step or batch" << endl;
		   					exit(1);

		   				}
		   			
		   			} else if (parameter == "debug_mode") {

		   				if(value == "true")
		   				{

							config_debug_mode = true;

						} else if (value == "false") {

							config_debug_mode = false;

						} else {

		   					validConfig = false;
		   					cerr << "ERROR READING CONFIGURATION FILE: debug_mode. debug_mode must be true or false" << endl;
		   					exit(1);

		   				}

		   			} else if (parameter == "print_memory_contents") {

		   				if(value == "true")
		   				{

							config_print_memory_contents = true;

						} else if (value == "false") {

							config_print_memory_contents = false;

						} else {

		   					validConfig = false;
		   					cerr << "ERROR READING CONFIGURATION FILE: print_memory_contents. print_memory_contents must be true or false" << endl;
		   					exit(1);

		   				}

		   			} else {

		   				validConfig = false;
		   				cout << parameter << endl;
		   				cout << parameter.size() << endl;
		   				cerr << "ERROR READING CONFIGURATION FILE: INVALID PARAMETER. Valid parameters are: program_input, memory_contents_input, register_file_input, output_mode, debug_mode, print_memory_contents" << endl;
		   				exit(1);

		   			}

				}

			}	

		}

	}

	
	
	
	
	//setting up all the unit and initial value (if applicable)
	map<string,Instruction> instructionMemory = Helper::readFileForInstruction(config_program_input);
	//map<int,string> registerMemory = Helper::readFileForRegister(config_register_file_input);
	//map<string,string> dataMemory = Helper::readFileForDataMemory(config_memory_contents_input);

	
	
	
	
	
	
	//then do each cycle. There are many steps for this
/*
*****Example of using InstMemory Class*********

instrutionMmeory = InstMemory(instructionList)

instM.setInAdress(PC)
instM.calculate();
string insutrction = instM.getOutInstruction();
... intruction from hex into binary
split into 31-25 ... */

	
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
		
