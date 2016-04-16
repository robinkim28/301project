#ifndef __COUNTER_H__
#define __COUNTER_H__

#include "Helper.h"
#include <string>


/* This class creates an object that acts as a PC counter
 */


class Counter
{
 public:
	//create a counter instance with a starting number 0
  Counter();
  //create a counter instance with a starting number
  Counter(int number);

  //access what number it is now. The answer should be in string, for example, "400a28"
  string getNumber();
  //set the number
  void setNumber(int number);
	//specifically for PC=PC+4
  void increment();

  string decToHex(int num);
 private:
  int myNumber;
};

#endif
