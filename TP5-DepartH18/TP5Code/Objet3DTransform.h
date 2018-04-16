///////////////////////////////////////////////////////////
//  Objet3DTransform.h
//  Implementation of the Class Objet3DTransform
//  Created on:      12-mars-2018 10:42:29
//  Original author: p482457
///////////////////////////////////////////////////////////

#if !defined(EA_2B1DE59F_2DAD_4838_A385_A7B4A90F464B__INCLUDED_)
#define EA_2B1DE59F_2DAD_4838_A385_A7B4A90F464B__INCLUDED_

#include "AbsObjet3D.h"

class Objet3DTransform : public AbsObjet3D
{

public:
	Objet3DTransform(float dx = 0.0, float dy = 0.0, float dz = 0.0);
	Objet3DTransform(const Objet3DTransform& mdd);
	virtual Objet3DTransform* cloner(void) const;
	virtual ~Objet3DTransform();

	// Operateur de combinaison de transformation
	Objet3DTransform& operator+=(const Objet3DTransform& mdd);
	float dx(void) const { return m_delta[0]; }
	float dy(void) const { return m_delta[1]; }
	float dz(void) const { return m_delta[2]; }
	const float* delta(void) const { return m_delta; }

	// Methode permettant d'accepter un objet visiteur
	virtual void accueillir(AbsObjet3DVisitor& vis);

	// Methode appliquant la transformation
	virtual void transform(const class Triangle& orig, class Triangle& dest) const;

protected:
	float m_delta[3];
};

#endif // !defined(EA_2B1DE59F_2DAD_4838_A385_A7B4A90F464B__INCLUDED_)
