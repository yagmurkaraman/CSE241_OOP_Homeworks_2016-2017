/*----------------------------------------------------------------------------*/
/*                                                                            */
/* HW03_141044016_Yagmur_Karaman                                              */
/*                                                                            */
/* main.cpp                                                                   */
/* ---------                                                                  */
/*	Created on 27/10/2016 by Yagmur_Karaman                                   */
/*                                                                            */
/* Description                                                                */
/* ------------                                                               */
/*		The main.cpp contains the header files and gets the program counter   */
/*	from CPU class, send the getLine function of CPUProgram class and         */
/*	return the next instruction. Then send instruction to execute function    */
/*	of CPU class.                                                             */
/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/*								  Includes                                    */
/*----------------------------------------------------------------------------*/
#include <iostream>
#include <fstream>
/*----------------------------------------------------------------------------*/
/*								 Header Files                                 */
/*----------------------------------------------------------------------------*/
#include "CPUProgram.h"
#include "CPU.h"
/*----------------------------------------------------------------------------*/
using namespace std;

int main(int argc, char** argv)
{	
	// dosya CPUProgram class constructorina gonderilir.
	ifstream inFile(argv[1]);
	CPUProgram myProg(argv[1]); 
	char *option=argv[2];

	CPU myCPU;
	
	while(!myCPU.halted())
	{
		string instruction=myProg.getLine(myCPU.getPC());	
		myCPU.setOption(option);	
		// eger instruction uygun degilse program bitirilir.
		if(!myCPU.execute(instruction))  
		{
			inFile.close();
			return 0;
		}			
	}// program halt edene kadar calisir.
	inFile.close();
	return 0;
}
/*----------------------------------------------------------------------------*/
/*				     	    End of main.cpp                                   */
/*----------------------------------------------------------------------------*/
