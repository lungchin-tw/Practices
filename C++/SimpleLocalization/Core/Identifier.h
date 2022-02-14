#pragma once


#include "Types.h"
#include "TypeInfo.h"
#include "UUID.h"


namespace hive
{
	class HV_Core_API Identifier final
	{
	public:

		static Identifier* Create();
		static Identifier& GetEmptyIdentifier();
		
		void Initialize( const Identifier& other );
		void Initialize( const StringT& name, size_t id );
		void Initialize( const HvUUID& uuid );
		void Initialize( const StringT& uuid_str );
		void AutoInitialize();
		
		const StringT& GetUName() const;
		size_t GetUID() const;
		const HvUUID& GetUUID() const;
		bool IsInitialized() const;

		const StringT& GetAlias() const;
		void SetAlias( const StringT& );

	private:

		static hive::Array<class Identifier*> _instanceArray;
		static bool _IsDestructing;

		Identifier();
		Identifier( Identifier& other );

		void Clear();

		~Identifier();

		StringT _UName;
		StringT _alias;
		size_t _UID;
		HvUUID _UUID;
	};

}// End of namespace hive
