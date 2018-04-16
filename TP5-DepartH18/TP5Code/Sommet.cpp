///////////////////////////////////////////////////////////
//  Sommet.cpp
//  Implementation of the Class Sommet
//  Created on:      12-mars-2018 21:52:37
//  Original author: p482457
///////////////////////////////////////////////////////////

#include "Sommet.h"

Sommet::Sommet(float x, float y, float z)
{
	m_coord[0] = x;
	m_coord[1] = y;
	m_coord[2] = z;
}

std::ostream& operator<<(std::ostream& o, const Sommet& s)
{
	return o << "( " << s.x() << ", " << s.y() << ", " << s.z() << ")";
}
