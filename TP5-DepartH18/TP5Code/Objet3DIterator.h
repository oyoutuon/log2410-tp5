///////////////////////////////////////////////////////////
//  Objet3DIterator.h
//  Implementation of the Class Objet3DIterator
//  Created on:      12-mars-2018 10:42:27
//  Original author: p482457
///////////////////////////////////////////////////////////

#if !defined(EA_161706C3_4A7A_4373_B130_79E7569F3523__INCLUDED_)
#define EA_161706C3_4A7A_4373_B130_79E7569F3523__INCLUDED_

#include <iterator>

typedef std::vector<std::unique_ptr<class AbsObjet3D> > Objet3DContainer;

// Definition d'un iterateur sur des Objet3D constants
class Objet3DIterator_const : public std::iterator<std::random_access_iterator_tag, size_t>
{

public:
	Objet3DIterator_const(Objet3DContainer::const_iterator& it) : m_iter(it) {};
	Objet3DIterator_const(const Objet3DIterator_const& mdd) : m_iter(mdd.m_iter) {};

	explicit operator const Objet3DContainer::const_iterator&() const { return m_iter; };
	const Objet3DIterator_const& operator++() { ++m_iter; return *this; }
	Objet3DIterator_const operator++(int) { Objet3DIterator_const iterTmp(*this); ++m_iter; return iterTmp; }
	const Objet3DIterator_const& operator--() { --m_iter; return *this; }
	Objet3DIterator_const operator--(int) { Objet3DIterator_const iterTmp(*this); --m_iter; return iterTmp; }
	bool operator==(const Objet3DIterator_const& rhs) const { return m_iter == rhs.m_iter; }
	bool operator!=(const Objet3DIterator_const& rhs) const { return !(m_iter == rhs.m_iter); }
	const class AbsObjet3D& operator*() const { return *(m_iter->get()); }
	const class AbsObjet3D* operator->() const { return m_iter->get(); }
	const Objet3DIterator_const& operator+=(size_t s) { m_iter += s; return *this; }
	const Objet3DIterator_const& operator-=(size_t s) { m_iter -= s; return *this; }

#if 0
	friend Objet3DIterator operator+(const Objet3DIterator_const&, size_t);
	friend iterator operator+(size_t, const iterator&);
	friend Objet3DIterator_const operator-(const Objet3DIterator_const&, size_t);
	friend difference_type operator-(Objet3DIterator_const, Objet3DIterator_const);
	friend void swap(Objet3DIterator_const& lhs, Objet3DIterator_const& rhs);
	friend bool operator==(const Objet3DIterator_const&, const Objet3DIterator_const&);
	friend bool operator!=(const Objet3DIterator_const&, const Objet3DIterator_const&);
	friend bool operator<(const Objet3DIterator_const&, const Objet3DIterator_const&);
	friend bool operator>(const Objet3DIterator_const&, const Objet3DIterator_const&);
	friend bool operator<=(const Objet3DIterator_const&, const Objet3DIterator_const&);
	friend bool operator>=(const Objet3DIterator_const&, const Objet3DIterator_const&);
#endif

private:
	Objet3DContainer::const_iterator m_iter;
};

// Definition d'un iterateur sur des Objet3D non-constants
class Objet3DIterator : public std::iterator<std::random_access_iterator_tag, size_t>
{

public:
	Objet3DIterator(Objet3DContainer::iterator& it) : m_iter(it) {};
	Objet3DIterator(const Objet3DIterator& mdd) : m_iter(mdd.m_iter) {};

	explicit operator Objet3DContainer::iterator&() { return m_iter; };
	const Objet3DIterator& operator++() { ++m_iter; return *this; }
	Objet3DIterator operator++(int) { Objet3DIterator iterTmp(*this); ++m_iter; return iterTmp; }
	const Objet3DIterator& operator--() { --m_iter; return *this; }
	Objet3DIterator operator--(int) { Objet3DIterator iterTmp(*this); --m_iter; return iterTmp; }
	bool operator==(const Objet3DIterator& rhs) const { return m_iter == rhs.m_iter; }
	bool operator!=(const Objet3DIterator& rhs) const { return !(m_iter == rhs.m_iter); }
	class AbsObjet3D& operator*() const { return *(m_iter->get()); }
	class AbsObjet3D* operator->() const { return m_iter->get(); }
	const Objet3DIterator& operator+=(size_t s) { m_iter += s; return *this; }
	const Objet3DIterator& operator-=(size_t s) { m_iter -= s; return *this; }

#if 0
	friend Objet3DIterator operator+(const Objet3DIterator&, size_t);
	friend iterator operator+(size_t, const iterator&);
	friend Objet3DIterator operator-(const Objet3DIterator&, size_t);
	friend difference_type operator-(Objet3DIterator, Objet3DIterator);
	friend void swap(Objet3DIterator& lhs, Objet3DIterator& rhs);
	friend bool operator==(const Objet3DIterator&, const Objet3DIterator&);
	friend bool operator!=(const Objet3DIterator&, const Objet3DIterator&);
	friend bool operator<(const Objet3DIterator&, const Objet3DIterator&);
	friend bool operator>(const Objet3DIterator&, const Objet3DIterator&);
	friend bool operator<=(const Objet3DIterator&, const Objet3DIterator&);
	friend bool operator>=(const Objet3DIterator&, const Objet3DIterator&);
#endif

private:
	Objet3DContainer::iterator m_iter;
};



#endif // !defined(EA_161706C3_4A7A_4373_B130_79E7569F3523__INCLUDED_)
