//Ferreol Sanchez-Haro fsanchezharo@cnm.edu
//Program 7 - Craps Game
//Dice.cpp


//Programer: Ferreol Sanchez
#include "Dice.h"

Dice::Dice()
{
	//seed the engine with a very large number
	engine.seed(chrono::system_clock::now().time_since_epoch().count());
}

void Dice::ThrowDice()
{
	//Create a distribution for 1 - 6
	uniform_int_distribution<int> dist(1, 6);

	d1 = dist(engine); 
	d2 = dist(engine);

	diceValue = d1 + d2;
}

tuple<int, int> Dice::GetDice()
{
	auto values = make_tuple(d1, d2);
	return values;
}

int Dice::GetValue()
{
	return diceValue;
}
