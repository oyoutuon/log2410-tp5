///////////////////////////////////////////////////////////
//  Objet3DComposite.cpp
//  Implementation of the Class Objet3DComposite
//  Created on:      12-mars-2018 10:42:22
//  Original author: p482457
///////////////////////////////////////////////////////////

#include "Objet3DComposite.h"

Objet3DComposite::Objet3DComposite(){

}

Objet3DComposite::Objet3DComposite(const Objet3DComposite & mdd)
{
	for (auto iter = mdd.cbegin(); iter != mdd.cend(); ++iter)
		addChild(*iter);
}

Objet3DComposite::~Objet3DComposite(){

}

Objet3DComposite * Objet3DComposite::cloner(void) const
{
	return new Objet3DComposite(*this);
}

Objet3DIterator Objet3DComposite::begin()
{
	return m_objets.begin();
}

Objet3DIterator Objet3DComposite::end()
{
	return m_objets.end();
}

Objet3DIterator_const Objet3DComposite::cbegin() const
{
	return m_objets.cbegin();
}

Objet3DIterator_const Objet3DComposite::cend() const
{
	return m_objets.cend();
}

void Objet3DComposite::addChild(const AbsObjet3D & obj)
{
	m_objets.push_back(std::unique_ptr<AbsObjet3D>(obj.cloner()));
}

Objet3DIterator_const Objet3DComposite::removeChild(Objet3DIterator_const iter)
{
	return m_objets.erase(Objet3DContainer::const_iterator(iter));
}

void Objet3DComposite::accueillir(AbsObjet3DVisitor & vis)
{
	vis.visit(*this);
}

