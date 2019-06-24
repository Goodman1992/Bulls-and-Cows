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

enum class EGuessStatus {
	OK,
	Not_Isogram,
	Wrong_Length,
	Not_Lowercase
};



class FBullCowGame
{
public:
	FBullCowGame(); // constructor
	void Reset();

	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	EGuessStatus CheckGuessValidity(FString) const;
	int32 GetHiddenWordLength() const;
	//provide a method for counting bulls & cows and increasing turn #
	FBullCowCount SubmitGuess(FString);// counts bulls & cows and increase try # assuming valid guess
	bool IsGameWon();

private:
	int32 MyCurrentTry;
	int32 MyMaxTries;
	FString MyHiddenWord;
};