///////////////////////////////////////////////////////////
//  TransformStack.h
//  Implementation of the Class AbsObjet3D
//  Created on:      2-avril-2018 19:43:12
//  Original author: p482457
///////////////////////////////////////////////////////////

#if !defined(TransformStack__INCLUDED_)
#define TransformStack__INCLUDED_

#include <vector>
#include <memory>

class TransformStack
{
public:
	static class Objet3DTransform& getCurrent(void);
	static void pushCurrent(void);
	static void push(const class Objet3DTransform& t);
	static void pop(void);

protected:
	TransformStack(void) = default;

	static std::vector<std::unique_ptr<class Objet3DTransform>> m_transforms;
};

#endif