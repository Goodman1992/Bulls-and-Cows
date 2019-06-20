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
FText GetGuess();
bool AskToPlayAgain();

FBullCowGame BCGame;

int main()
{
	BCGame.Reset();
	constexpr int32 WORD_LENGTH=5;
	constexpr int32 NUMBER_OF_TURNS = 5;
	//introduce the game
	PrintIntro(WORD_LENGTH);
	do {
		PlayGame(NUMBER_OF_TURNS);
	} while (AskToPlayAgain());

	return 0;
}

void PrintIntro(int32 WORD_Length)
{
	std::cout << "Welcome to Bulls and Cows, a fun word game. \n";
	std::cout << "Can you guess the " << WORD_Length << " letter isogram I'm thinking of? \n\n";
}

FText GetGuess() 
{
	FText Guess;
	int32 CurrentTry = BCGame.GetCurrentTry();

	std::cout << "Try " << CurrentTry << ". Enter the guess: ";
	std::getline(std::cin, Guess);
	
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
	
	//get a guess from the player
	// and repeat the guess back to them
	for (int32 count = 1; count <= NUMBER_OF_TURNS; count++)
	{
		FText Guess=GetGuess();//TODO make loops checking valid guesses

		//Submit valid guess to the game
		//Print number of bulls and cows

		std::cout << "You guessed: " << Guess << "\n";
		std::cout << std::endl;
	}
	//TODO sumarries game
}