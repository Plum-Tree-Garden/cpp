// Author: Plum Tree Garden
// File: GravitationalForce.h
// Date: 4/sep/2020

// defines/quantifies; mass. gravity constant. distance. gravitational force
// F1 = F2 = G((m1*m2/r(2)))
// F1 = F2 = (6.67*(10^-11) * ((m1*m2) / (r * r))


#ifndef GRAVITATIONALFORCE_GF_H
#define GRAVITATIONALFORCE_GF_H

#include <iostream>


namespace GravitationalForce
{
	class gf
	{
		private:
			double m_mass1;
			double m_mass2;
			double m_distance;
			double m_total_mass;
			double m_total_distance;
			double m_total_md;
			double m_gforce;

		public:
			gf() : m_mass1(0), m_mass2(0), m_distance(0), m_gforce(0), m_total_mass(0), m_total_distance(0), m_total_md(0) {}
			~gf() {}
			gf(const double& m1, const double& m2, const double& d);
			gf& operator=(const gf& gforce);

			double get_massOne() const;
			double get_massTwo() const;
			double get_distance() const;
			double get_totalMass() const;
			double get_totalDistance() const;
			double get_totalMD() const;
			double get_gforce() const;

			void display(std::ostream& os);
	};
	std::ostream& operator<<(std::ostream& os, const gf& g);
}
#endif
