
/*
** Copyright SOFTSTAR ENTERTAINMENT INC. All Rights Reserved.
*/


//#include "ExternDeclaration.h" I don't need to include the header. Because I use extern instead

float CrossFileFloat = 100.f;

float CrossFileFunction()
{
	CrossFileFloat = 200.f;
	return CrossFileFloat;
}
