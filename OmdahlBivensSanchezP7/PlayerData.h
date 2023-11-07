#ifndef PLAYERDATA_H
#define PLAYERDATA_H

#include <string>

using namespace std;

struct PlayerData
{
private:
	string name;
	int numWon{ 0 };
	int numLost{ 0 };

public:
	void SetName(string name) { this->name = name; }

	void IncrementNumWon() { numWon++; }
	void IncrementNumLost() { numLost++; }

	string GetName() { return name; }
	int GetNumWon() { return numWon; }
	int GetNumLost() { return numLost; }
};

#endif
