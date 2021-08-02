

// Author: Plum Tree Garden
// File: pageLoadingSpeed.cpp
// Date: 3/SEP/2020

#include "pageLoadingSpeed.h"


namespace pageSpeed 
{	
	// define member variables based on url page loading speed 
	pls::pls(const std::string& siteURL)
	{
		m_url = siteURL;
		m_pls = 3.4;
		set_abandonRate(m_pls);
		set_remainingUsers(m_abandonRate);
	}

	// assignment user input url as constructor string
	pls& pls::operator=(const pls& p) { return *this; }
	
	// ~50% of users will abanadon if pls > 3.... ~100% if pls > 5 seconds
	void pls::set_abandonRate(float& p)	
	{
		if(p <= maxPLS_one) { m_abandonRate = (int)(p * 16.67); }
		if(p >= maxPLS_two)  { m_remainingUsers = 0; }
		if(p > maxPLS_one && p < maxPLS_two) { m_abandonRate = ((int)((p - 3) * 25)) + 50; }
	}

	void pls::set_remainingUsers(int& p) { m_remainingUsers = (100 - m_abandonRate); }
	std::string pls::get_url() const { return m_url; }
	float pls::get_pls() const { return m_pls; }
	int pls::get_abandonRate() const    { return m_abandonRate; }
	int pls::get_remainingUsers() const { return m_remainingUsers; }
	std::string pls::get_standardOne() const {	return (m_pls <= (float)maxPLS_one) ? "Pass" : "Fail"; }
	std::string pls::get_standardTwo() const {	return (m_pls <= (float)maxPLS_two) ? "Pass" : "Fail"; }

	
	void pls::display(std::ostream& os) const
	{
		os << std::endl;
		os << "user input url: " << get_url() << std::endl;
		os << "fake page loading speed @pls: " << get_pls() << std::endl;
		os << "access w/ 3 second standard: " << get_standardOne() << std::endl;
		os << "access w/ 5 second standard: " << get_standardTwo() << std::endl;
		os << "usrs that accessed site which abandoned: " << get_abandonRate() << "%" << std::endl;
		os << "usrs that accessed site which remainied: " << get_remainingUsers() << "%" << std::endl;
	}
	
	std::ostream& operator<<(std::ostream& os, const pls& p)  { p.display(os); return os; }
}
