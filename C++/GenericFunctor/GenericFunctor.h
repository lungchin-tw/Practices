
#pragma once

#include <memory>


class NullType;

struct EmptyType {};

template< class T, class U >
struct TypeList
{
	typedef T Head;
	typedef U Tail;
};


#define TYPELIST_1(T1) TypeList< T1, NullType >
#define TYPELIST_2(T1, T2 ) TypeList< T1, TYPELIST_1(T2) >
#define TYPELIST_3(T1, T2, T3 ) TypeList< T1, TYPELIST_2(T2, T3) >
#define TYPELIST_4(T1, T2, T3, T4 ) TypeList< T1, TYPELIST_3(T2, T3, T4) >


template< class TList > struct Length;


template<> 
struct Length<NullType>
{
	enum { value = 0 };
};


template< class T, class U >
struct Length< TypeList<T, U> >
{
	enum { value = 1 + Length<U>::value };
};


template<class TList, unsigned int index, typename DefaultType = NullType >
struct TypeAtNonStrict
{
	typedef DefaultType Result;
};

template<class Head, class Tail, typename DefaultType >
struct TypeAtNonStrict< TypeList<Head, Tail>, 0, DefaultType >
{
	typedef Head Result;
};

template<class Head, class Tail, unsigned int index, typename DefaultType >
struct TypeAtNonStrict< TypeList<Head, Tail>, index, DefaultType >
{
	typedef typename TypeAtNonStrict<Tail, (index-1), DefaultType>::Result Result;
};


template< typename ResultType, class TList> class FunctorImpl;

template< typename ResultType >
class FunctorImpl< ResultType, NullType >
{
public:
	virtual ResultType operator()() = 0;
	virtual ~FunctorImpl(){}
};


template< typename ResultType, typename Param1 >
class FunctorImpl< ResultType, TypeList<Param1, NullType> >
{
public:
	virtual ResultType operator()( Param1 ) = 0;
	virtual ~FunctorImpl(){}
};


template< typename ResultType, typename Param1, typename Param2 >
class FunctorImpl< ResultType, TypeList<Param1, TypeList<Param2, NullType> > >
{
public:
	virtual ResultType operator()( Param1, Param2 ) = 0;
	virtual ~FunctorImpl(){}
};


template< class ParentFunctor, typename TCallback >
class FunctionHandler : public FunctorImpl< typename ParentFunctor::ResultType, typename ParentFunctor::ParamList>
{
public:

	typedef typename ParentFunctor::ResultType ResultType;

	FunctionHandler( const TCallback& callback ) : Callback( callback ) {}

	ResultType operator()()
	{
		return Callback();
	}

	ResultType operator()( typename ParentFunctor::Param1 p1 )
	{
		return Callback( p1 );
	}

	ResultType operator()( typename ParentFunctor::Param1 p1, typename ParentFunctor::Param2 p2 )
	{
		return Callback( p1, p2 );
	}

	virtual ~FunctionHandler(){}

private:
	TCallback Callback;
};


template< typename Return, typename TypeList, typename TCallback >
FunctorImpl<Return, TypeList>* CreateFunctionHandler( const TCallback& callback )
{
	typedef FunctorImpl<Return, TypeList> TFunctorImpl;
	typedef Functor<Return, TypeList> TFunctor;
	typedef FunctionHandler<TFunctor, TCallback> TFunctionHandler;

	TFunctorImpl* handler = new TFunctionHandler( callback );
	return handler;
}


template< typename ParentFunctor, typename TInstancePtr, typename TMethodPtr >
class MethodHandler : public FunctorImpl< typename ParentFunctor::ResultType, typename ParentFunctor::ParamList>
{
public:
	typedef typename ParentFunctor::ResultType ResultType;

	MethodHandler( const TInstancePtr& instance_ptr, TMethodPtr mf_ptr )
		: InstancePtr( instance_ptr )
		, MethodPtr( mf_ptr )
	{}

	ResultType operator()()
	{
		return ((*InstancePtr).*MethodPtr)();
	}

	ResultType operator()( typename ParentFunctor::Param1 p1 )
	{
		return ((*InstancePtr).*MethodPtr)( p1 );
	}

	ResultType operator()( typename ParentFunctor::Param1 p1, typename ParentFunctor::Param2 p2 )
	{
		return ((*InstancePtr).*MethodPtr)( p1, p2 );
	}

private:
	TInstancePtr InstancePtr;
	TMethodPtr MethodPtr;
};


template< typename Return, typename TypeList, typename TInstancePtr, typename TMethodPtr >
FunctorImpl<Return, TypeList>* CreateMethodHandler( const TInstancePtr& instance_ptr, TMethodPtr mf_ptr )
{
	typedef FunctorImpl<Return, TypeList> TFunctorImpl;
	typedef Functor<Return, TypeList> TFunctor;
	typedef MethodHandler<TFunctor, TInstancePtr, TMethodPtr> TMethodHandler;

	TFunctorImpl* handler = new TMethodHandler( instance_ptr, mf_ptr );
	return handler;
}


template< typename ResultType, typename TList >
class Functor
{
public:

	typedef FunctorImpl<ResultType, TList> TImplement;

	typedef ResultType ResultType;
	typedef TList ParamList;
	typedef typename TypeAtNonStrict<TList, 0>::Result Param1;
	typedef typename TypeAtNonStrict<TList, 1>::Result Param2;

	// Customized Constructor For Function
	template< typename TCallback > Functor( const TCallback& callback ); 
	template< typename TInstancePtr, typename TMethodPtr > Functor( const TInstancePtr& instance_ptr, TMethodPtr method_ptr );

	Functor( FunctorImpl< ResultType, ParamList>* impl_ptr )
		:ImplementPtr( impl_ptr )
	{}

	Functor( const Functor& other )
		: ImplementPtr( other.ImplementPtr )
	{}

	ResultType operator()()
	{
		return (*ImplementPtr)();
	}

	ResultType operator()( Param1 p1 )
	{
		return (*ImplementPtr)( p1 );
	}

	ResultType operator()( Param1 p1, Param2 p2 )
	{
		return (*ImplementPtr)( p1, p2 );
	}
	
private:
	
	Functor& operator=( const Functor& );

	TImplement* ImplementPtr;
};


template< typename ResultType, typename TList >
template< typename TCallback >
Functor<ResultType, TList>::Functor( const TCallback& callback )
	:ImplementPtr( new FunctionHandler< Functor, TCallback >( callback ) )
{}

//template< typename ResultType

template< typename ResultType, typename TList >
template< typename TInstancePtr, typename TMethodPtr >
Functor<ResultType, TList>::Functor( const TInstancePtr& instance_ptr, TMethodPtr mf_ptr )
	:ImplementPtr( new MethodHandler< Functor, TInstancePtr, TMethodPtr >( instance_ptr, mf_ptr ) )
{}
