/*----------------------------------------------------------------------------*/
/*                                                                            */
/* HW05_141044016_Yagmur_Karaman                                              */
/*                                                                            */
/* CPUProgram.h                                                               */
/* -------------                                                              */
/* Created on 14/11/2016 by Yagmur_Karaman                                    */
/*                                                                            */
/* Description                                                                */
/* ------------                                                               */
/*		The CPUProgram.cpp contains the functions which are used the read file*/
/*	stores instructions, find size of file and operator overloading.          */
/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/*							       Includes                                   */
/*----------------------------------------------------------------------------*/
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>
#include "CPUProgram.h"

using namespace std;

CPUProgram::CPUProgram(){ }

int CPUProgram::size()
{
	return (instructions.size());	
}
string& CPUProgram::operator[](int index)
{
	static string empty="\0";

	if(index<0)
	{
		cerr << "ERROR: DO NOT ENTER NEGATIVE INDEX!!!\n";
		return empty;
	}
	else if(index>=instructions.size())
	{
		cerr << "ERROR: LIMIT EXCEEDED!!!\n";
		return empty;
	}
	return (instructions[index]);
}// [] operator overloading

CPUProgram CPUProgram::operator+(const string back)
{
	CPUProgram newProg;
	newProg.instructions=instructions;
	(newProg.instructions).push_back(back);
	return newProg;
	
}// + operator overloading for class+string
CPUProgram CPUProgram::operator+=(const string back)
{
	if(back=="")
	{	
		cerr << "COULD NOT ADD EMPTY STRING!!!\n";
		return *this;
	}
	instructions.push_back(back);
	return *this;
}// += operator overloading for class+=string
CPUProgram CPUProgram::operator+(const CPUProgram& other)
{
	CPUProgram newProg;	
	newProg.instructions=instructions;
	
	for(int i=0; i<(other.instructions).size(); ++i)	
		(newProg.instructions).push_back(other.instructions[i]);
	
	return newProg;
}// + operator overloading for class+class
bool CPUProgram::operator==(const CPUProgram& other)const
{
	int sizeOther=(other.instructions).size();
	int sizeThis=instructions.size();

	if(sizeOther==sizeThis)
		return true;

	else
		return false;	
}// == operator overloading for int==int
bool CPUProgram::operator<=(const CPUProgram& other)const
{
	int sizeOther=(other.instructions).size();
	int sizeThis=instructions.size();

	if(sizeThis<=sizeOther)
		return true;

	else
		return false;
}// <= operator overloading for int==int
bool CPUProgram::operator>(const CPUProgram& other)const
{
	int sizeOther=(other.instructions).size();
	int sizeThis=instructions.size();

	if(sizeThis>sizeOther)
		return true;

	else
		return false;
}// > operator overloading for int==int
bool CPUProgram::operator>=(const CPUProgram& other)const
{
	int sizeOther=(other.instructions).size();
	int sizeThis=instructions.size();

	if(sizeThis>=sizeOther)
		return true;

	else
		return false;
}// >= operator overloading for int==int
bool CPUProgram::operator<(const CPUProgram& other)const
{
	int sizeOther=(other.instructions).size();
	int sizeThis=instructions.size();

	if(sizeThis<sizeOther)
		return true;
	else
		return false;
}// < operator overloading for int==int
bool CPUProgram::operator!=(const CPUProgram& other)const
{
	int sizeOther=(other.instructions).size();
	int sizeThis=instructions.size();

	if(sizeThis!=sizeOther)
		return true;

	return false;
}// != operator overloading for int==int
CPUProgram CPUProgram::operator--()//pre
{	
	instructions.pop_back();
	return *this;
}// -- operator overloading
CPUProgram CPUProgram::operator--(int ignoreMe)//post
{
	vector<string>temp=instructions;
	instructions.pop_back();

	return *this;
}// -- operator overloading
CPUProgram CPUProgram::operator()(int first, int last)
{
	static string empty="\0";
	int size=instructions.size();
	int i,j;
	if(first<0 || first >=size || last<0 || last>=size)
	{
		cerr << "ERROR: LIMIT EXCEEDED!!!\n";
		return empty;
	}	
	for(i=size; i>last; --i)
		instructions.pop_back();	

	instructions.erase(instructions.begin(),instructions.begin()+first-1);

	return *this;
}// () operator overloading for function call
ostream& operator<<(ostream& output, const CPUProgram& other)
{
	for(int i=0; i<(other.instructions).size(); i++)
		output << (other.instructions)[i] << endl;	

	return output;
}// << oprtator overloding for print program
int CPUProgram::ReadFile(string file)
{
	ifstream inFile;
	if(!(inFile))
    {
    	cerr << "ERRORS: FILE COULDN'T BE OPENED!!!\n";
    	return false;
    }// dosya acilamazsa hata verir.
	string line;
	//int i;
	inFile.open(file); // dosya acilir.
	
	
	while(getline(inFile, line))
	{
		instructions.push_back(line);	 
		
	}// tum instructionlari yeni bir string array icine atar.
	//total=i;// size, total icinde tutulur.
	
}
/*----------------------------------------------------------------------------*/
/*							End of CPUProgram.cpp                             */
/*----------------------------------------------------------------------------*/
