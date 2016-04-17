#include "Test.h"
#include <cassert>
using namespace std;

//default - create a Test instance with a starting number 0
Test::Test()
{
}
int main(int argc, char *argv[])
{
	cout << "main!" << endl;
	Test::testHelper();
	Test::testCounter();
	Test::testRegisterMemory();
	Test::testDataMemory();
	Test::testMathUnit();
	Test::testMain();
}
//Test Helper
void Test::testHelper()
{
	//decToHex
	//etc.
	cerr << "Pass Test!" << endl;
}

void Test::testCounter()
{
	//do something here
	cerr << "Pass Test!" << endl;
}

void Test::testRegisterMemory()
{
	//do something here
	cerr << "Pass Test!" << endl;
}

void Test::testDataMemory()
{
	//do something here
	cerr << "Pass Test!" << endl;
}

void Test::testMathUnit()
{
	//do something here
	cerr << "Pass Test!" << endl;
}

void Test::testMain()
{
	//do something here
	cerr << "Pass Test!" << endl;
}
