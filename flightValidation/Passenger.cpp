// Plum Tree Garden
// Passenger.cpp    


#include <iostream>
#include <cstring>
#include <iomanip>

#include "Passenger.h"


using namespace std;


namespace sict {


// default constructor
Passenger::Passenger() { 
    
   m_name[0] = '\0', m_dest[0] = '\0', m_yy = 0, m_mm = 0, m_dd = 0; 
}


// 2 paramater constructor
Passenger::Passenger(const char* name, const char* destination) {
    
 ( (name != nullptr) && (destination != nullptr) ) 
 ? (strncpy(m_name, name, 18), strncpy(m_dest, destination, 18), m_yy = 2018, m_mm = 10, m_dd = 1 )
 : (m_name[0] = '\0', m_dest[0] = '\0' );

// *this=Passenger(name, destination, 2018, 10, 1);
}


// 5 param consructor
Passenger::Passenger(const char* name, const char* destination, int yy, int mm, int dd) {

 ( (name != nullptr && destination != nullptr && yy > 2016 && yy < 2021 && mm > 0 && mm < 13 && dd > 0 && dd < 32) ) 
 ? (strncpy(m_name, name, 18), strncpy(m_dest, destination, 18), m_yy = yy, m_mm = mm, m_dd = dd )
 : (m_name[0] = '\0', m_dest[0] = '\0', m_yy = 0, m_mm = 0, m_dd = 0 );
// *this=Passenger();
}



// return passenger name
const char* Passenger::name() const { 
    
   return (!isEmpty()) ? ( m_name ) : ( "" ); 
}


// query travel compatability
bool Passenger::canTravelWith(const Passenger& x) const {
    
   return (strcmp(x.m_dest, m_dest) == 0 && x.m_yy == m_yy && x.m_mm == m_mm && x.m_dd == m_dd);
}


// query empty state
bool Passenger::isEmpty() const {   
    
   return ((m_name[0] == '\0' ||  m_dest[0] == '\0' || m_yy < 2017 || m_yy > 2020 || m_mm < 1 || m_mm > 12 || m_dd < 1 || m_dd > 31));
}


// display passenger data
void Passenger::display() const {

 ( !isEmpty() ) 
 ? ( cout << m_name << " - " << m_dest << " on " << m_yy << "/" << setfill('0') << setw(2) << m_mm << "/" << setfill('0') << setw(2) << m_dd << endl )
 : ( cout << "No passenger!" << endl );
}




// namespace end
}


