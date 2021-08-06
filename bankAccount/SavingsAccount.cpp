// Plum Tree Garden
// SavingsAccount.cpp

#include <iostream>

#include "SavingsAccount.h"


using namespace std;


namespace sict {
    
    
    SavingsAccount::SavingsAccount(double balance, double interest) : Account(balance) {
        
        m_interest = (interest > 0) ? interest : 0;
    }
    
    void SavingsAccount::monthEnd() { credit(balance() * m_interest); }
    
    void SavingsAccount::display(std::ostream& os) const {
        
        os << fixed;
        os.precision(2);
        
        os << "Account type: Savings"                     << endl
        << "Balance: $"          <<  balance()         << endl
        << "Interest Rate (%): " << (m_interest * 100) << endl;
    }
    
}

