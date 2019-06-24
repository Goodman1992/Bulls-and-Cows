#include "FBullCowGame.h"


FBullCowGame::FBullCowGame() {
	Reset();
}
void FBullCowGame::Reset()
{
	constexpr int MAX_TRIES = 8;
	MyMaxTries = MAX_TRIES;

	const FString HIDDEN_WORD = "planet";
	MyHiddenWord = HIDDEN_WORD;

	return;
}

int FBullCowGame::GetMaxTries() const { return MyMaxTries;}

int FBullCowGame::GetCurrentTry() const { return MyCurrentTry;}

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
	
	// otherwise, return OK
	if (false) {	// if the guess isn't a isogram, return an error
		return EGuessStatus::Not_Isogram;
	}
	else if (Guess) {	// if the guess isn't all lower case, return an error{
		return EGuessStatus::Not_Lowercase;
	}
	else if (Guess.length()!=GetHiddenWordLength()) { // if the guess length is wrong, return an error
		return EGuessStatus::Wrong_Length;
	}
	else {
		return EGuessStatus::OK;//TODO make actual error
	}
	
}

int32 FBullCowGame::GetHiddenWordLength() const{ return MyHiddenWord.length(); }

bool FBullCowGame::IsGameWon()
{
	return false;
}


// receives a valid guess incriments turn and returns count
FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
	// incriment the turn number
	MyCurrentTry++;

	//setup a return varible
	FBullCowCount BullCowCount;

	
	//loop through all letters in the guess
	int32 HiddenWordLength = MyHiddenWord.length();
					
	for (int32 MHWChar = 0; MHWChar < HiddenWordLength;MHWChar++) {
		for (int32 GChar = 0; GChar < HiddenWordLength;GChar++) {
			//compare letters against the hidden word
			// if they match then
			if (Guess[GChar]== MyHiddenWord[MHWChar]) {
				if (MHWChar==GChar) {
					BullCowCount.Bulls++; // incriment bulls if they're in the same place
				}
				else
				{
					BullCowCount.Cows++; // incriment cows if not
				}
			}
		}
	}

	return BullCowCount;
}

