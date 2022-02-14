#pragma once

#include "ContainerField.h"


namespace hive
{

class TypeInfo;


template<typename TYPE, int LENGTH>
class FixedArrayFieldExportIterator : public ContainerField::ExportIterator
{
public:
	FixedArrayFieldExportIterator( void* mem )
		: _items( (TYPE*)mem )
		, _currentPos( 0 )
	{}

	void* GetKey() const { return nullptr; }
	void* GetValue() const { return &_items[ _currentPos ]; }
	void MoveNext()
	{
		_currentPos = IsEnd() ? _currentPos : ++_currentPos;
	}

	bool IsEnd()
	{
		return ( _currentPos >= LENGTH );
	}


private:
	int _currentPos;
	TYPE* _items;
};


template<typename TYPE, int LENGTH>
class FixedArrayFieldImportIterator : public ContainerField::ImportIterator
{
public:
	FixedArrayFieldImportIterator( void* mem )
		: _items( (TYPE*)mem )
		, _curPos( 0 )
		, _isPointerType( ( hive::IsPointer<TYPE>::Val != 0 ) )
	{}

	void AddItem( void* value )
	{	
		if( _curPos < LENGTH )
		{
			AddItem( value, Int2Type<hive::IsPointer<TYPE>::Val>() );
		}
	}

	void AddItem( void*, void* )
	{
		throw StringT( _T("void FixedArrayFieldImportIterator::AddItem( void* key, void* value ) is invalid.") );
	}

	void* AddEmptyItem()
	{
		if( _isPointerType )
		{
			throw StringT( _T("void FixedArrayFieldImportIterator::AddEmptyItem() can't be applied for pointer type .") );
		}

		if( _curPos < LENGTH )
		{
			return &_items[ _curPos++ ];
		}
		else
		{
			throw StringT( _T("void FixedArrayFieldImportIterator::AddEmptyItem() : Exceeded this array's length.") );
		}
	}

	void* AddEmptyItem( void* )
	{
		throw StringT( _T("void FixedArrayFieldImportIterator::AddEmptyItem( void* key ) is invalid.") );
	}

private:

	void AddItem( void* value, Int2Type<0> )
	{
		_items[ _curPos++ ] = *((TYPE*)value);
	}

	void AddItem( void* value, Int2Type<1> )
	{
		_items[ _curPos++ ] = (TYPE)value;
	}

	int _curPos;
	TYPE* _items;
	bool _isPointerType;
};


template<typename TYPE, int LENGTH>
class FixedArrayField : public ContainerField
{
public:

	FixedArrayField() 
		: ContainerField( nullptr
						, 0
						, &GetTypeInfo<TYPE>()
						, IsPointer<TYPE>::Val
						, nullptr
						, SubTypeNameFunctorGenerator<TYPE>().Generate() )
	{}

	ContainerField::ExportIterator* CreateExportIterator( void* mem )
	{
		return new FixedArrayFieldExportIterator<TYPE, LENGTH>( mem );
	}

	ContainerField::ImportIterator* CreateImportIterator( void* mem )
	{
		return new FixedArrayFieldImportIterator<TYPE, LENGTH>( mem );
	}
};	

}// End of namespace hive