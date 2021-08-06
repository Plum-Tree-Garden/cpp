// Plum Tree Garden
// CRA_ACCOUNT.cpp


#include <iostream>
#include <iomanip>
#include <cstring>
#include "CRA_Account.h"


using namespace std;


namespace sict {


    bool CRA_Account::isEmpty() const { return !m_sin; }


    void CRA_Account::set(int yrs, double balance) {

        if (!isEmpty() && m_yrs < max_yrs) { m_tx_rtn[m_yrs] = yrs, m_balanceOwing[m_yrs] = balance, m_yrs++; }
    }


    void CRA_Account::set(const char* familyName, const char* givenName, int sin_) {
        
        m_familyName[0] = '\0', m_givenName[0] = '\0', m_sin = 0;
        
    	int sin = sin_;
        
	if (sin >= min_sin && sin <= max_sin && familyName[0] != '\0' && givenName[0] != '\0') {
            
		int sum = 0;
	    
            for (int i = 0; i < 5; ++i) {
                int temp = sin % 100;
                int even = temp / 10 * 2;
                sum += temp % 10 + even / 10 + even % 10;
                sin /= 100; }
            
            if (sum % 10 == 0) {
                	m_sin = sin_;
                strncpy(m_familyName, familyName, max_name_length + 1);
                strncpy(m_givenName, givenName, max_name_length + 1);
        }
        
        for (int i = 0; i < max_yrs; ++i) { m_balanceOwing[i] = 0, m_yrs = 0; } }
    }

	
    void CRA_Account::display() const {

	if(!isEmpty()) {		          cout << "Family Name: "   << m_familyName      << endl;
            					  cout << "Given Name : "   << m_givenName       << endl;
            					  cout << "CRA Account: "   << m_sin             << endl;
            for     (int i = 0; i < m_yrs; ++i) { cout << "Year ("          << m_tx_rtn[i]       << ") ";
            if      (m_balanceOwing[i] > 2.00)  { cout << "balance owing: " << m_balanceOwing[i] << endl; }
	    else if (m_balanceOwing[i] < -2.00) { cout << "refund due: "    << fixed             << 
		                                     setprecision(2) << (-1 * m_balanceOwing[i]) << endl; }
	    else 				{ cout << "No balance owing or refund due!"      << endl; }}}
	else 					{ cout << "Account object is empty!" 	         << endl; }

    }
    
}


