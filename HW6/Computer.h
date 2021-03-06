/*----------------------------------------------------------------------------*/
/*                                                                            */
/* HW04_141044016_Yagmur_Karaman                                              */
/*                                                                            */
/* Computer.h                                                                 */
/* -------------                                                              */
/* Created on 06/11/2016 by Yagmur_Karaman                                    */
/*                                                                            */
/* Description                                                                */
/* ------------                                                               */
/*		The Computer.h contains the functions which are used the execute of   */
/*		program as main.                                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#ifndef _COMPUTER_H__
#define _COMPUTER_H__
/*----------------------------------------------------------------------------*/
/*								Includes                                      */
/*----------------------------------------------------------------------------*/
#include <iostream>

#include "CPUProgramDyn.h"
#include "CPU.h"
#include "Memory.h"
#include "Computer.h"

using namespace std;

namespace YagmurDyn{
	
	class Computer{

		public:
			
			Computer();
			Computer(CPU myCPU, CPUProgramDyn myCPUProgram, Memory myMemory, int option);
			Computer(int option);
			void setCPU(CPU myCPU){ exeCPU=myCPU; }
			void setCPUProgram(CPUProgramDyn myCPUProgram){ exeProg=myCPUProgram; }
			void setMemory(Memory myMemory){ exeMemory=myMemory; }		
			CPU getCPU(){	return exeCPU;	}
			CPUProgramDyn getCPUProgram(){ return exeProg; }
			Memory getMemory(){ return exeMemory; }
			int execute();
			
		private:
			
			CPU exeCPU;
			CPUProgramDyn exeProg;
			Memory exeMemory;
			string instruction;	
			int mod;
	};
}
#endif
/*----------------------------------------------------------------------------*/
/*								End of Computer.h                             */
/*----------------------------------------------------------------------------*/