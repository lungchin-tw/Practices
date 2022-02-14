// TemplateStaticMember.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Base.h"
#include "Derived.h"



int _tmain(int argc, _TCHAR* argv[])
{
	/*
	* This Project's build will be fail, Because of BASE_API in ComTemplate
	*
	*  template<typename TYPE>
	*  class BASE_API ComTemplate
	*/
	CDerived derived;
	ComDerived com_derived;

	int id = 0;
	id = ComTemplate<int>::GetID();
	printf( "ComTemplate<int>::GetID() = %d\n", id );

	id = ComTemplate<int>::GetID();
	printf( "ComTemplate<int>::GetID() = %d\n", id );
	
	id = ComTemplate<float>::GetID();
	printf( "ComTemplate<int>::GetID() = %d\n", id );

	return 0;
}

