/*
	This is the console executable that makes use of the BullCow class
	this acts as the view in a MVC pattern and is responsible for all 
	use interaction. for game logic see the FBullCowgame.
*/


#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

void PrintIntro(int32 WORD_Length);
void PlayGame(int32 NUMBER_OF_TURNS);
FText GetValidGuess();
bool AskToPlayAgain();

FBullCowGame BCGame;

int main()
{
	BCGame.Reset();
	//introduce the game
	int32 MaxTries = BCGame.GetMaxTries();
	PrintIntro(BCGame.GetHiddenWordLength());
	for (int32 count = 1; count <= MaxTries;count++) {
		FText Guess = GetValidGuess();

		FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);

		std::cout << "Bulls = "<<BullCowCount.Bulls;
		std::cout << ".Cows = " << BullCowCount.Cows << "\n\n";
	}

	return 0;
}

void PrintIntro(int32 WORD_Length)
{
	std::cout << "Welcome to Bulls and Cows, a fun word game. \n";
	std::cout << "Can you guess the " << WORD_Length << " letter isogram I'm thinking of? \n\n";
}

//loop continuall until get a valid guess
FText GetValidGuess()
{
	EGuessStatus Status = EGuessStatus::Invalid_status;
	FText Guess;
	do {
		int32 CurrentTry = BCGame.GetCurrentTry();
		EGuessStatus Status = BCGame.CheckGuessValidity(Guess);
		switch (Status)
		{
		case EGuessStatus::Not_Isogram:
			std::cout << "Please enter an isogram.\n";
		case EGuessStatus::Wrong_Length:
			std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word.\n";
		case EGuessStatus::Not_Lowercase:
			std::cout << "Please enter all lower case letters.\n";
		default:
			//assume the guess is valid
			break;
		}
		std::cout << "Try " << CurrentTry << ". Enter the guess: ";
		std::getline(std::cin, Guess);
	} while (Status != EGuessStatus::OK);// keep looping unitl we get no error
	return Guess;
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again[Y/N]? \n";
	FText Response;
	std::getline(std::cin, Response);
	if (Response[0]=='Y'||Response[0]=='y') 
	{
		return true;
	}
	else if (Response[0]=='N'||Response[0]=='n') 
	{
		return false;
	}
	else {
		return AskToPlayAgain();
	}
	
}

void PlayGame(int32 NUMBER_OF_TURNS)
{
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();

	// loop asking for guesses while the game is not won
	// and there are still tries remaining

	while (!BCGame.IsGameWon() && (BCGame.GetCurrentTry()<=MaxTries)) {
		FText Guess = GetValidGuess();//TODO make loops checking valid guesses

		//Submit valid guess to the game
		FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);
		//Print number of bulls and cows

		std::cout << "You guessed: " << Guess << "\n";
		std::cout << std::endl;
		//TODO sumarries game
	}
		
}