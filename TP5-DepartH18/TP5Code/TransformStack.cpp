#include "TransformStack.h"
#include "Objet3DTransform.h"

// Instancier le vecteur de stockage des transformations
std::vector<std::unique_ptr<class Objet3DTransform>> TransformStack::m_transforms;

Objet3DTransform & TransformStack::getCurrent(void)
{
	// Si la pile de transformation est vide faire
	//    - Pousser une transformation vide sur la pile
	// Retourner la derniere transformation de la pile
	if (TransformStack::m_transforms.empty()) {
	TransformStack::push(Objet3DTransform(0, 0, 0));
	}
	return *(TransformStack::m_transforms.back());
}

void TransformStack::pushCurrent(void)
{
	// Si la pile de transformation n'est pas vide faire
	//    - Pousser la dernière transformation sur la pile
	// Sinon faire
	//    - Pousser une transformation vide sur la pile
	if (TransformStack::m_transforms.empty())
		TransformStack::push(Objet3DTransform(0, 0, 0));
	else
		TransformStack::push(*(TransformStack::m_transforms.back()));
		

}

void TransformStack::push(const Objet3DTransform & t)
{
	// Pousser la transformation recue en parametre sur la pile
	std::unique_ptr<class Objet3DTransform> p(new Objet3DTransform(t));

	TransformStack::m_transforms.push_back(std::move(p));

}

void TransformStack::pop(void)
{
	// Si la pile n'est pas vide faire
	//    - Retirer la derniere transformation de sur la pile
	if (!(TransformStack::m_transforms.empty()))
		TransformStack::m_transforms.pop_back();

}
