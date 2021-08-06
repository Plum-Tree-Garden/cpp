// Plum Tree Garden
// Good.h


#ifndef AID_GOOD_H
#define AID_GOOD_H

#include <iostream>
#include <fstream>

#include "iGood.h"
#include "Error.h"


namespace aid {
    
    const int max_sku_length = 7;
    const int max_unit_length = 10;
    const int max_name_length = 75;
    const double tax_rate = 0.13;
    
    
    class Good : public iGood {
        
        char m_type;
        char m_sku[max_sku_length + 1];
        char m_unit[max_unit_length + 1];
        char *m_name = nullptr;
        int m_qty;
        int m_qtyN;
        double m_price;
        bool m_isTaxed;
        
        
    protected:
        
        Error m_err;
        void name(const char*);
        const char* name() const;
        const char* sku() const;
        const char* unit() const;
        bool taxed() const;
        double itemPrice() const;
        double itemCost() const;
        void message(const char*);
        bool isClear() const;
        
    public:
        
        virtual ~Good();
        Good(const char = 'N');
        Good(const char* sku , const char* _name, const char* unit, int qty = 0, bool isTaxed = true, double price = 0.0, int qtyN = 0);
        Good(const Good& g);
        Good& operator=(const Good& g);
        
        
        std::fstream& store(std::fstream& file, bool newLine = true) const;
        std::fstream& load(std::fstream& file);
        std::ostream& write(std::ostream& os, bool linear) const;
        std::istream& read(std::istream& is);
        
        
        bool operator==(const char*) const;
        double total_cost() const;
        void quantity(int);
        bool isEmpty() const;
        int qtyNeeded() const;
        int quantity() const;
        bool operator>(const char*) const;
        bool operator>(const iGood&) const; // mod1
        int operator+=(int);
    };
    
    std::ostream& operator<<(std::ostream&, const iGood&); // mod3
    std::istream& operator>>(std::istream&, iGood&); // mod4
    double operator+=(double&, const iGood&); // mod2
    iGood* CreateGood();
}

#endif
