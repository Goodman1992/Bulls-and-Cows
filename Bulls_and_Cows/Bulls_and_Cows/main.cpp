#include <iostream>
#include <string>
#include "FBullCowGame.h"

void PrintIntro(int WORD_Length);
void PlayGame(int NUMBER_OF_TURNS);
std::string GetGuess();
bool AskToPlayAgain();

FBullCowGame BCGame;

int main()
{
	constexpr int WORD_LENGTH=5;
	constexpr int NUMBER_OF_TURNS = 5;
	//introduce the game
	PrintIntro(WORD_LENGTH);
	do {
		PlayGame(NUMBER_OF_TURNS);
	} while (AskToPlayAgain());

	return 0;
}

void PrintIntro(int WORD_Length)
{
	std::cout << "Welcome to Bulls and Cows, a fun word game. \n";
	std::cout << "Can you guess the " << WORD_Length << " letter isogram I'm thinking of? \n\n";
}

std::string GetGuess() 
{
	std::string Guess;
	int CurrentTry = BCGame.GetCurrentTry();

	std::cout << "Try " << CurrentTry << ". Enter the guess: ";
	std::getline(std::cin, Guess);
	
	return Guess;
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again[Y/N]? \n";
	std::string Response;
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

void PlayGame(int NUMBER_OF_TURNS)
{
	
	//get a guess from the player
	// and repeat the guess back to them
	for (int count = 1; count <= NUMBER_OF_TURNS; count++)
	{
		std::string Guess=GetGuess();
		std::cout << "You guessed: " << Guess << "\n";
		std::cout << std::endl;
	}
}