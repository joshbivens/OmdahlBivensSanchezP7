//Ferreol Sanchez-Haro fsanchezharo@cnm.edu
//Program 7 - Craps Game
//MoneyCenter.cpp
#include "MoneyCenter.h"

MoneyCenter::MoneyCenter()
{
	SetInitialBalance(200);
}

void MoneyCenter::SetInitialBalance(int dollars)
{
	balance = dollars;
}

bool MoneyCenter::SetBet(int bet)
{
	if(bet <= balance)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void MoneyCenter::UpdateBalance(bool didWin)
{
	bool isInRange = SetBet(bet);
	if (isInRange == true)
	{
		if (didWin == true)
		{
			balance = balance + bet;
		}
		else
		{
			balance = balance - bet;
		}
	}
}

int MoneyCenter::GetBalance()
{
	return  balance;
}

string MoneyCenter::Writelog()
{
	string log;

	log = "Player bet: " + to_string(bet) + "\r\n";
	return log;
}
