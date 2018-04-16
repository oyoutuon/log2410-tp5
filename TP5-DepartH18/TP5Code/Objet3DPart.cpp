///////////////////////////////////////////////////////////
//  Objet3DPart.cpp
//  Implementation of the Class Objet3DPart
//  Created on:      12-mars-2018 10:42:05
//  Original author: p482457
///////////////////////////////////////////////////////////

#include "Objet3DPart.h"
#include "Objet3DTransform.h"

void TriangleProxyIterator_impl<TriangleContainer::const_iterator>::loadCacheTransform(void)
{
	if (m_iter != m_iterEnd)
	{
		//if (m_transform != nullptr)
			m_transform.transform(*m_iter, m_triangleCache);
		//else
			//m_triangleCache = *m_iter;
	}
}

void TriangleProxyIterator_impl<TriangleContainer::iterator>::loadCacheTransform(void)
{
	if (m_iter != m_iterEnd)
	{
		//if (m_transform != nullptr)
			m_transform.transform(*m_iter, m_triangleCache);
		//else
			//m_triangleCache = *m_iter;
	}
}

Objet3DPart::Objet3DPart(){

}

Objet3DPart::Objet3DPart(const Triangle & t)
	: m_triangles(1, t)
{
}

Objet3DPart::Objet3DPart(const Objet3DPart & mdd)
	: m_triangles(mdd.m_triangles)
{
}

Objet3DPart::~Objet3DPart(){

}

Objet3DPart * Objet3DPart::cloner(void) const
{
	return new Objet3DPart(*this);
}

TriangleIterator Objet3DPart::triangle_begin()
{
	return TriangleIterator( m_triangles.begin(), m_triangles.end());
}

TriangleIterator Objet3DPart::triangle_end()
{
	return TriangleIterator(m_triangles.end(), m_triangles.end());
}

TriangleIterator_const Objet3DPart::triangle_cbegin() const
{
	return TriangleIterator_const(m_triangles.cbegin(), m_triangles.cend());
}

TriangleIterator_const Objet3DPart::triangle_cend() const
{
	return TriangleIterator_const(m_triangles.cend(), m_triangles.cend());
}

void Objet3DPart::addTriangle(const Triangle & t)
{
	m_triangles.push_back(t);
}

TriangleIterator_const Objet3DPart::removeTriangle(TriangleIterator_const iter)
{
	return TriangleIterator_const(m_triangles.erase(iter.get()), m_triangles.cend());
}

void Objet3DPart::accueillir(AbsObjet3DVisitor & vis)
{
	vis.visit(*this);
}
