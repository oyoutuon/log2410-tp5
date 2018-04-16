///////////////////////////////////////////////////////////
//  Objet3DTransform.cpp
//  Implementation of the Class Objet3DTransform
//  Created on:      12-mars-2018 10:42:30
//  Original author: p482457
///////////////////////////////////////////////////////////

#include "Objet3DTransform.h"
#include "Triangle.h"

Objet3DTransform::Objet3DTransform(float dx, float dy, float dz)
{
	m_delta[0] = dx;
	m_delta[1] = dy;
	m_delta[2] = dz;
}

Objet3DTransform::Objet3DTransform(const Objet3DTransform & mdd)
{
	m_delta[0] = mdd.m_delta[0];
	m_delta[1] = mdd.m_delta[1];
	m_delta[2] = mdd.m_delta[2];
}

Objet3DTransform * Objet3DTransform::cloner(void) const
{
	return new Objet3DTransform(*this);
}

Objet3DTransform::~Objet3DTransform(){

}

Objet3DTransform & Objet3DTransform::operator+=(const Objet3DTransform & mdd)
{
	m_delta[0] += mdd.m_delta[0];
	m_delta[1] += mdd.m_delta[1];
	m_delta[2] += mdd.m_delta[2];
	return *this;
}

void Objet3DTransform::accueillir(AbsObjet3DVisitor & vis)
{
	vis.visit(*this);
}

void Objet3DTransform::transform(const Triangle & orig, Triangle & dest) const
{
	Sommet* sommets_dest = dest.sommets();
	const Sommet* sommets_orig = orig.sommets();
	for (int i = 0; i < 3; ++i)
	{
		sommets_dest[i].x() = sommets_orig[i].x() + m_delta[0];
		sommets_dest[i].y() = sommets_orig[i].y() + m_delta[1];
		sommets_dest[i].z() = sommets_orig[i].z() + m_delta[2];
	}
}

