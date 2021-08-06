// Plum Tree Garden
// Good.cpp


#define _CRT_SECURE_NO_WARNINGS


#include <iostream>
#include <cstring>
#include <fstream>
#include <iomanip>

#include "Good.h"


using namespace std;


namespace aid {
    
    
    const char * Good::name() const { return m_name;             }
    const char * Good::sku() const  { return m_sku;              }
    const char * Good::unit() const { return m_unit;             }
    bool Good::taxed() const        { return m_isTaxed;          }
    double Good::itemPrice() const  { return m_price;            }
    double Good::total_cost() const { return itemCost() * m_qty; }
    void Good::quantity(int qty)    { m_qty = qty;               }
    int Good::qtyNeeded() const     { return m_qtyN;             }
    int Good::quantity() const      { return m_qty;              }
    Good::~Good()                   { delete[] m_name; m_name = nullptr; }
    double Good::itemCost() const   { return m_isTaxed ? m_price * (1.0 + tax_rate) : m_price; }
    void Good::message(const char * msg) { m_err.message(msg);             }
    bool Good::isClear() const           { return m_err.isClear();         }
    Good::Good(const Good& item)         { m_name = nullptr; *this = item; }
    bool Good::operator==(const char* sku) const { return (strcmp(m_sku, sku) == 0);       }
    bool Good::operator>(const char* sku) const  { return strcmp(m_sku, sku) > 0;          }
    bool Good::operator>(const iGood& item) const{ return strcmp(m_name, item.name()) > 0; }
    int Good::operator+=(int add) { return (m_qty += (add > 0 ? add : 0));  }
    std::ostream& operator<<(std::ostream & os, const iGood& item) { return item.write(os, true);}
    std::istream& operator>>(std::istream& is, iGood& item)    { return item.read(is); }
    double operator+=(double& add, const iGood& item) { return item.total_cost() + add;}
    
    void Good::name(const char* name) {
        
        if (name != nullptr) { m_name = new char[max_name_length+1];
            strncpy(m_name, name, max_name_length + 1);
            m_name[max_name_length] = '\0'; }
        else                 { m_name = nullptr; }
    }
    
    Good::Good(const char type) {
        
        m_type = type; m_sku[0] = '\0'; m_name = nullptr; m_unit[0] = '\0'; m_qty = 0; m_qtyN= 0;
        m_price = 0; m_isTaxed = false; m_err.message();
    }
    
    Good::Good(const char* sku, const char* _name, const char* unit, int qty, bool isTaxed, double price, int qtyN) {
        
        strncpy(m_sku, sku, max_sku_length + 1);
        m_sku[max_sku_length] = '\0';
        name(_name);
        strncpy(m_unit, unit, max_unit_length + 1);
        m_unit[max_unit_length] = '\0';
        m_qty = qty; m_isTaxed = isTaxed; m_price = price; m_qtyN = qtyN;
    }
    
    Good& Good::operator=(const Good& item) {
        
        if (this != &item) {
            
            strncpy(m_sku, item.m_sku, max_sku_length + 1);
            m_sku[max_sku_length] = '\0';
            strncpy(m_unit, item.m_unit, max_unit_length + 1);
            m_unit[max_unit_length] = '\0';
            name(item.m_name);
            m_qty = item.m_qty; m_price = item.m_price; m_isTaxed = item.m_isTaxed;
            m_qtyN = item.m_qtyN;
        }
        
        return *this;
    }
    
    bool Good::isEmpty() const {
        return  m_name == nullptr && m_sku[0] == '\0' && m_unit[0] == '\0' && m_qty == 0 &&
        m_price == 0 && m_isTaxed == false;
    }
    
    std::fstream & Good::store(std::fstream & file, bool newLine) const {
        
        file
        << m_type << "," << m_sku  << ',' << m_name << ',' << m_unit << ',' << m_isTaxed << ','
        << m_price << ',' << quantity() << ',' << qtyNeeded();
        
        if (newLine) { file << endl; }
        
        return file;
    }
    
    std::fstream& Good::load(std::fstream& file) {
        
        char newSku[max_sku_length + 1]; char newUnit[max_unit_length + 1]; char newName[max_name_length + 1];
        int newQty; int newQtyN; double newPrice; char taxed;
        
        file.getline(newSku, 1999, ',');
        file.getline(newName, 1999, ',');
        file.getline(newUnit, 1999, ',');
        file >> taxed; file.ignore();
        file >> newPrice; file.ignore();
        file >> newQty; file.ignore();
        file >> newQtyN; file.ignore();
        
        *this = Good(newSku, newName, newUnit, newQty, taxed != '0', newPrice, newQtyN);
        
        return file;
    }
    
    
    std::ostream& Good::write(std::ostream& os, bool linear) const {
        
        if (!m_err.isClear()) { os << m_err.message(); }
        
        else if (!isEmpty()) {
            
            char nme[max_name_length];
            int qty = m_qty;
            
            if (linear) {
                
                strncpy(nme, m_name, 20);
                nme[20] = 0;
                
                os << std::setw(max_sku_length)   << std::left << m_sku << "|"
                << std::setw(20) << std::left  << nme << "|"
                << std::setw(7)  << std::fixed << std::setprecision(2) << std::right << itemCost() << "|"
                << std::setw(4)  << std::right << qty << "|"
                << std::setw(10) << std::left  << m_unit << "|"
                << std::setw(4)  << std::right << m_qtyN<< "|";
            }
            else {
                strncpy(nme,m_name, 74);
                nme[74] = 0;
                os << " Sku: " << m_sku << std::endl
                << " Name (no spaces): " << nme << std::endl
                << " Price: " << m_price << std::endl
                << " Price after tax: ";
                
                if (m_isTaxed) { os << itemCost() << std::endl; }
                
                else { os << " N/A" << std::endl; }
                
                os << " Quantity on Hand: " << qty << " " << m_unit << std::endl
                   << " Quantity needed: " << m_qtyN;
            }
            
        }
        return os;
    }
    
    std::istream & Good::read(std::istream & is) {
        
        char newSku[max_sku_length + 1]; char newUnit[max_unit_length + 1]; char newName[max_name_length + 1];
        int newQty; int newQtyN; double newPrice; char taxed;
        
        if (!is.fail()) m_err.clear();
        
        std::cout << " Sku: "; is.getline(newSku, max_sku_length, '\n');
        std::cout << " Name (no spaces): "; is.getline(newName, 74, '\n');
        std::cout << " Unit: "; is.getline(newUnit, 10, '\n');
        std::cout << " Taxed? (y/n): "; is >> taxed;
        
        if (taxed == 'y' || taxed == 'Y' || taxed == 'n' || taxed == 'N') {
            std::cin.ignore(1000, '\n'); std::cout << " Price: "; is >> newPrice; }
        
        else { is.setstate(std::ios::failbit); m_err.message("Only (Y)es or (N)o are acceptable"); }
        
        if (m_err.isClear() && is.fail()) { m_err.message("Invalid Price Entry"); }
        if (m_err.isClear()) { std::cout << " Quantity on hand: "; std::cin >> newQty; }
        if (m_err.isClear() && is.fail()) { m_err.message("Invalid Quantity Entry"); }
        if (m_err.isClear()) { std::cout << " Quantity needed: "; std::cin >> newQtyN; std::cin.ignore(); }
        if (m_err.isClear() && is.fail()) { m_err.message("Invalid Quantity Needed Entry"); }
        if (!is.fail()) {
            *this = Good(newSku, newName, newUnit, newQty, taxed == 'y' || taxed == 'Y', newPrice, newQtyN); }
        
        return is;
    }
    
    // namespace end
}
