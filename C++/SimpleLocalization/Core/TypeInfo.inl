

#define HV_AUTO_GENERATE_TYPE_FIELD_CONSTRUCTOR_1( TEMPLATE )\
	template<typename CLASS, typename TYPE>\
	TypeField::TypeField( const StringT& name, TEMPLATE<TYPE> (CLASS::*field), ETypeFieldFlag flag, const StringT& group )\
		: _name( name )\
		, _className( CLASS::ClassName() )\
		, _group( group )\
		, _offset( (int)(&(((CLASS*)0)->*field) ) )\
		, _isPointer( false )\
		, _typeInfo( hive::GetTypeInfo< TEMPLATE<TYPE> >() )\
		, _contanerFieldPtr( nullptr )\
		, _getSubTypeNameFunctor( nullptr )\
		, _flag( flag )\
	{}\


#define HV_AUTO_GENERATE_IS_NATIVE_TYPE( TYPE )\
	template<> struct IsNativeType<TYPE>\
	{\
		enum { Val = 1 };\
	};\



#include "ContainerField.h"
#include "FixedArrayField.h"
#include "ArrayField.h"
#include "ListField.h"
#include "MapField.h"


namespace hive // Begin of namespace hive 2nd section
{

template<typename TYPE>
struct IsNativeType
{
	enum { Val = 0 };
};

/*
* specialized template struct IsNativeType
*/
HV_AUTO_GENERATE_IS_NATIVE_TYPE(bool)
HV_AUTO_GENERATE_IS_NATIVE_TYPE(wchar_t)
HV_AUTO_GENERATE_IS_NATIVE_TYPE(unsigned char)
HV_AUTO_GENERATE_IS_NATIVE_TYPE(char)
HV_AUTO_GENERATE_IS_NATIVE_TYPE(short)
HV_AUTO_GENERATE_IS_NATIVE_TYPE(unsigned short)
HV_AUTO_GENERATE_IS_NATIVE_TYPE(int)
HV_AUTO_GENERATE_IS_NATIVE_TYPE(unsigned int)
HV_AUTO_GENERATE_IS_NATIVE_TYPE(int64)
HV_AUTO_GENERATE_IS_NATIVE_TYPE(uint64)
HV_AUTO_GENERATE_IS_NATIVE_TYPE(long)
HV_AUTO_GENERATE_IS_NATIVE_TYPE(unsigned long)
HV_AUTO_GENERATE_IS_NATIVE_TYPE(float)
HV_AUTO_GENERATE_IS_NATIVE_TYPE(double)
HV_AUTO_GENERATE_IS_NATIVE_TYPE(StringT)

/*
* Constructor Function Template
*/
template<typename TYPE>
void Constructor( void* mem )
{
	new (mem) TYPE;
}

/*
* Destructor Function Template
*/
template<typename TYPE>
void Destructor( void* mem )
{
	((TYPE*)mem)->TYPE::~TYPE();
}


template<typename TYPE >
const StringT& GetSubTypeName( void* mem )
{
	return ((TYPE*)mem)->GetClassName();
}

template<typename TYPE> 
Identifier* IdentifierGetter( void* mem )
{
	return hive::GetIdentifierByInstance<TYPE>( mem );
}


template<typename TYPE>
class SubTypeNameFunctorGenerator
{
public:
	
	TGetSubTypeNameFunctor Generate()
	{
		return Generate( Int2Type<hive::IsPointer<TYPE>::Val>() );
	}

private:

	TGetSubTypeNameFunctor Generate( Int2Type<true> )
	{
		return GetSubTypeName< hive::StripPointer<TYPE>::Type >;
	}

	TGetSubTypeNameFunctor Generate( Int2Type<false> )
	{
		return nullptr;
	}
};


/*
* TypeField Template Constructors
*/
template<typename CLASS, typename TYPE>
TypeField::TypeField( const StringT& name, TYPE (CLASS::*field), ETypeFieldFlag flag, const StringT& group )
	: _name( name )
	, _className( CLASS::ClassName() )
	, _group( group )
	, _offset( (int)(&(((CLASS*)0)->*field) ) )
	, _isPointer( hive::IsPointer<TYPE>::Val )
	, _typeInfo( hive::GetTypeInfo<TYPE>() )
	, _contanerFieldPtr( nullptr )
	, _getSubTypeNameFunctor( SubTypeNameFunctorGenerator<TYPE>().Generate() )
	, _flag( flag )
{}

template<typename CLASS, typename TYPE, int LENGTH> 
TypeField::TypeField( const StringT& name, TYPE (CLASS::*field)[LENGTH], ETypeFieldFlag flag, const StringT& group )
	: _name( name )
	, _className( CLASS::ClassName() )
	, _group( group )
	, _offset( (int)(&(((CLASS*)0)->*field) ) )
	, _isPointer( false )
	, _typeInfo( hive::GetTypeInfo<TYPE, LENGTH>() )
	, _contanerFieldPtr( new FixedArrayField<TYPE, LENGTH>() )
	, _getSubTypeNameFunctor( nullptr )
	, _flag( flag )
{}

HV_AUTO_GENERATE_TYPE_FIELD_CONSTRUCTOR_1(Vector2D)
HV_AUTO_GENERATE_TYPE_FIELD_CONSTRUCTOR_1(Vector3D)
HV_AUTO_GENERATE_TYPE_FIELD_CONSTRUCTOR_1(Vector4D)
HV_AUTO_GENERATE_TYPE_FIELD_CONSTRUCTOR_1(Quaternion)
HV_AUTO_GENERATE_TYPE_FIELD_CONSTRUCTOR_1(Matrix3x3)
HV_AUTO_GENERATE_TYPE_FIELD_CONSTRUCTOR_1(Matrix4x4)

template<typename CLASS, typename TYPE>
TypeField::TypeField( const StringT& name, Array<TYPE> (CLASS::*field), ETypeFieldFlag flag, const StringT& group )
	: _name( name )
	, _className( CLASS::ClassName() )
	, _group( group )
	, _offset( (int)(&(((CLASS*)0)->*field) ) )
	, _isPointer( false )
	, _typeInfo( hive::GetTypeInfo< Array<TYPE> >() )
	, _contanerFieldPtr( new ArrayField<TYPE>() )
	, _getSubTypeNameFunctor( nullptr )
	, _flag( flag )
{}

template<typename CLASS, typename TYPE>
TypeField::TypeField( const StringT& name, List<TYPE> (CLASS::*field), ETypeFieldFlag flag, const StringT& group )
	: _name( name )
	, _className( CLASS::ClassName() )
	, _offset( (int)(&(((CLASS*)0)->*field) ) )
	, _isPointer( false )
	, _typeInfo( hive::GetTypeInfo< List<TYPE> >() )
	, _contanerFieldPtr( new ListField<TYPE>() )
	, _getSubTypeNameFunctor( nullptr )
	, _flag( flag )
{}

template<typename CLASS, typename Key, typename Value>
TypeField::TypeField( const StringT& name, Map<Key, Value> (CLASS::*field), ETypeFieldFlag flag, const StringT& group )
	: _name( name )
	, _className( CLASS::ClassName() )
	, _offset( (int)(&(((CLASS*)0)->*field) ) )
	, _isPointer( false )
	, _typeInfo( hive::GetMapTypeInfo<Key, Value>() )
	, _contanerFieldPtr( new MapField<Key, Value>() )
	, _getSubTypeNameFunctor( nullptr )
	, _flag( flag )
{}


/*
* TypeInfo's template methods
*/
template<size_t N>
TypeInfo& TypeInfo::SetTypeFields( TypeField (&fields)[N] )
{
	_fields.RemoveAll();

	for( int i=0; i<N; i++ )
	{
		_fields.Insert( fields[i].GetName(), &(fields[i]) );
	}

	return *this;
}

template< typename TYPE >
TypeInfo& GetTypeInfo()
{
	return hive::StripPointer<TYPE>::Type::StaticTypeInfo();
}


template< typename TYPE >
const StringT& GetTypeName()
{
	static StringT name = ( hive::IsPointer<TYPE>::Val == 0 ) ? StripPointer<TYPE>::Type::ClassName() : StripPointer<TYPE>::Type::ClassName() + StringT( _T("*") );
	return name;
}



template<typename TYPE, int LENGTH>
const StringT& GetTypeName()
{	
	static tchar len_str[128];
	_itot_s( LENGTH, len_str, 10 );
	static StringT name = GetTypeName<TYPE>() + StringT( _T( "[" ) ) + StringT( len_str ) + StringT( _T( "]" ) );
	return name;
}

template<typename TYPE>
TypeInfo& CreateTypeInfo( const StringT& name )
{
	static TypeInfo instance( name, IsNativeType<TYPE>::Val, sizeof(TYPE), Constructor<TYPE>, Destructor<TYPE>, IdentifierGetter<TYPE> );
	return instance;
}

template<typename TYPE, int LENGTH>
TypeInfo& GetTypeInfo()
{	
	static TypeInfo instance( GetTypeName<TYPE, LENGTH>(), IsNativeType<TYPE[LENGTH]>::Val, sizeof(TYPE[LENGTH]), nullptr, nullptr, nullptr );
	return instance;
}


template< typename Key, typename Value >
TypeInfo& GetMapTypeInfo()
{	
	static TypeInfo instance( GetMapTypeName<Key, Value>(), IsNativeType< Map<Key, Value> >::Val, sizeof(Map<Key, Value>), nullptr, nullptr, nullptr );
	return instance;
}


template< typename Key, typename Value >
const StringT& GetMapTypeName()
{	
	static StringT name = StringT( _T( "Map<" ) ) + GetTypeName<Key>() + StringT( _T( ", " ) ) + GetTypeName<Value>() + StringT( _T( ">" ) );
	return name;
}


}// End of namespace hive

