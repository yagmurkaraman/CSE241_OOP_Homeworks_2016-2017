#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H

#include <iostream>
#include <exception>
#include <string>
using namespace std;

class MyException : public exception
{
	public:
		MyException(const char* message){ 
			printMessage=message; } 

		const char* what()const throw(){ 
			return printMessage; } 

	private:
		const char* printMessage;

};
#endif
