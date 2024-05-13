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

	// Start log
	log.Startlog(bank.GetBalance());
}

string CrapsGame::GetSummary()
{
	stringstream ss;
	ss << "Hello " << data.GetName() << ","
		<< "\r\nYour beginning balance was $200"
		<< "\r\nYou won " << data.GetNumWon() << " and lost " << data.GetNumLost() << " games."
		<< "\r\nYour final balance is $" << bank.GetBalance() << endl;

	return ss.str();
}

void CrapsGame::ThrowTheDice()
{
	dice.ThrowDice();
}

/**
 * Simulates a round in a game of craps.
 * 
 * This function rolls two dice, calculates the total value, logs the bet, 
 * and then determines the outcome based on the rules of craps. If the total 
 * is 2, 3, or 12, the player loses; if it's 7 or 11, the player wins. 
 * Otherwise, it sets up for the point round. Finally, it logs the outcome 
 * and returns a message to the user indicating the next step in the game.
 * 
 * @return A message indicating the result of the round.
 */
string CrapsGame::MakeYourPlay()
{
	// First, calls Dice.GetValue() to get the value of the dice roll
	int total{ 0 };
	total = dice.GetValue();

	// Writes the bet to log
	log.WriteLog(bank.Writelog());

	// Then looks at rules to see how the player did
	if (total == 2 || total == 3 || total == 12)
	{
		PlayerLoses();
		data.IncrementNumLost();
		bank.UpdateBalance(false);
		result = "You lost!\nYour balance is $" + to_string(bank.GetBalance()) + "\n";
	}
	else if (total == 7 || total == 11)
	{
		PlayerWins();
		data.IncrementNumWon();
		bank.UpdateBalance(true);
		result = "You won!\nYour balance is $" + to_string(bank.GetBalance()) + "\n";
	}
	else // If not win/lose, moves to point round
	{
		pointRound = true;
		point = total;
		result = "You have to play the point round!\n";
	}

	log.WriteLog(result);
	return result;
}

/**
 * Plays the point round in a game of craps.
 * 
 * This function rolls two dice, calculates the total value, and determines 
 * whether the player wins, loses, or needs to continue the point round. If 
 * the total matches the point established in the initial round, the player 
 * wins. If the total is 7, the player loses. Otherwise, the point round 
 * continues. The function updates game statistics and logs the outcome.
 * 
 * @return A message indicating the result of the point round.
 */
string CrapsGame::PlayPointRound()
{
	int total{ 0 };
	total = dice.GetValue();

	if (total == point)
	{
		PlayerWins();
		data.IncrementNumWon();
		bank.UpdateBalance(true);
		result = "You won!\nYour balance is $" + to_string(bank.GetBalance()) + "\n";
	}
	else if (total == 7)
	{
		PlayerLoses();
		data.IncrementNumLost();
		bank.UpdateBalance(false);
		result = "You lost!\nYour balance is $" + to_string(bank.GetBalance()) + "\n";
	}
	else
	{
		result = "Roll again!\n";
	}

	log.WriteLog(result);
	return result;
}

void CrapsGame::ResetGame()
{
	bank.SetInitialBalance(200);
	won = false;
	pointRound = false;
	point = 2;
	result = "";
}

/**
 * Called when player chooses to end the game.
 * 
 * Generates a summary of the game's outcomes and writes it 
 * to the log file, then closes the log file.
 */
void CrapsGame::GameOver()
{
	// Write summary to log file and close
	log.CloseLog(GetSummary());
}
