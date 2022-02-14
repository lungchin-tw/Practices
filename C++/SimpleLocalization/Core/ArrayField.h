#pragma once

#include "ContainerField.h"


namespace hive
{

class TypeInfo;


template<typename TYPE>
class ArrayFieldExportIterator : public ContainerField::ExportIterator
{
public:
	ArrayFieldExportIterator( void* mem )
		: _data( *((hive::Array<TYPE>*)mem) )
		, _curPos( 0 )
	{}

	void* GetKey() const { return nullptr; }
	void* GetValue() const { return _data.GetItem( _curPos ); }
	void MoveNext()	{ _curPos = IsEnd() ? _curPos : ++_curPos; }
	bool IsEnd() { return ( _curPos >= _data.Size() ); }

	void operator=( const ArrayFieldExportIterator<TYPE>& other )
	{
		_data = other._data;
		_curPos = other._curPos;
	}
	
private:

	hive::Array<TYPE>& _data;
	uint _curPos;
};


template<typename TYPE>
class ArrayFieldImportIterator : public ContainerField::ImportIterator
{
public:
	ArrayFieldImportIterator( void* mem )
		: _data( *((hive::Array<TYPE>*)mem) )
		, _typeIsPointer( ( hive::IsPointer<TYPE>::Val != 0 ) )
	{}

	void AddItem( void* value )
	{
		AddItem( value, Int2Type<hive::IsPointer<TYPE>::Val>() );
	}

	void AddItem( void*, void* )
	{
		throw StringT( _T("void ArrayFieldImportIterator::AddItem( void* key, void* value ) is invalid.") );
	}

	void* AddEmptyItem()
	{	
		if( _typeIsPointer == HV_TRUE )
		{
			throw StringT( _T("void ArrayFieldImportIterator::AddEmptyItem() can't be applied for pointer type .") );	
		}

		_data.PushBack( TYPE() );
		return _data.Back();
	}

	void* AddEmptyItem( void* )
	{
		throw StringT( _T("void ArrayFieldImportIterator::AddEmptyItem( void* key ) is invalid.") );
	}


	void operator=( const ArrayFieldImportIterator<TYPE>& other )
	{
		_data = other._data;
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


	hive::Array<TYPE>& _data;
	bool _typeIsPointer;
};


template<typename TYPE>
class ArrayField : public ContainerField
{
public:

	ArrayField() 
		: ContainerField( nullptr
						, 0
						, &GetTypeInfo<TYPE>()
						, IsPointer<TYPE>::Val
						, nullptr
						, SubTypeNameFunctorGenerator<TYPE>().Generate() )
	{}


	ContainerField::ExportIterator* CreateExportIterator( void* mem )
	{
		return new ArrayFieldExportIterator<TYPE>( mem );
	}

	ContainerField::ImportIterator* CreateImportIterator( void* mem )
	{
		return new ArrayFieldImportIterator<TYPE>( mem );
	}
};	
	

}// End of namespace hive