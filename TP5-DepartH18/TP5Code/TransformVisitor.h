///////////////////////////////////////////////////////////
//  TransformVisitor.h
//  Implementation of the Class TransformVisitor
//  Created on:      3-avril-2018 11:24:56
//  Original author: francois
///////////////////////////////////////////////////////////

#if !defined(_TransformVisitor__INCLUDED_)
#define _TransformVisitor__INCLUDED_

#include <iostream>
#include <string>

#include "AbsObjet3DVisitor.h"

class TransformVisitor : public AbsObjet3DVisitor
{

public:
	TransformVisitor(void) {};

	virtual void visit(class Objet3DPart& obj) = 0;
	virtual void visit(class Objet3DComposite& obj);
	virtual void visit(class Objet3DTransform& obj);

protected:
	virtual void visit(class AbsObjet3D& obj) {};
};
#endif // !defined(_TransformVisitor__INCLUDED_)
