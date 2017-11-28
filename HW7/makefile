all: begin

begin: _mainTester.o BigramMap.o BigramDyn.o
	  g++ _mainTester.o BigramMap.o BigramDyn.o -o exe

_mainTester.o: _mainTester.cpp
	g++ -std=c++11 -c _mainTester.cpp
	
BigramMap.o: BigramMap.cpp
	g++ -std=c++11 -c BigramMap.cpp
	
BigramDyn.o: BigramDyn.cpp
	g++ -std=c++11 -c BigramDyn.cpp

clean:
	rm *.o exe
