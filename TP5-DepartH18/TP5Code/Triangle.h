///////////////////////////////////////////////////////////
//  Triangle.h
//  Implementation of the Class Triangle
//  Created on:      12-mars-2018 21:52:34
//  Original author: p482457
///////////////////////////////////////////////////////////

#if !defined(EA_D4E99ABD_A482_453b_9D74_AEF769B694E8__INCLUDED_)
#define EA_D4E99ABD_A482_453b_9D74_AEF769B694E8__INCLUDED_

#include "Sommet.h"

class Triangle
{

public:
	Triangle(void) {};
	Triangle(const Sommet& s1, const Sommet& s2, const Sommet& s3) 
	{ 
		m_sommet[0] = s1;  m_sommet[1] = s2; m_sommet[2] = s3;
	};
	Triangle(const Triangle& mdd) 
	{
		m_sommet[0] = mdd.m_sommet[0];
		m_sommet[1] = mdd.m_sommet[1];
		m_sommet[2] = mdd.m_sommet[2];
	};

	Sommet* sommets() { return m_sommet; }
	Sommet& s1() { return m_sommet[0]; }
	Sommet& s2() { return m_sommet[1]; }
	Sommet& s3() { return m_sommet[2]; }
	const Sommet* sommets() const { return m_sommet; }
	const Sommet& s1() const { return m_sommet[0]; }
	const Sommet& s2() const { return m_sommet[1]; }
	const Sommet& s3() const { return m_sommet[2]; }
private:
	Sommet m_sommet[3];

};
#endif // !defined(EA_D4E99ABD_A482_453b_9D74_AEF769B694E8__INCLUDED_)
