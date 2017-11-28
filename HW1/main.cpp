/*----------------------------------------------------------------------------*/
/*                                                                            */
/* HW01_141044016_Yagmur_Karaman                                              */
/*                                                                            */
/* main.cpp                                                                   */
/* ---------                                                                  */
/* Created on 05/10/2016 by Yagmur_Karaman                                    */
/*                                                                            */
/* Description                                                                */
/* ------------                                                               */
/*		The main.cpp contains the implementations of functions for the very   */
/*	simple CPU simulation program.                                            */
/*                                                                            */
/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/*							Includes                                          */
/*----------------------------------------------------------------------------*/
#include <iostream>
#include <fstream>
#include <string>
/*----------------------------------------------------------------------------*/
using namespace std;
/*----------------------------------------------------------------------------*/
/*						Function Prototypes                                   */
/*----------------------------------------------------------------------------*/
/* int makeMove(string line,char *option,int *r1,int *r2,int *r3,int *r4,     */
/*				int *r5)                                                      */
/* -----------                                                                */
/*		This function gets to instruction and registers for move, then        */
/*	prints the result if option is 1.                                         */
/*----------------------------------------------------------------------------*/
int makeMove(string line,char *option,int *r1, int *r2, int *r3, int *r4, 
				int *r5);
/*----------------------------------------------------------------------------*/
/* int makeAddition(string line,char *option,int *r1,int *r2,int *r3,int *r4, */
/*				int *r5)                                                      */
/* -----------                                                                */
/*		This function gets to instruction and registers for addition, then    */
/*	prints the result if option is 1.                                         */
/*----------------------------------------------------------------------------*/
int makeAddition(string line,char *option,int *r1, int *r2, int *r3, int *r4, 
				int *r5);
/*----------------------------------------------------------------------------*/
/* int makeSubtraction(string line,char *option,int *r1,int *r2,int *r3,      */
/*				int *r4, int *r5)                                             */
/* -----------                                                                */
/*		This function gets to instruction and registers for subtraction, then */
/*	prints the result if option is 1.                                         */
/*----------------------------------------------------------------------------*/
int makeSubtraction(string line,char *option,int *r1, int *r2, int *r3, int *r4,
				 int *r5);
/*----------------------------------------------------------------------------*/
/* int makeJump(string line,char *option,int *r1,int *r2,int *r3,int *r4,     */
/*				int *r5)                                                      */
/* -----------                                                                */
/*		This function gets to instruction and registers for jump, then        */
/*	prints the result if option is 1.                                         */
/*----------------------------------------------------------------------------*/
int makeJump(string line,char *option,int *r1, int *r2, int *r3, int *r4, 
				int *r5, ifstream &inFile);
/*----------------------------------------------------------------------------*/
/* int makePrint(string line,char *option,int *r1,int *r2,int *r3,int *r4,    */
/*				int *r5)                                                      */
/* -----------                                                                */
/*		This function gets to instruction and registers for print, then       */
/*	prints the result if option is 1.                                         */
/*----------------------------------------------------------------------------*/
int makePrint(string line,char *option,int *r1, int *r2, int *r3, int *r4, 
				int *r5);
/*----------------------------------------------------------------------------*/
/* int makeHalt()                                                             */
/* -----------                                                                */
/*		This function gets no arguments, and only finish the program.         */
/*----------------------------------------------------------------------------*/
int makeHalt(string line);
/*----------------------------------------------------------------------------*/
/* int getConstant(string line)                                               */
/* -------------                                                              */
/*		This function gets to line, and if instruction contains the constant, */
/*	calculates and returns it.                                                */
/*----------------------------------------------------------------------------*/
int getConstant(string line);
/*----------------------------------------------------------------------------*/
/* string removeSpaces(string line)                                           */
/* -------------                                                              */
/*		This function gets to line, and remove all spaces in line and return  */
/*	the spaceless line.                                                       */
/*----------------------------------------------------------------------------*/
string removeSpaces(string line);
/*----------------------------------------------------------------------------*/
/* string lowToUpper(string line)                                             */
/* ----------                                                                 */
/*		This function gets to line, and makes upper case all line and return  */
/*	the line.                                                                 */
/*----------------------------------------------------------------------------*/
string lowToUpper(string line);
/*----------------------------------------------------------------------------*/
/* string removeComments(string line)                                         */
/* ------------                                                               */
/*		This function gets to line, and remove comment if line contains and   */
/*	return line.                                                              */
/*----------------------------------------------------------------------------*/
string removeComments(string line);
/*----------------------------------------------------------------------------*/
int main(int argc, char** argv) {
  
    string nameOfFile;
    ifstream inFile(argv[1]);
    char *option=argv[2];
    string line,line1;
    int r1=0,r2=0,r3=0,r4=0,r5=0;
    int i,k,a=1,size,c=1; 
    
    if(argc!=3)
    {
    	cerr << "ERROR: INVALID COMMAND LINE PARAMETERS!!!\n";
    	return false;
   	}// eksik, fazla veya uygunsuz inputlar icin hata verir.	 
    if((*option!='0') && (*option!='1'))
    {
    	cerr << "ERROR: INVALID OPTION!!!\n";
    	return false;	
    }// 0-1 disindaki option'lar icin hata verir.
    if(!(inFile))
    {
    	cout << "ERRORS: FILE COULDN'T BE OPENED!!!\n";
    	return false;
    }// dosya acilamazsa hata verir.
  	while(!inFile.eof())
  	{ 			
		getline(inFile,line);
		line=lowToUpper(line);
		
		i=0;
		k=0;
		while(i<3)
		{
			if((line[k]>='A' && line[k]<='Z') || (line[k]>='a' && line[k]<='z'))
			{
				i++;
				k++;
			}
			else
				k++;
		}// instructiondaki komutun son harfini bulur.
		if(line[k]!=' ' && line[0]!='\0' && line[0]!='H')
		{
			cout << "ERROR: " << line << "-INVALID REGISTER\n"; 	
			return false;
		}// komut ile register arasinda bosluk olup olmadigini kontrol eder.
		size=line.length();
		
		i=0,k=0;
		while(i<size && line[i]!=';')
		{
			if(line[k]!=';')
			{
				i++;
				k++;
			}
			else
				k++;	
		}// satirda ; varsa indexini bulur.
			
		if(i!=size && line[i+1]!='\0')
		{
			if(line[i-1]!=' ')
				a=0;
			else
				line.erase(i,size); // yorum varsa siler.
		}
		else if(i!=size && line[i+1]=='\0')
			a=0;
		line=removeSpaces(line);
		
					
		
				
		if(a==0)
		{
			cout << "ERROR: " << line << "-INVALID REGISTER\n"; 	
			return false;
		}// noktali virgul yorum baslangici degilse hata verir.
		else if(a==1)
		{
			if(line[0]=='\0')
				return 0;
				
			if(line[0]=='M' && line[1]=='O' && line[2]=='V')
				a=makeMove(line,option,&r1,&r2,&r3,&r4,&r5);				
			
			else if(line[0]=='A' && line[1]=='D' && line[2]=='D')
				a=makeAddition(line,option,&r1,&r2,&r3,&r4,&r5);
			
			else if(line[0]=='S' && line[1]=='U' && line[2]=='B')
				a=makeSubtraction(line,option,&r1,&r2,&r3,&r4,&r5);
					
			else if(line[0]=='J' && line[1]=='M' && line[2]=='P')
				c=makeJump(line,option,&r1,&r2,&r3,&r4,&r5,inFile);
					
			else if(line[0]=='P' && line[1]=='R' && line[2]=='N')
				a=makePrint(line,option,&r1,&r2,&r3,&r4,&r5);
		
			else if(line[0]=='H' && line[1]=='L' && line[2]=='T')
				makeHalt(line);
			
			else 
			{
				cout << "ERROR: " << line << "-INVALID REGISTER\n";
				return false;
			}
			if(a==0 && line[0]!='\0')
			{
				cout << "ERROR: " << line << "-INVALID REGISTER\n"; 	
				return false;
			}
			else if(c==0)
			{
				cout << "ERROR: " << line << "-INVALID REGISTER\n"; 	
				return false;
			}
			
		}	
	}
	inFile.close();
	return true;
}
/*----------------------------------------------------------------------------*/
/*							Function Implementations                          */
/*----------------------------------------------------------------------------*/
/* Function makeMove                                                          */
/* ------------------                                                         */
/*		This function gets to instruction and registers for move, then        */
/*	prints the result if option is 1.                                         */

int makeMove(string line, char *option, int *r1, int *r2, int *r3, int *r4,
			 int *r5)
{
	int index=3,index1=3,constant;
	
	if(line[index]!='R')
	{
		return false;
	}	
	else
	{
		if(line[index1+1]>='1' && line[index1+1]<='5')
		{
			index=index1+1;
				
			if(line[index+1]==',')
			{	
				if(line[index+2]=='R')
				{
					if(line[index+4]!='\0')
						return false; 
						
					else if(line[index+3]>='1' && line[index+3]<='5')
					{
					
						if(line[index+3]=='1')
						{
							switch(line[index1+1])
							{
								case '1': *r1=*r1; break;
								case '2': *r1=*r2; break;
								case '3': *r1=*r3; break;
								case '4': *r1=*r4; break;
								case '5': *r1=*r5; break;
							}
						}		
						else if(line[index+3]=='2')
						{
							switch(line[index1+1])
							{
								case '1': *r2=*r1; break;
								case '2': *r2=*r2; break;
								case '3': *r2=*r3; break;
								case '4': *r2=*r4; break;
								case '5': *r2=*r5; break;
							}
						}
						else if(line[index+3]=='3')
						{
							switch(line[index1+1])
							{
								case '1': *r3=*r1; break;
								case '2': *r3=*r2; break;
								case '3': *r3=*r3; break;
								case '4': *r3=*r4; break;
								case '5': *r3=*r5; break;
							}
						}
						else if(line[index+3]=='4')
						{
							switch(line[index1+1])
							{
								case '1': *r4=*r1; break;
								case '2': *r4=*r2; break;
								case '3': *r4=*r3; break;
								case '4': *r4=*r4; break;
								case '5': *r4=*r5; break;
							}
						}
						else if(line[index+3]=='5')
						{
							switch(line[index1+1])
							{
								case '1': *r5=*r1; break;
								case '2': *r5=*r2; break;
								case '3': *r5=*r3; break;
								case '4': *r5=*r4; break;
								case '5': *r5=*r5; break;
							}
						}
						else
							return false;
					}
					
					if(*option=='1')
					{
					cout << "MOV " << 'R' << line[index1+1] << ",";	
					cout << 'R' << line[index+3] << "-";
					cout << "R1=" << *r1 << "," << "R2=" << *r2 << ","
					<< "R3=" << *r3 << "," << "R4=" << *r4 << ","
					<< "R5=" << *r5 << endl; 
					}
				}
				else if(line[index+2]>='0' && line[index+2]<='9')
				{	
					
					constant=getConstant(line);
					if(constant==-1)
						return false;	
					
					switch(line[index1+1])
					{
						case '1': *r1=constant; break;
						case '2': *r2=constant; break;
						case '3': *r3=constant; break;
						case '4': *r4=constant; break;
						case '5': *r5=constant; break;
					}
					if(*option=='1')
					{
						cout << "MOV " << 'R' << line[index1+1] << ",";	
						cout << constant << "-";
						cout << "R1=" << *r1 << "," << "R2=" << *r2 << ","
						<< "R3=" << *r3 << "," << "R4=" << *r4 << ","
						<< "R5=" << *r5 << endl; 
					}
				}
				else
					return false;
			}
			else
				return false;
		}
		else
			return false;
				
	}	 
	return true;
}
/*----------------------------------------------------------------------------*/
/* Function makeAddition                                                      */
/* ------------------                                                         */
/*		This function gets to instruction and registers for addition, then    */
/*	prints the result if option is 1.                                         */

int makeAddition(string line,char *option,int *r1, int *r2, int *r3, int *r4, 
				int *r5)
{
	int index=3,index1=3,constant;
	
	if(line[index]!='R')
	{
		return false;
	}	
	else
	{
		if(line[index1+1]>='1' && line[index1+1]<='5')
		{
			index=index1+1;
				
			if(line[index+1]==',')
			{	
				if(line[index+2]=='R')
				{
					if(line[index+4]!='\0')
						return false;
					
					else if(line[index+3]>='1' && line[index+3]<='5')
					{
						if(line[index+3]=='1')
						{
							switch(line[index1+1])
							{
								
								case '1': *r1=*r1+*r1; break;
								case '2': *r2=*r1+*r2; break;
								case '3': *r3=*r1+*r3; break;
								case '4': *r4=*r1+*r4; break;
								case '5': *r5=*r1+*r5; break;
							} 
						}	
						else if(line[index+3]=='2')
						{
							switch(line[index1+1])
							{
								case '1': *r1=*r2+*r1; break;
								case '2': *r2=*r2+*r2; break;
								case '3': *r3=*r2+*r3; break;
								case '4': *r4=*r2+*r4; break;
								case '5': *r5=*r2+*r5; break;
							}
						}
						else if(line[index+3]=='3')
						{
							switch(line[index1+1])
							{
								case '1': *r1=*r3+*r1; break;
								case '2': *r2=*r3+*r2; break;
								case '3': *r3=*r3+*r3; break;
								case '4': *r4=*r3+*r4; break;
								case '5': *r5=*r3+*r5; break;
							}
						}
						else if(line[index+3]=='4')
						{
							switch(line[index1+1])
							{
								case '1': *r1=*r4+*r1; break;
								case '2': *r2=*r4+*r2; break;
								case '3': *r3=*r4+*r3; break;
								case '4': *r4=*r4+*r4; break;
								case '5': *r5=*r4+*r5; break;
							}
						}
						else if(line[index+3]=='5')
						{
							switch(line[index1+1])
							{
								case '1': *r1=*r5+*r1; break;
								case '2': *r2=*r5+*r2; break;
								case '3': *r3=*r5+*r3; break;
								case '4': *r4=*r5+*r4; break;
								case '5': *r5=*r5+*r5; break;
							}
						}
						else
							return false;	
					}
					if(*option=='1')
					{
						cout << "ADD " << line[index1] << line[index1+1] << ",";	
						cout << line[index+2] << line[index+3] << "-";
						cout << "R1=" << *r1 << "," << "R2=" << *r2 << ","
						<< "R3=" << *r3 << "," << "R4=" << *r4 << ","
						<< "R5=" << *r5 << endl; 
					}
				}
				else if(line[index+2]>='0' && line[index+2]<='9')
				{	
				
					constant=getConstant(line);
					if(constant==0)
						return false;	
					
					switch(line[index1+1])
					{
						case '1': *r1+=constant; break;
						case '2': *r2+=constant; break;
						case '3': *r3+=constant; break;
						case '4': *r4+=constant; break;
						case '5': *r5+=constant; break;
					}
					if(*option=='1')
					{
						cout << "ADD " << 'R' << line[index1+1] << ",";	
						cout << constant << "-";
						cout << "R1=" << *r1 << "," << "R2=" << *r2 << ","
						<< "R3=" << *r3 << "," << "R4=" << *r4 << ","
						<< "R5=" << *r5 << endl; 
					}
				}
				else
				{
					return false;
				}
			}
			else
				return false;		
		}
		else
			return false;
			
	}
	return true;
}
/*----------------------------------------------------------------------------*/
/* Function makeSubtracion                                                    */
/* ------------------                                                         */
/*		This function gets to instruction and registers for subtraction, then */
/*	prints the result if option is 1.                                         */

int makeSubtraction(string line,char *option,int *r1, int *r2, int *r3, int *r4, 
					int *r5)
{	
	int index=3,index1=3,constant;
	
	if(line[index]!='R')
	{
		return false;
	}	
	else
	{
		if(line[index1+1]>='1' && line[index1+1]<='5')
		{
			index=index1+1;
				
			if(line[index+1]==',')
			{	
				if(line[index+2]=='R')
				{
					if(line[index+4]!='\0')
						return false;
					
					else if(line[index+3]>='1' && line[index+3]<='5')
					{
						if(line[index+3]=='1')
						{
							switch(line[index1+1])
							{
								
								case '1': *r1=*r1-*r1; break;
								case '2': *r2=*r1-*r2; break;
								case '3': *r3=*r1-*r3; break;
								case '4': *r4=*r1-*r4; break;
								case '5': *r5=*r1-*r5; break;
							} 
						}	
						else if(line[index+3]=='2')
						{
							switch(line[index1+1])
							{
								case '1': *r1=*r2-*r1; break;
								case '2': *r2=*r2-*r2; break;
								case '3': *r3=*r2-*r3; break;
								case '4': *r4=*r2-*r4; break;
								case '5': *r5=*r2-*r5; break;
							}
						}
						else if(line[index+3]=='3')
						{
							switch(line[index1+1])
							{
								case '1': *r1=*r3-*r1; break;
								case '2': *r2=*r3-*r2; break;
								case '3': *r3=*r3-*r3; break;
								case '4': *r4=*r3-*r4; break;
								case '5': *r5=*r3-*r5; break;
							}
						}
						else if(line[index+3]=='4')
						{
							switch(line[index1+1])
							{
								case '1': *r1=*r4-*r1; break;
								case '2': *r2=*r4-*r2; break;
								case '3': *r3=*r4-*r3; break;
								case '4': *r4=*r4-*r4; break;
								case '5': *r5=*r4-*r5; break;
							}
						}
						else if(line[index+3]=='5')
						{
							switch(line[index1+1])
							{
								case '1': *r1=*r5-*r1; break;
								case '2': *r2=*r5-*r2; break;
								case '3': *r3=*r5-*r3; break;
								case '4': *r4=*r5-*r4; break;
								case '5': *r5=*r5-*r5; break;
							}
						}
						else
							return false;	
					}
					if(*option=='1')
					{
						cout << "SUB " << 'R' << line[index1+1] << ",";	
						cout << 'R' << line[index+3] << "-";
						cout << "R1=" << *r1 << "," << "R2=" << *r2 << ","
						<< "R3=" << *r3 << "," << "R4=" << *r4 << ","
						<< "R5=" << *r5 << endl; 
					}
				}
				else if(line[index+2]>='0' && line[index+2]<='9')
				{		
					constant=getConstant(line);
					if(constant==0)
						return false;	
					
					switch(line[index1+1])
					{
						case '1': *r1-=constant; break;
						case '2': *r2-=constant; break;
						case '3': *r3-=constant; break;
						case '4': *r4-=constant; break;
						case '5': *r5-=constant; break;
					}
					if(*option=='1')
					{
						cout << "SUB " << 'R' << line[index1+1] << ",";	
						cout << constant << "-";
						cout << "R1=" << *r1 << "," << "R2=" << *r2 << ","
						<< "R3=" << *r3 << "," << "R4=" << *r4 << ","
						<< "R5=" << *r5 << endl; 
					}
				}
				else
					return false;
				
			}
			else
				return false;		
		}
		else
			return false;
			
	}
	return true;
}
/*----------------------------------------------------------------------------*/
/* Function makeJump                                                          */
/* ------------------                                                         */
/*		This function gets to instruction and registers for jump, then        */
/*	prints the result if option is 1.                                         */
int makeJump(string line,char *option,int *r1, int *r2, int *r3, int *r4, 
			int *r5, ifstream &inFile)
{
	int index=3,index1=3,constant,k,a=1;
	string newLine;
	
	if((line[index]!='R') && !(line[index]>='0' && line[index]<='9'))
	{
		return false;
	}	
	else
	{
		if((line[index]=='R') && (line[index+1]>='1' && line[index+1]<='5'))
		{
			index=index1+1;
				
			if(line[index+1]==',')
			{
				if(line[index+2]>='0' && line[index+2]<='9')
				{	
					constant=getConstant(line);
					if(constant==0)
						return false;	
						
					if(*option=='1')
					{
						cout << "JMP " << line[index1] << line[index1+1] << ",";	
						cout << constant << "-";
						cout << "R1=" << *r1 << "," << "R2=" << *r2 << ","
						<< "R3=" << *r3 << "," << "R4=" << *r4 << ","
						<< "R5=" << *r5 << endl; 
					}
					if((line[index1+1]=='1' && *r1==0) || 
						(line[index1+1]=='2' && *r2==0) || 
						(line[index1+1]=='3' && *r3==0) ||
						(line[index1+1]=='4' && *r4==0) || 
						(line[index1+1]=='5' && *r5==0))
					{	
						inFile.seekg(0); // dosyanin basina gider.
						
						for(k=0; k<constant; k++)
						{
							getline(inFile, newLine);
						}// constant kadar satir alir.
						newLine=removeComments(lowToUpper(removeSpaces(newLine)));
						// alinan satiri temizler.
						if(a==1)
						{
							if(newLine[0]=='M' && newLine[1]=='O' && 
								newLine[2]=='V')
								a=makeMove(newLine,option,r1,r2,r3,r4,r5);
						
							else if(newLine[0]=='A' && newLine[1]=='D' && 
								newLine[2]=='D')
								a=makeAddition(newLine,option,r1,r2,r3,r4,r5);
					
							else if(newLine[0]=='S' && newLine[1]=='U' && 
								newLine[2]=='B')
								a=makeSubtraction(newLine,option,r1,r2,r3,r4,r5);
				
							else if(newLine[0]=='J' && newLine[1]=='M' && 
								newLine[2]=='P')
								a=makeJump(newLine,option,r1,r2,r3,r4,r5,inFile);
		
							else if(newLine[0]=='P' && newLine[1]=='R' && 
								newLine[2]=='N')
								a=makePrint(newLine,option,r1,r2,r3,r4,r5);
						
							else if(newLine[0]=='H' && newLine[1]=='L' && 
								newLine[2]=='T')
								makeHalt(line);
								
							else
								a=0;
							
							if(a==0)
							{
								cout << "ERROR: " << newLine << 
									"-INVALID REGISTER\n"; 	
								return false;
							}
						}
						
					}
				}
				else
					return false;
			}
			else
				return false;
		}
		else if(line[index]>='0' && line[index]<='9')
		{
			constant=getConstant(line);
			if(constant==0)
				return false;	
			
			if(*option=='1')
			{
				cout << "JMP " << constant << "-";
				cout << "R1=" << *r1 << "," << "R2=" << *r2 << ","
				<< "R3=" << *r3 << "," << "R4=" << *r4 << ","
				<< "R5=" << *r5 << endl;
	
			}
			inFile.seekg(0); // dosyanin basina gider.

			for(k=0; k<constant; k++)
			{
				getline(inFile, newLine);
			}// constant kadar satir alir.
			newLine=removeComments(lowToUpper(removeSpaces(newLine)));
			// satiri temizler.
			if(a==1)
			{
				if(newLine[0]=='M' && newLine[1]=='O' && newLine[2]=='V')
					a=makeMove(newLine,option,r1,r2,r3,r4,r5);
			
				else if(newLine[0]=='A' && newLine[1]=='D' && newLine[2]=='D')
					a=makeAddition(newLine,option,r1,r2,r3,r4,r5);
		
				else if(newLine[0]=='S' && newLine[1]=='U' && newLine[2]=='B')
					a=makeSubtraction(newLine,option,r1,r2,r3,r4,r5);
	
				else if(newLine[0]=='J' && newLine[1]=='M' && newLine[2]=='P')
					a=makeJump(newLine,option,r1,r2,r3,r4,r5,inFile);

				else if(newLine[0]=='P' && newLine[1]=='R' && newLine[2]=='N')
					a=makePrint(newLine,option,r1,r2,r3,r4,r5);
			
				else if(newLine[0]=='H' && newLine[1]=='L' && newLine[2]=='T')
					makeHalt(line);
				
				else
					a=0;
					
				if(a==0)
				{
					cout << "ERROR: " << newLine << "-INVALID REGISTER\n"; 	
					return false;
				}
			}
		}
		else
			return false;
	}
	return true;
}
/*----------------------------------------------------------------------------*/
/* Function makePrint                                                         */
/* ------------------                                                         */
/*		This function gets to instruction and registers for print, then       */
/*	prints the result if option is 1.                                         */

int makePrint(string line,char *option,int *r1, int *r2, int *r3, int *r4, 
				int *r5)
{
	int index=3,constant;
	
	if((line[index]!='R') && !(line[index]>='0' && line[index]<='9'))	
		return false;
		
	else
	{		
		if((line[index]=='R') && (line[index+1]>='1' && line[index+1]<='5'))
		{
			if(line[index+2]!='\0')
				return false;
				
			else if(*option=='1'){
								
				cout << "PRN " << 'R' << line[index+1] << "-" 
				<< "R1=" << *r1 << "," << "R2=" << *r2 << ","
				<< "R3=" << *r3 << "," << "R4=" << *r4 << ","
				<< "R5=" << *r5 << endl; 
						
			}
			if(line[index+1]=='1')
				cout << line[index] << line[index+1] << "=" << *r1;
				
			else if(line[index+1]=='2')
				cout << line[index] << line[index+1] << "=" << *r2;
			
			else if(line[index+1]=='3')
				cout << line[index] << line[index+1] << "=" << *r3;
			
			else if(line[index+1]=='4')
				cout << line[index] << line[index+1] << "=" << *r4;
			
			else if(line[index+1]=='5')
				cout << line[index] << line[index+1] << "=" << *r5;
	
				cout << endl;
				
		}
		else if(line[index]>='0' && line[index]<='9')
		{			    
			constant=getConstant(line);
			if(constant==-1)
				return false;	
			
			cout << endl << constant;
			
			if(*option=='1')
			{			
				cout << "\nPRN " << constant << "-" 
				<< "R1=" << *r1 << "," << "R2=" << *r2 << ","
				<< "R3=" << *r3 << "," << "R4=" << *r4 << ","
				<< "R5=" << *r5 << endl; 
					
			}
		}
		else
			return false;
	
	}
	return true;
}
/*----------------------------------------------------------------------------*/
/* Function makeHalt                                                          */
/* -----------                                                                */
/*		This function gets no arguments, and only finish the program.         */

int makeHalt(string line)
{
	cout << "HALT\n";
	
	return true;
}
/*----------------------------------------------------------------------------*/
/* Function getConstant                                                       */
/* -------------                                                              */
/*		This function gets to line, and if instruction contains the constant, */
/*	calculates and returns it.                                                */

int getConstant(string line)
{
	string constant;
	int index;
	int i=0,j=0,k,c=0,sizeNew;
	
	sizeNew=line.length();
	
	if(line[3]=='R')
	{
		while(line[c]!=',')
			c++;
	}
	else
		c=2;
	
	index=c+1;
	
	while(index<sizeNew)
	{ 	
		if((line[index]>='0' && line[index]<='9')){
							
			constant[i]=line[index];		
			index++;		
			i++;
		}
		else
			return -1;
	}
	for(k=0; k<i; k++)
	{
		j=10*j+(constant[k]-'0');
	}
	return j;
}
/*----------------------------------------------------------------------------*/
/* Function removeSpaces                                                      */
/* -------------                                                              */
/*		This function gets to line, and remove all spaces in line and return  */
/*	the spaceless line.                                                       */

string removeSpaces(string line){

	int size,i;
		
	size=line.length();
	
	for(i=size-1; i>=0; --i)
	{
 		if(line[i]==' ')
 		{
 			line.erase(i,1);
 		}	
	}
	return line;
}
/*----------------------------------------------------------------------------*/
/* Function lowToUpper                                                        */
/* ----------                                                                 */
/*		This function gets to line, and makes upper case all line and return  */
/*	the line.                                                                 */

string lowToUpper(string line)
{
	int size,i;
	
	size=line.length();
	
	for(i=0; i<size; i++)
	{
		if(line[i]>='a' && line[i]<='z')
			line[i]=line[i]+('A'-'a');
	}
	return line;
}
/*----------------------------------------------------------------------------*/
/* Function removeComments                                                    */
/* ------------                                                               */
/*		This function gets to line, and remove comment if line contains and   */
/*	return line.                                                              */

string removeComments(string line)
{
	
	int i=0,k=0,a;
	int size;
	
	size=line.length();
				
	i=0,k=0;
	while(i<size && line[i]!=';')
	{
		if(line[k]!=';')
		{
			i++;
			k++;
		}
		else
			k++;	
	}
	if(i!=size && line[i+1]!='\0')
		line.erase(i,size);
	
	else if(i!=size && line[i+1]=='\0')
		a=0;
			
	if(a==0)
	{
		cout << "ERROR: " << line << "-INVALID REGISTER\n"; 	
		return 0;
	}
	
	return line;
}
/*----------------------------------------------------------------------------*/
/*							End of main.cpp                                   */
/*----------------------------------------------------------------------------*/
