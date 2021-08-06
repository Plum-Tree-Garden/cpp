// Plum Tree Garden
// Perishable.cpp


#include <iostream>
#include <cstring>
#include <fstream>
#include <string>

#include "Perishable.h"


using namespace std;


namespace aid {
    
    Perishable::Perishable() : Good('P') { m_err.clear(); }
    
    const Date& Perishable::expiry() const { return m_exp; }
    
    fstream& Perishable::store(fstream& file, bool newLine) const {
        
        Good::store(file, false);
      
        file << "," << expiry();
        
        if (newLine == true) { file << endl; }
        
        return file;
    }
    
    fstream& Perishable::load(fstream& file) {
        
        Good::load(file);
        
            m_exp.read(file);
            file.ignore();
        
        return file;
    }
    
    std::ostream& Perishable::write(std::ostream& os, bool linear) const {
        
        Good::write(os, linear);
        
        if (isClear()&& !isEmpty()) {
           
            // (linear == false) ? os << "\n Expiry date: " << m_exp : m_exp.write(os);
            if (linear == false) {
                os << "\n Expiry date: " << m_exp;
            }
            else {
                os << m_exp;
            }
            
            // os << ((linear == false) ? ("\n Expiry date: " << m_exp) : ("|" << m_exp) << endl);
        }
        
        return os;
    }
    
    std::istream& Perishable::read(std::istream& is) {
        
        Good::read(is);
        
        if (!is.fail()) {
            
            cout << " Expiry date (YYYY/MM/DD): ";
        
            m_exp.read(is);
            //cout << m_exp << endl;
        }
            
            if (m_exp.errCode() == YEAR_ERROR){ is.setstate(ios::failbit); m_err.message("Invalid Year in Date Entry"); }
            else if (m_exp.errCode() == MON_ERROR) { is.setstate(ios::failbit); m_err.message("Invalid Month in Date Entry"); }
            else if (m_exp.errCode() == DAY_ERROR) { is.setstate(ios::failbit); m_err.message("Invalid Day in Date Entry"); }
            else if (m_exp.errCode() == PAST_ERROR){ is.setstate(ios::failbit); m_err.message("Invalid Expiry in Date Entry"); }
            else if (m_exp.errCode() == CIN_FAILED) { is.setstate(ios::failbit); m_err.message("Invalid Date Entry");}
        
        
        return is;
    }
    
    
// namespace end
}
            

        
    

    
    


