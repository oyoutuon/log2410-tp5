#include "TP5_Tests.h"

int main(int argc, char** argv)
{
	TP5_Tests lesTests;

	lesTests.testVisiteurOutput();
	lesTests.testSingleton();
	lesTests.testVisiteurTransformOutput();
	lesTests.testBoundingBoxCalculator();
}