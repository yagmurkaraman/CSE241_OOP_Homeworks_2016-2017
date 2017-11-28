#include "Bigram.h"
#include "BigramDyn.h"
#include <iostream>
#include <fstream>
#include <string>
#include <utility>
#include <stdlib.h>
#include <exception>
#include <map>
#include <sstream>
#include "Bigram.h"
#include "BigramDyn.h"
#include "MyException.h"

using namespace std;

template <class T>
BigramDyn<T>::BigramDyn()
{
	array=nullptr;
	myDyn=nullptr;
}
template <class T>
BigramDyn<T>::BigramDyn(const BigramDyn<T>& other){

	dataType=other.dataType;
	size=other.size;
	myDyn=new pair<pair<T,T>, int>[size-1];

	for(int j=0; j<size; ++j)
	{
		array[j]=other.array[j];
	}	
	for(int i=0; i<size-1; ++i)
	{
		myDyn[i].first=other[i].first;
		myDyn[i].second=other[i].second;
	}		
}
template <class T>
BigramDyn<T>& BigramDyn<T>::operator=(const BigramDyn<T>& other){

	int temp=size;
	if(size!=other.size)
	{
		delete[] myDyn;
		delete[] array;
		array=new T[size];
		myDyn=new pair<pair<T,T>, int>[other.size -1];
	}	
	dataType=other.dataType;
	size=other.size;
	for(int j=0; j<size; ++j)
		array[j]=other.array[j];

	for(int i=0; i<size-1; ++i)
	{
		myDyn[i].first=other[i].first;
		myDyn[i].second=other[i].first;
	}	
	return *this;
}
template <class T>
void BigramDyn<T>::readFile(string file)
{
	ifstream inFile(file);
	T temp;
	string temp1;
	string line;
	
	if(inFile.fail())
	{
		myDyn=nullptr;
		throw MyException("ERROR: FILE COULDN'T OPEN!!");
	}
	int i=0;
	while(inFile>>temp1)
	{
		i++;
	}
	size=i;
	if(size==0)
	{	
		myDyn=nullptr;
		throw MyException("EMPTY FILE!!");
	}
	else if(size==1)
	{	
		myDyn=nullptr;
		throw MyException("FILE DOES NOT CONTAIN ENOUGH INPUTS!!");
	}
	inFile.close();
	inFile.open(file);
	array=new T[size];
	
	getline(inFile,line);	
	istringstream parser(line);
	int k=0;

	while(k<i)
	{
		parser >> temp;
		if(parser.fail())
		{
			myDyn=nullptr;
			throw MyException("NOT GOOD SET: BAD DATA!!");
		}
		array[k]=temp;
		k++;
	}
	k=0;
	myDyn=new pair<pair<T,T>, int>[size-1];
	for(i=0; i<size-1; ++i)
	{
		bool flag=true;
		for(int j=0; j<i; ++j)
		{
			if(array[i]==myDyn[j].first.first && array[i+1]==myDyn[j].first.second)
			{
				myDyn[j].second++;
				flag=false;
			}	
		}
		if(flag==true)
		{
			myDyn[k]=make_pair((make_pair(array[i],array[i+1])), 1);

			++k;
		}
	}		
}
template <class T>
int BigramDyn<T>::numGrams(){
	return size-1;
}
template <class T>
int BigramDyn<T>::numOfGrams(T v1, T v2){

	int found=0;
	for(int i=0; i<size; ++i)
	{
		if(array[i]==v1 && array[i+1]==v2)
			found++;
	}
	return found;	
}
template <class T>
pair<T,T> BigramDyn<T>::maxGrams(){

	int max=myDyn[0].second;
	
	int i,j=0;
	for(i=0; myDyn[i].second!='\0'; ++i)
	{
		if(myDyn[i].second>max)
		{	
			max=myDyn[i].second;

		}			
	}
	for(i=0; myDyn[i].second!=max; ++i)
	;	

	return myDyn[i].first;
}
template <class T>
void BigramDyn<T>::print(ostream& output){

	int max=myDyn[0].second;
	int i,j=0;
		
	for(i=0; myDyn[i].second!='\0'; ++i)
	{
		if(myDyn[i].second>max)
		{	
			max=myDyn[i].second;
			++j;
		}			
	}
	// j -- maxGrams
	for(int k=0; myDyn[k].second!='\0'; ++k)
	{	
		for(int m=0; myDyn[m].second!='\0'; ++m)
		{
			if(myDyn[m].second==max)
			{
				output << "BigramDyn(" <<  myDyn[m].first.first << "," <<myDyn[m].first.second <<") :  ";
				output << myDyn[m].second << endl;
			}

		}	
	max--;
	}

}
template <class T>
BigramDyn<T>:: ~BigramDyn()
{
	if(myDyn!=nullptr)
	{	
		delete[] myDyn;
		delete[] array;
		myDyn=nullptr;
		array=nullptr;
	}	
}
