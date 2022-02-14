#pragma once


namespace hive
{

class TypeInfo;


	class HV_Core_API ContainerField
	{
	public:

		class ExportIterator
		{
		public:
			virtual ~ExportIterator(){}
			virtual void* GetKey() const = 0;
			virtual void* GetValue() const = 0;
			virtual void MoveNext() = 0;
			virtual bool IsEnd() = 0;
		};

		class ImportIterator
		{
		public:
			virtual ~ImportIterator(){}
			virtual void AddItem( void* value ) = 0;
			virtual void AddItem( void* key, void* value ) = 0;
			virtual void* AddEmptyItem() = 0;
			virtual void* AddEmptyItem( void* key ) = 0;
		};
		
		ContainerField( TypeInfo* key_type_info
						, bool key_is_pointer
						, TypeInfo* value_type_info
						, bool value_is_pointer
						, TGetSubTypeNameFunctor key_sub_type_name_functor
						, TGetSubTypeNameFunctor value_sub_type_name_functor )
			: _keyTypeInfo( key_type_info )
			, _keyIsPointer( key_is_pointer )
			, _valueTypeInfo( value_type_info )
			, _valueIsPointer( value_is_pointer )
			, _getKeySubTypeNameFunctor( key_sub_type_name_functor )
			, _getValueSubTypeNameFunctor( value_sub_type_name_functor )
		{}

		virtual ~ContainerField(){}

		virtual ContainerField::ExportIterator* CreateExportIterator( void* mem ) = 0;
		virtual ContainerField::ImportIterator* CreateImportIterator( void* mem ) = 0;

		TypeInfo* GetKeyTypeInfoPtr() const { return _keyTypeInfo; }
		TypeInfo* GetValueTypeInfoPtr() const { return _valueTypeInfo; }
		bool KeyIsPointer() const { return _keyIsPointer; }
		bool ValueIsPointer() const { return _valueIsPointer; }

		const StringT& GetKeySubTypeName( void* mem ) const
		{
			return ( _getKeySubTypeNameFunctor == nullptr ) ? GetKeyTypeInfoPtr()->GetName() : _getKeySubTypeNameFunctor( mem );
		}

		const StringT& GetValueSubTypeName( void* mem ) const
		{
			return ( _getValueSubTypeNameFunctor == nullptr ) ? GetValueTypeInfoPtr()->GetName() : _getValueSubTypeNameFunctor( mem );
		}

	protected:
		TypeInfo* _keyTypeInfo;
		TypeInfo* _valueTypeInfo;

		uint8 _keyIsPointer : 1;
		uint8 _valueIsPointer : 1;

		TGetSubTypeNameFunctor _getKeySubTypeNameFunctor;
		TGetSubTypeNameFunctor _getValueSubTypeNameFunctor;
	};

}// End of namespace hive