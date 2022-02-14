#pragma once

using namespace hive;

/*
* Class Declaration Marcos
*/
#define HV_DECLARE_GET_CLASS_NAME()\
	virtual const StringT& GetClassName() const;\

#define HV_IMPLEMENT_GET_CLASS_NAME( TYPE )\
	const StringT& TYPE::GetClassName() const\
	{\
		return TYPE::ClassName();\
	}\


#define HV_DECLARE_GET_IDENTIFIER()\
	virtual Identifier* GetIdentifier() const;\

#define HV_IMPLEMENT_GET_IDENTIFIER( TYPE )\
	Identifier* TYPE::GetIdentifier() const\
	{\
		return hive::GetIdentifierByInstance<TYPE>( (void*)this );\
	}\


#define HV_ENABLE_AUTO_REGISTER_INSTANCE()\
	instance.EnableAutoRegisterInstance();\


#define HV_DECLARE_STATIC_CLASS_NAME()\
	static const StringT& ClassName();\

#define HV_IMPLEMENT_STATIC_CLASS_NAME( TYPE )\
	const StringT& TYPE::ClassName()\
	{\
		static StringT name( _T(#TYPE) );\
		return name;\
	}\


#define HV_INTERFACE_DECLARATION( TYPE )\
	public:\
		typedef TYPE ThisType;\
		HV_DECLARE_STATIC_CLASS_NAME()\
		static TypeInfo& StaticTypeInfo();\
		HV_DECLARE_GET_CLASS_NAME()\
		virtual void ForEachField( InstanceFieldIterator& iterator )=0;\

#define HV_DEFINE_SUPER( SUPER )\
		typedef SUPER Super;\

#define HV_INTERFACE_DECLARATION_INHERITED( TYPE, SUPER )\
	public:\
		HV_DEFINE_SUPER( SUPER )\
		HV_INTERFACE_DECLARATION( TYPE )\


#define HV_CLASS_DECLARATION( TYPE )\
	public:\
		typedef TYPE ThisType;\
		HV_DECLARE_STATIC_CLASS_NAME()\
		static TypeInfo& StaticTypeInfo();\
		HV_DECLARE_GET_CLASS_NAME()\
		HV_DECLARE_GET_IDENTIFIER()\
		virtual void ForEachField( InstanceFieldIterator& iterator );\


#define HV_DEFINE_SUPER( SUPER )\
	typedef SUPER Super;\


#define HV_CLASS_DECLARATION_INHERITED( TYPE, SUPER )\
	public:\
		HV_DEFINE_SUPER( SUPER )\
		HV_CLASS_DECLARATION( TYPE )\
		

#define HV_INTERFACE_IMPLEMENTATION_BEGIN( TYPE )\
	HV_IMPLEMENT_STATIC_CLASS_NAME( TYPE )\
	HV_IMPLEMENT_GET_CLASS_NAME( TYPE )\
	TypeInfo& TYPE::StaticTypeInfo()\
	{\
		static int StaticTypeInfoStatus = 0;\
		static TypeInfo instance( TYPE::ClassName(), HV_FALSE, sizeof(TYPE), nullptr, nullptr, nullptr );\
		HV_TYPE_INFO_INITIALIZED()\


#define HV_INTERFACE_IMPLEMENTATION_BEGIN_INHERITED( TYPE )\
	HV_INTERFACE_IMPLEMENTATION_BEGIN( TYPE )\
		if( ( StaticTypeInfoStatus & TYPE_INFO_INHERITE_SETTED ) == 0 )\
		{\
			instance.Inherit( Super::StaticTypeInfo() );\
			StaticTypeInfoStatus |= TYPE_INFO_INHERITE_SETTED;\
		}\

/*
* Class Implementation Marcos
*/
#define HV_TEMPLATE_IMPLEMENTATION_BEGIN_1( TEMPLATE )\
	public:\
		typedef TEMPLATE<Type> ThisType;\
		static const StringT& ClassName()\
		{\
			static StringT name =  StringT( _T(#TEMPLATE) ) + StringT( _T( "<" ) ) + GetTypeName<Type>() + StringT( _T( ">" ) );\
			return name;\
		}\
		const StringT& GetClassName() const\
		{\
			return ThisType::ClassName();\
		}\
		static TypeInfo& StaticTypeInfo()\
		{\
			static int StaticTypeInfoStatus = 0;\
			static TypeInfo& instance = CreateTypeInfo< ThisType >( ThisType::ClassName() );\
			HV_TYPE_INFO_INITIALIZED()\


#define HV_CLASS_IMPLEMENTATION_BEGIN( TYPE )\
	void TYPE::ForEachField( InstanceFieldIterator& iterator )\
	{\
		iterator.SetDataBegin( (char*)this );\
		TYPE::StaticTypeInfo().Accept( iterator );\
	}\
	HV_IMPLEMENT_STATIC_CLASS_NAME( TYPE )\
	HV_IMPLEMENT_GET_CLASS_NAME( TYPE )\
	HV_IMPLEMENT_GET_IDENTIFIER( TYPE )\
	TypeInfo& TYPE::StaticTypeInfo()\
	{\
		static int StaticTypeInfoStatus = 0;\
		static TypeInfo& instance = CreateTypeInfo<TYPE>( TYPE::ClassName() );\
		HV_TYPE_INFO_INITIALIZED()\


#define HV_TYPE_INFO_INITIALIZED()\
	if( ( StaticTypeInfoStatus & TYPE_INFO_INITIALIZED ) != 0 )\
	{\
		return instance;\
	}\
	StaticTypeInfoStatus |= TYPE_INFO_INITIALIZED;\


#define HV_CLASS_IMPLEMENTATION_BEGIN_INHERITED( TYPE )\
	HV_CLASS_IMPLEMENTATION_BEGIN( TYPE )\
		if( ( StaticTypeInfoStatus & TYPE_INFO_INHERITE_SETTED ) == 0 )\
		{\
			instance.Inherit( Super::StaticTypeInfo() );\
			StaticTypeInfoStatus |= TYPE_INFO_INHERITE_SETTED;\
		}\


#define HV_TYPE_FIELD_BEGIN()\
	static TypeField fields[] =\
	{\


#define HV_ADD_TYPE_FIELD( FIELD_NAME, FLAG, GROUP )\
	TypeField( StringT( _T(#FIELD_NAME) ), &ThisType::FIELD_NAME, FLAG, StringT( _T(#GROUP) ) ),\


#define HV_TYPE_FIELD_END()\
	};\
	\
	if( ( StaticTypeInfoStatus & TYPE_INFO_FIELDS_SETTED ) == 0 )\
	{\
		instance.SetTypeFields( fields );\
		StaticTypeInfoStatus |= TYPE_INFO_FIELDS_SETTED;\
	}


#define HV_CLASS_IMPLEMENTATION_END()\
		return instance;\
	};


#define HV_INTERFACE_IMPLEMENTATION_END()  HV_CLASS_IMPLEMENTATION_END()




