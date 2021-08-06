// Plum Tree Garden
// SavingsAccount.h


#include "Account.h"


#ifndef SICT_SAVINGSACCOUNT_H
#define SICT_SAVINGSACCOUNT_H


namespace sict {
    
    
    class SavingsAccount : public Account {
        
        double m_interest;
        
    public:
        
        virtual ~SavingsAccount() { }
        SavingsAccount(double, double);
        void monthEnd();
        void display(std::ostream&) const;
        
    };
    
}

#endif
