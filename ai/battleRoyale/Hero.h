// Plum Tree Garden
// Hero.h


#ifndef SICT_HERO_H
#define SICT_HERO_H
 

namespace sict {
    

    const int max_rounds = 100;

        class Hero {

            char m_name[40];
            int m_hp;
            int m_att;

        public:

            Hero();
            Hero(const char name[40], int hp, int att);
            void operator-=(int attack);
            bool isAlive() const;
            int attackStrength() const;
            friend std::ostream& operator<<(std::ostream& os, const Hero& hero);

    };

            const Hero& operator*(const Hero& first, const Hero& second);
}

#endif
