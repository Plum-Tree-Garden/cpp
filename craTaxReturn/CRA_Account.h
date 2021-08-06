// Plum Tree Garden
// CRA_ACCOUNT.h


#ifndef CRA_ACCOUNT_H
#define CRA_ACCOUNT_H


namespace sict {
    
    const int max_name_length = 40;
    const int min_sin = 100000000;  
    const int max_sin = 999999999;  
    const int max_yrs = 4;          
    
    class CRA_Account {
        
        char   m_familyName[max_name_length + 1];
	char   m_givenName[max_name_length + 1];
        int    m_sin; 
	int    m_yrs; 
	int    m_tx_rtn[max_yrs];
        double m_balanceOwing[max_yrs];
        
    public:

	bool isEmpty() const;
	void set(int yrs, double balance);
	void set(const char *familyName, const char *givenName, int sin_);
        void display() const; 

    };

}


#endif


