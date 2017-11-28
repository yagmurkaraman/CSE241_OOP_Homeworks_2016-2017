/*----------------------------------------------------------------------------*/
/*                                                                            */
/* HW06_141044016_Yagmur_Karaman                                              */
/*                                                                            */
/* CPUProgramDyn.h                                                            */
/* -------------                                                              */
/* Created on 30/11/2016 by Yagmur_Karaman                                    */
/*                                                                            */
/* Description                                                                */
/* ------------                                                               */
/*		The CPUProgramDyn.cpp contains the functions which are used           */
/*	the read file stores instructions, find size of file and                  */
/*	operator overloading.                                                     */
/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/*							       Includes                                   */
/*----------------------------------------------------------------------------*/
#include <iostream>
#include <fstream>

#include "CPUProgramDyn.h"

namespace YagmurDyn{

	const int DOUBLE_ALLOC=2;
	
	CPUProgramDyn::CPUProgramDyn(){ instructions=nullptr; }

	CPUProgramDyn::CPUProgramDyn(int option):capacity(50),used(0){

		instructions=nullptr;
		instructions=new string[capacity];
		mod=option;	
	}
	CPUProgramDyn::CPUProgramDyn(const CPUProgramDyn& other)
	{
		used=other.used;
		instructions=new string[used];
		
		for(int i=0; i<used; ++i)
			instructions[i]=other.instructions[i];
			
	}
	CPUProgramDyn& CPUProgramDyn::operator=(const CPUProgramDyn& other)
	{
		int tempCap=capacity;
		if(capacity!=other.capacity)
		{
			delete[] instructions;
			instructions=new string[other.capacity];
		}
		used=other.used;
		for(int i=0; i<used; ++i)
			instructions[i]=other.instructions[i];

		return *this;		
	}
	string& CPUProgramDyn::operator[](int index)
	{
		static string empty="\0";
		
		if(index<0)
		{
			cerr << "ERROR: DO NOT ENTER NEGATIVE INDEX!!!\n";
			return empty;
		}
		else if(index>=used)
		{
			cerr << "ERROR: LIMIT EXCEEDED!!!\n";
			return empty;
		}
		return (instructions[index]);
	}// [] operator overloading

	CPUProgramDyn CPUProgramDyn::operator+(const string back)
	{
		if(back=="")
		{	
			cerr << "ERROR: COULD NOT ADD EMPTY STRING!!!\n\n";	
			return *this;
		}
		else if(used>=capacity)
		{
			cerr << "LIMIT EXCEEDED\n";
			return *this;
		}
		instructions[used]=back;
		used++;
		return *this;	
		
	}// + operator overloading for class+string
	CPUProgramDyn CPUProgramDyn::operator+=(const string back)
	{	
		if(back=="")
		{	
			cerr << "ERROR: COULD NOT ADD EMPTY STRING!!!\n\n";	
			return *this;
		}
		else if(used>=capacity)
		{
			cerr << "LIMIT EXCEEDED\n";
			return *this;
		}
		instructions[used]=back;
		used++;
		return *this;
	}// += operator overloading for class+=string
	CPUProgramDyn CPUProgramDyn::operator+(const CPUProgramDyn& other)
	{
		CPUProgramDyn newProg;	
		int i;

		string *temp=newProg.instructions;
		newProg.instructions=new string[used+other.used];

		for(i=0; i<used; ++i)	
			newProg.instructions[i]=instructions[i];

		for(int j=0; j<other.used; ++j)
		{
			newProg.instructions[i]=other.instructions[j];
			++i;
		}
		newProg.used=used+other.used;

		return newProg;
	}// + operator overloading for class+class
	bool CPUProgramDyn::operator==(const CPUProgramDyn& other)const
	{
		int sizeOther=other.used;
		int sizeThis=used;

		if(sizeOther==sizeThis)
			return true;

		else
			return false;	
	}// == operator overloading for int==int
	bool CPUProgramDyn::operator<=(const CPUProgramDyn& other)const
	{
		int sizeOther=other.used;
		int sizeThis=used;

		if(sizeThis<=sizeOther)
			return true;

		else
			return false;
	}// <= operator overloading for int==int
	bool CPUProgramDyn::operator>(const CPUProgramDyn& other)const
	{
		int sizeOther=other.used;
		int sizeThis=used;

		if(sizeThis>sizeOther)
			return true;

		else
			return false;
	}// > operator overloading for int==int
	bool CPUProgramDyn::operator>=(const CPUProgramDyn& other)const
	{
		int sizeOther=other.used;
		int sizeThis=used;

		if(sizeThis>=sizeOther)
			return true;

		else
			return false;
	}// >= operator overloading for int==int
	bool CPUProgramDyn::operator<(const CPUProgramDyn& other)const
	{
		int sizeOther=other.used;
		int sizeThis=used;

		if(sizeThis<sizeOther)
			return true;
		else
			return false;
	}// < operator overloading for int==int
	bool CPUProgramDyn::operator!=(const CPUProgramDyn& other)const
	{
		int sizeOther=other.used;
		int sizeThis=used;

		if(sizeThis!=sizeOther)
			return true;

		return false;
	}// != operator overloading for int==int
	CPUProgramDyn CPUProgramDyn::operator--()//pre
	{
		string *temp=instructions;
		for(int i=0; i<used-1; ++i)
			instructions[i]=temp[i];

		return *this;
	}// -- operator overloading
	CPUProgramDyn CPUProgramDyn::operator--(int ignoreMe)//post
	{
		CPUProgramDyn temp;

		temp.instructions=instructions;
		instructions=new string[used-1];
		
		for(int i=0; i<used-1; ++i)
			instructions[i]=temp.instructions[i];
		
		return temp;
	}// -- operator overloading
	CPUProgramDyn CPUProgramDyn::operator()(int first, int last)
	{
		static string empty="\0";
		int size=used;
		int i,j,newSize;

		if(first<0 || first>size || last<0 || last>size || first>last)
		{
			cerr << "\nERROR: INVALID INDEXES!!!";
			return empty;
		}
		string *temp=instructions;
		
		j=0;
		for(int i=first-1; i<last; ++i)
		{
			temp[j]=instructions[i];
			++j;
		}
		instructions=temp;
		used=last-first+1;

		return *this;
	}// () operator overloading for function call
	ostream& operator<<(ostream& output, const CPUProgramDyn& other)
	{
		cout << endl;
		for(int i=0; i<other.used; i++)
			output << (other.instructions)[i] << endl;	
		
		return output;
	}// << operator overloding for print program
	int CPUProgramDyn::ReadFile(string file)
	{
		capacity=50;
		used=0;
		instructions=new string[capacity];

		ifstream inFile;
		if(!(inFile))
	    {
	    	cerr << "ERRORS: FILE COULDN'T BE OPENED!!!\n";
	    	return false;
	    }// dosya acilamazsa hata verir.
		string line;

		inFile.open(file);
		while(getline(inFile, line))
		{
			if(used>=capacity)
			{	
				capacity*=DOUBLE_ALLOC;
				string *temp=new string[capacity];
				for(int i=0; i<used; ++i)
					temp[i]=instructions[i];

				delete[] instructions;
				instructions=temp;
			}
			instructions[used]=line;
			used++;
		}	
		inFile.close();
	}
	CPUProgramDyn::~CPUProgramDyn()
	{
		if(instructions!=nullptr)
		{	delete[] instructions;
			instructions=nullptr;
		}	
	}
}
/*----------------------------------------------------------------------------*/
/*							End of CPUProgramDyn.cpp                             */
/*----------------------------------------------------------------------------*/