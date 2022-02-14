// Functor.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <io.h>
#include "GenericFunctor.h"
#include "GenericBinder.h"
#include <functional>


using namespace std;


template<class T, class U>
class Conversion
{
	typedef char Small;
	class Big { char dummy[2]; };
	static Small Test( U );
	static Big Test(...);
	static T MakeT();


public:
	enum { exists = (sizeof( Test( MakeT() ) ) == sizeof(Small)) }; 

};


/* Test Functions */
void TestFunction()
{
	cout << "TestFunction()\n";
}

void TestFunction( int i )
{
	cout << "TestFunction( int i ) i = " << i << "\n";
}

void TestFunction( int i, double d )
{
	cout << "TestFunction( int i, double d ) i = " << i << ", d = " << d << "\n";
}

void TestFunctionOperator()
{
	Functor<void, NullType > delegate0( CreateFunctionHandler<void, NullType, void(*)()>( TestFunction ) ); 
	delegate0();

	Functor<void, TYPELIST_1( int ) > delegate1( CreateFunctionHandler<void, TYPELIST_1( int ), void(*)(int)>( TestFunction ) ); 
	delegate1( 10 );

	Functor<void, TYPELIST_2( int, double ) > delegate2( CreateFunctionHandler<void, TYPELIST_2( int, double ), void(*)(int, double)>( TestFunction ) ); 
	delegate2( 1, 4.5 );

	auto f = std::bind( (void(*)())TestFunction );
	f();

	cout << "\n";
}


/*Test Member Function*/
class AMock
{
public:
	
	void PublicMethod()
	{
		cout << "void AMock::PublicMethod()\n";
	}

	void PublicMethod( int value )
	{
		cout << "void AMock::PublicMethod( int value ), value = " << value << "\n";
	}

	void PublicMethod( float x, float y )
	{
		cout << "void AMock::PublicMethod( float x, float y ), x = " << x << ", y = " << y << "\n";
	}
};

template< typename Head, typename Tail >
void TestHeadTail()
{
	cout << "void TestHeadTail()\n";
	cout << "\n";
}

void TestMemberFunctor()
{
	AMock mock;

	// Type 1
	{
		cout << "TestMemberFunctor() : Type 1\n";
		Functor<void, NullType> mf0( CreateMethodHandler<void, NullType, AMock*, void(AMock::*)()>( &mock, &AMock::PublicMethod ) );
		mf0();

		Functor<void, TYPELIST_1(int)> mf1( CreateMethodHandler<void, TYPELIST_1(int), AMock*, void(AMock::*)(int)>( &mock, &AMock::PublicMethod ) );
		mf1(1);

		Functor<void, TYPELIST_2(float, float)> mf2( CreateMethodHandler<void, TYPELIST_2(float, float), AMock*, void(AMock::*)(float, float)>( &mock, &AMock::PublicMethod ) );
		mf2(1, 2);
	}

	// Type 2
	{
		cout << "TestMemberFunctor() : Type 2\n";
		Functor<void, NullType> mf0( (AMock *const)(&mock), (void(AMock::*)())(&AMock::PublicMethod) );
		mf0();

		Functor<void, TYPELIST_1(int)> mf1( (AMock *const)(&mock), (void(AMock::*)(int))(&AMock::PublicMethod) );
		mf1(1);

		Functor<void, TYPELIST_2(float, float)> mf2( (AMock *const)(&mock), (void(AMock::*)(float, float))(&AMock::PublicMethod) );
		mf2(1, 2);
	}

	cout << "\n";
}


/* Test Function Struct */
struct TestFunctionStruct
{
	void operator()( int i )
	{
		cout << "TestFunctionStruct::operator()( int i ) i = " << i << "\n";
	}

	void operator()()
	{
		cout << "TestFunctionStruct::operator()()\n";
	}

	void operator()( int i, double d )
	{
		cout << "TestFunctionStruct::operator()( int i, double d ) i = " << i << ", d = " << d << "\n";
	}
};

void TestStructOperator()
{
	TestFunctionStruct test_struct;

	Functor<void, NullType> delegate0( CreateMethodHandler<void, NullType, TestFunctionStruct*, void(TestFunctionStruct::*)()>( &test_struct, &TestFunctionStruct::operator() ) );
	delegate0();

	Functor<void, TYPELIST_1(int)> delegate1( CreateMethodHandler<void, TYPELIST_1(int), TestFunctionStruct*, void(TestFunctionStruct::*)(int)>( &test_struct, &TestFunctionStruct::operator() ) );
	delegate1(10);
		
	Functor<void, TYPELIST_2(int, double)> delegate2( CreateMethodHandler<void, TYPELIST_2(int, double), TestFunctionStruct*, void(TestFunctionStruct::*)(int, double)>( &test_struct, &TestFunctionStruct::operator() ) );
	delegate2(1, 4.5);

	//auto f = std::bind( (void(*)())TestFunctionStruct, test_struct );
	//f();
	cout << "\n";
}


void TestBinding()
{	
	AMock mock;

	// Example : Binding 1 Parameter
	{ 
		cout << "TestBinding() : Example : Binding 1 Parameter\n";
		typedef Functor<void, TYPELIST_1(int)> TIntFunctor1;

		TIntFunctor1 mf1( CreateMethodHandler<void, TYPELIST_1(int), AMock*, void(AMock::*)(int)>( &mock, &AMock::PublicMethod ) );
		BinderFirst<TIntFunctor1> binder(mf1, 10);
		Functor<void, NullType> mf0(binder);
		mf0();
	}

	// Example : Binding 2 Parameters
	{
		cout << "TestBinding() : Example : Binding 2 Parameters\n";
		typedef Functor<void, TYPELIST_1(float)> TFloatFunctor1;
		typedef Functor<void, TYPELIST_2(float, float)> TFloatFunctor2;

		TFloatFunctor2 mf2( CreateMethodHandler<void, TYPELIST_2(float, float), AMock*, void(AMock::*)(float, float)>( &mock, &AMock::PublicMethod ) );
		BinderFirst<TFloatFunctor2> binder0(mf2, 10);

		Functor<void, TYPELIST_1(float)> mf1(binder0);
		BinderFirst<TFloatFunctor1> binder1(mf1, 20);

		Functor<void, NullType> mf0(binder1);
		mf0();
	}

	cout << "\n";
}


int _tmain(int argc, _TCHAR* argv[])
{
	
	/*cout << Conversion< double, int >::exists << "\n";
	cout << Conversion< char, char* >::exists << "\n";
	cout << Conversion< char*, char* >::exists << "\n";*/
		
	TestStructOperator();
	TestFunctionOperator();
	TestMemberFunctor();

	TestHeadTail< TYPELIST_4(int, char, float, double)::Head, TYPELIST_4(int, char, float, double)::Tail >();

	TestBinding();

	return 0;
}

