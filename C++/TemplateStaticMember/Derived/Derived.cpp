// Derived.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "Derived.h"
#include "Base.h"


// This is an example of an exported variable
DERIVED_API int nDerived=0;

// This is an example of an exported function.
DERIVED_API int fnDerived(void)
{
	return 42;
}

// This is the constructor of a class that has been exported.
// see Derived.h for the class definition
CDerived::CDerived()
{
	int id = 0;
	
	/*id = ComTemplate<int, true>::GetID();
	printf( "ComTemplate<int>::GetID() = %d\n", id );*/

	id = ComTemplate<int, false>::GetID();
	printf( "ComTemplate<int>::GetID() = %d\n", id );
	
	id = ComTemplate<float>::GetID();
	printf( "ComTemplate<int>::GetID() = %d\n", id );

	return;
}
