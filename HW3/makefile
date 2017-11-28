all: begin

begin: main.o CPU.o CPUProgram.o
	  g++ main.o CPU.o CPUProgram.o -o exe

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

CPU.o: CPU.cpp
	g++ -std=c++11 -c CPU.cpp

CPUProgram.o: CPUProgram.cpp
	g++ -std=c++11 -c CPUProgram.cpp

clean:
	rm *.o exe
