#pragma once


#include "TypeInfoAutomation.h"
#include "Types.h"


namespace hive // Begin of namespace hive 2nd section
{


enum ETypeFieldFlag
{
	SHOW_IN_EDITOR,
	ENABLE_WRITE,
	ENABLE_SERIALIZATION,

	DEFAULT = 0xFFFFFFFF,
	DISABLE_SERIALIZATION = DEFAULT ^ ENABLE_SERIALIZATION,
};


enum EStaticTypeInfoStatus
{
	TYPE_INFO_INITIALIZED = 0x00000001,
	TYPE_INFO_FIELDS_SETTED = 0x00000002,
	TYPE_INFO_INHERITE_SETTED = 0x00000004,
};


class TypeInfo;
class StringA;
class StringW;
class ContainerField;
class InstanceFieldIterator;
class Identifier;


typedef void (*TConstructorFunc)( void* mem );
typedef void (*TDestructorFunc)( void* mem );
typedef Identifier* (*TIdentifierGetter)( void* mem );


template<typename TYPE> void Constructor( void* mem );
template<typename TYPE> void Destructor( void* mem );
template<typename TYPE> Identifier* IdentifierGetter( void* mem );


template<typename TYPE>
struct IsPointer
{
	enum { Val = 0 };
};

template<typename TYPE>
struct IsPointer<TYPE*>
{
	enum { Val = 1 };
};


template<typename TYPE>
struct StripPointer
{
	typedef TYPE Type;
};

template<typename TYPE>
struct StripPointer<TYPE*>
{
	typedef TYPE Type;
};


typedef const StringT& (*TGetSubTypeNameFunctor)( void* mem );


class HV_Core_API TypeField final
{
public:	

	template<typename CLASS, typename TYPE> TypeField( const StringT& name, TYPE (CLASS::*field), ETypeFieldFlag flag, const StringT& group = StringT() );
	template<typename CLASS, typename TYPE, int LENGTH> TypeField( const StringT& name, TYPE (CLASS::*field)[LENGTH], ETypeFieldFlag flag, const StringT& group = StringT() );
	template<typename CLASS, typename TYPE> TypeField( const StringT& name, Vector2D<TYPE> (CLASS::*field), ETypeFieldFlag flag, const StringT& group = StringT() );
	template<typename CLASS, typename TYPE> TypeField( const StringT& name, Vector3D<TYPE> (CLASS::*field), ETypeFieldFlag flag, const StringT& group = StringT() );
	template<typename CLASS, typename TYPE> TypeField( const StringT& name, Vector4D<TYPE> (CLASS::*field), ETypeFieldFlag flag, const StringT& group = StringT() );
	template<typename CLASS, typename TYPE> TypeField( const StringT& name, Quaternion<TYPE> (CLASS::*field), ETypeFieldFlag flag, const StringT& group = StringT() );
	template<typename CLASS, typename TYPE> TypeField( const StringT& name, Matrix3x3<TYPE> (CLASS::*field), ETypeFieldFlag flag, const StringT& group = StringT() );
	template<typename CLASS, typename TYPE> TypeField( const StringT& name, Matrix4x4<TYPE> (CLASS::*field), ETypeFieldFlag flag, const StringT& group = StringT() );
	template<typename CLASS, typename TYPE> TypeField( const StringT& name, Array<TYPE> (CLASS::*field), ETypeFieldFlag flag, const StringT& group = StringT() );
	template<typename CLASS, typename TYPE> TypeField( const StringT& name, List<TYPE> (CLASS::*field), ETypeFieldFlag flag, const StringT& group = StringT() );
	template<typename CLASS, typename Key, typename Value> TypeField( const StringT& name, Map<Key, Value> (CLASS::*field), ETypeFieldFlag flag, const StringT& group = StringT() );
	
	TypeField& operator=( const TypeField& other );

	const StringT& GetClassName() const { return _className; }
	const StringT& GetName() const { return _name; }
	hive::uint32 GetOffset() const { return _offset; }
	bool IsPointer() const { return _isPointer; }
	bool HasFlag( ETypeFieldFlag flag ) { return ( ( _flag & flag ) == flag );  }
	TypeInfo& GetTypeInfo() const { return _typeInfo; }
	const StringT& GetSubTypeName( void* mem ) const;
	ContainerField* GetContainer() const { return _contanerFieldPtr; }

private:

	StringT _name;
	const StringT& _className;
	StringT _group;
	TypeInfo& _typeInfo;
	hive::uint32 _offset;
	ContainerField* _contanerFieldPtr;
	TGetSubTypeNameFunctor _getSubTypeNameFunctor;

	uint8 _isPointer : 1;
	ETypeFieldFlag _flag;
};


class HV_Core_API TypeInfo final : public IVisitable<TypeField>//, NextIDGenerator<size_t>
{
public:
	typedef Map<StringT, TypeField*> TTypeFieldPtrMap;
	typedef TTypeFieldPtrMap::Iterator TTypeFieldPtrIterator;

	typedef Array<TypeField*> TTypeFieldPtrArray;

	
	TypeInfo( const StringT& name
			, bool is_native_type
			, size_t size
			, TConstructorFunc cf
			, TDestructorFunc df
			, TIdentifierGetter ig );

	~TypeInfo();

	TypeInfo& operator=( const TypeInfo& other );

	void ConstructObject( void* mem );
	void DestructObject( void* mem );
	Identifier* GetIdentifier( void* mem );

	const StringT& GetName() const { return _name; }
	bool IsNativeType() const { return _isNativeType; }
	void EnableAutoRegisterInstance() { _autoRegisterInstance = HV_TRUE; }
	bool AutoRegisterInstance() const { return _autoRegisterInstance; }
	size_t GetSize() const { return _size; }
	bool HasFields() const { return ( _fields.Size() > 0 ); }
	bool IsA( TypeInfo& other );
	
	TypeInfo& Inherit( TypeInfo& base );

	template<size_t N> TypeInfo& SetTypeFields( TypeField (&fields)[N] );
	IVisitor<TypeField>::ReturnType Accept( IVisitor<TypeField>& visitor );

private:

	TypeInfo(){}


	StringT _name;
	bool _isNativeType;
	bool _autoRegisterInstance;
	size_t  _size;
	TConstructorFunc _constructor;
	TDestructorFunc _destructor;
	TIdentifierGetter _identifierGetter;
	TypeInfo* _superTypeInfo;
	TTypeFieldPtrMap _fields;
	TTypeFieldPtrArray _orderedFields;
};


template< typename TYPE > TypeInfo& GetTypeInfo();
template< typename TYPE, int LENGTH > TypeInfo& GetTypeInfo();

/*
* specialized template GetTypeInfo() for native TypeInfos
*/
template<> HV_Core_API TypeInfo& GetTypeInfo<bool>();
template<> HV_Core_API TypeInfo& GetTypeInfo<wchar_t>();
template<> HV_Core_API TypeInfo& GetTypeInfo<unsigned char>();
template<> HV_Core_API TypeInfo& GetTypeInfo<char>();
template<> HV_Core_API TypeInfo& GetTypeInfo<short>();
template<> HV_Core_API TypeInfo& GetTypeInfo<unsigned short>();
template<> HV_Core_API TypeInfo& GetTypeInfo<int>();
template<> HV_Core_API TypeInfo& GetTypeInfo<unsigned int>();
template<> HV_Core_API TypeInfo& GetTypeInfo<int64>();
template<> HV_Core_API TypeInfo& GetTypeInfo<uint64>();
template<> HV_Core_API TypeInfo& GetTypeInfo<long>();
template<> HV_Core_API TypeInfo& GetTypeInfo<unsigned long>();
template<> HV_Core_API TypeInfo& GetTypeInfo<float>();
template<> HV_Core_API TypeInfo& GetTypeInfo<double>();
template<> HV_Core_API TypeInfo& GetTypeInfo<StringT>();


template< typename TYPE > const StringT& GetTypeName();
template< typename TYPE, int LENGTH > const StringT& GetTypeName();

template<typename TYPE> TypeInfo& CreateTypeInfo( const StringT& name );


/*
* specialized template GetTypeInfo() for native TypeInfos
*/
template<> HV_Core_API const StringT& GetTypeName<bool>();
template<> HV_Core_API const StringT& GetTypeName<wchar_t>();
template<> HV_Core_API const StringT& GetTypeName<unsigned char>();
template<> HV_Core_API const StringT& GetTypeName<char>();
template<> HV_Core_API const StringT& GetTypeName<short>();
template<> HV_Core_API const StringT& GetTypeName<unsigned short>();
template<> HV_Core_API const StringT& GetTypeName<int>();
template<> HV_Core_API const StringT& GetTypeName<unsigned int>();
template<> HV_Core_API const StringT& GetTypeName<int64>();
template<> HV_Core_API const StringT& GetTypeName<uint64>();
template<> HV_Core_API const StringT& GetTypeName<long>();
template<> HV_Core_API const StringT& GetTypeName<unsigned long>();
template<> HV_Core_API const StringT& GetTypeName<float>();
template<> HV_Core_API const StringT& GetTypeName<double>();
template<> HV_Core_API const StringT& GetTypeName<StringT>();


}// End of namespace hive



#include "TypeInfo.inl"
