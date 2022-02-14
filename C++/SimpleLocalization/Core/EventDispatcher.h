#pragma once


#include "Array.h"
#include "Types.h"
#include "Utility.h"


namespace hive
{




/*
* GenericEventDispatcher
*/
template<typename Dispatcher>
class GenericEventDispatcher
{
public:
	GenericEventDispatcher(){}
	~GenericEventDispatcher()
	{
		Dispatch_OnDestroy();

		_observers.RemoveAll();
	}

	void RegisterObserver( IGenericObserver<Dispatcher>& observer )
	{	
		IGenericObserver<Dispatcher>* item = &observer;
		if( _observers.Find( item ) < 0 )
		{
			_observers.PushBack( &observer );
		}
	}

	void RemoveObserver( IGenericObserver<Dispatcher>& observer )
	{
		IGenericObserver<Dispatcher>* item = &observer;
		uint idx = _observers.Find( item );
		if( idx >= 0 )
		{
			_observers.Remove( idx );
		}
	}

	void RemoveAllObserver()
	{
		_observers.RemoveAll();
	}
	
	template<typename Dispatcher>
	void DispatchByType()
	{
		Dispatcher* dispatcher = static_cast<Dispatcher*>( this );

		for( uint i=0; i<_observers.Size(); i++ )
		{	
			_observers( i )->Notify( *dispatcher );
		}
	}

protected:

	void Dispatch_OnDestroy()
	{
		Dispatcher* dispatcher = static_cast<Dispatcher*>( this );

		for( uint i=0; i<_observers.Size(); i++ )
		{	
			_observers( i )->OnDispatcherDestroy( *dispatcher );
		}
	}


	hive::Array< IGenericObserver<Dispatcher>* > _observers;

};

} // End of namespace hive