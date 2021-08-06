// Plum Tree Garden
// Perishable.h



#define _CRT_SECURE_NO_WARNINGS
#ifndef AID_PERISHABLE_H
#define AID_PERISHABLE_H

#include <fstream>
#include <iostream>

#include "Good.h"
#include "Date.h"

namespace aid {
    
    
    class Perishable : public Good {
        
        Date m_exp;
        
    public:
        
        Perishable();
        const Date& expiry() const;
                
        std::fstream& store(std::fstream& file, bool newLine = true) const;
        std::fstream& load(std::fstream& file);
        std::ostream& write(std::ostream& os, bool linear) const;
        std::istream& read(std::istream& is);
    };
    
    iGood* CreatePerishable();
}

#endif



