// Lab0001.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <time.h>

void SetRandNumbers(int maxValue, int numberOfTrue);
int maxValue;
static const int maxTrue = 1;
int i_RandomNumbers[maxTrue];
bool guess;
void setGuess(bool p_guess);
int userGuess;
int timesFailed;

int main()
{	
	guess = false;
	timesFailed = 0;

	std::cout << "Please Enter the Max Value... (WARNING LARGE NUMBERS WILL MAKE THE GAME HARDER)" << std::endl;
	std::cin >> maxValue;
	std::cout << std::endl;

    SetRandNumbers(maxValue, maxTrue);

		while (!guess)
		{
			std::cout << "Enter a Guess" << std::endl;
			std::cin >> userGuess;

			for (int j = 0; j < maxTrue; j++)
			{
				if (i_RandomNumbers[j] == userGuess)
				{
					setGuess(true);
				}

			}

			if (!guess) {
				std::cout << "Ha, try again" << std::endl;
				timesFailed++;
			}

		}

		if (timesFailed < 10)
	std::cout << "YOU DID IT ... better not set the max to a low number or a letter i dont want to add error checking" << std::endl;
		if (timesFailed > 10)
	std::cout << "You tried to many times... im sorry but... its a loss" << std::endl;
		if (timesFailed > 45)
			std::cout << "but you get my respect for the commitment" << std::endl;


	system("Pause");
    return 0;

}

void SetRandNumbers(int maxValue, int numberOfTrue)
{
	srand(time(NULL));

	for (int i = 0; i < numberOfTrue; i++)
	{
		i_RandomNumbers[i] = rand() % maxValue + 1;

	   // std::cout << i_RandomNumbers[i] << std::endl;
	}
}

void setGuess(bool p_guess)
{
	guess = p_guess;
}
