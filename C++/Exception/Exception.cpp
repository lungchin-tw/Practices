// Exception.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"



void DeclareException() throw( ... )
{
	throw exception( "DeclareException Throw Exception.\n" );
}

void UndeclareException()
{
	throw exception( "UndeclareException Throw Exception.\n" );
}

int _tmain(int argc, _TCHAR* argv[])
{
	/*__try
	{
		printf( "__try\n" );
	}
	__finally
	{
		printf( "__finally\n" );
	}*/
	
	
	try
	{
		printf( "try\n" );
		//UndeclareException();
		DeclareException();
	}
	catch( exception& e )
	{	
		printf( e.what() );
	}

	return 0;
}

