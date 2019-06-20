#include "FBullCowGame.h"


FBullCowGame::FBullCowGame() {
	Reset();
}
void FBullCowGame::Reset()
{
	constexpr int MAX_TRIES = 8;
	MyCurrentTry = 1;
	MyMaxTries = MAX_TRIES;

	const FString HIDDEN_WORD = "planet";
	MyHiddenWord = HIDDEN_WORD;

	return;
}

int FBullCowGame::GetMaxTries() const { return MyMaxTries;}

int FBullCowGame::GetCurrentTry() const { return MyCurrentTry;}

bool FBullCowGame::IsGameWon()
{
	return false;
}


// receives a valid guess incriments turn and returns count
FBullCowCount FBullCowGame::SubmitGuess(FString)
{
	// incriment the turn number
	MyCurrentTry++;

	//setup a return varible
	FBullCowCount BullCowCount;

	//loop through all letters in the guess
		//compare letters against the hidden word
		
	return BullCowCount;
}

bool FBullCowGame::CheckGuessValidity(std::string)
{
	return false;
}
