///////////////////////////////////////////////////////////
//  TP5_Tests.cpp
//  Implementation of the Class TP5_Tests
//  Created on:      12-mars-2018 10:42:32
//  Original author: p482457
///////////////////////////////////////////////////////////

#include<iostream>

#include "TP5_Tests.h"

#include "Sommet.h"
#include "Triangle.h"
#include "Objet3DPart.h"
#include "Objet3DTransform.h"
#include "OutputVisitor.h"
#include "TransformStack.h"
#include "OutputTransformVisitor.h"
#include "BoundingBoxCalculator.h"

TP5_Tests::TP5_Tests()
	: s1(), s2(1.0),
	s3(1.0, 1.0),
	s4(0.0, 1.0),
	s5(0.0, 0.0, 1.0),
	s6(1.0, 0.0, 1.0),
	s7(0.0, 1.0, 1.0),
	s8(1.0, 1.0, 1.0),
	t11(s1, s3, s2),
	t12(s1, s4, s3),
	t21(s1, s7, s4),
	t22(s1, s5, s7),
	t31(s5, s6, s8),
	t32(s5, s8, s7),
	t41(s6, s2, s3),
	t42(s6, s3, s8),
	t51(s5, s2, s6),
	t52(s5, s1, s2),
	t61(s7, s8, s3),
	t62(s7, s3, s4)
{
	// Regrouper les triangles en faces
	Objet3DPart face1(t11);
	face1.addTriangle(t12);

	Objet3DPart face2(t21);
	face2.addTriangle(t22);

	Objet3DPart face3(t31);
	face3.addTriangle(t32);

	Objet3DPart face4(t41);
	face4.addTriangle(t42);

	Objet3DPart face5(t51);
	face5.addTriangle(t52);

	Objet3DPart face6(t61);
	face6.addTriangle(t62);

	// Definir un cube composite avec 6 faces
	Objet3DComposite cube1;
	cube1.addChild(face1);
	cube1.addChild(face2);
	cube1.addChild(face3);
	cube1.addChild(face4);
	cube1.addChild(face5);
	cube1.addChild(face6);

	// Definir 4 transformations pour positionner les cubes
	Objet3DTransform transfo1(0.0, 0.0, 0.0);
	Objet3DTransform transfo2(1.0, 0.0, 0.0);
	Objet3DTransform transfo3(0.0, 1.0, 0.0);
	Objet3DTransform transfo4(0.0, 0.0, 1.0);

	// Definir des composites pour positionner les 4 cubes dans l'espace
	Objet3DComposite composit1;
	composit1.addChild(transfo1);
	composit1.addChild(cube1);

	Objet3DComposite composit2;
	composit2.addChild(transfo2);
	composit2.addChild(cube1);

	Objet3DComposite composit3;
	composit3.addChild(transfo3);
	composit3.addChild(cube1);

	Objet3DComposite composit4;
	composit4.addChild(transfo4);
	composit4.addChild(cube1);

	// Definir un assemblage de 4 cubes
	m_objet.addChild(composit1);
	m_objet.addChild(composit2);
	m_objet.addChild(composit3);
	m_objet.addChild(composit4);
	std::cout << "objet declaré"<<std::endl;
	
}

TP5_Tests::~TP5_Tests(){
}

void TP5_Tests::testVisiteurOutput()
{
	// Instancier un visiteur de sortie
	OutputVisitor vis(std::cout);

	// Tester le visiteur de sortie sans transformation
	std::cout << "Tests du VISITEUR OutputVisitor" << std::endl;
	std::cout << "=========================" << std::endl << std::endl;
	m_objet.accueillir(vis);
}

void TP5_Tests::testSingleton()
{
	// Instancier un visiteur de sortie
	OutputVisitor vis(std::cout);

	// Construire un objet simple contenant un seul triangle
	Objet3DPart part1(t11);

	// Construire une transformation sur la Part1
	std::cout << std::endl << std::endl;
	std::cout << "Tests du SINGLETON" << std::endl;
	std::cout << "=========================" << std::endl << std::endl;

	part1.accueillir(vis);

	TransformStack::push(Objet3DTransform(0.5, -0.5, 1.0));
	part1.accueillir(vis);

	TransformStack::push(Objet3DTransform(0, 0, 0));
	part1.accueillir(vis);

	TransformStack::pop();
	part1.accueillir(vis);

	TransformStack::pushCurrent();
	part1.accueillir(vis);

	Objet3DTransform t_inverse(-0.5, 0.5, -1.0);
	TransformStack::getCurrent() += t_inverse;
	part1.accueillir(vis);
}

void TP5_Tests::testVisiteurTransformOutput()
{
	// Instancier un visiteur de sortie avec transformation
	OutputTransformVisitor vis(std::cout);

	// Tester le visiteur de sortie avec transformation
	std::cout << "Tests du VISITEUR OutputTransformVisitor" << std::endl;
	std::cout << "=========================" << std::endl << std::endl;
	m_objet.accueillir(vis);
}

void TP5_Tests::testBoundingBoxCalculator()
{
	// Instancier un visiteur de calcul de la boite englobante
	BoundingBoxCalculator vis;

	// Tester le visiteur de calcul de la boite englobante
	std::cout << "Tests du VISITEUR BoundingBoxCalculator" << std::endl;
	std::cout << "=========================" << std::endl << std::endl;
	m_objet.accueillir(vis);

	float* boite = vis.getBoite();
	std::cout << "Boite englobante de l'objet:" << std::endl;
	std::cout << "\txmin = " << boite[0] << std::endl;
	std::cout << "\txmax = " << boite[1] << std::endl;
	std::cout << "\tymin = " << boite[2] << std::endl;
	std::cout << "\tymax = " << boite[3] << std::endl;
	std::cout << "\tzmin = " << boite[4] << std::endl;
	std::cout << "\tzmax = " << boite[5] << std::endl;
}

