// SimpleOpenMP.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <omp.h>


int _tmain(int argc, _TCHAR* argv[])
{
	#pragma omp parallel for
	for ( int i=0; i<10; ++i )
	{
		printf( "<T:%d> - %d\n,", omp_get_thread_num(), i );
	}

	printf( "\n" );

	for ( int i=0; i<10; ++i )
	{
		printf( "%d,", i );
	}

	return 0;
}

