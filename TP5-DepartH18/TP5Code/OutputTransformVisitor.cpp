#include "OutputTransformVisitor.h"
#include "Objet3DPart.h"
#include "Objet3DComposite.h"

void OutputTransformVisitor::visit(Objet3DPart & obj)
{
	// Imprimer tous les triangles contenus dans l'objet
	// Meme methode que OutputVisitor::visit(Objet3DPart& obj)

	m_indent = "  ";
	int itri = 0;
	for (auto itert = obj.triangle_cbegin(); itert != obj.triangle_cend(); ++itert, ++itri) {
		m_stream << m_indent << "T" << itri << ": "
			<< itert->s1() << " | "
			<< itert->s2() << " | "
			<< itert->s3() << std::endl;
	}
}

void OutputTransformVisitor::visit(Objet3DComposite & obj)
{
	// Si l'objet composite a des enfants, faire:
	//     - Incrementer l'indentation de 3 espaces
	//     - Imprimer "COMPOSITE:" selon la bonne indentation sur une ligne seule
	//     - Invoquer la methode TransformVisitor::visit(Objet3DComposite &) de 
	//       la classe de base  pour visiter les enfants
	//     - Restaurer l'indentation
	if (obj.cbegin() != obj.cend()) {
		std::string troisEspaces = "   ";
		std::string saved = m_indent;
		m_indent += troisEspaces;
		m_stream << m_indent << "COMPOSITE:" << std::endl;
		TransformVisitor::
		TransformVisitor::visit(obj);
		m_indent = saved;

	}

}
