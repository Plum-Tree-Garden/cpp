// Plum Tree Garden
// Date.h

#ifndef AID_DATE_H
#define AID_DATE_H

#include <iostream>

namespace aid {
    

    // pre-define const int
    const int min_year = 2018;
    const int max_year = 2038;
    
    const int min_date = 751098;
    
    const int NO_ERROR = 0;
    const int CIN_FAILED = 1;
    const int DAY_ERROR = 2;
    const int MON_ERROR = 3;
    const int YEAR_ERROR = 4;
    const int PAST_ERROR = 5;

    
    class Date {
        
        // class variables
        
        
        int mdays(int, int) const;
        
    public:
        
        int m_year;
        int m_month;
        int m_day;
        int m_compare;
        int m_dataNumb;
        
        // constructors
        Date();
        Date(int year, int month, int day);
        
        // operators
        bool operator >  (const Date& rhs) const;
        bool operator <  (const Date& rhs) const;
        bool operator >= (const Date& rhs) const;
        bool operator <= (const Date& rhs) const;
        bool operator != (const Date& rhs) const;
        bool operator == (const Date& rhs) const;
        
        // queries and modifiers
        int errCode() const;
        bool bad() const;
        bool isEmpty() const;
        
        std::istream& read(std::istream& istr);
        std::ostream& write(std::ostream& ostr) const;
        
        
    };

    // helper functions
    std::istream& operator >> (std::istream& istr, Date&);
    std::ostream& operator << (std::ostream& ostr, const Date&);
    
    
}


#endif
