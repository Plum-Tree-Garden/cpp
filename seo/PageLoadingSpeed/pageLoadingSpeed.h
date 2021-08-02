// Author: Plum Tree Garden
// File: pageLoadingSpeed.H
// Date: 3/SEP/2020
// TODO - CALCULATE ACTUAL PAGE LOADING SPEED FOR ANY GIVEN URL

#ifndef PAGESPEED_PLS_H
#define PAGESPEED_PLS_H

#include <iostream>
#include <string>

namespace pageSpeed 
{
	const int maxPLS_one = 3;
	const int maxPLS_two = 5;

	class pls
	{
		private:
			float m_pls;
			int m_abandonRate;
			int m_remainingUsers;
			std::string	m_url;
			std::string m_standard;

		public:
			pls() : m_pls(0), m_abandonRate(0), m_remainingUsers(0), m_url(""), m_standard("") {}
			pls(const std::string& p);
			pls& operator=(const pls& p);
			~pls() {}
			
			std::string get_url() const;
			float get_pls() const;
			void set_abandonRate(float& p);
			int get_abandonRate() const;
			void set_remainingUsers(int& p);
			int get_remainingUsers() const;
			std::string get_standardOne() const;
			std::string get_standardTwo() const;
			void display(std::ostream& os) const;
	};
	std::ostream& operator<<(std::ostream& os, const pls& p);
}
#endif
