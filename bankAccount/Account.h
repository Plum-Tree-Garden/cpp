// Plum Tree Garden
// Account.h


#include "iAccount.h"


#ifndef SICT_ACCOUNT_H
#define SICT_ACCOUNT_H

namespace sict {
    
    
    class Account: public iAccount {
        
        double m_balance;
        
    public:
        
        virtual ~Account() { }
        Account(double);
        bool credit(double);
        bool debit(double);
        
    protected:
        
        double balance() const;
        
    };
    
}


#endif
