#include <iostream>
#include <ctime>

using std::cout;
using std::cin;

void PrintIntroduction(int Difficulty)
{
	cout << "--------------------------------------------\n";
	cout << "You're a secret agent breaking into a LEVEL " << Difficulty << " server room...\n";
	cout << "You need to enter the correct code to continue...\n\n";
}

bool PlayGame(int Difficulty)
{
	PrintIntroduction(Difficulty);

	//declare 3 number code
	int CodeDigitA = rand() % Difficulty + Difficulty;
	int CodeDigitB = rand() % Difficulty + Difficulty;
	int CodeDigitC = rand() % Difficulty + Difficulty;

	const int CodeSum = CodeDigitA + CodeDigitB + CodeDigitC;		//14
	const int CodeProduct = CodeDigitA * CodeDigitB * CodeDigitC;	//64

	//give the player some hints
	cout << "+ There are 3 numbers in the code.\n";
	cout << "+ The numbers add up to be: " << CodeSum << "\n";
	cout << "+ The numbers multiply to be: " << CodeProduct << "\n";

	//store player guesses
	int GuessA, GuessB, GuessC;

	cout << "Enter three numbers followed by an x: ";

	//get player guesses
	cin >> GuessA >> GuessB >> GuessC;

	int GuessSum = GuessA + GuessB + GuessC;
	int GuessProduct = GuessA * GuessB * GuessC;

	//check if the player made the right guess
	if (GuessSum == CodeSum && GuessProduct == CodeProduct)
	{

		cout << "\n*** Well done agent. You've extracted a file! Keep going! ***\n\n";
		return true;
	}
	else
	{

		cout << "\n*** You're code didn't work. Try again, agent. ***\n\n";
		return false;
	}
}

int main()
{
	srand(time(NULL));

	const int MaxDifficulty = 10;
	int LevelDifficulty = 1;

	char playAgain = 'n';

	while (LevelDifficulty <= MaxDifficulty)
	{
		bool bCompletedLevel = PlayGame(LevelDifficulty);

		cin.clear();
		cin.ignore();

		if (bCompletedLevel)
		{
			LevelDifficulty++;
		}
	}

	cout << "Great work agent! You got all the files! Now get out of there!\n";

	return 0;
}

