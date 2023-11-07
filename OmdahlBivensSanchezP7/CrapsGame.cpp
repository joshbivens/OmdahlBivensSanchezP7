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
	if (won)
	{
		result = "You won!\nYour balance is " + to_string(bank.GetBalance());
	}
	else
	{
		result = "You lost\nYour balance is " + to_string(bank.GetBalance());
	}

	if (pointRound)
	{
		result = "You have to play the point round!";
	}

	// Return string with results
	return result;
}

void CrapsGame::ThrowTheDice()
{
	dice.ThrowDice();
}

// Contains the logic of what wins/loses in the round
string CrapsGame::MakeYourPlay()
{
	// First call Dice.GetValue() to get the value of the dice roll
	int total{ 0 };
	total = dice.GetValue();

	// Set bet
	//bank.SetBet(10);
	log.WriteLog(bank.Writelog());

	// Then look at rules to see how the player did
	if (total == 2 || total == 3 || total == 12)
	{
		PlayerLoses();
		bank.UpdateBalance(false);
		log.WriteLog(GetSummary());
	}
	else if (total == 7 || total == 11)
	{
		PlayerWins();
		bank.UpdateBalance(true);
		log.WriteLog(GetSummary());
	}
	else // If not win/lose, moves to point round
	{
		pointRound = true;
		point = total;
		log.WriteLog(GetSummary());
	}

	// Create message to user: "You have to play the point round!"
	return GetSummary();
}

// Contains the logic of what wins/loses in the point round
string CrapsGame::PlayPointRound()
{
	// First call Dice.GetValue() to get the value of the dice roll
	int total{ 0 };
	total = dice.GetValue();

	if (total == point)
	{
		PlayerWins();
		log.WriteLog(GetSummary());
	}
	else if (total == 7)
	{
		PlayerLoses();
		log.WriteLog(GetSummary());
	}

	// Create string with results
	return GetSummary();
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
	stringstream ss;
	ss << "Hello " << data.GetName() << ","
		<< "\nYour beginning balance was $200"
		<< "\nYou won " << data.GetNumWon() << " and lost " << data.GetNumLost() << " games."
		<< "\nYour final balance is " << bank.GetBalance() << endl;

	log.CloseLog(ss.str());
}
