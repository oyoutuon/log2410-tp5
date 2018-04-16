///////////////////////////////////////////////////////////
//  OutputVisitor.h
//  Implementation of the Class AbsObjet3DVisitor
//  Created on:      2-avril-2018 21:24:56
//  Original author: francois
///////////////////////////////////////////////////////////

#if !defined(_OutputVisitor__INCLUDED_)
#define _OutputVisitor__INCLUDED_

#include <iostream>
#include <string>

#include "AbsObjet3DVisitor.h"

class OutputVisitor : public AbsObjet3DVisitor
{

public:
	OutputVisitor(std::ostream& os) : m_stream(os) {};

	virtual void visit(class Objet3DPart& obj);
	virtual void visit(class Objet3DComposite& obj);
	virtual void visit(class Objet3DTransform& obj);

protected:
	virtual void visit(class AbsObjet3D& obj) {};

	std::ostream& m_stream;
	std::string m_indent;
};
#endif // !defined(_OutputVisitor__INCLUDED_)
