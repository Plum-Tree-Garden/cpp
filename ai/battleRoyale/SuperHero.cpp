// Plum Tree Garden
// SuperHero.cpp


#include <iostream>
#include <cstring>

#include "SuperHero.h"


using namespace std;


namespace sict {

    SuperHero::SuperHero()                { m_pow = 0, m_d = 0;                      }

    int SuperHero::defend() const         { return m_d;                              }
    
    int SuperHero::attackStrength() const { return (Hero::attackStrength() + m_pow); }
    
    SuperHero::SuperHero(const char name[40], int hp, int att, int pow, int d)

    :Hero(name, hp, att)                  { m_pow = pow, m_d = d;                    }


    const SuperHero& operator*(const SuperHero& first, const SuperHero& second) {

        SuperHero sHero1 = first;     SuperHero sHero2 = second;     int i = 0;

        while (i < max_rounds && sHero1.isAlive() && sHero2.isAlive()) {

            sHero1 -= ( sHero2.attackStrength() - sHero1.defend() );
            sHero2 -= ( sHero1.attackStrength() - sHero2.defend() );
            i++;
        }

        cout << "Super Fight! " << first << " vs " << second << " : Winner is "
             << ((sHero1.isAlive()) ? first : second) << " in " << i << " rounds." << endl;

        return (sHero1.isAlive()) ? first : second;

    }

}
