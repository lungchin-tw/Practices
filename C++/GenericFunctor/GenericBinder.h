#pragma once


#include "GenericFunctor.h"


template<typename TIncoming>
class BinderFirst
	: public FunctorImpl<typename TIncoming::ResultType, typename TIncoming::ParamList::Tail>
{
public:
	typedef Functor<typename TIncoming::ResultType, typename TIncoming::ParamList::Tail> TOutgoing;
	typedef typename TIncoming::Param1 TBound;
	typedef typename TIncoming::ResultType ResultType;

	BinderFirst( const TIncoming& functor, TBound bound )
		: InFunctor( functor )
		, Bound( bound )
	{}

	BinderFirst( const BinderFirst& other )
		: InFunctor( other.InFunctor )
		, Bound( other.Bound )
	{}

	ResultType operator()()
	{
		return InFunctor(Bound);
	}

	ResultType operator()( typename TOutgoing::Param1 p1 )
	{
		return InFunctor(Bound, p1);
	}

private:
	TIncoming InFunctor;
	TBound Bound;
};