CC = g++
LD = g++
CCFLAG = -Wall -Wno-deprecated -g -c
LDFLAG = -Wall -Wno-deprecated -g

EXECS = main
#in some case other platform create .exe and will not delete the executable, so I can add extraclean part if needed

all: $(EXECS)

main: main.o Counter.o InstMemory.o Helper.o
	$(LD) $(LDFLAG) -o main main.o Counter.o InstMemory.o Helper.o
	
main.o: main.cpp
	$(CC) $(CCFLAG) main.cpp

Helper.o: Helper.h Helper.cpp 
	$(CC) $(CCFLAG) Helper.cpp
	
Counter.o: Counter.h Counter.cpp
	$(CC) $(CCFLAG) Counter.cpp

InstMemory.o: InstMemory.h InstMemory.cpp 
	$(CC) $(CCFLAG) InstMemory.cpp

clean:
	/bin/rm -f *.o $(EXECS)
