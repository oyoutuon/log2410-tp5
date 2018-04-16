#include "AbsObjet3D.h"

// Conteneur vide d'enfant pour simplifier l'écriture des methodes
// qui retournent des iterateurs
static Objet3DContainer empty_container;

Objet3DIterator AbsObjet3D::begin()
{
	return empty_container.begin();
}

Objet3DIterator AbsObjet3D::end()
{
	return empty_container.end();
}

Objet3DIterator_const AbsObjet3D::cbegin() const
{
	return empty_container.cbegin();
}

Objet3DIterator_const AbsObjet3D::cend() const
{
	return empty_container.cend();
}

void AbsObjet3D::addChild(const AbsObjet3D &)
{
	// Echoue silencieusement
}

Objet3DIterator_const AbsObjet3D::removeChild(Objet3DIterator_const)
{
	// Echoue silencieusement
	return empty_container.cend();
}
