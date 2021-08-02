// Author: Plum Tree Garden
// File: GravitationalForce.h
// Date: 4/sep/2020


#include <cmath>
#include <iomanip>
#include "GravitationalForce.h"


namespace GravitationalForce
{
	
	gf::gf(const double& m1, const double& m2, const double& d) { 
		
		m_mass1 = m1;
		m_mass2 = m2;
		m_distance = d;
		m_total_mass = m_mass1 * m_mass2;
		m_total_distance = m_distance * m_distance;
		m_total_md = m_total_mass / m_total_distance;
		
		const double ga = 6.67;
		const double gb = 0.0000000001;
		double bigG = ga * gb;
		m_gforce = bigG * m_total_md;
	}


	gf& gf::operator=(const gf& gvty) { return *this; }


	double gf::get_massOne() const { return m_mass1; }
	double gf::get_massTwo() const { return m_mass2; }
	double gf::get_distance() const { return m_distance; }
	double gf::get_totalMass() const { return m_total_mass; }
	double gf::get_totalDistance() const { return m_total_distance; }
	double gf::get_totalMD() const { return m_total_md; }
	double gf::get_gforce() const { return m_gforce; }


	void gf::display(std::ostream& os) 
	{
		os << "Mass 1: " << get_massOne() << " Kg" << std::endl;
		os << "Mass 2: " << get_massTwo() << " Kg" << std::endl;
		os << "Distance: " << get_distance() << " metres"<< std::endl;
		os << "Total Mass: " << get_totalMass() << " kg squared"<< std::endl;
		os << "Total Distance: " << get_totalDistance() << " metres squared"<< std::endl;
		os << "Total Mass/Distance: " << get_totalMD() << std::endl;
		os << "Gravitational Force: " << std::fixed << std::setprecision(12) << gf::get_gforce();
		os << " N" << std::endl;
	}

	std::ostream& operator<<(std::ostream& os, const gf& g) 
	{
		g.display(os);
		return os;
	}

}
