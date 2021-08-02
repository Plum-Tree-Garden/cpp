#ifndef RPS_RANDOMSIMULATION_H
#define RPS_RANDOMSIMULATION_H

// include header files
#include <iostream>
#include <cstdlib>
#include <ctime>


	// namespace (rps)-rock, paper, scissors
	namespace rps 
	{
		// class generates random simulation between 2 ai 
		class randomSimulation 
		{
			const int ACTIONS_MIN=1, ACTIONS=3;			// define # of actions available eatch match
			const int ROCK=1, PAPER=2, SCISSORS=3;		// define value of: rock, paper, scissors

			int simulations;							// # of matches simulated

			int* matchVictor = nullptr;					// define matchVictor, 0=tie, 1=one, 2=2

			int* ai_one = nullptr;						// define cpu-ai # one
			int* ai_two = nullptr;						// define cpu-ai # two

			std::string* choice_one = nullptr;			// value of RPS in string format for cpu-ai # one
			std::string* choice_two = nullptr;			// value of RPS in string format for cpu-ai # one

		public:

			randomSimulation(); 						// default constructor, initialize matches to 0, ai to null
			~randomSimulation();						// destructor--dealloc
			randomSimulation(const int sim);			// 1-arg cons... generate x "match" simulations

			int generateRandomNumber(int min, int max); // generate random number, used as hand(rps)
			int getVictor(int aone, int atwo);			// determine tie, victor, loser, and weight outcome

			std::string getChoice(int choice);			// equivelant value of ACTION in string format

			void display() const; 						// display match data


		// class end
		};

	// namespace end
	}

// header end
#endif
