//Ferreol Sanchez-Haro fsanchezharo@cnm.edu
//Program 7 - Craps Game
//MoneyCenter.h

#ifndef MONEYCENTER_H
#define MONEYCENTER_H

#include <string>

using namespace std;

class MoneyCenter
{
private:
		int bet{ 0 };
		static int balance;

public:
		MoneyCenter();  //constructor, calls WriteBeginFile() method
		void SetInitialBalance(int dollars);  //sets class variable to 200
		bool SetBet(int bet);  //sets the bet into class variable and checks to see if the bet amount is in range.  Returns a true if bet is in range and false if not.
		void UpdateBalance(bool didWin); //adds or subtracts the bet to/from the balance
		int GetBalance();  //returns balance
		string Writelog();  //creates a string for the logger

};

#endif
