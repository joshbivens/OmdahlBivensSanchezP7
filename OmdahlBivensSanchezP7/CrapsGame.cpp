// Joshua Bivens
// jbivens1@cnm.edu
// OmdahlBivensSanchezP7
// Group Project 7 - The Craps Game

// CrapsGame.cpp

// Programmer: Joshua Bivens

#include "CrapsGame.h"

void CrapsGame::PlayerWins()
{
	won = true;
}

void CrapsGame::PlayerLoses()
{
	won = false;
}

CrapsGame::CrapsGame()
{
	rules =
		"Craps is a popular dice game played in casinos. The C++\n"
		"variation is as follows : Make a bet.Roll two dice. Each die\n"
		"has six faces, representing values 1 - 6. Check the sum of the\n"
		"faces showing on the two dice\n\n"
		"If the sum is 2, 3 or 12 (craps), you lose.\n"
		"If the sum is 7 or 11 (natural), you win.\n"
		"If the sum is anything else, a point is established (the sum of\n"
		"the dice you rolled) and you continue to roll until you re - roll\n"
		"the point (you win) or you roll a 7 (you lose).";
}

string CrapsGame::GetSummary()
{
	stringstream ss;
	ss << "Hello " << data.GetName() << ","
		<< "\r\nYour beginning balance was $200"
		<< "\r\nYou won " << data.GetNumWon() << " and lost " << data.GetNumLost() << " games."
		<< "\r\nYour final balance is " << bank.GetBalance() << endl;

	return ss.str();
}

void CrapsGame::ThrowTheDice()
{
	dice.ThrowDice();

	if (pointRound)
	{
		PlayPointRound();
	}
	else
	{
		MakeYourPlay();
	}
}

// Contains the logic of what wins/loses in the round
string CrapsGame::MakeYourPlay()
{
	// First call Dice.GetValue() to get the value of the dice roll
	int total{ 0 };
	total = dice.GetValue();

	// Write the bet to log
	log.WriteLog(bank.Writelog());

	// Then look at rules to see how the player did
	if (total == 2 || total == 3 || total == 12)
	{
		PlayerLoses();
		data.IncrementNumLost();
		bank.UpdateBalance(false);
		ResetGame();
		result = "You lost!\nYour balance is " + to_string(bank.GetBalance());
		log.WriteLog(result);
	}
	else if (total == 7 || total == 11)
	{
		PlayerWins();
		data.IncrementNumWon();
		bank.UpdateBalance(true);
		ResetGame();
		result = "You won!\nYour balance is " + to_string(bank.GetBalance());
		log.WriteLog(result);
	}
	else // If not win/lose, moves to point round
	{
		pointRound = true;
		point = total;
		result = "You have to play the point round!";
		log.WriteLog(result); // Should this be written to log?
	}

	// Create message to user: "You have to play the point round!"
	return result;
}

// Contains the logic of what wins/loses in the point round
string CrapsGame::PlayPointRound()
{
	int total{ 0 };
	total = dice.GetValue();

	if (total == point)
	{
		PlayerWins();
		data.IncrementNumWon();
		bank.UpdateBalance(true);
		ResetGame();
		result = "You won!\nYour balance is " + to_string(bank.GetBalance());
		log.WriteLog(result);
	}
	else if (total == 7)
	{
		PlayerLoses();
		data.IncrementNumLost();
		bank.UpdateBalance(false);
		ResetGame();
		result = "You lost!\nYour balance is " + to_string(bank.GetBalance());
		log.WriteLog(result);
	}
	else
	{
		result = "Roll again!";
		log.WriteLog(result);
	}

	// Create string with results
	return result;
}

void CrapsGame::ResetGame()
{
	won = false;
	pointRound = false;
	point = 2;
	result = "";
}

void CrapsGame::GameOver()
{
	// Write summary to log file and close
	log.CloseLog(GetSummary());
}
