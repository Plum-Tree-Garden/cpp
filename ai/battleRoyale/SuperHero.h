// Plum Tree Garden
// SuperHero.h


#ifndef SICT_SUPERHERO_H
#define SICT_SUPERHERO_H

#include "Hero.h"


namespace sict {


    class SuperHero : public Hero {
        
	int m_pow;
        int m_d;

    public:

        SuperHero();
        SuperHero(const char name[40], int hp, int att, int pow, int dee);
        int attackStrength() const;
        int defend() const;


    };

    const SuperHero& operator*(const SuperHero& first, const SuperHero& second);

    
}


#endif
