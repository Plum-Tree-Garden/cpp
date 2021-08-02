// Author: Plum Tree Garden
// File: main.cpp
// Date: 4/sep/2020
// Quantifying Gravitational Force

// This application quantifies equally distributed gravitational force between 2 spherical object masses 


#include <iostream>
#include "GravitationalForce.h"


int main() 
{
	double userInput_mass1 = 0;
	double userInput_mass2 = 0;
	double userInput_distance = 0;

	std::cout << std::endl << std::endl;
	std::cout << "Quantifying Gravitational Force" << std::endl;
	std::cout << "-------------------------------" << std::endl << std::endl;

	std::cout << "Input Mass (Kg)for Object (a): ";
		std::cin >> userInput_mass1;
	std::cout << "Input Mass (Kg) for Object (b): ";
		std::cin >> userInput_mass2;
	std::cout << "Input centre-centre distance (m) between both Masses: "; 
		std::cin >> userInput_distance;
	std::cout << std::endl;

	GravitationalForce::gf gforce(userInput_mass1, userInput_mass2, userInput_distance);
	
	std::cout << gforce;
	std::cout << std::endl << std::endl;

    return 0;
}
