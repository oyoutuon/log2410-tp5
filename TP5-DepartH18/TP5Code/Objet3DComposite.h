///////////////////////////////////////////////////////////
//  Objet3DComposite.h
//  Implementation of the Class Objet3DComposite
//  Created on:      12-mars-2018 10:42:22
//  Original author: p482457
///////////////////////////////////////////////////////////

#if !defined(EA_07E396E4_F3D6_464c_93C9_7AE00BE2097F__INCLUDED_)
#define EA_07E396E4_F3D6_464c_93C9_7AE00BE2097F__INCLUDED_

#include "AbsObjet3D.h"

#include <vector>
#include <memory>

class Objet3DComposite : public AbsObjet3D
{

public:
	Objet3DComposite();
	Objet3DComposite( const Objet3DComposite& mdd );
	virtual ~Objet3DComposite();
	virtual Objet3DComposite* cloner(void) const;

	// Interface de gestion des enfants dans le patron composite
	virtual Objet3DIterator begin();
	virtual Objet3DIterator end();
	virtual Objet3DIterator_const cbegin() const;
	virtual Objet3DIterator_const cend() const;
	virtual void addChild(const AbsObjet3D&);
	virtual Objet3DIterator_const removeChild(Objet3DIterator_const);

	// Methode permettant d'accepter un objet visiteur
	virtual void accueillir(AbsObjet3DVisitor& vis);

private:
	Objet3DContainer m_objets;
};
#endif // !defined(EA_07E396E4_F3D6_464c_93C9_7AE00BE2097F__INCLUDED_)
