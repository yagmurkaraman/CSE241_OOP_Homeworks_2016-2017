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
/*		The CPU.h contains the functions which are used the execute of        */
/*		instructions.                                                         */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#ifndef _CPU_H__
#define _CPU_H__
/*----------------------------------------------------------------------------*/
/*								Includes                                      */
/*----------------------------------------------------------------------------*/
#include <iostream>

using namespace std;

class CPU{

	public:
	
		CPU();		
		void setRegisters(int value); 
		int halted();
		int execute(string line);
		string lowToUpper(string line)const;
		int findFirst(string line)const; 
		int allControls(string line);
		int isValid(string line, int first)const;
		int spaceForReg(string line, int first)const;
		int findFirstInst(string line,int first)const;
		int controlValid(string line,int regOrConst)const;
		int controlComments(string line)const;
		string removeComments(string line)const;    
		int controlSpace(string line,int regOrConst)const;
		string removeSpaces(string line)const;
		int register1(string line)const;
		int register2(string line)const;
		int constant(string line)const;
		int isWhichInstruction(string line, int reg1, int reg2, int cons);
		int isMov(string line, int reg1, int reg2, int cons);
		int isAdd(string line, int reg1, int reg2, int cons);
		int isSub(string line, int reg1, int reg2, int cons);
		int isJmp(string line,int reg1, int reg2,int cons);
		int isPrn(string line, int reg1, int reg2, int cons);
		void print(string line);
		int getPC(){ return PC; } //inline
		void setPC(int pCounter){ PC=pCounter; } //inline
		void setOption(char *setOpt){ option=setOpt; } //inline
		char getOption(){ return *option; } //inline
	
	private:
		
		string line;
		int PC;
		char *option;
		int reg[5];
		int flag=-1;
};
#endif
/*----------------------------------------------------------------------------*/
/*								End of CPU.h                                  */
/*----------------------------------------------------------------------------*/
