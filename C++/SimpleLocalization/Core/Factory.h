#pragma once


#include "Map.h"
#include "Types.h"
#include "TypeDatabase.h"
#include "Memory.h"


#define HV_DESTROY_INSTANCE_POINTER( object )\
	if( object != nullptr )\
	{\
		hive::DestroyObject( object );\
		object = nullptr;\
	}\


namespace hive
{


class HV_Core_API Factory
{
public:
	typedef size_t UIDType;
	typedef Map<void*, Identifier*> TInstanceTable;
	typedef Map< StringT, TInstanceTable* > TIdentifierTable;
	typedef TIdentifierTable::Iterator TIdentifierTableIterator;


	static Factory& Instance();

	void* CreateObjectByName( const StringT& name, bool auto_identifier = HV_TRUE );

	template<typename TYPE>
	void* CreateObject( bool auto_identifier = HV_TRUE )
	{
		TypeInfo& type = _typeDB.GetTypeInfo<TYPE>();
		void* mem = HV_AllocMem( type.GetSize() );
		type.ConstructObject( mem );

		if( type.AutoRegisterInstance() == HV_TRUE )
		{
			RegisterInstance( type.GetName(), mem, auto_identifier );
		}

		return mem;
	};

	template<typename TYPE>
	void DestructObject( TYPE* object )
	{
		DestructObject<TYPE>( object, Int2Type<hive::IsNativeType<TYPE>::Val>() );
	};

	template<typename TYPE>
	void DestructObject( TYPE* object, Int2Type<1> )
	{
		HV_DeallocDel<TYPE>( object );
	}

	template<typename TYPE>
	void DestructObject( TYPE* object, Int2Type<0> )
	{	
		TypeInfo* ti_ptr = GetTypeInfoByName( hive::GetSubTypeName<TYPE>( (void*)object ) );

		if( ti_ptr != nullptr )
		{
			if( ti_ptr->AutoRegisterInstance() == HV_TRUE )
			{
				RemoveInstance( *ti_ptr, object );
			}

			ti_ptr->DestructObject( object );
			HV_DeallocateMem( object );
		}
	}

	template<typename Concrete>
	TypeInfo& RegisterType()
	{
		return _typeDB.GetTypeInfo<Concrete>();
	}

	void RegisterType( TypeInfo& value );
	
	template<typename Concrete>
	TypeInfo& GetTypeInfo()
	{
		return _typeDB.GetTypeInfo<Concrete>();
	}

	TypeInfo* GetTypeInfoByName( const StringT& name );

	Identifier* FindIdentifierByInstance( const TypeInfo& ti, void* instance );
	void* GetInstanceByUID( const StringT& type_name, Factory::UIDType id );
	void* GetInstanceByUUID( const StringT& type_name, const HvUUID& uuid );

	void RegisterInstance( const StringT& type_name, void* instance, bool auto_identifier );


private:
	
	Factory(){};
	Factory( const Factory& other );
	Factory& operator=( const Factory& other );
	~Factory();

	//UIDType GetNextUID();
	//UIDType GetCurrentUID();
	//void SetBaseUID( UIDType base );
	//UIDType GetBaseUID() const;
	//void ResetUID( UIDType base );
	
	void RemoveInstance( const TypeInfo& ti, void* instance );

	TypeDataBase _typeDB;
	TIdentifierTable _identifierTable;
	//NextIDGenerator<UIDType> _UIDGenerator;


	friend HV_Core_API void InitializeIdentifierByOther( TypeInfo& ti, void* mem, const Identifier &other );
};


template<typename Concrete>
TypeInfo& RegisterType()
{
	return Factory::Instance().RegisterType<Concrete>();
}


HV_Core_API TypeInfo* GetTypeInfoByName( const StringT& name );

template<typename TYPE>
Identifier* GetIdentifierByInstance( void* mem )
{
	return Factory::Instance().FindIdentifierByInstance( GetTypeInfo<TYPE>(), mem );
}

HV_Core_API void* GetInstanceByUID( const StringT& type_name, Factory::UIDType id );
HV_Core_API void* GetInstanceByUUID( const StringT& type_name, const HvUUID& uuid );


/*
* template function CreateObjectByName
*
* typename Interface : The expected base type or interface
*/
template<typename Interface>
Interface* CreateObjectByName( const StringT& name, bool auto_identifier = HV_TRUE )
{
	return static_cast<Interface*>(Factory::Instance().CreateObjectByName( name, auto_identifier ));
}


/*
* template function CreateObject
*
* typename Concrete : The expected type
* typename Base : The expected base type
*/
template<typename Concrete, typename Base>
Base* CreateObject( bool auto_identifier = HV_TRUE )
{
	return (Base*)(Factory::Instance().CreateObject<Concrete>( auto_identifier ));
}


template<class TYPE>
void DestroyObject( TYPE* object )
{
	Factory::Instance().DestructObject<TYPE>( object );
}



} // End of namespace hive

