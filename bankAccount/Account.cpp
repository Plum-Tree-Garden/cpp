// Plum Tree Garden
// Account.cpp

#include <iostream>

#include "Account.h"


using namespace std;


namespace sict {
    
    Account::Account(double balance)    {         m_balance = (balance > 0) ? balance : 0; }
    
    bool Account::credit(double credit) { return (m_balance += (credit > 0) ? credit : 0); }
    
    bool Account::debit(double debit)   { return (m_balance -= (debit > 0) ? debit : 0);   }
    
    double Account::balance() const     { return  m_balance;                               }
    
    
    
}
