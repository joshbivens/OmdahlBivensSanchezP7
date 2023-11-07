//Ferreol Sanchez-Haro fsanchezharo@cnm.edu
//Program 7 - Craps Game
//Dice.h
#ifndef DICE_H
#define DICE_H

#include <tuple>
#include <random>
#include <chrono>

using namespace std;

class Dice
{
private:
		int d1{ 1 }, d2{ 1 };  //the numbers on each die
		int diceValue{ 2 };  // the value of the two dice together
		default_random_engine engine;  //random engine for determining random numbers

public:
		Dice();  //default constructor
		void ThrowDice();  //gets the random numbers for the two dice and the diceValue.
		tuple<int, int>  GetDice();  //returns the two values of the dice.
		int GetValue();  //returns the diceValue

};

#endif
