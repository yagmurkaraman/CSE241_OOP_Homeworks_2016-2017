/*----------------------------------------------------------------------------*/
/*                                                                            */
/* HW04_141044016_Yagmur_Karaman                                              */
/*                                                                            */
/* CPUProgram.h                                                               */
/* -------------                                                              */
/* Created on 06/11/2016 by Yagmur_Karaman                                    */
/*                                                                            */
/* Description                                                                */
/* ------------                                                               */
/*		The CPUProgram.h contains the functions which are used the read file, */
/*	stores instructions and find size of file.                                */
/*----------------------------------------------------------------------------*/
#ifndef _CPUPROGRAM_H__
#define _CPUPROGRAM_H__

/*----------------------------------------------------------------------------*/
/*						     Includes                                         */
/*----------------------------------------------------------------------------*/
#include <iostream>
#include <vector>
using namespace std;

class CPUProgram{

	public:
		
		CPUProgram();
		CPUProgram(string inFile){ ReadFile(inFile); } //inline
		CPUProgram(int option){	mod=option;	}
		void setOption(int setOpt){ option=setOpt; } //inline
		char getOption(){ return option; } //inline
		int ReadFile(string file);
		int size(); //inline
		string getLine(int line){ return instructions[line]; }//inline
		
		string& operator[](int index);
		CPUProgram operator+(const string back);
		CPUProgram operator+=(const string back);
		CPUProgram operator+(const CPUProgram& other);
		bool operator==(const CPUProgram& other)const;	
		bool operator<=(const CPUProgram& other)const;
		bool operator>=(const CPUProgram& other)const;
		bool operator<(const CPUProgram& other)const;
		bool operator>(const CPUProgram& other)const;
		bool operator!=(const CPUProgram& other)const;
		CPUProgram operator--();
		CPUProgram operator--(int ignoreMe);
		CPUProgram operator()(int first, int last);
		friend ostream& operator<<(ostream& output,const CPUProgram& other);

	private:

		string file; 
		vector<string>instructions;
		vector<string>temp;
		int total;
		int mod;
		int option;		
};
#endif
/*----------------------------------------------------------------------------*/
/*							End of CPUProgram.h                               */
/*----------------------------------------------------------------------------*/