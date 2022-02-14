/**
*
* @file     Array.h
* @author   Shawn Hsiao
* @version  1.0
*
* @section  LICENSE
*
* (C) 2009 XPEC Entertainment Inc. All rights reserved.
*
* @section	Description
*
* Automatically resized array template
*
*/

#ifndef HIVE_ARRAY_H
#define HIVE_ARRAY_H


#include "TypeInfoAutomation.h"


namespace hive
{

class TypeInfo;
class FieldExporter;
class FieldImporter;
class StringT;


template <class Type>
class Array
{
public:
	static const uint ARRAY_INIT_SIZE = 20;

	HV_TEMPLATE_IMPLEMENTATION_BEGIN_1( hive::Array )
	HV_CLASS_IMPLEMENTATION_END()

	//--------------------------------------------------------------------------------------
    /// @brief Constructor
    ///
    /// @param [in] iStartSize Initial elements to allocate        
    //--------------------------------------------------------------------------------------
    Array( uint iStartSize = ARRAY_INIT_SIZE );

    //--------------------------------------------------------------------------------------
    /// @brief Copy constructor
    ///
    /// @param [in] rhs Array to copy from
    //--------------------------------------------------------------------------------------
    Array( const Array& rhs );
    
    //--------------------------------------------------------------------------------------
    /// @brief Destructor        
    //--------------------------------------------------------------------------------------
    ~Array();

public:
    //--------------------------------------------------------------------------------------
    /// @brief This function is to simulate C-style array
    ///
    /// @return Pointer to the first element in array
    //--------------------------------------------------------------------------------------
    HV_INLINE operator       Type * ();

    //--------------------------------------------------------------------------------------
    /// @brief This function is to simulate C-style array
    ///
    /// @return Pointer to the first element in array
    //--------------------------------------------------------------------------------------
    HV_INLINE operator const Type * () const;
    
    //--------------------------------------------------------------------------------------
    /// @brief Access an array element, used like a normal C array, index must be within array's range
    ///
    /// @param [in] iIndex Index to element, start from zero
    /// 
    /// @return Reference to the element
    //--------------------------------------------------------------------------------------
    HV_INLINE Type&       operator[] ( uint iIndex );
	HV_INLINE Type&       operator() ( uint iIndex );

    //--------------------------------------------------------------------------------------
    /// @brief Access an array element, used like a normal C array, index must be within array's range
    ///
    /// @param [in] iIndex Index to element, start from zero
    /// 
    /// @return Reference to the element
    //--------------------------------------------------------------------------------------
	HV_INLINE const Type& operator() ( uint iIndex ) const;

    //--------------------------------------------------------------------------------------
    /// @brief Copy operator
    ///
    /// @param [in] rhs Array to copy from
    ///
    /// @return Reference to self
    //--------------------------------------------------------------------------------------
    Array<Type>& operator = (  const Array<Type>& rhs );

    //--------------------------------------------------------------------------------------
    /// @brief Access an array element
    ///
    /// @param [in] iIndex Index to element, start from zero
    /// 
    /// @return Pointer to the element, NULL if index is out of range
    //--------------------------------------------------------------------------------------
    HV_INLINE Type*       GetItem( uint iIndex );

    //--------------------------------------------------------------------------------------
    /// @brief Access an array element
    ///
    /// @param [in] iIndex Index to element, start from zero
    /// 
    /// @return Pointer to the element, NULL if index is out of range
    //--------------------------------------------------------------------------------------
    HV_INLINE const Type* GetItem(  uint iIndex ) const;

	//--------------------------------------------------------------------------------------
	/// @brief Find an array element, value should implemnet operator ==
	///
	/// @param [in] value
	/// 
	/// @return Pointer iIndex to the element, <0 if value not found
	/// added by steve 2010/8/20
	//--------------------------------------------------------------------------------------
	int32	Find ( Type &val) const;

    //--------------------------------------------------------------------------------------
    /// @brief Get number of elements stored        
    ///
    /// @return Number of elements stored
    //--------------------------------------------------------------------------------------
    HV_INLINE uint Size() const;

    //--------------------------------------------------------------------------------------
    /// @brief Get number of reserved elements, including elements stored and free elements
    ///
    /// @return Number of reserved elements
    //--------------------------------------------------------------------------------------
    HV_INLINE uint GetReservedSize() const;

    //--------------------------------------------------------------------------------------
    /// @brief Reserve elements, only work when the passed size is larger than current one
    /// 
    /// @param [in] iSize Number of elements to reserve
    /// 
    /// @return True on success
    //--------------------------------------------------------------------------------------
    bool Reserve( uint iSize );

    //--------------------------------------------------------------------------------------
    /// @brief Resize the array to the specified size ( number of elements stored ), so a Size()
    ///        call immediately after this will return the new size
    /// 
    /// @param [in] iSize Number of elements to resize        
    //--------------------------------------------------------------------------------------
    void Resize( uint iSize, bool bActualSize = HV_FALSE );

    //--------------------------------------------------------------------------------------
    /// @brief Resize the array to the specified size ( number of elements stored ), so a Size()
    ///        call immediately after this will return the new size
    /// 
    /// @param [in] iSize Number of elements to resize        
    /// 
    /// @param [in] padding If the new size specified is larger the current size, this is used to pad
    ///             elements newly created    
    //--------------------------------------------------------------------------------------
    void Resize( uint iSize, const  Type& padding, bool bActualSize = HV_FALSE );

    //--------------------------------------------------------------------------------------
    /// @brief Insert an element into array
    /// 
    /// @param [in] item Element to insert
    /// 
    /// @param [in] iIndex Index to insert, newly inserted element pushes the elements including
    ///                    the element originally on iIndex backward one position
    //--------------------------------------------------------------------------------------
    void Insert(  const Type& item, uint iIndex );

	//--------------------------------------------------------------------------------------
	/// @brief Swap two element
	//--------------------------------------------------------------------------------------
	void Swap( uint iIndex_1, uint iIndex_2 );

    //--------------------------------------------------------------------------------------
    /// @brief Add item at last position
    /// 
    /// @param [in] item Item to add
    //--------------------------------------------------------------------------------------
    void PushBack( const Type& item );

    //--------------------------------------------------------------------------------------
    /// @brief Add item at first position
    /// 
    /// @param [in] item Item to add
    //--------------------------------------------------------------------------------------
    void PushFront( const Type& item );

    //--------------------------------------------------------------------------------------
    /// @brief remove item at last position
    //--------------------------------------------------------------------------------------
    void PopBack();

	//--------------------------------------------------------------------------------------
	/// @brief Get the last item
	/// 
	/// @return Pointer to the element, NULL if index is out of range
	//--------------------------------------------------------------------------------------
	HV_INLINE Type* Back ();

	//--------------------------------------------------------------------------------------
	/// @brief Get the fist item
	/// 
	/// @return Pointer to the element, NULL if index is out of range
	//--------------------------------------------------------------------------------------
	HV_INLINE Type* Front ();

	HV_INLINE const Type* Front () const;

	//--------------------------------------------------------------------------------------
    /// @brief Remove a item at specified index
    /// 
    /// @param [in] iIndex Index to remove
    /// 
    /// @return True on success
    //--------------------------------------------------------------------------------------
    bool Remove(  uint iIndex );

    //--------------------------------------------------------------------------------------
    /// @brief Remove all items 
    //--------------------------------------------------------------------------------------
    void RemoveAll();

	//--------------------------------------------------------------------------------------
	/// @brief Check Array is empty or not
	//--------------------------------------------------------------------------------------
	bool Empty() const;

private:
    //--------------------------------------------------------------------------------------
    void GrowBuffer(  uint iSize = 0 );

    //--------------------------------------------------------------------------------------
    void Shift(  uint iIndex,  bool bLeft );

protected:
    uint m_iReservedSize;
    uint m_iNumElements;
    Type* m_pBuffer;
};

} // End of namespace hive

#include <Core/Array.inl>

#endif // End of HIVE_ARRAY_H
