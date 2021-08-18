#include "randomSimulation.h"


// namespace begin
namespace rps 
{


	// 0 arg cons
	randomSimulation::randomSimulation() : ai_one(nullptr), ai_two(nullptr), choice_one(nullptr), choice_two(nullptr), simulations(0) {}


	// 1 arg cons
	randomSimulation::randomSimulation(const int sim) : simulations(sim)
	{
		// set dyn arrays size = simulations
		ai_one = new int[simulations];
		ai_two = new int[simulations];

		matchVictor = new int[simulations];

		choice_one = new std::string[simulations];
		choice_two = new std::string[simulations];
		
		// seed 0 to time clock
		srand(time(0));

		// store x simulations
		for (int i = 0; i < simulations; i++) 
		{
			// store each random number simulated
			ai_one[i] = generateRandomNumber(ACTIONS_MIN, ACTIONS);
			ai_two[i] = generateRandomNumber(ACTIONS_MIN, ACTIONS);

			// store each simulated event in string format
			choice_one[i] = getChoice(ai_one[i]);
			choice_two[i] = getChoice(ai_two[i]);

			// determine match Victor and store in matchVictor array
			matchVictor[i] = getVictor(ai_one[i], ai_two[i]);
		}
	}


	// dest.
	randomSimulation::~randomSimulation() 
	{
		delete[] ai_one;
		delete[] ai_two;
		delete[] choice_one;
		delete[] choice_one;
	}


	// generate random number
	int randomSimulation::generateRandomNumber(int min, int max)
	{
		return rand() % max + min;
	}


	// determine tie, victor, loser
	int randomSimulation::getVictor(int ai_one, int ai_two) {

		// match is tie if both play same hand
		if (ai_one == ai_two)
			return 0;

		// rock loses to paper
		if (ai_one == 1 && ai_two == 2)
			return 2;

		// rock beats scissors
		if (ai_one == 1 && ai_two == 3)
			return 1;

		// paper beats rock
		if (ai_one == 2 && ai_two == 1)
			return 1;

		// paper loses to scissors
		if (ai_one == 2 && ai_two == 3)
			return 2;

		// scissors loses to rock
		if (ai_one == 3 && ai_two == 1)
			return 2;

		// scissors beats paper
		if (ai_one == 3 && ai_two == 2)
			return 1;
		}


	// equivelant value of ACTION
	std::string randomSimulation::getChoice(int choice)
	{
		switch (choice) 
		{
			case 1: return "[ROCK] ";
				break;
			case 2: return "[PAPER]";
				break;
			case 3: return "[SCISSORS]";
				break;
		}
	}


	// display match data
	void randomSimulation::display() const
	{
		for (int i = 0; i < simulations; i++)
		{
			std::cout << '\n' << "Match" << i + 1 << ": " << '\n';
			std::cout << "ai_one selected: " << choice_one[i] << '\n';
			std::cout << "ai_two selected: " << choice_two[i] << '\n';
			std::cout << '\n';
		}

	}


// namespace end
}
