#pragma once


#include "Map.h"
#include "Types.h"
#include "Memory.h"
#include "TypeInfo.h"


namespace hive
{


class HV_Core_API TypeDataBase
{
public:

	typedef Map<StringT, TypeInfo*> TTypeMap;
	typedef TTypeMap::Iterator TTypeMapIterator;

	
	template<typename TYPE>
	TypeInfo& GetTypeInfo()
	{
		TypeInfo& tif = hive::GetTypeInfo<TYPE>();
		RegisterType( tif );
		
		return tif;
	}

	void RegisterType( TypeInfo& type );

	TypeInfo* GetTypeByName( const StringT& name );

	void Clear();
	

private:

	TTypeMap _typeMap;
};


} // End of namespace hive

