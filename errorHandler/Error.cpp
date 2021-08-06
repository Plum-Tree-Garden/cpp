// Plum Tree Garden
// Error.cpp

#include <iostream>
#include <cstring>

#include "Error.h"


using namespace std;


namespace aid {
    
    
    Error::Error(const char* errorMessage) {
        
	    m_pMessage = nullptr;
	    if (errorMessage != nullptr && errorMessage[0] != '\0') { message(errorMessage); }
    }
    
    void Error::clear() { delete [] m_pMessage; m_pMessage = nullptr; }
    
    bool Error::isClear() const { return (m_pMessage == nullptr || m_pMessage[0] == '\0'); }
    
    void Error::message(const char* str) {
        
	clear();

	int newLength = strlen(str);

        if (str != nullptr && str[0] != '\0') {
            
            m_pMessage = new char[newLength + 1];
            strncpy(m_pMessage, str, newLength);
            m_pMessage[newLength] = '\0';
        }
	else { str = nullptr; }
    }
    
    const char* Error::message() const { 
	    
	    if (m_pMessage != nullptr) { return m_pMessage; } 
	    else 		       { return nullptr; }
    }
    
    std::ostream& operator<<(std::ostream& os, const Error& err) {
        
        if (!err.isClear()) { os << err.message(); }
       
        return os; 
    }

    Error::~Error() { delete [] m_pMessage; m_pMessage = nullptr; }
    
}
