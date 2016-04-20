#include "Counter.h"
#include "Helper.h"

using namespace std;

//default - create a counter instance with a starting number 0
Counter::Counter()
{
	myNumber = 0;
}

  //create a counter instance with a starting number
Counter::Counter(int number)
{
	myNumber = number;
}

  //access what number it is now
string Counter::getNumber()
{
	return Helper::decToHex(myNumber);
}





//for given Counter, decode into string
void Counter::setNumber(int number)
{
	myNumber = number;
}

//For PC+ = PC+4
void Counter::increment()
{
	myNumber = myNumber + 4;
}
