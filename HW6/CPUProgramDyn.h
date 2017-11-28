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
/*		The CPUProgramDyn.h contains the functions which are used             */
/*	the read file, stores instructions and find size of file.                 */
/*----------------------------------------------------------------------------*/
#ifndef _CPUPROGRAMDYN_H__
#define _CPUPROGRAMDYN_H__

/*----------------------------------------------------------------------------*/
/*						     Includes                                         */
/*----------------------------------------------------------------------------*/
#include <iostream>

namespace YagmurDyn{

	using std::ifstream;
    using std::string;
	using std::cout;
 	using std::cerr;
	using std::cin;
	using std::endl;
	using std::ostream;
	using std::istream;
	

	class CPUProgramDyn{

		public:
			
			CPUProgramDyn();	
			CPUProgramDyn(string inFile){ ReadFile(inFile); } //inline
			CPUProgramDyn(int option);
			CPUProgramDyn(const CPUProgramDyn& other);
			void setOption(int setOpt){ option=setOpt; } //inline
			char getOption(){ return option; } //inline
			int getCapacity(){ return capacity; }
			int getUsed(){ return used; }
			int ReadFile(string file);
			int size(){ return used;} //inline
			string getLine(int line){ return instructions[line]; }//inline
			string& operator[](int index);
			CPUProgramDyn& operator=(const CPUProgramDyn& other);
			CPUProgramDyn operator+(const string back);
			CPUProgramDyn operator+=(const string back);
			CPUProgramDyn operator+(const CPUProgramDyn& other);
			bool operator==(const CPUProgramDyn& other)const;	
			bool operator<=(const CPUProgramDyn& other)const;
			bool operator>=(const CPUProgramDyn& other)const;
			bool operator<(const CPUProgramDyn& other)const;
			bool operator>(const CPUProgramDyn& other)const;
			bool operator!=(const CPUProgramDyn& other)const;
			CPUProgramDyn operator--();
			CPUProgramDyn operator--(int ignoreMe);
			CPUProgramDyn operator()(int first, int last);
			friend ostream& operator<<(ostream& output,const CPUProgramDyn& other);
			~CPUProgramDyn();

		private:

			string file; 
			string *instructions;
			int capacity;
			int used;
			int mod;
			int option;		
	};
}
#endif
/*----------------------------------------------------------------------------*/
/*							End of CPUProgram.h                               */
/*----------------------------------------------------------------------------*/
