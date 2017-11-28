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
/*		The CPUProgram.cpp contains the functions which are used the read file*/
/*	stores instructions and find size of file.                                */
/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/*							       Includes                                   */
/*----------------------------------------------------------------------------*/
#include <iostream>
#include <fstream>
#include "CPUProgram.h"
/*----------------------------------------------------------------------------*/
using namespace std;

void CPUProgram::readFile(string file)
{
	ifstream inFile;
	string line;
	int i;
	inFile.open(file); // dosya acilir.
	
	i=0;
	while(getline(inFile, line))
	{
		instructions[i]=line;
		i++;
	}// tum instructionlari yeni bir string array icine atar.
	total=i;// size, total icinde tutulur.	
}
/*----------------------------------------------------------------------------*/
/*							End of CPUProgram.cpp                             */
/*----------------------------------------------------------------------------*/
