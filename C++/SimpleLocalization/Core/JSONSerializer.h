#pragma once


#include "Utility.h"
#include "TypeInfo.h"
#include "SharedInstanceCollection.h"
#include "TypeSerializer.h"


namespace json_exporter
{
	HV_Core_API void ExportClassToNode( hive::IJsonNode& node, const StringT& type_name, void* mem );
}

namespace json_importer
{
	HV_Core_API void* CreateInstanceFromNode( IJsonNode& node, TypeInfo& base_type );
	HV_Core_API bool ImportIdentifier( IJsonNode& class_node, Identifier& identifier );
}


namespace hive
{


const StringT g_TypeNameToken( _T( "Type" ) );
const StringT g_IdentifierToken( _T( "Identifier" ) );
const StringT g_IdentifierUNameToken( _T( "UName" ) );
const StringT g_IdentifierUIDToken( _T( "UID" ) );
const StringT g_IdentifierAliasToken( _T( "Alias" ) );
const StringT g_IdentifierUUIDToken( _T( "UUID" ) );
const StringT g_SharedInstanceToken( _T( "SharedInstance" ) );
const StringT g_MapKeyToken( _T( "Key" ) );
const StringT g_MapValueToken( _T( "Value" ) );


class HV_Core_API JSONFieldIterator : public InstanceFieldIterator
{
public:
	typedef Array<IJsonNode*> TNodeArray;

	JSONFieldIterator( IJsonNode* node );
	virtual ~JSONFieldIterator(){};

	virtual void Visit( TypeField& tf );

protected:
	void PushNode( IJsonNode* node );
	void PopNode();

	IJsonNode* _curNode;
	TNodeArray _nodeStack;
};

	
class HV_Core_API JSONFieldExporter : public JSONFieldIterator
{
public:

	typedef void (*TAttributeFunctor)( IJsonNode* node, const StringT& name, void* mem );
	typedef void (*TArrayFunctor)( IJsonNode* node, const StringT& name, ContainerField* container, void* mem );

	struct Functor
	{
		Functor( TAttributeFunctor attr_fun, TArrayFunctor array_func )
			: AttributeFunctor( attr_fun )
			, ArrayFunctor( array_func )
		{}

		TAttributeFunctor AttributeFunctor;
		TArrayFunctor ArrayFunctor;
	};
		
	typedef Map<StringT, JSONFieldExporter::Functor> TFunctorTable;


	template<typename TYPE>
	static void SaveAsFile( const StringT& file_name, TYPE* input, bool is_pretty )
	{
		IJsonLoader* loader = ConfigManagerGetInstance().CreateJsonConfig( file_name.CString() );

		SharedInstanceCollection::Instance().AddAddress( input );
		json_exporter::ExportClassToNode( *loader, input->GetClassName(), input );
			
		loader->SaveFile(is_pretty);
		ConfigManagerGetInstance().Release( file_name.CString() );
	}
		

	JSONFieldExporter( IJsonNode* node );


protected:
	virtual void VisitNativeType( TypeField& );
	virtual void VisitContainerType( TypeField& );
	virtual void VisitClassType( TypeField& );

private:
	static TFunctorTable _functorTable;
	static bool _staticInitialized;
	static void StaticInitialization();

	void ExportClassPointerToNode( IJsonNode& node, const StringT& sub_type_name, void* mem );
	void ExportArrayContainer( TypeField& tf, char* attr_ptr);
	void ExportMapContainer( TypeField& tf, char* attr_ptr );
	void ExportContainerClassValueToNode( IJsonNode& node, bool is_pointer, const StringT& sub_type_name, void* mem );
};


class HV_Core_API JSONFieldImporter : public JSONFieldIterator
{
public:

	typedef bool (*TAttributeFunctor)( IJsonNode* node, const StringT& name, void* mem );
	typedef void (*TArrayFunctor)( IJsonNode* node, const StringT& name, ContainerField* container, void* mem );
	typedef void* (*TAttributCreator)();
	typedef void (*TAttributDestructor)( void* );
		
	struct Functor
	{
		Functor( TAttributeFunctor attr_fun, TArrayFunctor array_func, TAttributCreator attr_creator, TAttributDestructor attr_destructor )
			: AttributeFunctor( attr_fun )
			, ArrayFunctor( array_func )
			, AttributCreator( attr_creator )
			, AttributDestructor( attr_destructor )
		{}

		TAttributeFunctor AttributeFunctor;
		TArrayFunctor ArrayFunctor;
		TAttributCreator AttributCreator;
		TAttributDestructor AttributDestructor;

	};
		
	typedef Map<StringT, JSONFieldImporter::Functor> TFunctorTable;


	template<typename TYPE>
	static TYPE* LoadFromeFile( const StringT& file_name )
	{
		IJsonNode* node = ConfigManagerGetInstance().LoadJsonConfig( file_name.CString() );
		if( node == nullptr )
		{
			throw file_name + StringT( _T( " is not exist!" ) );
		}

		void* mem = json_importer::CreateInstanceFromNode( *node, GetTypeInfo<TYPE>() );

		if( mem == nullptr )
		{
			ConfigManagerGetInstance().Release( file_name.CString() );
			throw hive::g_TypeNameToken + StringT( _T( "field is not exist!" ) );
		}

		ConfigManagerGetInstance().Release( file_name.CString() );

		return (TYPE*)mem;
	}

	JSONFieldImporter( IJsonNode* node );

protected:
	virtual void VisitNativeType( TypeField& );
	virtual void VisitContainerType( TypeField& );
	virtual void VisitClassType( TypeField& );

private:
	static TFunctorTable _functorTable;
	static bool _staticInitialized;
	static void StaticInitialization();

	void ImportArrayContainer( TypeField& tf, char* attr_ptr );
	void ImportMapContainer( TypeField& tf, char* attr_ptr );
};


} // end of namespace hive