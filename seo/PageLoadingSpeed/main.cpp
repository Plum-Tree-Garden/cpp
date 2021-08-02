// Author: Plum Tree Garden
// File: pageLoadingSpeed.cpp
// Date: 3/SEP/2020
// SEO GOOGLE OPTIMIZATION
// BASED ON 34 WAYS TO IMPROVE SEO ON GOOGLE
// https://www.quicksprout.com/ways-to-improve-seo-ranking/
// compile: g++ main.cpp pageLoadingSpeed.cpp -std=c++11 -o seo

#include <iostream>
#include <string>

#include "pageLoadingSpeed.h"

int main()
{
	// retrieve url from user input
	std::string userInputURL;
	
	std::cout << std::endl;
	std::cout << "SEO - Google Optimization" << std::endl; 
	std::cout << "Designed to determine optimization vs Google Algorithmic Search Engine"  << std::endl << std::endl;	
	std::cout << "Enter URL: ";	
	std::cin >> userInputURL;


	// 1; Page Loading Speed			- the faster a page loads, the lower the user abandonment rate
	std::cout << std::endl << std::endl; 
	std::cout << "Test 1: Page Loading Speed" << std::endl;
	std::cout << "--------------------------";
	pageSpeed::pls inputURL(userInputURL);
	std::cout << inputURL;

	return 0;
}

