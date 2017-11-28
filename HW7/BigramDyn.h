#ifndef BIGRAMDYN_H
#define BIGRAMDYN_H

#include <iostream>
#include <fstream>
#include <string>
#include <utility>
#include <map>
#include <exception>
#include "Bigram.h"
#include "MyException.h"
using namespace std;

template <class T>

class BigramDyn : public Bigram<T>
{
	public:
		
		BigramDyn();
		BigramDyn(const BigramDyn& other);
		BigramDyn& operator=(const BigramDyn& other);
		BigramDyn(int type){ dataType=type; }
		int getType(){ return dataType; }
		int getSize(){ return size; }
		virtual void readFile(string file)override;
		virtual int numGrams()override;
		virtual int numOfGrams(T v1, T v2)override;
		virtual pair<T,T> maxGrams()override;
		virtual void print(ostream& output)override;
		~BigramDyn();

	private:
		int dataType;
		int size;
		T *array;
		pair<pair<T,T> , int> *myDyn;
		


};
#endif
