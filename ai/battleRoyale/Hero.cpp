// Plum Tree Garden
// Hero.h


#include <iostream>
#include <cstring>

#include "Hero.h"


using namespace std;


namespace sict {


    Hero::Hero()                               { m_name[0] = '\0', m_hp = 0, m_att = 0;   }

    Hero::Hero(const char n[40], int h, int a) { strncpy(m_name, n, 40), m_hp=h, m_att=a; }

    void Hero::operator -=(int attack)         { attack > 0 && isAlive() ? m_hp-= attack : m_hp = 0; }

    bool Hero::isAlive() const                 { return m_hp > 0; }

    int Hero::attackStrength() const           { return m_att;    }

    std::ostream& operator<<(std::ostream& os, const Hero& hero) { return os << hero.m_name;  }

    const Hero& operator*(const Hero& first, const Hero& second) {

        Hero hero1 = first;     Hero hero2 = second;     int i = 0;

            while (i < max_rounds && hero1.isAlive() && hero2.isAlive())
                hero1 -= hero2.attackStrength(), hero2 -= hero1.attackStrength(), i++;

            cout << "Ancient Battle! " << first << " vs " << second << " : Winner is "
                 << ((hero1.isAlive()) ? first : second) << " in " << i << " rounds." << endl;

        return (hero1.isAlive()) ? first : second;

        
    }

};
