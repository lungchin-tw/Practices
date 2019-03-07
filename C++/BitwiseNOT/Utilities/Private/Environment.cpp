/*
** Copyright CHEN, LUNG-CHIN. All Rights Reserved.
*/


#include "Environment.h"
#include "TypeDefine.h"

#include <iostream>


Environment& Environment::Get()
{
	static Environment Instance;
	return Instance;
}

void Environment::Print()
{
	std::cout << "========== Environment::Print ===============" << std::endl;
	std::cout << "\t Sizeof( int )   : " << sizeof(int) << std::endl;
	std::cout << "\t Sizeof( int* )  : " << sizeof(IntPtr) << std::endl;
	std::cout << "\t Sizeof( int** ) : " << sizeof(IntPtrPtr) << std::endl;
	std::cout << "=============================================" << std::endl;
}

