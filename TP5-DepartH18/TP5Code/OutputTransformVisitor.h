///////////////////////////////////////////////////////////
//  OutputTransformVisitor.h
//  Implementation of the Class OutputTransformVisitor
//  Created on:      3-avril-2018 11:51:56
//  Original author: francois
///////////////////////////////////////////////////////////

#if !defined(_OutputTransformVisitor__INCLUDED_)
#define _OutputTransformVisitor__INCLUDED_

#include <iostream>
#include <string>

#include "TransformVisitor.h"

class OutputTransformVisitor : public TransformVisitor
{

public:
	OutputTransformVisitor(std::ostream& os) : m_stream(os) {};

	virtual void visit(class Objet3DPart& obj);
	virtual void visit(class Objet3DComposite& obj);

protected:
	std::ostream& m_stream;
	std::string m_indent;
};
#endif // !defined(_OutputTransformVisitor__INCLUDED_)
