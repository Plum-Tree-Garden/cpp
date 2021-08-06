// Plum Tree Garden
// Kingdom.h

#ifndef SICT_KINGDOM_H
#define SICT_KINGDOM_H


namespace sict {


	struct Kingdom {


		char m_name[32];
		int m_population;


	};


	void display(Kingdom &pKingdom);
	void display(Kingdom pKingdom[], int count);


}


#endif


