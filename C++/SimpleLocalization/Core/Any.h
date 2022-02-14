
/**
*
* @file     Any.h
* @author   Ellison Mu
* @version  1.0
*
* @section  LICENSE
*
* (C) 2010 XPEC Entertainment Inc. All rights reserved.
*
* @section	Description
*
* Provide a method to distinguish generic type.
*
*/

#ifndef HIVE_ANY_H
#define HIVE_ANY_H

namespace hive
{

class HV_Core_API Any
{

public:	
	//--------------------------------------------------------------------------
	/// @brief Constructor
	//--------------------------------------------------------------------------
	Any() 
		: content(0)
	{

	}

	//--------------------------------------------------------------------------
	/// @brief Destructor
	//--------------------------------------------------------------------------
	~Any()  
	{
		if ( content )
			HV_DeallocDel( content );
	}

	//--------------------------------------------------------------------------
	/// @brief Constructor
	/// 
	/// @param [in] value Assign Value 
	//--------------------------------------------------------------------------
	template <typename Type>
	Any(  const Type& value )
		: content( HV_AllocNew( Holder<Type>, Holder<Type>(value) ) )
	{

	}
	
	//--------------------------------------------------------------------------
	/// @brief Constructor
	/// 
	/// @param [in] value Assign Value 
	//--------------------------------------------------------------------------
	Any(  const Any& other )
		: content(other.content ? other.content->clone() : 0)
	{

	}

public: // modifiers
	//--------------------------------------------------------------------------
	/// @brief swap item
	/// 
	/// @param [in] rhs Item to swap from 
	/// 
	/// @return Swapped item 
	//--------------------------------------------------------------------------
	Any& swap(  Any& rhs )
	{
		_SWAP(content, rhs.content);		
		return *this;
	}

	//--------------------------------------------------------------------------------------
	/// @brief Copy operator
	///
	/// @param [in] rhs Item to copy from
	///
	/// @return Self
	//--------------------------------------------------------------------------------------
	template<typename Type>
	Any& operator = (  const Type& rhs )
	{
		Any(rhs).swap(*this);
		return *this;
	}

	//--------------------------------------------------------------------------------------
	/// @brief Copy operator
	///
	/// @param [in] rhs Item to copy from
	///
	/// @return Self
	//--------------------------------------------------------------------------------------
	Any& operator = (  Any rhs )
	{
		rhs.swap(*this);
		return *this;
	}

public: // queries
	//--------------------------------------------------------------------------------------
	/// @brief Check if empty
	///
	/// @return True is empty, false if not empty
	//--------------------------------------------------------------------------------------
	bool	empty() const
	{
		return !content;
	}

	//--------------------------------------------------------------------------------------
	/// @brief Get type info
	///
	/// @return Type info
	//--------------------------------------------------------------------------------------
	const type_info& type() const					
	{
		//return content ? content->type() : typeid( void );
		return content->type();		// for support Emscripten
	}


private:
	template<typename Type> 
	HV_INLINE void _SWAP( Type& _Left, Type& _Right )
	{	// exchange values stored at _Left and _Right
		if ( &_Left != &_Right )
		{	// different, worth swapping
			Type _Tmp = _Left;

			_Left = _Right;
			_Right = _Tmp;
		}
	}

private:
	class Placeholder
	{
	public:
		//--------------------------------------------------------------------------
		virtual	~Placeholder() {}

		//--------------------------------------------------------------------------
		virtual const type_info& type() const = 0;

		//--------------------------------------------------------------------------
		virtual Placeholder* clone() const = 0;
	};

	template <typename Type>
	class Holder : public Placeholder
	{
	public:
		Type held;

		//--------------------------------------------------------------------------
		Holder(  const Type& value ) : held( value ) {}

		//--------------------------------------------------------------------------
		virtual const type_info& type() const
		{
			return typeid( Type );
		}

		//--------------------------------------------------------------------------
		virtual Placeholder* clone() const
		{
			return HV_AllocNew( Holder, Holder(held) );
		}
	private:
		 Holder & operator = (  const Holder& );
	};

	public:
		Placeholder*	content;

	private:
		//--------------------------------------------------------------------------
		template<typename Type>
		friend Type* any_cast(  Any* );

		//--------------------------------------------------------------------------
		template<typename Type>
		friend Type* unsafe_any_cast(  Any* );
};

//--------------------------------------------------------------------------
template<typename Type>
Type * any_cast(  Any* operand )
{
	return operand && operand->type() == typeid( Type )
		? &static_cast<Any::Holder<Type> *>(operand->content)->held
		: 0;
} // End of any_cast

//--------------------------------------------------------------------------
template<typename Type>
HV_INLINE const Type * any_cast(  const Any* operand )
{
	return any_cast<Type>( const_cast<Any*> (operand) );
} // End of any_cast

//--------------------------------------------------------------------------
template<typename Type>
Type any_cast(  Any & operand )
{
	const Type* result = any_cast<Type>( &operand );

	if ( !result )
	{
		WinOutput( "HE_ERROR, Any any_cast failed" );
		ASSERT(0);
	}
	return *result;
} // End of any_cast

//--------------------------------------------------------------------------
template<typename Type>
Type any_cast(  const Any & operand )
{
	 const Type* result = any_cast<Type>( &operand );

	 if ( !result )  
	 {
		WinOutput( "HE_ERROR, Any any_cast failed" );
		ASSERT(0);
	 }
	 return *result;
} // End of any_cast

//--------------------------------------------------------------------------
template<typename Type>
HV_INLINE Type* unsafe_any_cast(  Any* operand )
{
	return &static_cast<Any::Holder<Type> *>(operand->content)->held;
} // End of unsafe_any_cast

//--------------------------------------------------------------------------
template<typename Type>
HV_INLINE const Type* unsafe_any_cast(  const Any* operand )
{
	return unsafe_any_cast<Type>( const_cast<Any*> (operand) );
} // End of unsafe_any_cast

} // End of namespace hive

#endif	// End of HIVE_ANY_H