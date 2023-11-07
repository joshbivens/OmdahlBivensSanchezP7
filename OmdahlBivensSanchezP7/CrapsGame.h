// Joshua Bivens
// jbivens1@cnm.edu
// OmdahlBivensSanchezP7
// Group Project 7 - The Craps Game

// CrapsGame.h

// Programmer: Joshua Bivens

#ifndef CRAPSGAME_H
#define CRAPSGAME_H

#include "Logger.h"
#include "PlayerData.h"
#include "MoneyCenter.h"
#include "Dice.h"

#include <string>

using namespace std;

// PASSTHRU/CONTROLLER CLASS
class CrapsGame
{
private:
	bool won{ false }; // if the player won the round
	bool pointRound{ false }; //true if the player is in the point round
	int point{ 2 }; //The point value that has to be matched in the point round
	string rules; //the rules of C++ Craps
	string result; //the result of the dice roll � win, lose or play point
	Logger log; //Logger object, handles the log file
	MoneyCenter bank; //manages the player�s money 
	Dice dice; //handles getting the roll of the dice 
	PlayerData data; // a struct that contains the player�s data.
	void PlayerWins(); //A utility method 
	void PlayerLoses(); //Another utility method

public:
	CrapsGame(); //create the rules string here.

	//setters or mutators change the values of the class variables
	void SetName(string name) { data.SetName(name); }
	bool SetBet(int bet) { return bank.SetBet(bet); }

	//Get methods do not do any calculations - they return a value 
	string GetRules() { return rules; }
	string GetSummary();
	string GetName() { return data.GetName(); }
	int GetBalance() { return bank.GetBalance(); }
	bool GetPoint() { return pointRound; }
	bool IsTheLogOpen() { return log.IsLogOpen(); }
	tuple<int, int> GetTheDice() { return dice.GetDice(); }

	//class methods
	void ThrowTheDice();
	string MakeYourPlay(); //Roll the dice, and what happens?
	string PlayPointRound(); //play the point round to win/lose
	void ResetGame();
	void GameOver(); //Finish the log file and close it
};

#endif

