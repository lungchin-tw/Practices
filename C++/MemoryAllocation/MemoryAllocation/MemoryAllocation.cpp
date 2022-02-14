// MemoryAllocation.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <memory>


class Base
{
public:

	Base() : X( 0 )
	{}

	virtual ~Base(){}

	static void* operator new( size_t size )
	{	
		return malloc( size );
	}

	static void operator delete( void* mem, size_t size )
	{	
		free( mem );
	}

protected:
	 int X;
};


class Derived : public Base
{
public:

	Derived() : Y( 0 )
	{}

	virtual ~Derived(){}

protected:
	 int Y;
};


/*void* operator new( size_t size )
{}*/


int _tmain(int argc, _TCHAR* argv[])
{
	// method 1
	/*
	void* mem = malloc( sizeof( Derived ) );
	Base* obj = new ( mem ) Derived;
	delete obj;
	*/

	// method 2
	Base* obj2 = new Derived();
	delete obj2;

	Base* obj3 = new Base();
	delete obj3;

	return 0;
}

