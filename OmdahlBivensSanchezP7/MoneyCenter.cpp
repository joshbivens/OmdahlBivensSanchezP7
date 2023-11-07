//Ferreol Sanchez-Haro fsanchezharo@cnm.edu
//Program 7 - Craps Game
//MoneyCenter.cpp

//Programer: Ferreol Sanchez
#include "MoneyCenter.h"

MoneyCenter::MoneyCenter()
{
	SetInitialBalance(200);
}

void MoneyCenter::SetInitialBalance(int dollars)
{
	balance = dollars;
}

bool MoneyCenter::SetBet(int playerBet)
{
	bet = playerBet;

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
	if (didWin == true)
	{
		balance = balance + bet;
	}
	else
	{
		balance = balance - bet;
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
