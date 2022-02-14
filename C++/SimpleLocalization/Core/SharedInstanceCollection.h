#pragma once


#include "Core.h"
#include "Utility.h"


namespace hive
{


class HV_Core_API SharedInstanceCollection final : private UnCopyable
{
public:

	static SharedInstanceCollection& Instance();

	void Begin();
	void End();

	void AddAddress( void* mem );
	void MakeAddressPair( void* old_mem, void* new_mem );
	void* FindNewAddress( void* old_mem );
	bool HasOldAddress( void* mem );
	void AddUnresolvedAddress( size_t address, size_t* address_ptr );

	bool IsValid() const { return isValid; }

protected:

	Map<size_t, size_t> _addressTable;
	Map<size_t, Array<size_t*> > _unresolvedAddressTable;

private:
	SharedInstanceCollection();
	~SharedInstanceCollection();

	bool isValid;
};


} // end of namespace hive


