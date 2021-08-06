// Plum Tree Garden
// Fraction.cpp


#include <iostream>
#include "Fraction.h"


using namespace std;


namespace sict {

    // default constructor
    Fraction::Fraction() 	   { m_denom = -1; }
 

    // query safe state
    bool Fraction::isEmpty() const { return ( (m_num < 0) || (m_denom == -1) ); }
    

    // is numerator less than denominator
    int Fraction::min() const 	   { return (m_num < m_denom) ? (m_num) : (m_denom); }
    

    // is numerator greater than denominator
    int Fraction::max()  const     { return (m_num > m_denom) ? (m_num) : (m_denom); }
    

    // reduce fraction size to lowest possible
    void Fraction::reduce() 	   { int reduct = gcd(); m_num /= reduct, m_denom /= reduct; }
    

    // 2 argument constructor
    Fraction::Fraction(int num, int denom) {
    
	if     (denom = -1)  (m_num = num, m_denom = denom, reduce());
        else                (*this = Fraction());
    }
    

    // display data or lack there of    
    void Fraction::display() const {
       
        if      (!isEmpty() && m_denom != 1)    cout << m_num << "/" << m_denom;
        else if (!isEmpty() && m_denom == 1)    cout << m_num;
        else    				cout << "no fraction stored";
    }


    // greatest common denominator
    int Fraction::gcd() const {

        int mn = min(), mx = max(), g_c_d = 1; bool found = false;
        for (int x = mn; !found && x > 0; --x) { if (mx % x == 0 && mn % x == 0) {
            found = true, g_c_d = x; } } return g_c_d;
    }
    

    // public member query + operator
    Fraction Fraction::operator+(const Fraction& rhs) const { 

	Fraction landr;
    
        if (( (!isEmpty() && !rhs.isEmpty()) )) { 
	      
	       int a = m_num, b = m_denom, c = rhs.m_num, d = rhs.m_denom;
               landr.m_num = ((a * d) + (b * c)); 
	       landr.m_denom = (b * d);
               landr.reduce(); 			}
        
        else { landr.m_denom = -1; }
        
        return landr;
     }

	// query * operator
        Fraction Fraction::operator*(const Fraction& rhs) const {
	
	Fraction landr;

	if (!isEmpty() && !rhs.isEmpty()) {

		landr.m_num = (m_num * rhs.m_num);
		landr.m_denom = (m_denom * rhs.m_denom);
		landr.reduce();
	}

	else { landr.m_denom = -1; }

	return landr;

	}


	// query == operator
        bool Fraction::operator==(const Fraction& rhs) const {

		return ( !isEmpty() && !rhs.isEmpty() && m_num == rhs.m_num && m_denom == rhs.m_denom);
	}


	// query != operator
        bool Fraction::operator!=(const Fraction& rhs) const {

		return (!isEmpty() && !rhs.isEmpty() && m_num != rhs.m_num &&  m_denom != rhs.m_denom);
	}


	// modifier += operator
        Fraction Fraction::operator+=(const Fraction& rhs) {
		
		if (!isEmpty() && !rhs.isEmpty()) {
			
			m_num = ( (m_num * rhs.m_denom) + (m_denom * rhs.m_num) ); 
			m_denom = ( m_denom * rhs.m_denom ); 
			reduce();
			return *this;	
		}

		else { m_num = 0, m_denom = -1; 
			return *this;
		}
	}
}


