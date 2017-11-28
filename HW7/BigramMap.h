#ifndef BIGRAMMAP_H
#define BIGRAMMAP_H

#include <iostream>
#include <fstream>
#include <string>
#include <utility>
#include <exception>
#include <map>
#include <vector>
#include "Bigram.h"
#include "MyException.h"
using namespace std;

template <class T>

class BigramMap : public Bigram<T>
{
	public:
		
		BigramMap(){}
		BigramMap(int type){ dataType=type; }
		int getType(){ return dataType; }
		int getSize(){ return size; }
		virtual void readFile(string file)override;
		virtual int numGrams()override;
		virtual int numOfGrams(const T v1, const T v2)override;
		virtual pair<T,T> maxGrams()override;
		virtual void print(ostream& output)override;

	private:
		
		int dataType;
		map< pair<T,T>, int > myMap;
		typename map< pair<T,T> ,int>::iterator it1;
		typename map<  pair<T,T> ,int>::iterator found;
		typename map< pair<T,T> ,int>::iterator it2;
		int size;
		vector<T> array;
		
};
#endif
