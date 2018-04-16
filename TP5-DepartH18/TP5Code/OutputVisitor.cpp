#include "OutputVisitor.h"
#include "Objet3DPart.h"
#include "Objet3DComposite.h"
#include "Objet3DTransform.h"

void OutputVisitor::visit(Objet3DPart & obj)
{
	// Imprimer tous les triangles contenus dans l'objet
	// Chaque triangle est imprime selon le format
	// "T#: (x, y, z) | (x, y, z) | (x, y, z)"
	// ou: # est le numero du triangle a partir de 0
	//     (x, y, z) sont les coordonnees d'un sommet

	m_indent = "  ";
	int itri = 0;
	for (auto itert = obj.triangle_cbegin() ; itert != obj.triangle_cend(); ++itert, ++itri) {
		m_stream << m_indent << "T" << itri << ": "
			<< itert->s1() << " | "
			<< itert->s2() << " | "
			<< itert->s3() << std::endl;
	}
}

void OutputVisitor::visit(Objet3DComposite & obj)
{
	// Imprimer tous les enfants de l'objet
	// Si le composite a des enfants faire:
	//    - incrementer le niveau d'indentation de 3 espaces
	//    - invoquer le visiteur sur chaque enfant
	//    - decrementer le niveau d'indentation
	std::string troiEspaces = "   ";
	m_indent = "   ";
	std::string saved ;

	// Imprimer tous les enfants de l'objet

	auto iter = obj.begin();
	if (iter != obj.end())
	{
		//incrementer le niveau d'indentation de 3 espaces
		saved = m_indent;
		m_indent += troiEspaces;
		m_stream << m_indent << "COMPOSITE:" << std::endl;
		//invoquer le visiteur sur chaque enfant
		for (; iter != obj.end(); ++iter) {
			iter->accueillir(*this);
		}			
		//decrementer le niveau d'indentation	
		m_indent=saved;
	}
	
}

void OutputVisitor::visit(Objet3DTransform & obj)
{
	// Imprimer les attributs de la transformation selon le format:
	// "TRANSFO [dx, dy, dz]"
	// ou : dx, dy et dz sont les composantes de la transformation
	m_stream << "TRANSFO ["
	<< obj.dx()
	<< obj.dy()
	<< obj.dz() << std::endl;
}
