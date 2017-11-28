#ifndef BIGRAM_H
#define BIGRAM_H

#include <iostream>
#include <fstream>
#include <string>
#include <utility>
#include <exception>
#include "MyException.h"

using namespace std;

template<class T>

class Bigram{

	public:

		virtual void readFile(string file)=0;
		virtual int numGrams()=0;
		virtual int numOfGrams(T v1, T v2)=0;
		virtual pair<T,T> maxGrams()=0;
		friend ostream& operator<<(ostream& output, Bigram& other){
			other.print(output);
			return output;
		}
		virtual void print(ostream& output)=0;
		 
	
};
#endif
