/*----------------------------------------------------------------------------*/
/*                                                                            */
/* HW02_141044016_Yagmur_Karaman                                              */
/*                                                                            */
/* main.cpp                                                                   */
/* ---------                                                                  */
/* Created on 15/10/2016 by Yagmur_Karaman                                    */
/*                                                                            */
/* Description                                                                */
/* -------------                                                              */
/*	The main.cpp contains the implementations of functions for the            */
/*	homework II, which are used the design CPU.                               */
/*                                                                            */
/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/*                            Includes                                        */
/*----------------------------------------------------------------------------*/
#include <iostream>
#include <fstream>
#include <string>
/*----------------------------------------------------------------------------*/
using namespace std;

/*----------------------------------------------------------------------------*/
/*                        Function Prototypes                                 */
/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* string lowToUpper(string line)                                             */
/* ---------------                                                            */
/* Description                                                                */
/* ------------                                                               */
/*		This function takes line and convert upper all letters, and return    */
/*		line with upper letters.                                              */
/*----------------------------------------------------------------------------*/
string lowToUpper(string line);
/*----------------------------------------------------------------------------*/
/* int findFirst(string line)                                                 */
/* ---------------------------                                                */
/* Description                                                                */
/* ------------                                                               */
/*		This function takes line and find first nonspace index and return     */
/*		index.                                                                */
/*----------------------------------------------------------------------------*/
int findFirst(string line);
/*----------------------------------------------------------------------------*/
/* int isValid(string line, int first)                                        */
/* ---------------------                                                      */
/* Description                                                                */
/* ------------                                                               */
/*		This function takes line and first nonspace index, and control        */
/*		first nonspace index in line is valid or invalid.                     */
/*      Return 1 on success, 0 on error.                                      */
/*----------------------------------------------------------------------------*/ 
int isValid(string line, int first);
/*----------------------------------------------------------------------------*/
/* int spaceForReg(string line, int first)                                    */
/* -------------------                                                        */
/* Description                                                                */
/* ------------                                                               */
/*		This function takes line and first nonspace index, and control        */
/*		space after command.                                                  */
/*		Return 1 on success, 0 on error.                                      */
/*----------------------------------------------------------------------------*/
int spaceForReg(string line, int first);
/*----------------------------------------------------------------------------*/
/* int findFirstInst(string line, int first)                                  */
/* ------------------                                                         */
/* Description                                                                */
/* ------------                                                               */
/*		This function takes line and first nonspace index, and find           */
/*		first nonspace index after the command, and return this index.        */
/*----------------------------------------------------------------------------*/
int findFirstInst(string line,int first);
/*----------------------------------------------------------------------------*/
/* int controlValid(string line, int regOrConst)                              */
/* ------------------                                                         */
/* Description                                                                */
/* ------------                                                               */
/*		This function takes line and first nonspace index after command       */
/*		(regOrConst), and control this index valid or invalid.                */
/*		Return 1 on success, 0 on error.                                      */
/*----------------------------------------------------------------------------*/
int controlValid(string line,int regOrConst);
/*----------------------------------------------------------------------------*/
/* int controlComments(string line)                                           */
/* ------------------                                                         */
/* Description                                                                */
/* ------------                                                               */
/*		This function takes line control comments are valid or invalid.       */
/*		After instruction, if line have ; and some comments after ; or        */
/*		line does not have ; and some comments return 1(success);             */
/*      if line have ; but does not have some comments after ; or line        */
/*      have some comments but does not have ; before comments,               */
/*		return 0(error).                                                      */
/*----------------------------------------------------------------------------*/
int controlComments(string line);
/*----------------------------------------------------------------------------*/
/* string removeComments(string line)                                         */
/* --------------------                                                       */
/* Description                                                                */
/* ------------                                                               */
/*		This function takes line and and if line have some comments           */
/*		remove these, and return cleaned line.                                */
/*----------------------------------------------------------------------------*/
string removeComments(string line);
/*----------------------------------------------------------------------------*/
/* int controlSpace(string line, int regOrConst)                              */
/* --------------------                                                       */
/* Description                                                                */
/* ------------                                                               */
/*		This function takes line and control all spaces are valid             */
/*		or invalid, return 1 on success, 0 on error.                          */
/*----------------------------------------------------------------------------*/    
int controlSpace(string line,int regOrConst);
/*----------------------------------------------------------------------------*/
/* string removeSpaces(string line)                                           */
/* -----------------                                                          */
/* Description                                                                */
/* ------------                                                               */
/*		This function takes line and remove all spaces, and return            */
/*		cleaned line.                                                         */
/*----------------------------------------------------------------------------*/
string removeSpaces(string line);
/*----------------------------------------------------------------------------*/
/* int register1(string line)                                                 */
/* ----------------                                                           */
/* Description                                                                */
/* ------------                                                               */
/*		This function takes line and if line have register after command,     */
/*		find its value, and control is it between 1-5, return register value  */
/*		on success, -1 on invalid register and 0 on other errors.             */
/*----------------------------------------------------------------------------*/
int register1(string line);
/*----------------------------------------------------------------------------*/
/* int register2(string line)                                                 */
/* ----------------                                                           */
/* Description                                                                */
/* ------------                                                               */
/*		This function takes line and if line have register after comma,       */
/*		find its value, and control is it between 1-5, return register value  */
/*		on success, -1 on invalid register and 0 on other errors.             */
/*----------------------------------------------------------------------------*/
int register2(string line);
/*----------------------------------------------------------------------------*/
/* int constant(string line)                                                  */
/* ----------------                                                           */
/* Description                                                                */
/* ------------                                                               */
/*		This function takes line and if line have constant find its value,    */
/*		and return constant value on success, -1 on error.                    */
/*----------------------------------------------------------------------------*/
int constant(string line);
/*----------------------------------------------------------------------------*/
/* int memoryCons(string line)                                                */
/* ---------------                                                            */
/* Description                                                                */
/* ------------                                                               */
/*		This function takes line and if line have memory address,             */
/*		calculate it, and return memory address value on success, -1 on error.*/
/*----------------------------------------------------------------------------*/
int memoryCons(string line);
/*----------------------------------------------------------------------------*/
/* int isWhichInstruction(string line,unsigned int* memory,int *reg, int reg1,*/ 
/* int reg2, int cons,int memo,ifstream &inFile,char *option)                 */
/* -------------------------------                                            */
/* Description                                                                */
/* ------------                                                               */
/*		This function calls instruction functions.                            */
/*----------------------------------------------------------------------------*/
int isWhichInstruction(string line,unsigned int* memory,int *reg, int reg1, 
				int reg2, int cons,int memo,ifstream &inFile,char *option);
/*----------------------------------------------------------------------------*/
/* int isMov(string line,unsigned int* memory,int *reg, int reg1, int reg2,   */ 
/*		int cons,int memo)                                                    */
/* -----------------------------                                              */
/* Description                                                                */
/* ------------                                                               */
/*		This function relaizes MOV command.                                   */
/*----------------------------------------------------------------------------*/
int isMov(string line,unsigned int* memory,int *reg, int reg1, int reg2, 
		int cons,int memo);
/*----------------------------------------------------------------------------*/
/* int isAdd(string line,unsigned int* memory,int *reg, int reg1, int reg2,   */ 
/*		int cons,int memo)                                                    */
/* -----------------------------                                              */
/* Description                                                                */
/* ------------                                                               */
/*		This function relaizes ADD command.                                   */
/*----------------------------------------------------------------------------*/
int isAdd(string line,unsigned int* memory,int *reg, int reg1, int reg2, 
		int cons,int memo);
/*----------------------------------------------------------------------------*/
/* int isSub(string line,unsigned int* memory,int *reg, int reg1, int reg2,   */ 
/*		int cons,int memo)                                                    */
/* -----------------------------                                              */
/* Description                                                                */
/* ------------                                                               */
/*		This function relaizes SUB command.                                   */
/*----------------------------------------------------------------------------*/
int isSub(string line,unsigned int* memory,int *reg, int reg1, int reg2, 
		int cons,int memo);
/*----------------------------------------------------------------------------*/
/* int isJmp(string line,unsigned int* memory,int *reg, int reg1, int reg2,   */
/*		int cons,int memo,ifstream &inFile,char *option)                      */
/* -----------------------------                                              */
/* Description                                                                */
/* ------------                                                               */
/*		This function relaizes JMP command.                                   */
/*----------------------------------------------------------------------------*/
int isJmp(string line,unsigned int* memory,int *reg, int reg1, int reg2, 
		int cons,int memo,ifstream &inFile,char *option);
/*----------------------------------------------------------------------------*/
/* int isJpn(string line,unsigned int* memory,int *reg, int reg1, int reg2,   */ 
/*		int cons,int memo,ifstream &inFile,char *option)                      */
/* -----------------------------                                              */
/* Description                                                                */
/* ------------                                                               */
/*		This function relaizes JPN command.                                   */
/*----------------------------------------------------------------------------*/
int isJpn(string line,unsigned int* memory,int *reg, int reg1, int reg2, 
		int cons,int memo,ifstream &inFile,char *option);
/*----------------------------------------------------------------------------*/
/* int isPrn(string line,unsigned int* memory,int *reg, int reg1, int reg2,   */ 
/*		int cons,int memo)                                                    */
/* -----------------------------                                              */
/* Description                                                                */
/* ------------                                                               */
/*		This function relaizes PRN command.                                   */
/*----------------------------------------------------------------------------*/
int isPrn(string line,unsigned int* memory,int *reg, int reg1, int reg2, 
		int cons,int memo);
/*----------------------------------------------------------------------------*/
/* void isHlt(unsigned int* memory, int *reg)                                 */
/* ------------------------                                                   */
/* Description                                                                */
/* ------------                                                               */
/*		This function relaizes HLT command, exits program.                    */
/*----------------------------------------------------------------------------*/
void isHlt(unsigned int* memory,int *reg);
/*----------------------------------------------------------------------------*/
/* string newLineJump(string line,int cons,ifstrean &inFile)                  */
/* ---------------------------                                                */
/* Description                                                                */
/* ------------                                                               */
/*		This function get the line for JMP or JPN commands and return this    */
/*		new line.                                                             */
/*----------------------------------------------------------------------------*/
string newLineJump(string line,int cons,ifstream &inFile);
/*----------------------------------------------------------------------------*/
/* int allControls(string line,unsigned int* memory,int *reg,                 */
/*			ifstream& inFile,char *option)                                    */
/* -------------------------------                                            */
/* Description                                                                */
/* ------------                                                               */
/*		This function is base function to our CPU program. All controls are   */
/*		made in this function. Return 1 on success, 0 on error and            */
/*		exit program.                                                         */
/*----------------------------------------------------------------------------*/
int allControls(string line,unsigned int* memory,int *reg,ifstream& inFile,
		char *option);
/*----------------------------------------------------------------------------*/
/* void printResult(string line,unsigned int* memory,int *reg,int reg1,       */
/*			int reg2,int cons,int memo)								          */
/* ---------------------------------                                          */
/* Description                                                                */
/* ------------                                                               */
/*		This function print result according to option.                       */
/*		If option is 0, only print last values of registers and memory.       */
/*		Else if option is 1, print registers for each line, and when          */
/*		program come to HLT, print last values registers and memory.          */
/*		Else if option is 2, print registers and memory for each line, and    */
/*		when program come to HLT, print last values registers and memory.     */
/*----------------------------------------------------------------------------*/
void printResult(string line,unsigned int* memory,int *reg,int reg1,
		int reg2,int cons,int memo);
/*----------------------------------------------------------------------------*/
/* void printMemory(unsigned int* memory)                                     */
/* ------------------------                                                   */
/* Description                                                                */
/* ------------                                                               */
/*		This function prints all contents of memory.                          */
/*----------------------------------------------------------------------------*/
void printMemory(unsigned int* memory);

int main(int argc, char** argv)
{
	string nameOfFile;
    ifstream inFile(argv[1]);
    char *option=argv[2];
    string line;
	int reg[5]={0};
	unsigned int memory[50]={0};
    int lineCounter;
    int const MAX_LINES=200;
    
    if(argc!=3)
    {
    	cerr << "ERROR: INVALID COMMAND LINE PARAMETERS!!!\n";
    	return false;
   	}// eksik, fazla veya uygunsuz inputlar icin hata verir.	 
    if((*option!='0') && (*option!='1') && (*option!='2'))
    {
    	cerr << "ERROR: INVALID OPTION!!!\n";
    	return false;	
    }// 0-1-2 disindaki option'lar icin hata verir.
    if(!(inFile))
    {
    	cerr << "ERRORS: FILE COULDN'T BE OPENED!!!\n";
    	return false;
    }// dosya acilamazsa hata verir.
    lineCounter=0;
    while(!inFile.eof())
    {
    	getline(inFile,line);
    	++lineCounter;
    }// dosyadaki line sayisini sayar.	
    if(lineCounter-2==MAX_LINES)
    {
    	cerr<<"ERROR: THE .TXT FILE CAN BE MOST 200 LINES!!!\n";
    	return 0;
    }// 200 den fazla line var ise hata verir.
    else
	{
		inFile.close();
		inFile.open(argv[1]);// dosyanin basina gelir.	
		while(!inFile.eof())
	  	{	 			
			getline(inFile,line);
			if(!(allControls(line,memory,reg,inFile,option)))
				return 0;
		}// dosya sonuna kadar line alir ve programa sokar.
	}
	inFile.close();// dosya kapandi.
	return 0;
}
/*----------------------------------------------------------------------------*/
/*					    Functions Implementations                             */
/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Function allControls                                                       */
/* ---------------------                                                      */
/*		This function is base function to our CPU program. All controls are   */
/*		made in this function. Return 1 on success, 0 on error and            */
/*		exit program.                                                         */

int allControls(string line,unsigned int* memory,int* reg,ifstream& inFile,
															char *option)
{
    int first,regOrConst;
    int reg1,reg2,cons,memo;
    
	line=lowToUpper(line);// buyuk harfe cevirir.
	first=findFirst(line);// ilk harfin indexini bulur.

	if(line[first]=='H')
	{
		isHlt(memory,reg); //eger HLT gelirse programi bitirir. 
		return 0;
	}
	else if(line[first]=='\0')
		return 0;
	
	if(!(isValid(line,first)))				 						 		
	{
		cerr << "ERROR: " << line << "-INVALID COMMAND OR SPACES UNTIL COMMAND!!!\n";
		return 0;	
	}// komut uygunsuzsa hata mesaji verip programi bitirir.		
	if(!(spaceForReg(line,first)))
	{
		cerr << "ERROR: " << line << "-INVALID SPACE AFTER COMMAND!!!\n";
		return 0;
	}// komuttan sonra en az 1 tane bosluk yoksa hata mesaji verip programi bitirir.
	
	// komuttan sonra gelen instructionin indexini bulur.
	regOrConst=findFirstInst(line,first); 
	 
	if(!(controlValid(line,regOrConst)))  
	{
		cerr << "ERROR: " << line << "-IT IS NOT REGISTER OR CONSTANT!!!\n";
		return 0;
	}// instructionin uygun degilse hata mesaji verip programi bitirir.
	if(!controlComments(line))
	{
		cerr << "ERROR: " << line << "-PLEASE CONTROL YOUR COMMENTS!!!\n";	
		return 0;
	}// instructionda yorum varsa uygun olup olmadigina bakar, uygun degilse
	// hata mesaji verip programi bitirir.
	line=removeComments(line);// yorum varsa ve uygunsa siler.	
	if(!(controlSpace(line,regOrConst))) // 
	{
		cerr << "ERROR: " << line << "-THERE IS INVALID SPACES IN INSTRUCTION!!!\n";	
		return 0;
	}// instructiondaki tüm bosluklari kontrol eder, uygun degilse hata mesaji
	// verip programi bitirir.
	line=removeSpaces(line);// bosluklari siler.
	reg1=register1(line);// ilk registerin degerini bulur.
	reg2=register2(line);// virgulden sonraki registerin degerini bulur.
	cons=constant(line);// constant degerini hesaplar.
	memo=memoryCons(line);// memory location degerini hesaplar.

	if(memo==-2)
	{
		cerr << "ERROR: " << line << "-MEMORY CAN NOT CONTAIN NEGATIVE VALUES\n"
			<< "                 OR CAN NOT BE SMALLER 0 OR BIGGER 49!!!\n";
		return 0;
	}	
	else if(reg1==0 || reg2==0)
	{
		cerr << "ERROR: "<< line << "INVALID REGISTER FOR INSTRUCTION\n";
		return 0;
	}	
	// satirdaki komut uygunsa calistirir, degilse hata mesaji verip 
	// programi bitirir.
	if(!(isWhichInstruction(line,memory,reg,reg1,reg2,cons,memo,inFile,option)))	
		return 0; 
	
	if(*option=='1' && (line[0]!='J' && line[1]!='M'))
		printResult(line,memory,reg,reg1,reg2,cons,memo);
	
	else if(*option=='2' && (line[0]!='J' && line[1]!='M'))
	{	
		cout << "-------------------------------------------------------------"
			"----------------"<< endl;
		printResult(line,memory,reg,reg1,reg2,cons,memo);
		printMemory(memory);
	}
	return 1;
}
/*----------------------------------------------------------------------------*/
/* Function isWhichInstruction                                                */
/* --------------------                                                       */
/*		This function calls instruction functions.                            */

int isWhichInstruction(string line,unsigned int* memory,int *reg, int reg1, 
					int reg2, int cons,int memo, ifstream &inFile,char *option)
{	
	if(line[0]=='M')
		isMov(line,memory,reg,reg1,reg2,cons,memo);
		
	else if(line[0]=='A')
		isAdd(line,memory,reg,reg1,reg2,cons,memo);
	
	else if(line[0]=='S')
		isSub(line,memory,reg,reg1,reg2,cons,memo);
	
	else if(line[0]=='J' && line[1]=='M')
	{	
		if(!(isJmp(line,memory,reg,reg1,reg2,cons,memo,inFile,option)))
			return 0;
	}
	else if(line[0]=='P')
		isPrn(line,memory,reg,reg1,reg2,cons,memo);
	
	else if(line[0]=='J' && line[1]=='P')
	{
		if(!(isJpn(line,memory,reg,reg1,reg2,cons,memo,inFile,option)))
			return 0;
	}
	return 1;
}
/*----------------------------------------------------------------------------*/
/* Function isMov                                                             */
/* --------------                                                             */
/*		This function relaizes MOV command.                                   */

int isMov(string line,unsigned int* memory,int *reg, int reg1, int reg2, 
			int cons,int memo)
{
	if(cons==-1 && memo==-1)
		reg[reg2-1]=reg[reg1-1]; 
		
	else if(memo==-1 && reg2==-1)
		reg[reg1-1]=cons;
					
	else if(reg2==-1 && cons==-1)
	{
		if(line[3]=='R')
			memory[memo]=reg[reg1-1];
			
		else if(line[3]=='#')
			reg[reg1-1]=memory[memo];	
	}
	else if(reg1==-1 && reg2==-1)
		memory[memo]=cons;
	
	else if(reg1==-1 && cons==-1)
	{
		if(line[3]=='#')
			reg[reg2-1]=memory[memo];
		
		else if(line[3]=='R')
			memory[memo]=reg[reg2-1];
	}
	return 1;					
}
/*----------------------------------------------------------------------------*/
/* Function isAdd                                                             */
/* ----------------                                                           */
/*		This function relaizes ADD command.                                   */

int isAdd(string line,unsigned int* memory,int *reg, int reg1, int reg2, 
			int cons,int memo)
{
	if(cons==-1 && memo==-1)
		reg[reg1-1]+=reg[reg2-1];

	else if(memo==-1 && reg2==-1)
		reg[reg1-1]+=cons;
		
	else if(reg2==-1 && cons==-1)
		reg[reg1-1]+=memory[memo];
		
	return 1;	
}
/*----------------------------------------------------------------------------*/
/* Function isSub                                                             */
/* ----------------                                                           */
/*		This function relaizes SUB command.                                   */

int isSub(string line,unsigned int* memory,int *reg, int reg1, int reg2, 
			int cons,int memo)
{
	if(cons==-1 && memo==-1)
		reg[reg1-1]-=reg[reg2-1];

	else if(memo==-1 && reg2==-1)
		reg[reg1-1]-=cons;
	
	else if(reg2==-1 && cons==-1)
		reg[reg1-1]-=memory[memo];
	
	return 1;	
}
/*----------------------------------------------------------------------------*/
/* Function isJmp                                                             */
/* ----------------                                                           */
/*		This function relaizes JMP command.                                   */

int  isJmp(string line,unsigned int* memory,int *reg, int reg1, int reg2, 
			int cons,int memo,ifstream &inFile,char *option)
{
 	if(*option=='1')
		printResult(line,memory,reg,reg1,reg2,cons,memo);
	
	if(reg1==-1)
	{
		line=newLineJump(line,cons,inFile);
		if(!(allControls(line,memory,reg,inFile,option)))
			return 0;
	}
	else if(reg[reg1-1]==0)
	{
		line=newLineJump(line,cons,inFile);
		if(!(allControls(line,memory,reg,inFile,option)))
			return 0;
	}
	else
	{
		while(!inFile.eof())
		{
			getline(inFile,line);
			if(!(allControls(line,memory,reg,inFile,option)))
				return 0;
		}
	}
	return 1;
}
/*----------------------------------------------------------------------------*/
/* Function isJpn                                                             */
/* ----------------                                                           */
/*		This function relaizes JPN command.                                   */

int isJpn(string line,unsigned int* memory,int *reg, int reg1, int reg2, 
			int cons,int memo,ifstream &inFile,char *option)
{
	if(*option=='1')
		printResult(line,memory,reg,reg1,reg2,cons,memo);
	
	if(reg2==-1 && memo==-1)
	{
		if(reg[reg1-1]<=0)
		{	
			line=newLineJump(line,cons,inFile);			
			if(!(allControls(line,memory,reg,inFile,option)))
				return 0;
		}
		else
		{
			while(!inFile.eof())
			{
				getline(inFile,line);
				if(!(allControls(line,memory,reg,inFile,option)))
					return 0;
			}
		}
	}
	return 1;
}
/*----------------------------------------------------------------------------*/
/* Function isPrn                                                             */
/* ----------------                                                           */
/*		This function relaizes PRN command.                                   */

int isPrn(string line,unsigned int* memory,int *reg, int reg1, int reg2, 
			int cons,int memo)
{
	if(cons==-1 && memo==-1)	
		cout << reg[reg1-1] << endl;
	
	else if(reg1==-1 && memo==-1)
		cout << cons << endl;
	
	else if(reg1==-1 && cons==-1)
		cout << memory[memo] << endl;	
	
	return 1;	
}
/*----------------------------------------------------------------------------*/
/* Function isAdd                                                             */
/* ----------------                                                           */
/*		This function relaizes HLT command, exits program.                    */

void isHlt(unsigned int* memory,int *reg)
{
	cout << "-------------------------------------------------------------"
			"----------------"<< endl;
	cout << "HALT!\n";
	cout << "HLT-"<<"R1="<<reg[0]<<",R2="<<reg[1]<<",R3="<<reg[2]<<",R4="<<
			reg[3]<<",R5="<<reg[4]<<endl;
		
	printMemory(memory);		
	
	return;
}
/*----------------------------------------------------------------------------*/
/* Function isValid                                                           */
/* ------------------                                                         */
/*		This function takes line and first nonspace index, and control        */
/*		first nonspace index in line is valid or invalid.                     */
/*      Return 1 on success, 0 on error.                                      */

int isValid(string line, int first)
{
	
	if(line[first]=='M' && line[first+1]=='O' && line[first+2]=='V')
		return 1;
	
	else if(line[first]=='A' && line[first+1]=='D' && line[first+2]=='D')
		return 1;
		
	else if(line[first]=='S' && line[first+1]=='U' && line[first+2]=='B')
		return 1;
	
	else if(line[first]=='J' && line[first+1]=='M' && line[first+2]=='P')
		return 1;
		
	else if(line[first]=='P' && line[first+1]=='R' && line[first+2]=='N')
		return 1;
		
	else if(line[first]=='J' && line[first+1]=='P' && line[first+2]=='N')
		return 1;
		
	return 0;
}
/*----------------------------------------------------------------------------*/
/* Function removeSpaces                                                      */
/* ----------------------                                                     */
/*		This function takes line and and if line have some comments           */
/*		remove these, and return cleaned line.                                */

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
/* Function controlSpace                                                      */
/* ----------------------                                                     */
/*		This function takes line and control all spaces are valid             */
/*		or invalid, return 1 on success, 0 on error.                          */

int controlSpace(string line,int regOrConst)
{
	int i,size,sizetemp;
	string temp;

	temp=removeSpaces(line);
	sizetemp=temp.length();
	size=line.length();
	
	if(line[regOrConst]=='R')
	{
		if(line[regOrConst+1]>='1' && line[regOrConst+1]<='5')
		{
			i=regOrConst+2;
			while(line[i]!=',' && sizetemp!=5)
			{
				if(line[i]==' ')
					i++;	
					
				else 
					return 0;	
			}
			++i;
			while(line[i]==' ')
				++i;
			
			if(line[0]='P')
				return 1;
				
			else if((line[i]>='0' && line[i]<='9') || line[i]=='#')
			{
				++i;
				while((line[i]>='0' && line[i]<='9') && i!=size)
					++i;
	
				while(i!=size)
				{
					if(line[i]!=' ')
						return 0;
					else
						++i;
				}
			}	
		}
		else
			return 0;	
	}	
	else if(line[regOrConst]>='0' && line[regOrConst]<='9')
	{	
		i=regOrConst;
		while((line[i]>='0' && line[i]<='9') && i!=size)
			++i;
		
		while(i!=size)
		{
			if(line[i]!=' ')
				return 0;
			else
				++i;	
		}
	}
	else if(line[regOrConst]=='#')
	{
		i=regOrConst+1;
		while((line[i]>='0' && line[i]<='9') && line[i]!=',')
			++i;
			
		if(line[i]==',')
		{
			++i;
			while(line[i]==' ')
				++i;
					
			if(line[i]=='R')
			{
				if(line[i+1]>='1' && line[i+1]<='5')
				{
					i=i+2;
					if(i!=size)
					{
						while(i!=size)
						{
							if(line[i]!=' ')
								return 0;
							else
								++i;	
						}
					}
					else
						return 1;
				}
			}
			else if(line[i]>='0' && line[i]<='9')
			{
				while((line[i]>='0' && line[i]<='9') && i!=size)
					++i;
	
				while(i!=size)
				{
					if(line[i]!=' ')
						return 0;
					else
						++i;
				}
			}		
		}
		else if(i==size && temp[0]=='P') 
			return 1;

		else
			return 0;		
	}
	return 1;
}
/*----------------------------------------------------------------------------*/
/* Function controlComments                                                   */
/* ------------------------                                                   */
/*		This function takes line control comments are valid or invalid.       */
/*		After instruction, if line have ; and some comments after ; or        */
/*		line does not have ; and some comments return 1(success);             */
/*      if line have ; but does not have some comments after ; or line        */
/*      have some comments but does not have ; before comments,               */
/*		return 0(error).                                                      */

int controlComments(string line)
{
	int i=0;
	int size;
	
	size=line.length();
	i=line.find(";");
	i++;
				
	if(i>0)
	{
		while(i!=size)
		{
			if(line[i]==' ')
				i++;
				
			else
				line.erase(i,size);
				return 1;
			
		}
		return 0;
	}
	else
		return 1;
}
/*----------------------------------------------------------------------------*/
/* Function removeComments                                                    */
/* -------------------------                                                  */
/*		This function takes line and and if line have some comments           */
/*		remove these, and return cleaned line.                                */

string removeComments(string line)
{
	int i=0,size;
	
	size=line.length();
	i=line.find(";");
	i++;
	
	if(i>0)
		line.erase(i-1,size);
	
	return line;
}
/*----------------------------------------------------------------------------*/
/* Function controlValid                                                      */
/* ----------------------                                                     */
/*		This function takes line and first nonspace index after command       */
/*		(regOrConst), and control this index valid or invalid.                */
/*		Return 1 on success, 0 on error.                                      */

int controlValid(string line,int regOrConst)
{
	if(line[regOrConst]=='R' || (line[regOrConst]>='0' && line[regOrConst]<='9')
		|| line[regOrConst]=='#')
		return 1;
	
	return 0;
}
/*----------------------------------------------------------------------------*/
/* Function findFirstInst                                                     */
/* ------------------------                                                   */
/*		This function takes line and first nonspace index, and find           */
/*		first nonspace index after the command, and return this index.        */

int findFirstInst(string line,int first)
{
	int i;
	first=first+3;
	
	for(i=first; line[i]==' '; ++i)
	;	
	
	return i;
}
/*----------------------------------------------------------------------------*/
/* Function spaceForReg                                                       */
/* ----------------------                                                     */
/*		This function takes line and first nonspace index, and control        */
/*		space after command.                                                  */
/*		Return 1 on success, 0 on error.                                      */

int spaceForReg(string line, int first)
{
	first=first+3;
	
	if(line[first]==' ')
		return 1;		
	else
		return 0;
}
/*----------------------------------------------------------------------------*/
/* Function findFirst                                                         */
/* ------------------                                                         */
/*		This function takes line and find first nonspace index and return     */
/*		index.                                                                */

int findFirst(string line)
{
	int i;
	
	for(i=0; line[i]==' '; ++i)
	;
	
	return i;
}
/*----------------------------------------------------------------------------*/
/* Function lowToUpper                                                        */
/* --------------------                                                       */
/*		This function takes line and convert upper all letters, and return    */
/*		line with upper letters.                                              */

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
/* Function newLineJump                                                       */
/* ---------------------                                                      */
/*		This function get the line for JMP or JPN commands and return this    */
/*		new line.                                                             */

string newLineJump(string line,int cons,ifstream &inFile)
{
	int k;
	string newLine;
	inFile.seekg(0);
	
	for(k=0; k<cons; k++)
	{
		getline(inFile, newLine);
	}
	return newLine;
}
/*----------------------------------------------------------------------------*/
/* Function memoryCons                                                        */
/* --------------------                                                       */
/*		This function takes line and if line have memory address,             */
/*		calculate it, and return memory address value on success, -1 on error.*/

int memoryCons(string line)
{
	int index,i,k,cons;
	string constant;
	
	if(line[3]=='R')
	{
		if(line[6]!='#')
			return -1;
			
		else
			index=7;
	}
	else if(line[3]!='#')
		return -1;
	
	else
		index=4;
	
	i=line.find(',');
	if(i<=0 && line[0]!='P')
		return -1;
	
	else if(i<index)
	{
		i=0;
		while(line[index]!='\0')
		{	
			if((line[index]>='0' && line[index]<='9')){
							
				constant[i]=line[index];		
				index++;		
				i++;
			}
			else
				return -1;
		}
	}
	else
	{
		i=0;
		while(line[index]!=',')
		{ 	
			if((line[index]>='0' && line[index]<='9')){
							
				constant[i]=line[index];		
				index++;		
				i++;
			}
			else
				return -1;
		}
	}
	cons=0;
	for(k=0; k<i; k++)
		cons=10*cons+(constant[k]-'0');
	
	if(!(cons>=0 && cons<=49))
		return -2;
	
	return (cons);		
}
/*----------------------------------------------------------------------------*/
/* Function register1                                                         */
/* -------------------                                                        */
/*		This function takes line and if line have register after command,     */
/*		find its value, and control is it between 1-5, return register value  */
/*		on success, -1 on invalid register and 0 on other errors.             */

int register1(string line)
{
	int indexOfFirstReg=3;
	if(line[indexOfFirstReg]=='R' && (line[indexOfFirstReg+1]>='1' && 
						line[indexOfFirstReg+1]<='5'))
		return (line[indexOfFirstReg+1]-'0');
	
	else if(line[indexOfFirstReg]=='R' && !(line[indexOfFirstReg+1]>='1' && 
				line[indexOfFirstReg+1]<='5'))
		return 0;
	else
		return -1;
}
/*----------------------------------------------------------------------------*/
/* Function register2                                                         */
/* ------------------                                                         */
/*		This function takes line and if line have register after comma,       */
/*		find its value, and control is it between 1-5, return register value  */
/*		on success, -1 on invalid register and 0 on other errors.             */

int register2(string line)
{
	int indexOfFirstReg;
	int j=0;
	
	j=line.find(',');
	
	if(j>0)
		indexOfFirstReg=j+1;
	
	else
		return -1;
	//cout << indexOfFirstReg <<endl;
	if(line[indexOfFirstReg]=='R'  && (line[indexOfFirstReg+1]>='1' && 
				line[indexOfFirstReg+1]<='5'))
		return (line[indexOfFirstReg+1]-'0');		
	
	else if(line[indexOfFirstReg]=='R' && !(line[indexOfFirstReg+1]>='1' && 
			line[indexOfFirstReg+1]<='5'))
		return 0;
	else
		return -1;
}
/*----------------------------------------------------------------------------*/
/* Function constant                                                          */
/* ------------------                                                         */
/*		This function takes line and if line have constant find its value,    */
/*		and return constant value on success, -1 on error.                    */

int constant(string line)
{
	string constant;
	int index;
	int i=0,constan=0,k,j,size;
	
	size=line.length();
	j=line.find(',');
	
	if((line[3]=='R' || line[3]=='#') && j>0)
		index=j+1;
	
	else
		index=3;
	
	while(index<size)
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
		constan=10*constan+(constant[k]-'0');
	}
	return constan;		
}
/*----------------------------------------------------------------------------*/
/* Function printResult                                                       */
/* ----------------------                                                     */
/*		This function print result according to option.                       */
/*		If option is 0, only print last values of registers and memory.       */
/*		Else if option is 1, print registers for each line, and when          */
/*		program come to HLT, print last values registers and memory.          */
/*		Else if option is 2, print registers and memory for each line, and    */
/*		when program come to HLT, print last values registers and memory.     */

void printResult(string line,unsigned int *memory,int *reg,int reg1,int reg2,
			int cons,int memo)
{
	
	if(line[0]=='P')
	{
		cout << line[0] << line[1] << line[2] << " ";
		
		if(reg1==-1 && cons==-1)
			cout << "#" << memo;
			
		else if(reg1==-1 && memo==-1)
			cout << cons;
			
		else if(cons==-1 && memo==-1)
			cout << line[3] << line[4];
			
		cout<<"-" << "R1="<< reg[0]<< ",R2="<< reg[1]<< ",R3="<< reg[2]
			<< ",R4="<< reg[3]<< ",R5="<< reg[4]<<endl;
	}
	else if(reg1==-1 && reg2==-1 && line[3]=='#')
	{
		cout << line[0] << line[1] << line[2] << " " <<"#"<<memo<<
			","<<cons<<"-" << "R1="<< reg[0]<< ",R2="<< reg[1]<< ",R3="<< 
			reg[2]<< ",R4="<< reg[3]<< ",R5="<< reg[4]<<endl;
	}
	else if(cons==-1 && reg2==-1)
	{
		cout << line[0] << line[1] << line[2] << " " << line[3] << line[4]<<
			","<<"#"<<memo<<"-" << "R1="<< reg[0]<< ",R2="<< reg[1]<< ",R3="<< 
			reg[2]<< ",R4="<< reg[3]<< ",R5="<< reg[4]<<endl;
	}
	else if(cons==-1 && memo==-1)
	{
		cout << line[0] << line[1] << line[2] << " " << line[3] << line[4]<<
			","<<line[6]<<line[7]<<"-" << "R1="<< reg[0]<< ",R2="<< reg[1]<< 
			",R3="<< reg[2]<< ",R4="<< reg[3]<< ",R5="<< reg[4]<<endl;
	}
	else if(reg2==-1 && memo==-1)
	{
		cout << line[0] << line[1] << line[2] << " " << line[3] << line[4]<<
			","<<cons<<"-" << "R1="<< reg[0]<< ",R2="<< reg[1]<< 
			",R3="<< reg[2]<< ",R4="<< reg[3]<< ",R5="<< reg[4]<<endl;
	}
	else if(reg1==-1 && memo==-1)
	{
		cout << line[0] << line[1] << line[2] << " " << cons <<
			"-" << "R1="<< reg[0]<< ",R2="<< reg[1]<< ",R3="<< reg[2]<< ",R4="<<
			reg[3]<< ",R5="<< reg[4]<<endl;
	}
	else if(reg1==-1 && cons==-1)
	{
		cout << line[0] << line[1] << line[2] << " " << "#"<<memo <<
			","<<"R"<<reg2 <<"-"<< "R1="<< reg[0]<< ",R2="<< reg[1]<< ",R3="<< 
			reg[2]<< ",R4="<<reg[3]<< ",R5="<< reg[4]<<endl;
	}	
	return;	
}
/*----------------------------------------------------------------------------*/
/* Function printMemory                                                       */
/* ----------------------                                                     */
/*		This function prints all contents of memory.                          */

void printMemory(unsigned int* memory)
{
	int i;
	cout <<endl<<"			***CONTENTS OF THE MEMORY***\n";
	
	for(i=0; i<50; ++i)
	{
		cout << "#"<<i<<"="<<memory[i]<<"	";
		
		if(!((i+1)%10))
			cout << endl;
	}	
	return;
}
/*----------------------------------------------------------------------------*/
/*                             End of main.cpp                                */
/*----------------------------------------------------------------------------*/
