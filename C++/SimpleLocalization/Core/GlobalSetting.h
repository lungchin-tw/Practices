#pragma once


#include "Types.h"


namespace hive
{
	

class HV_Core_API GlobalSetting
{
public:
	enum
	{
		IS_EDITOR = 0x1,
		IS_FOR_WPF = 0x2,
		IS_EDIT_PARTICLE = 0x4,
		MASK = 0xFFFFFFFF,
	};


	static void EnableFlag( uint32 flag );
	static void DisableFlag( uint32 flag );
	static bool IsExistFlag( uint32 flag );
	

private:
	static uint32 _flags;
};





} // end of namespace hive