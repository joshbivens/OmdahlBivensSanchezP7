// Joshua Bivens
// jbivens1@cnm.edu
// OmdahlBivensSanchezP7
// Group Project 7 - The Craps Game

// Logger.h

// Programmer: Joshua Bivens

#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <ctime>
#include <chrono>
#include <iomanip>

using namespace std;

class Logger
{
private:
	string playerName;		//to personalize the log
	string filename;		//the file to be written
	string timeRightNow;	//string giving current time
	string dateTimeStamp;	//string giving current date and time
	bool bLogOpen{ false };	//bool to show if log was opened
	ofstream output;		//output stream belongs to the class and it used several times.
	void FileName();		//method that creates the fileName
	void Time();			//method that creates the timeRightNow string

public:
	Logger();								//default constructor, delegates to overloaded constructor
	explicit Logger(string name);			//overloaded constructor
	void Startlog(double initialBalance);	//writes string with initial balance
	void WriteLog(string s);				//writes each transaction into log
	void CloseLog(string s);				//writes summary and closes file
	bool IsLogOpen();						//to check from the form
};

#endif