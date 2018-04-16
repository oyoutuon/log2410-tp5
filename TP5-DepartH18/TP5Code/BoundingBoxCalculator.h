///////////////////////////////////////////////////////////
//  BoundingBoxCalculator.h
//  Implementation of the Class BoundingBoxCalculator
//  Created on:      3-avril-2018 13:40:00
//  Original author: francois
///////////////////////////////////////////////////////////

#if !defined(_BoundingBoxCalculator__INCLUDED_)
#define _BoundingBoxCalculator__INCLUDED_

#include <iostream>
#include <string>

#include "TransformVisitor.h"

class BoundingBoxCalculator : public TransformVisitor
{

public:
	BoundingBoxCalculator(void);

	virtual void visit(class Objet3DPart& obj);

	float* getBoite(void) { return m_boite; }

protected:
	float m_boite[6];
};
#endif // !defined(_BoundingBoxCalculator__INCLUDED_)
