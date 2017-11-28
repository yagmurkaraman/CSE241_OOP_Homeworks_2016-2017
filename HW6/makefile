all: begin

begin: _mainTester.o CPU.o CPUProgramDyn.o Memory.o Computer.o
	  g++ _mainTester.o CPU.o CPUProgramDyn.o Memory.o Computer.o -o exe

_mainTester.o: _mainTester.cpp
	g++ -std=c++11 -c _mainTester.cpp

CPUProgramDyn.o: CPUProgramDyn.cpp
	g++ -std=c++11 -c CPUProgramDyn.cpp
	
CPU.o: CPU.cpp
	g++ -std=c++11 -c CPU.cpp

Memory.o: Memory.cpp
	g++ -std=c++11 -c Memory.cpp
	
Computer.o: Computer.cpp
	g++ -std=c++11 -c Computer.cpp
	
clean:
	rm *.o exe
