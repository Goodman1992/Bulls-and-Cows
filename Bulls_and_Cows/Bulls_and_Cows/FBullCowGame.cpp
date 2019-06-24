#include "FBullCowGame.h"
#include <list>
#include <vector>
#include <cctype>
FBullCowGame::FBullCowGame() {
	Reset();
}
void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	MyMaxTries = MAX_TRIES;

	const FString HIDDEN_WORD = "planet";
	MyHiddenWord = HIDDEN_WORD;

	return;
}

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries;}

int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry;}

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess)
{
	
	// otherwise, return OK
	if (Guess.length() != GetHiddenWordLength()) { // if the guess length is wrong, return an error
		return EGuessStatus::Wrong_Length;
	}
	else if (!Islowercase(Guess)) {	// if the guess isn't all lower case, return an error{
		return EGuessStatus::Not_Lowercase;
	}
	else if (!CheckIsogram(Guess)) {  // if the guess isn't a isogram, return an error
		return EGuessStatus::Not_Isogram;
	}
	else {
		return EGuessStatus::OK;
	}
	
}

int32 FBullCowGame::GetHiddenWordLength() const{ return MyHiddenWord.length(); }

bool FBullCowGame::IsGameWon()
{
	return false;
}

// receives a valid guess incriments turn and returns count
FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{
	MyCurrentTry++;
	FBullCowCount BullCowCount;
	int32 WordLength = MyHiddenWord.length();// assuming same length as guess
	
	//loop through all letters in the hidden word				
	for (int32 MHWChar = 0; MHWChar < WordLength;MHWChar++) {
		for (int32 GChar = 0; GChar < WordLength;GChar++) {
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

//check is the guess is an isogram
bool FBullCowGame::CheckIsogram(FString Guess) {
	std::list<char> CheckedChars;
	int32 OriginalSize=Guess.length();
	int32 UniqueLength;

	//Push all chars in guess to list
	for (int count = 0; count < Guess.length();count++) {
			CheckedChars.push_back(Guess[count]);
	}
	CheckedChars.sort();
	CheckedChars.unique();
	UniqueLength = CheckedChars.size();
	if (OriginalSize==UniqueLength) {
		return true;
	}
	else {
		return false;
	}
}
bool FBullCowGame::Islowercase(FString Guess) {
	for (int32 count = 0; count < Guess.length();count++) {
		if (std::islower(Guess[count])) {
			continue;
		}
		else {
			return false;
		}
	}
	return true;
}