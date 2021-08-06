// Plum Tree Garden
// Date.cpp

#define _CRT_SECURE_NO_WARNINGS


#include <iostream>

#include "Date.h"


using namespace std;


namespace aid {
    
    // default constructor
    Date::Date() { m_year = 0; m_month = 0; m_day = 0; }
    
    // Constructor: w/ 3 paramaters
    Date::Date(int year, int month, int day) {

        if (year >= min_year && year <= max_year) {
            if (month > 0 && month < 13) {
                if (day > 0 && day <= mdays(month, year)) {
                    //cout << "here" << endl;
                        m_compare = NO_ERROR;
                        m_year = year; m_month = month; m_day = day;
                        m_dataNumb = year * 372 + month * 31 + day;
                    
                    if (m_dataNumb < min_date) { *this = Date(); m_compare = PAST_ERROR; }
                    }
                else     { *this = Date(); m_compare = DAY_ERROR;  } }
            else         { *this = Date(); m_compare = MON_ERROR;  } }
        else             { *this = Date(); m_compare = YEAR_ERROR; }
    }
    
    // isEmpty function
    bool Date::isEmpty() const                   { return (m_day == 0 && m_month == 0 && m_year == 0);  }
    
    // int errCode() function
    int Date::errCode() const                    { return (m_compare);                    }
    
    // bad() function
    bool Date::bad() const                       { return (m_compare != NO_ERROR);        }
    
    // operator: less than
    bool Date::operator<(const Date& rhs) const  { return (m_dataNumb < rhs.m_dataNumb);  }
    
    // operator: greater than
    bool Date::operator>(const Date& rhs) const  { return (m_dataNumb > rhs.m_dataNumb);  }
    
    // operator: less than or equal to
    bool Date::operator<=(const Date& rhs) const { return (m_dataNumb <= rhs.m_dataNumb); }
    
    // operator: greater than or equal to
    bool Date::operator>=(const Date& rhs) const { return (m_dataNumb >= rhs.m_dataNumb); }
    
    // operator: compare equal to
    bool Date::operator==(const Date& rhs) const { return (m_day == rhs.m_day && m_month == rhs.m_month && m_year == rhs.m_year && m_dataNumb == rhs.m_dataNumb); }
    
    // operator: not equal to
    bool Date::operator!=(const Date& rhs) const { return (m_year != rhs.m_year || m_month != rhs.m_month || m_day != rhs.m_day || m_dataNumb != rhs.m_dataNumb); }
    
    // store in istream / return
    std::istream& Date::read(std::istream& istr) {
        
        Date f_yyMMdd;
        char filler;
        
        istr
            >> f_yyMMdd.m_year  >> filler
            >> f_yyMMdd.m_month >> filler
            >> f_yyMMdd.m_day;
        //cout << f_yyMMdd.m_day << endl << f_yyMMdd.m_month << endl << f_yyMMdd.m_year << endl;
                if (istr.fail()) { m_compare = CIN_FAILED; }
                else             { *this = Date(f_yyMMdd.m_year, f_yyMMdd.m_month, f_yyMMdd.m_day); }
        
        return istr;
    }
    
    // store in ostream / return
    std::ostream& Date::write (std::ostream& ostr) const {
    
        ostr << m_year << "/" << (m_month < 10 ? 0 : m_month);
        
        if (m_month < 10) ostr << m_month; ostr << "/" << (m_day < 10 ? 0 : m_day);
        if (m_day < 10) ostr << m_day;
        
        return ostr;
    }
    
    // return reference to istream / read
    std::istream& operator >> (std::istream& istr, Date& rhs) { return rhs.read(istr);  }
    
    // ostream: return reference from ostream / write
    std::ostream& operator << (std::ostream& ostr, const Date& rhs) { return rhs.write(ostr); }
    
    // private function
    int Date::mdays(int mon, int year) const {
        int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
        int month = mon >= 1 && mon <= 12 ? mon : 13;
        month--;
        return days[month] + int((month == 1)*((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
    }
    
}
