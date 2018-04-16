///////////////////////////////////////////////////////////
//  AbsObjet3DVisitor.h
//  Implementation of the Class AbsObjet3DVisitor
//  Created on:      21-mars-2018 16:41:56
//  Original author: francois
///////////////////////////////////////////////////////////

#if !defined(EA_3D81CC67_D57B_4268_856B_6A03432DD161__INCLUDED_)
#define EA_3D81CC67_D57B_4268_856B_6A03432DD161__INCLUDED_

class AbsObjet3DVisitor
{

public:
	AbsObjet3DVisitor() {};
	virtual ~AbsObjet3DVisitor() {};

	virtual void visit(class Objet3DPart& obj) = 0;
	virtual void visit(class Objet3DComposite& obj) = 0;
	virtual void visit(class Objet3DTransform& obj) = 0;


protected:
	virtual void visit(class AbsObjet3D& obj) = 0;
};
#endif // !defined(EA_3D81CC67_D57B_4268_856B_6A03432DD161__INCLUDED_)
