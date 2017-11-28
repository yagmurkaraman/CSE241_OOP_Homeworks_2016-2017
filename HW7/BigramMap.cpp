#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <utility>
#include <stdlib.h>
#include <map>
#include <vector>
#include <sstream>
#include <exception>
#include "Bigram.h"
#include "BigramMap.h"
#include "MyException.h"

using namespace std;

template <class T>
void BigramMap<T>::readFile(string file)
{
	ifstream inFile(file);
	T temp;
	string temp2;
	string line;
	
	if(inFile.fail())
	{
		throw MyException("ERROR: FILE COULDN'T OPEN!!");
	}	
	int i=0;
	while(inFile>>temp2)
	{	
		++i;
	}	
	size=i;

	if(size==0)
		throw MyException("EMPTY FILE!!");

	else if(size==1)
		throw MyException("FILE DOES NOT CONTAIN ENOUGH INPUTS!!");

	inFile.close();
	inFile.open(file);

	getline(inFile,line);	
	istringstream parser(line);
	int k=0;

	while(k<i)
	{
		parser >> temp;
		if(parser.fail())
			throw MyException("NOT GOOD SET: BAD DATA!!");
	
		array.push_back(temp);
		++k;
	}
		
	inFile.close();

	k=0;
	it1=myMap.begin();
	for(i=0; i<size-1; ++i)
	{
		found=myMap.find((pair<T,T>(array[i],array[i+1])));
		bool flag=true;
		if(found!=myMap.end())
		{	
			it1=found;
			it1->second++;
			flag=false;
				
		}
		if(flag==true)
		{
			myMap.insert(make_pair((make_pair(array[i],array[i+1])), 1));
		}
	}

}
template <class T>
int BigramMap<T>::numGrams()
{
	return size-1;	
}
template <class T>
int BigramMap<T>::numOfGrams(const T v1, const T v2)
{
	int i=0;
	it1=myMap.begin();
	while(it1!=myMap.end())
	{
		//cout << "first " << it1->first.first << " " << "second " << it1->first.second << endl;
		if(it1->first.first==v1 && it1->first.second==v2)
			i=it1->second;
			
		it1++;
	}
	return i;
}
template <class T>
pair<T,T> BigramMap<T>::maxGrams()
{
	it1=myMap.begin();
	int max=it1->second;

	int i,j=0;
	for(i=0; it1!=myMap.end(); ++i)
	{
		if(it1->second>max)
		{	
			max=it1->second;
			++j;
		}	
		++it1;		
	}
	
	for(it1=myMap.begin(); it1->second!=max; ++it1)
	;

	return it1->first;	
}
template <class T>
void BigramMap<T>::print(ostream& output)
{
	it1=myMap.begin();
	int max;
	int i,j=0;
		
	max=it1->second;
	for(i=0; it1!=myMap.end(); ++i)
	{
		if(it1->second>max)
		{	
			max=it1->second;
			++j;
		}
		++it1;			
	}
	// j -- maxGrams
	it1=myMap.begin();
	
	for(int k=0; it1!=myMap.end(); ++k)
	{	
		it2=myMap.begin();	
		for(int m=0; it2!=myMap.end(); ++m)
		{
			if(it2->second==max)
			{
				cout << "BigramMap(" <<  it2->first.first << "," <<it2->first.second <<") :  ";
				cout << it2->second << endl;
			}
			++it2;
		}	
		++it1;
		max--;
	}	
}