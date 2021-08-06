// Plum Tree Garden
// Allocator.cpp

#include "SavingsAccount.h"
#include "ChequingAccount.h"

namespace sict {
    
    
    iAccount* CreateAccount(const char* type, double balance) {
        
        
        if (type != nullptr && type[0] != '\0') {
            
            switch (type[0]) {
                    
                case 'S': { return new SavingsAccount(balance, .05); break; }
                case 'C' : { return new ChequingAccount(balance, 0.50, 2.00); }
                default : return nullptr;
            }
        }
        
        else { return nullptr; }
    }
    
    
}
