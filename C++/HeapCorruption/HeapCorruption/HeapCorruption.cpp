// HeapCorruption.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <memory>
#include <crtdbg.h>


int _tmain(int argc, _TCHAR* argv[])
{
	_CrtSetDbgFlag( _CRTDBG_ALLOC_MEM_DF /*| _CRTDBG_LEAK_CHECK_DF*/ );
	_CrtSetReportMode( _CRT_ERROR, _CRTDBG_MODE_DEBUG );

	int * array;
   array = (int *) malloc( 5 * sizeof(int) );
   array[1] = 1;
   array[3] = 3;
   array[5] = 5; /* write out-of-bounds */
   array[0] = 0;
   array[2] = 2;
   array[4] = 4;
   free(array);
	return 0;
}

