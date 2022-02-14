// DllA.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "Base.h"


int BaseTemplate::ID = 0;


// This is an example of an exported variable
BASE_API int nBase=0;

// This is an example of an exported function.
BASE_API int fnBase(void)
{
	return 42;
}

// This is the constructor of a class that has been exported.
// see DllA.h for the class definition
CBase::CBase()
{	
	return;
}
