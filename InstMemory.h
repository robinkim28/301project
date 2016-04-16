#ifndef __INSTMEMORY_H__
#define __INSTMEMORY_H__

#include "Helper.h"

/* This class creates an object that acts as a PC counter
 */


class InstMemory
{
 public:
	//create the instruction memory with empty memory
  InstMemory();
  //create the instruction memory, with given database of instruction. The database is in the form string,string
  //for example, "44578220" paired with "a7c31002"
  InstMemory(map<string,string> instructionList);

  //given input, calculate the output
  void calculate();
  
  //input
  string inAddress;
  //output
  string outInstruction;

 private:
  map<string,string> myInstructionList;
};

#endif
