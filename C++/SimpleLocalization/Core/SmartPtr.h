/**
*
* @file     SmartPtr.h
* @author   Chao-Chih Lin
* @version  1.0
*
* @section  LICENSE
*
* (C) 2009 XPEC Entertainment Inc. All rights reserved.
*
* @section	Description
*
*
*/
#ifndef HIVE_SMART_PTR_H
#define HIVE_SMART_PTR_H

#include <algorithm>
#include <cassert>

namespace hive
{

	template <typename T>
	class RefCounted
	{
	public:

		RefCounted()
			: refCount_( HV_AllocNew( uintptr_t, uintptr_t ) )
		{
			(*refCount_) = 1;
		}

		RefCounted(const RefCounted& rhs)
			: refCount_(rhs.refCount_)
		{
			(*refCount_)++;
		}

		bool release()
		{
			if (!--*refCount_)
			{
				HV_DeallocDel( refCount_ );
				refCount_ = 0;
				return true;
			}

			return false;
		}

		void swap(RefCounted& rhs)
		{
			std::swap(refCount_, rhs.refCount_);
		}

	protected:

		// why this deconstructor should be declared in protected scope?
		// check Modern C++ design: Policy class deconstructor
		~RefCounted()
		{
			// refCount_ should be deleted automatically by release function
		}

	private:
		uintptr_t* refCount_;
	};

	template
	<
		typename T,
		template <class> class OwnerShipPolicy
	>
	class SmartPtr
		: OwnerShipPolicy<T>
	{
		typedef OwnerShipPolicy<T> OP;

	public:

		SmartPtr()
			: pointee_(0)
		{
		}

		SmartPtr(T* p)
			: pointee_(p)
		{
		}

		SmartPtr(const SmartPtr& rhs)
			: OP(rhs)
			, pointee_(rhs.pointee_)
		{
		}

		template
		<
			typename Y,
			template <class> class OwnerShipPolicy
		>
		SmartPtr(const SmartPtr<Y, OwnerShipPolicy>& rhs)
			: OP(rhs)
			, pointee_(rhs.pointee_)
		{
		}

		~SmartPtr()
		{
			if (OP::release())
			{
				// this is a workaround due to suck memory manage facility
				// why program got assertion fail when I delete a NULL ptr?
				if (pointee_)
				{
					HV_DeallocDel( pointee_ );
					pointee_ = NULL;
				}
			}
		}

		SmartPtr& operator = (const SmartPtr& rhs)
		{
			SmartPtr temp(rhs);
			temp.swap(*this);
			return *this;
		}

		T* operator->()
		{
			return pointee_;
		}

		bool valid() const
		{
			return pointee_!=0;
		}

		T* get()
		{
			return pointee_;
		}

		const T* operator->() const
		{
			return pointee_;
		}

		T& operator*()
		{
			return *pointee_;
		}

		const T& operator*() const
		{
			return *pointee_;
		}

		bool operator == (const SmartPtr& rhs) const
		{
			return pointee_ == rhs.pointee_;
		}

		bool operator != (const SmartPtr& rhs) const
		{
			return pointee_ != rhs.pointee_;
		}

	private:

		void swap(SmartPtr& rhs)
		{
			OP::swap(rhs);
			std::swap(pointee_,  rhs.pointee_);
		}

		T* pointee_;
	};

	/*
	template 
	<
		typename T,
		template <class> class OwnerShipPolicy
	>
	class WeakPtr
		: public SmartPtr<T, OwnerShipPolicy>
	{
	public:

		WeakPtr(const );

		bool valid();
	};
	*/
}   // End of namespace hive


#endif // End of HIVE_SMART_PTR_H