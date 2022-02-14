#pragma once


#include "Utility.h"


namespace hive
{
	

class HV_Core_API InstanceFieldIterator : public IVisitor<TypeField>
{
public:
	InstanceFieldIterator();

	void SetDataBegin( char* mem );
	virtual IVisitor<TypeField>::ReturnType Visit( TypeField& tf );

protected:
	
	virtual void VisitNativeType( TypeField& )=0;
	virtual void VisitContainerType( TypeField& )=0;
	virtual void VisitClassType( TypeField& )=0;

	char* _object;
};

	
} // end of namespace hive
