// Plum Tree Garden
// Kingdom.cpp

#include <iostream>
#include "Kingdom.h"


using namespace std;


namespace sict {


	// Display kingdom name and population
	void display(Kingdom &pKingdom) {

		cout << pKingdom.m_name << ", population " << pKingdom.m_population << endl;

	}


	// Display overload
	void display(Kingdom pKingdom[], int count) {
        
        int sum = 0;
        
	        cout << "------------------------------" << endl;
        	cout << "Kingdoms of SICT" << endl;
        	cout << "------------------------------" << endl;
        
        	for (int i = 0; i < count; i++) {
			cout << i + 1 << ". " << pKingdom[i].m_name 
			     << ", population " << pKingdom[i].m_population << endl;
			sum = sum + pKingdom[i].m_population;
        	}

        	cout << "------------------------------" << endl;
        	cout << "Total population of SICT: " << sum << endl;
        	cout << "------------------------------" << endl;
    	}


}
    
