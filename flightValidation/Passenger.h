// Plum Tree Garden
// Passenger.h      


#ifndef SICT_PASSENGER_H     				    // header guard
#define SICT_PASSENGER_H 				    // header guard


namespace sict { 					    // create namespace sict
												
	const int maxCharacters = 19; 			    // maxCharacters for name / dest


    class Passenger {					    // create class Passenger

        char m_name[19], m_dest[19]; 			    // member name and destination
	int m_yy, m_mm, m_dd; 				    // member date == m_yy/mm/dd
	
    public: 						    // public functions
		
        Passenger(); 					    // default constructor
        Passenger(const char*, const char*); 		    // 2 paramater constructor
        Passenger(const char*, const char*, int, int, int); // 5 paramater constructor
	bool canTravelWith(const Passenger&) const; 	    // query travel compatability
        const char* name() const; 	                    // return passenger name
	void display() const; 				    // display passenger data
	bool isEmpty() const; 				    // query empty state

    }; 							    // class end


} 					  		    // namespace end


#endif


