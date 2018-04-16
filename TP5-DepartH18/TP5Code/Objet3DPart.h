///////////////////////////////////////////////////////////
//  Objet3DPart.h
//  Implementation of the Class Objet3DPart
//  Created on:      12-mars-2018 10:42:05
//  Original author: p482457
///////////////////////////////////////////////////////////

#if !defined(EA_9DB65DC2_FBFC_4180_8428_6F8FA7ACA1CE__INCLUDED_)
#define EA_9DB65DC2_FBFC_4180_8428_6F8FA7ACA1CE__INCLUDED_

#include "AbsObjet3D.h"
#include "TriangleProxyIterator.h"

class Objet3DPart : public AbsObjet3D
{

public:
	Objet3DPart();
	explicit Objet3DPart(const Triangle& t);
	Objet3DPart(const Objet3DPart& mdd);
	virtual ~Objet3DPart();
	virtual Objet3DPart* cloner(void) const;

	// Interface de gestion des triangles definissant l'objet
	virtual TriangleIterator triangle_begin();
	virtual TriangleIterator triangle_end();
	virtual TriangleIterator_const triangle_cbegin() const;
	virtual TriangleIterator_const triangle_cend() const;
	virtual void addTriangle(const Triangle&);
	virtual TriangleIterator_const removeTriangle(TriangleIterator_const);

	// Methode permettant d'accepter un objet visiteur
	virtual void accueillir(AbsObjet3DVisitor& vis);

private:
	TriangleContainer m_triangles;
};
#endif // !defined(EA_9DB65DC2_FBFC_4180_8428_6F8FA7ACA1CE__INCLUDED_)
