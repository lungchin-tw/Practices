#pragma once

#include "ContainerField.h"
#include "Core.h"

namespace hive
{

class TypeInfo;


template<typename Key, typename Value>
class MapFieldExportIterator : public ContainerField::ExportIterator
{
public:

	typedef typename hive::Map<Key, Value> TMap;
	typedef typename TMap::Iterator TIterator;


	MapFieldExportIterator( void* mem )
		: _data( *((TMap*)mem) )
	{
		_iterator = _data.Begin();
	}

	void* GetKey() const
	{	
		return _iterator.GetNode()->m_key;
	}

	void* GetValue() const
	{
		return _iterator.GetNode()->m_item;
	}

	void MoveNext()
	{
		if( _iterator != _data.End() )
		{
			++_iterator;
		}
	}

	bool IsEnd()
	{
		return ( _iterator == _data.End() );
	}


private:
	TMap& _data;
	TIterator _iterator;
};


template<typename Key, typename Value>
class MapFieldImportIterator : public ContainerField::ImportIterator
{
public:
	MapFieldImportIterator( void* mem )
		: _data( *((hive::Map<Key, Value>*)mem) )
	{}

	void AddItem( void* )
	{
		throw StringT( _T("void MapFieldImportIterator::AddItem( void* value ) is invalid.") );
	}

	void AddItem( void* key, void* value )
	{
		AddItem( key, value, Int2Type<hive::IsNativeType<Value>::Val>(), Int2Type<hive::IsPointer<Value>::Val>() );
	}

	void* AddEmptyItem()
	{
		throw StringT( _T("void MapFieldImportIterator::AddEmptyItem(void) is invalid.") );
	}

	void* AddEmptyItem( void* key )
	{
		if( ( hive::IsPointer<Key>::Val == 0 ) && ( hive::IsPointer<Value>::Val == 0 ) )
		{
			_data.Insert( *((Key*)key), Value() );
			return _data.Find( *((Key*)key) );
		}
		
		throw StringT( _T("void MapFieldImportIterator::AddEmptyItem( void* key ) can't be applied on Class/Struct Pointer.") );
	}

private:

	void AddItem( void* key, void* value, Int2Type<1>, Int2Type<0> ) // Value is native type
	{
		_data.Insert( *((Key*)key), *((Value*)value) );
	}

	void AddItem( void*, void*, Int2Type<1>, Int2Type<1> ) // Value is native pointer
	{
		throw StringT( _T("void MapFieldImportIterator::AddItem( void* key, void* value ) can't be applied on Native Pointer.") );
	}

	void AddItem( void*, void*, Int2Type<0>, Int2Type<0> ) // Value is Class/Struct
	{
		throw StringT( _T("void MapFieldImportIterator::AddItem( void* key, void* value ) can't be applied on Class/Stuct.") );
	}

	void AddItem( void* key, void* value, Int2Type<0>, Int2Type<1> ) // Value is Class/Struct Pointer
	{
		_data.Insert( *((Key*)key), (Value)value );
	}



	hive::Map<Key, Value>& _data;
};


template<typename Key, typename Value>
class MapField : public ContainerField
{
public:

	MapField()
		: ContainerField( &hive::GetTypeInfo<Key>()
						, hive::IsPointer<Key>::Val
						, &hive::GetTypeInfo<Value>()
						, hive::IsPointer<Value>::Val
						, SubTypeNameFunctorGenerator<Key>().Generate()
						, SubTypeNameFunctorGenerator<Value>().Generate() )
	{}

	ContainerField::ExportIterator* CreateExportIterator( void* mem )
	{
		return new MapFieldExportIterator<Key, Value>( mem );
	}

	ContainerField::ImportIterator* CreateImportIterator( void* mem )
	{
		return new MapFieldImportIterator<Key, Value>( mem );
	}
};	
	

}// End of namespace hive