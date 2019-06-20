#pragma once

#include <iostream>
#include <string>

using FString = std::string;
using int32 = int;

struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};


class FBullCowGame
{
public:
	FBullCowGame(); // constructor
	void Reset();
	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	bool IsGameWon(); 
	bool CheckGuessValidity(FString);
	//provide a method for counting bulls & cows and increasing turn #
	FBullCowCount SubmitGuess(FString);// counts bulls & cows and increase try # assuming valid guess

private:
	int32 MyCurrentTry;
	int32 MyMaxTries;
	FString MyHiddenWord;
};