#pragma once
#include <iostream>
#include <string>

class FBullCowGame
{
public:
	void Reset(int WordLength);
	int GetMaxTries();
	int GetCurrentTry();
	bool IsGameWon();
	bool CheckGuessValidity(std::string);
private:
	int MyCurrentTry=1;
	int MyMaxTries=5;
};