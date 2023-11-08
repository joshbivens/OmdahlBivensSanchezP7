// Joshua Bivens
// jbivens1@cnm.edu
// OmdahlBivensSanchezP7
// Group Project 7 - The Craps Game

// Logger.cpp

// Programmer: Joshua Bivens

#include "Logger.h"

Logger::Logger() : Logger("")
{
}

Logger::Logger(string name) : playerName{ name }
{
	FileName(); // Creates output file name
	Time(); // Gets current time
	// Open log file
	output.open(filename.c_str());

	// Check if file opened
	if (!output.is_open())
	{
		// If not, set bLogOpen to false
		bLogOpen = false;
	}
	else
	{
		// If so, write to file:
		// Name, Program Name, say Hello to player and call
		// them by name.
		// Tell them this is the log of your Craps Games.
		output << "Hello " << playerName << endl;
		output << "Program Name: Craps Game" << endl;
	}
}

void Logger::FileName()
{
	// e.g. Log_11_1_2023_06.22.34
	auto now = chrono::system_clock::now();
	auto in_time_t = chrono::system_clock::to_time_t(now);
	struct tm OSTime;
	localtime_s(&OSTime, &in_time_t);

	// Format time for filename
	stringstream ss;
	ss << put_time(&OSTime, "%m_%d_%Y_%H.%M.%S");

	// Set output filename
	filename = "Log_" + ss.str() + ".txt";

	// Set dateTimeStamp
	dateTimeStamp = ss.str();
}

// For the MoneyCenter to write the initial balance
void Logger::Startlog(double initialBalance)
{
	output << "This is the log of your Craps game.\n" 
		<< "Initial Balance : $" << initialBalance << "\n" << endl;
}

// 
void Logger::WriteLog(string s)
{
	Time();
	// Then write timeRightNow and result of game
	output << timeRightNow << "\n" << s << endl;
}

void Logger::CloseLog(string s)
{
	// Write string passed
	output << s << endl;
	// Close output file
	output.close();

	// Opens the file in notepad
	string openfile = "notepad.exe " + filename;
	system(openfile.c_str());
}

bool Logger::IsLogOpen()
{
	return bLogOpen;
}

void Logger::Time()
{
	auto now = chrono::system_clock::now();
	auto in_time_t = chrono::system_clock::to_time_t(now);
	struct tm OSTime;
	localtime_s(&OSTime, &in_time_t);

	stringstream ss;
	ss << put_time(&OSTime, "%X");

	// Set current time
	timeRightNow = ss.str();
}

