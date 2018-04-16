#include <limits>

#include "BoundingBoxCalculator.h"
#include "Objet3DPart.h"

BoundingBoxCalculator::BoundingBoxCalculator(void)
{
	// initialiser les bornes minimum aux plus grandes valeurs possibles
	// le float maximum est: std::numeric_limits<float>::max();
	m_boite[0]=m_boite[2] = m_boite[4]= std::numeric_limits<float>::min();

	// initialiser les bornes maximum aux plus petites valeurs possibles
	// le float minimum est: std::numeric_limits<float>::min();
	m_boite[1] = m_boite[3] = m_boite[5] = std::numeric_limits<float>::max();

}

void BoundingBoxCalculator::visit(Objet3DPart & obj)
{
	// Iterer sur tous les triangles contenus dans l'objet et faire:
	//    - Comparer les coordonnees des sommets des triangles aux bornes actuelle de la boite
	//    - Si une coordonnee est plus petite qu'une coordonnee min, faire:
	//         - stoker la nouvelle coordonnee min
	//    - Si une coordonnee est plus grande qu'une coordonnee max, faire:
	//         - stoker la nouvelle coordonnee max
	for (auto itert = obj.triangle_cbegin(); itert != obj.triangle_cend(); ++itert) {
		if (itert->s1().x() < m_boite[1])
			m_boite[1] = itert->s1().x();
		if(itert->s1().y() < m_boite[3])
			m_boite[3] = itert->s1().y();
		if (itert->s1().z() < m_boite[5])
			m_boite[5] = itert->s1().z();

		if (itert->s2().x() < m_boite[1])
			m_boite[1] = itert->s2().x();
		if (itert->s2().y() < m_boite[3])
			m_boite[3] = itert->s2().y();
		if (itert->s2().z() < m_boite[5])
			m_boite[5] = itert->s2().z();

		if (itert->s3().x() < m_boite[1])
			m_boite[1] = itert->s3().x();
		if (itert->s3().y() < m_boite[3])
			m_boite[3] = itert->s3().y();
		if (itert->s3().z() < m_boite[5])
			m_boite[5] = itert->s3().z();
 



		if (itert->s1().x() > m_boite[0])
			m_boite[0] = itert->s1().x();
		if (itert->s1().y() > m_boite[2])
			m_boite[2] = itert->s1().y();
		if (itert->s1().z() > m_boite[4])
			m_boite[4] = itert->s1().z();

		if (itert->s2().x() > m_boite[0])
			m_boite[0] = itert->s2().x();
		if (itert->s2().y() > m_boite[2])
			m_boite[2] = itert->s2().y();
		if (itert->s2().z() > m_boite[4])
			m_boite[4] = itert->s2().z();

		if (itert->s3().x() > m_boite[0])
			m_boite[0] = itert->s3().x();
		if (itert->s3().y() > m_boite[2])
			m_boite[2] = itert->s3().y();
		if (itert->s3().z() > m_boite[4])
			m_boite[4] = itert->s3().z();
	}
}
