// Plum Tree Garden
// ChequingAccount.h


#ifndef SICT_CHEQUINGACCOUNT_H
#define SICT_CHEQUINGACCOUNT_H

#include <iostream>
#include "Account.h"

using namespace std;

namespace sict {
    
    
    class ChequingAccount : public Account {
        
        double m_transFee;
        double m_monthFee;
        
        
    public:
        
        ChequingAccount(double, double, double);
        bool credit(double);
        bool debit(double);
        void monthEnd();
        void display(std::ostream&) const;
        
    };
    
} 



#endif
