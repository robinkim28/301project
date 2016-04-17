CC = g++ -std=gnu++0x 
LD = g++ -std=gnu++0x
CCFLAG = -Wall -Wno-deprecated -g -c
LDFLAG = -Wall -Wno-deprecated -g

EXECS = main test
#in some case other platform create .exe and will not delete the executable, so I can add extraclean part if needed

all: $(EXECS)

main: main.o Counter.o InstMemory.o Helper.o RegisterMemory.o
	$(LD) $(LDFLAG) -o main main.o Counter.o InstMemory.o Helper.o
	
main.o: main.cpp
	$(CC) $(CCFLAG) main.cpp
	
test: test.o Counter.o InstMemory.o Helper.o RegisterMemory.o
	$(LD) $(LDFLAG) -o test test.o Counter.o InstMemory.o Helper.o
	
test.o: test.h test.cpp
	$(CC) $(CCFLAG) test.cpp

Helper.o: Helper.h Helper.cpp 
	$(CC) $(CCFLAG) Helper.cpp
	
Counter.o: Counter.h Counter.cpp
	$(CC) $(CCFLAG) Counter.cpp

InstMemory.o: InstMemory.h InstMemory.cpp 
	$(CC) $(CCFLAG) InstMemory.cpp
	
RegisterMemory.o: RegisterMemory.h RegisterMemory.cpp 
	$(CC) $(CCFLAG) RegisterMemory.cpp

clean:
	/bin/rm -f *.o $(EXECS)
