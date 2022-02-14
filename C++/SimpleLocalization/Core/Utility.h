/**
*
* @file     Utility.h
* @author   Shawn Hsiao
* @version  1.0
*
* @section  LICENSE
*
* (C) 2009 XPEC Entertainment Inc. All rights reserved.
*
* @section	Description
*
* Utility defines and functions
*
*/

#ifndef HIVE_Utility_H
#define HIVE_Utility_H

#include <Core\StringA.h>
#include <Core\StringW.h>

namespace hive
{

template<typename Type>
Type HvMin( Type x, Type y )
{
	return x < y ? x : y;
}

template<typename Type>
Type HvMax( Type x, Type y )
{
	return x < y ? y : x;
}

#define HV_DEGREE_TO_RADIAN(x)  ( (x) / (180) ) * (HV_PI)
#define HV_RADIAN_TO_DEGREE(x)  ( (x) * (180) ) / (HV_PI)


#define HV_GETTER_DECLARATION( ClassName, PropertyName, ReturnType )\
	ReturnType Get##PropertyName() const;\

#define HV_GETTER_IMPLEMENTATION( ClassName, PropertyName, ReturnType )\
	ReturnType ClassName::Get##PropertyName() const\
	{\
		return PropertyName;\
	}\

#define HV_SETTER_DECLARATION( ClassName, PropertyName, ImportType )\
	void Set##PropertyName( ImportType rhs );\

#define HV_SETTER_IMPLEMENTATION( ClassName, PropertyName, ImportType )\
	void ClassName::Set##PropertyName( ImportType rhs )\
	{\
		PropertyName = rhs;\
	}\
						
// clamp variables of any type
template<class Type> inline Type Clamp(Type A, Type Min, Type Max)
{
	if(A<Min) return Min;
	if(A>Max) return Max;
	return A;
}

// swap variables of any type
template<class Type> inline void Swap(Type &A, Type &B)
{
	Type C=A;
	A=B;
	B=C;
}

// Checking if a number is between two numbers or not.
template<typename Type>
inline bool IsBetweenTwoNumbers( Type value, Type begin, Type end )
{
	Type min = hive::HvMin( begin, end );
	Type max = hive::HvMax( begin, end );
	return ( value >= min ) && ( value <= max );
}


/*
* IGenericObserver
*/
template<typename Dispatcher>
class IGenericObserver
{
public:

	virtual ~IGenericObserver(){}
	virtual void Notify( Dispatcher& ) = 0;
	virtual void OnDispatcherDestroy( Dispatcher& ){};
};


template<typename Dispatcher>
void SwitchDispatcher( Dispatcher* old_dispatcher, Dispatcher* new_dispatcher, IGenericObserver<Dispatcher>& observer )
{
	if( old_dispatcher != nullptr )
	{
		old_dispatcher->RemoveObserver( observer );
	}

	if( new_dispatcher != nullptr )
	{	
		new_dispatcher->RegisterObserver( observer );
	}
}


/*
* Uncopyable
*/
class HV_Core_API UnCopyable
{
public:
	UnCopyable(){}
	virtual ~UnCopyable(){}

private:
	UnCopyable( const UnCopyable& );
	UnCopyable& operator=( const UnCopyable& );
};


/*
* a Flag Recorder template
*/
template<typename TYPE>
class FlagRecorder
{
public:
	FlagRecorder() : _flag( 0 )
	{}

	void EnableFlag( TYPE flag )
	{
		_flag = _flag | flag;
	}

	void DisableFlag( TYPE flag )
	{
		_flag = (~flag) & _flag;
	}

	bool IsExistFlag( TYPE flag ) const
	{
		return ( ( flag & _flag ) == flag );
	}

	TYPE GetFlag() const
	{
		return _flag;
	}

private:

	TYPE _flag;
};


/*
* A Visitor tempalte for utility use.
*/
template<typename VisitType, typename R = void> 
class IVisitor
{
public:
	typedef R ReturnType;
	virtual ~IVisitor(){}
	virtual ReturnType Visit( VisitType& )=0;
};

template<typename VisitType, typename R = void> 
class IVisitable
{
public:
	typedef R ReturnType;
	virtual ~IVisitable(){}
	virtual ReturnType Accept( IVisitor<VisitType>& )=0;
};


template<typename TargetType, void (TargetType::*CallBack)() >
class TraverseTargetCallBack : public IVisitor<TargetType>
{
public:

	void Visit( TargetType& target )
	{
		(target.*CallBack)();
	}
};



HV_Core_API wchar_t* Char2WideChar( const char* ch );
HV_Core_API StringW Char2StringW( const char* ch );
HV_Core_API StringA WideChar2StringA( const wchar_t* );
HV_Core_API StringT GetStringTFromChar( const char* ch );


/*
* Alexandrescu( 2000b ) Invented this simple and generic template, could be applied on
* 1. Call a function at Compile Time by a constant
* 2. Dispatching at Compile Time by a constant
*/
template<int v>
struct Int2Type
{
	enum{ value = v };
};


template<typename TYPE>
class NextIDGenerator
{
public:

	NextIDGenerator()
		: _base( 0 )
		, _nextID( 0 )
	{}

	NextIDGenerator( TYPE base )
		: _base( base )
	{}

	TYPE GetNextID()
	{
		return ( ++_nextID + _base );
	}

	TYPE GetCurrentID()
	{
		return ( _nextID + _base );
	}

	TYPE GetBase() const { return _base; }

	void Reset( TYPE base )
	{
		_base = base;
		_nextID = 0;
	}

private:
	TYPE _base;
	TYPE _nextID;
};


// log2 method, by Ellison at 7/10/2013
HV_Core_API int32 log2( int32 x );

// portable c++ GetTickCount
// http://www.firstobject.com/getmillicount-milliseconds-portable-c++.htm
HV_Core_API uint UtilGetTickCount();
//HV_Core_API uint UtilGetTime();

}  // End of namespace hive

#endif // End of HIVE_Utility_H