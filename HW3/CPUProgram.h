/*----------------------------------------------------------------------------*/
/*                                                                            */
/* HW03_141044016_Yagmur_Karaman                                              */
/*                                                                            */
/* CPUProgram.h                                                               */
/* -------------                                                              */
/* Created on 27/10/2016 by Yagmur_Karaman                                    */
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
/*----------------------------------------------------------------------------*/
using namespace std;

const int SIZE=200;

class CPUProgram{

	public:
		
		CPUProgram(string inFile){ readFile(inFile); } //inline 
		void readFile(string file);
		int size(int total){ return total; } //inline
		const string getLine(int line)const{ return instructions[line-1]; }//inline
		
	private:

		string file; 
		string instructions[SIZE];
		int total;		
};
#endif
/*----------------------------------------------------------------------------*/
/*							End of CPUProgram.h                               */
/*----------------------------------------------------------------------------*/
