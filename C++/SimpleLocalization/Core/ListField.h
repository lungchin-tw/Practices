#pragma once

#include "ContainerField.h"


namespace hive
{

class TypeInfo;


template<typename TYPE>
class ListFieldExportIterator : public ContainerField::ExportIterator
{
public:

	typedef typename hive::List<TYPE> TList;
	typedef typename TList::Iterator TIterator;


	ListFieldExportIterator( void* mem )
		: _data( *((TList*)mem) )
		, _iterator( _data.Begin() )
	{}

	void* GetKey() const { return nullptr; }
	void* GetValue() const { return (void*)(&(*_iterator)); }
	void MoveNext()
	{
		if( _iterator != _data.End() )
		{
			++_iterator;
		}
	}

	bool IsEnd() { return ( _iterator == _data.End() ); }

private:
	TList& _data;
	TIterator _iterator;
};


template<typename TYPE>
class ListFieldImportIterator : public ContainerField::ImportIterator
{
public:
	ListFieldImportIterator( void* mem )
		: _data( *((hive::List<TYPE>*)mem) )
	{}

	void AddItem( void* value )
	{
		AddItem( value, Int2Type<hive::IsPointer<TYPE>::Val>() );
	}

	void AddItem( void*, void* )
	{
		throw StringT( _T("void ListFieldImportIterator::AddItem( void* key, void* value ) is invalid.") );
	}

	void* AddEmptyItem()
	{
		if( hive::IsPointer<TYPE>::Val == 0 )
		{
			_data.PushBack( TYPE() );
			return &_data.Back();
		}
		
		throw StringT( _T("void ArrayFieldImportIterator::AddEmptyItem() can't be applied for pointer type .") );
	}

	void* AddEmptyItem( void* )
	{
		throw StringT( _T("void ListFieldImportIterator::AddEmptyItem( void* key ) is invalid.") );
	}

private:

	void AddItem( void* value, Int2Type<0> )
	{
		_data.PushBack( *((TYPE*)value) );
	}

	void AddItem( void* value, Int2Type<1> )
	{
		_data.PushBack( (TYPE)value );
	}

	hive::List<TYPE>& _data;
};

	
template<typename TYPE>
class ListField : public ContainerField
{
public:

	ListField() 
		: ContainerField( nullptr
						, 0
						, &GetTypeInfo<TYPE>()
						, IsPointer<TYPE>::Val
						, nullptr
						, SubTypeNameFunctorGenerator<TYPE>().Generate() )
	{}


	ContainerField::ExportIterator* CreateExportIterator( void* mem )
	{
		return new ListFieldExportIterator<TYPE>( mem );
	}

	ContainerField::ImportIterator* CreateImportIterator( void* mem )
	{
		return new ListFieldImportIterator<TYPE>( mem );
	}
};	
	

}// End of namespace hive