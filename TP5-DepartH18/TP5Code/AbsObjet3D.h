///////////////////////////////////////////////////////////
//  AbsObjet3D.h
//  Implementation of the Class AbsObjet3D
//  Created on:      12-mars-2018 10:43:12
//  Original author: p482457
///////////////////////////////////////////////////////////

#if !defined(EA_E5457525_34F5_4f8d_9391_101D9DE26E42__INCLUDED_)
#define EA_E5457525_34F5_4f8d_9391_101D9DE26E42__INCLUDED_

#include <vector>
#include <memory>
#include <string>
#include <iostream>

#include "Objet3DIterator.h"
#include "AbsObjet3DVisitor.h"

class AbsObjet3D
{

public:
	AbsObjet3D() = default;
	virtual ~AbsObjet3D() {};
	virtual AbsObjet3D* cloner(void) const = 0;

	// Interface de gestion des enfants dans le patron composite
	virtual Objet3DIterator begin();
	virtual Objet3DIterator end();
	virtual Objet3DIterator_const cbegin() const;
	virtual Objet3DIterator_const cend() const;
	virtual void addChild( const AbsObjet3D& );
	virtual Objet3DIterator_const removeChild(Objet3DIterator_const);

	// Methode permettant d'accepter un objet visiteur
	virtual void accueillir(AbsObjet3DVisitor& vis) = 0;
};

#endif // !defined(EA_E5457525_34F5_4f8d_9391_101D9DE26E42__INCLUDED_)
