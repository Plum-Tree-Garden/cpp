// Plum Tree Garden
// ChequingAccount.cpp

#include "ChequingAccount.h"
#include <math.h>

namespace sict {
    
    ChequingAccount::ChequingAccount(double balance, double transfee, double monthfee) : Account(balance) {
        
        m_transFee = (transfee > 0) ? transfee : 0;
        m_monthFee = (monthfee > 0) ? monthfee : 0;
    }
    
    bool ChequingAccount::credit(double credit) { return (credit > m_transFee) ? Account::credit(credit - m_transFee) : Account::credit(-1); }
    
    bool ChequingAccount::debit(double debited) { return Account::debit(debited + m_transFee); }
    
    void ChequingAccount::monthEnd() { Account::debit(m_monthFee - m_transFee); }
    
    void ChequingAccount::display(std::ostream& os) const {
        
        os << fixed;
        os.precision(2);
        os << "Account type: Chequing\n" << "Balance: $" << floor (balance()) << endl;
        os << "Per Transaction Fee: " << m_transFee << endl;
        os << "Monthly Fee: " << m_monthFee << endl;
    }
    
}
