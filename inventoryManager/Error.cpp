// Plum Tree Garden
// Error.cpp

#define _CRT_SECURE_NO_WARNINGS


#include<iostream>
#include<cstring>

#include"Error.h"


using namespace std;


namespace aid {

    Error::~Error() { delete[] m_err; m_err = nullptr; }
    
    void Error::clear() { delete[] m_err; m_err = nullptr; }
    
    bool Error::isClear() const { return  (m_err == nullptr) ? true : false; }

	Error::Error(const char* message) {

		if ((message == nullptr) || (strcmp(message, "") == 0) ) { m_err = nullptr; }
    
        else {
            
			errStrlen = strlen(message);
			
            m_err = new char[errStrlen + 1];
			strncpy(m_err, message, errStrlen);
			m_err[errStrlen] = '\0';

		}

	}
    
	void Error::message(const char* str) {
        
        delete [] m_err;
        
		errStrlen = strlen(str);      // and check string is exist or its empty or not.
		if (str == nullptr) { m_err = nullptr; }
        
		else if (strcmp(str, "") == 0) { m_err = nullptr; }
		
        else {

			m_err = new char[errStrlen + 1];
			strncpy(m_err, str, errStrlen);
			m_err[errStrlen] = '\0';
		}

	}

	const char* Error::message() const {
		
        if (m_err != nullptr) { return m_err; }
		else                  { return nullptr; }
	}
    
	std::ostream& operator<<(std::ostream& os, const Error& text) {
        
		if (text.message() != nullptr) os << text.message();
		return os;
	}
    
// namespace end
}

