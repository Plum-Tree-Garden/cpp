// Plum Tree Garden
// Error.h


#ifndef AID_ERROR_H
#define  AID_ERROR_H

#include <iostream>

using namespace std;


namespace aid {

    
	class Error {
        
		char* m_err;
		int errStrlen = 0;
        
	public:
        
        virtual ~Error();
		Error(const char* errorMessage = nullptr);
		Error(const Error& em) = delete;
		Error& operator=(const Error& em) = delete;
		void clear();
		bool isClear() const;
		void message(const char* str);
		const char* message()const;
	};

	std::ostream& operator<<(std::ostream&, const Error&);
    
}


#endif


