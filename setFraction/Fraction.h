// Plum Tree Garden
// Fraction.h


#ifndef SICT_FRACTION_H
#define SICT_FRACTION_H


namespace sict {

    
    class Fraction {
        
        int m_num;
        int m_denom;
    
        
        int max() const;
        int min() const;
        void reduce();
        int gcd() const;

        
    public:
        
        Fraction();
        Fraction(int num, int denom);
        
	bool isEmpty() const;
        void display() const;
        
	Fraction operator+(const Fraction& rhs) const;
        Fraction operator*(const  Fraction& rhs) const;
	bool operator==(const Fraction& rhs) const;
	bool operator!=(const Fraction& rhs) const;
	Fraction operator+=(const Fraction& rhs);
    };
    
    
}

#endif


