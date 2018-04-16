///////////////////////////////////////////////////////////
//  TP5_Tests.h
//  Implementation of the Class TP5_Tests
//  Created on:      12-mars-2018 10:42:32
//  Original author: p482457
///////////////////////////////////////////////////////////

#if !defined(EA_8F5DA6E7_D3AF_4553_9518_33D2FA7BE423__INCLUDED_)
#define EA_8F5DA6E7_D3AF_4553_9518_33D2FA7BE423__INCLUDED_

#include "Sommet.h"
#include "Triangle.h"
#include "Objet3DComposite.h"
#include "Objet3DTransform.h"

class TP5_Tests
{

public:
	TP5_Tests();
	virtual ~TP5_Tests();

	void testVisiteurOutput();
	void testSingleton();
	void testVisiteurTransformOutput();
	void testBoundingBoxCalculator();

private:
	// Quelques sommets
	Sommet s1, s2, s3, s4, s5, s6, s7, s8;

	// Quelques triangles
	Triangle t11, t12, t21, t22, t31, t32, t41, t42, t51, t52, t61, t62;

	// Un objet composite
	Objet3DComposite m_objet;
};
#endif // !defined(EA_8F5DA6E7_D3AF_4553_9518_33D2FA7BE423__INCLUDED_)
