#pragma once

#include "Types.h"


namespace hive
{
	class HV_Core_API HvUUID final
	{
	public:
		enum EConst
		{
			LENGTH = 16,
		};


		HvUUID();
		HvUUID( const HvUUID& other );
		HvUUID( const StringT& other );

		bool IsInitialized() const;

		void operator=( const HvUUID& rhs );
#ifdef _WIN32
		void operator=( const GUID& rhs );
#endif
		void operator=( const StringT& rhs );
		bool operator!=( const HvUUID& rhs ) const;
		bool operator==( const HvUUID& rhs ) const;
		const StringT& ToString() const;
		void Clear();

	private:
		bool IsValidString( const StringT& ) const;
		void FromCheckedMSGUID( const GUID& rhs );
		
		uint8 _data[ LENGTH ];
		bool _initialized;
		StringT _strData;

		friend HV_Core_API HvUUID* GenerateUUID();
	};


	HV_Core_API HvUUID* GenerateUUID();
} // end of namespace hive
