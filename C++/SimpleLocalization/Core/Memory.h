/**
*
* @file     Memory.h
* @author   Feynman Su
* @version  1.0
*
* @section  LICENSE
*
* (C) 2009 XPEC Entertainment Inc. All rights reserved.
*
* @section	Description
*
* Debug memory system
*
*/
/**
* 
* @author   Ellison Mu
* @version  2010/9/9
*
* Modify memory usage interface, Alloc_New/Dealloc_Del to supply new/delete operator
*
*/

#ifndef HIVE_MEMORY_H
#define HIVE_MEMORY_H

#include <new>

namespace hive
{

//=============================================================================
/// Double Link list
//=============================================================================
template<class Type>
class DoubleLinkList
{
public :
	DoubleLinkList   ();
	virtual     ~DoubleLinkList  ();

	Type        operator[]          ( int32 iIndex );
	const Type  operator[]          ( int32 iIndex ) const;

	HV_INLINE   bool     PushBack            (  Type pItem );
	HV_INLINE   bool     PushFront           (  Type pItem );

	HV_INLINE   bool     Add                 (  Type pItem );
	HV_INLINE   bool     AddFront            (  Type pItem );

	HV_INLINE   bool     Insert              (  Type pItem,  Type pRefItem );
	HV_INLINE   bool     Remove              (  Type pItem,  bool bDelete = HV_FALSE );

	HV_INLINE   Type        PopBack             ();
	HV_INLINE   Type        PopFront            ();

	HV_INLINE   Type        GetHead             ();
	HV_INLINE   const Type  GetHead             () const;
	HV_INLINE   Type        GetTail             ();
	HV_INLINE   const Type  GetTail             () const;

	HV_INLINE   bool     IsEmpty             () const;
	HV_INLINE   int32    GetNumItems         () const;
	HV_INLINE   void     Clear               (  bool bDelete );

protected :
	virtual     void     DeleteItem          (  Type pItem );

private :
	DoubleLinkList   (  const DoubleLinkList &src ); ///< 不允許拷貝建構,所以設為Private

private :
	Type	m_pHead;
	Type	m_pTail;
	int32   m_iNumItems;
}; // End of DoubleLinkList


//=============================================================================
/// 函式實做
//=============================================================================
template<class Type>
DoubleLinkList<Type>::DoubleLinkList() :
m_pHead(HV_NULL),
m_pTail(HV_NULL),
m_iNumItems(0)
{
} // End of constructor


//-------------------------------------------------------------------------
template<class Type>
DoubleLinkList<Type>::~DoubleLinkList()
{
	Clear( HV_FALSE );
} // End of destructor


//-------------------------------------------------------------------------
template<class Type>
Type DoubleLinkList<Type>::operator[] ( int32 iIndex )
{
	ASSERT( iIndex < m_iNumItems );
	if ( iIndex >= m_iNumItems )
	{
		return HV_NULL;
	} // End if

	if ( m_iNumItems <= 0 )
	{
		return HV_NULL;
	} // End if

	Type pItem = GetHead();
	for ( int32 i = 0; i < iIndex; ++i )
	{
		ASSERT( pItem != HV_NULL );
		pItem = pItem->GetNext();
	} // End while

	ASSERT( pItem != HV_NULL );

	return pItem;
}; // End of operator


//-------------------------------------------------------------------------
template<class Type>
const Type DoubleLinkList<Type>::operator[] ( int32 iIndex ) const
{
	ASSERT( iIndex < m_iNumItems );
	if ( iIndex >= m_iNumItems )
	{
		return HV_NULL;
	} // End if

	if ( m_iNumItems <= 0 )
	{
		return HV_NULL;
	} // End if

	Type pItem = GetHead();
	for ( int32 i = 0; i < iIndex; ++i )
	{
		ASSERT( pItem != HV_NULL );
		pItem = pItem->GetNext();
	} // End while

	ASSERT( pItem != HV_NULL );

	return pItem;
}; // End of operator


//-------------------------------------------------------------------------
template<class Type>
bool DoubleLinkList<Type>::PushBack( Type pItem )
{
	return Add( pItem );
} // End of PushBack on DoubleLinkList


//-------------------------------------------------------------------------
template<class Type>
bool DoubleLinkList<Type>::PushFront( Type pItem )
{
	return AddFront( pItem );
} // End of PushFront on DoubleLinkList


//-------------------------------------------------------------------------
template<class Type>
bool DoubleLinkList<Type>::Add( Type pItem )
{
	ASSERT( pItem != HV_NULL );
	ASSERT( pItem->GetNext() == HV_NULL );
	ASSERT( pItem->GetPrev() == HV_NULL );

	if ( m_pHead == HV_NULL )
	{
		m_pTail = m_pHead = pItem;
	} // End if
	else
	{
		m_pTail->SetNext( pItem );
		pItem->SetPrev( m_pTail );
		m_pTail = pItem;
	} // End else

	m_iNumItems++;

	return HV_TRUE;
} // End of Add on DoubleLinkList


//-------------------------------------------------------------------------
template<class Type>
bool DoubleLinkList<Type>::AddFront( Type pItem )
{
	ASSERT( pItem != HV_NULL );
	ASSERT( pItem->GetNext() == HV_NULL );
	ASSERT( pItem->GetPrev() == HV_NULL );

	if ( m_pTail == HV_NULL )
	{
		m_pTail = m_pHead = pItem;
	} // End if
	else
	{
		m_pHead->SetPrev( pItem );
		pItem->SetNext( m_pHead );
		m_pHead = pItem;
	} // End else

	m_iNumItems++;

	return HV_TRUE;
} // End of AddFront on DoubleLinkList


//-------------------------------------------------------------------------
template<class Type>
bool DoubleLinkList<Type>::Insert( Type pItem, Type pRefItem )
{
	ASSERT( pItem->GetNext() == HV_NULL );
	ASSERT( pItem->GetPrev() == HV_NULL );

	if ( pRefItem == HV_NULL )
	{
		Add( pItem );
	} // End if
	else if ( m_pHead == pRefItem )
	{
		AddFront( pItem );
	} // End else if
	else
	{
		Type pPrev = pRefItem->GetPrev();

		pRefItem->SetPrev( pItem );

		pItem->SetNext( pRefItem );
		pItem->SetPrev( pPrev );

		if ( pPrev != HV_NULL )
		{
			pPrev->SetNext( pItem );
		} // End if

		m_iNumItems++;
	} // End else

	return HV_TRUE;
} // End of Insert on DoubleLinkList


//-------------------------------------------------------------------------
template<class Type>
bool DoubleLinkList<Type>::Remove( Type pItem, bool bDelete )
{
	ASSERT( pItem != HV_NULL );
	if ( pItem == HV_NULL )
	{
		return HV_FALSE;
	} // End if

	Type pPrev = pItem->GetPrev();
	Type pNext = pItem->GetNext();

	if ( pPrev == HV_NULL )
	{
		ASSERT( m_pHead == pItem );
		PopFront();
	} // End if
	else if ( pNext == HV_NULL )
	{
		ASSERT( m_pTail == pItem );
		PopBack();
	} // End if
	else
	{
		pNext->SetPrev( pPrev );
		pPrev->SetNext( pNext );

		pItem->SetNext( HV_NULL );
		pItem->SetPrev( HV_NULL );

		m_iNumItems--;
	} // End else

	if ( bDelete == HV_TRUE )
	{
		DeleteItem( pItem );
	} // End if

	return HV_TRUE;
} // End of Remove on DoubleLinkList


//-------------------------------------------------------------------------
template<class Type>
Type DoubleLinkList<Type>::PopBack()
{
	ASSERT( m_pTail != HV_NULL );
	if ( m_pTail == HV_NULL )
	{
		return HV_NULL;
	} // End if

	Type pItem = m_pTail;

	Type pPrev = pItem->GetPrev();
	if ( pPrev != HV_NULL )
	{
		pPrev->SetNext( HV_NULL );
		m_pTail = pPrev;
	} // End if
	else
	{
		m_pTail = m_pHead = HV_NULL;
	} // End else

	pItem->SetNext( HV_NULL );
	pItem->SetPrev( HV_NULL );

	m_iNumItems--;
	return pItem;
} // End of PopBack on DoubleLinkList


//-------------------------------------------------------------------------
template<class Type>
Type DoubleLinkList<Type>::PopFront()
{
	ASSERT( m_pHead != HV_NULL );
	if ( m_pHead == HV_NULL )
	{
		return HV_NULL;
	} // End ifs

	Type pItem = m_pHead;
	Type pNext = pItem->GetNext();
	if ( pNext != HV_NULL )
	{
		pNext->SetPrev( HV_NULL );
		m_pHead = pNext;
	} // End if
	else
	{
		m_pTail = m_pHead = HV_NULL;
	} // End else

	pItem->SetNext( HV_NULL );
	pItem->SetPrev( HV_NULL );

	m_iNumItems--;

	return pItem;
} // End of PopFront on DoubleLinkList


//-------------------------------------------------------------------------
template<class Type>
Type DoubleLinkList<Type>::GetHead()
{
	return m_pHead;
} // End of GetHead on DoubleLinkList


//-------------------------------------------------------------------------
template<class Type>
const Type DoubleLinkList<Type>::GetHead() const
{
	return m_pHead;
} // End of GetHead on DoubleLinkList


//-------------------------------------------------------------------------
template<class Type>
Type DoubleLinkList<Type>::GetTail()
{
	return m_pTail;
} // End of GetTail on DoubleLinkList


//-------------------------------------------------------------------------
template<class Type>
const Type DoubleLinkList<Type>::GetTail() const
{
	return m_pTail;
} // End of GetTail on DoubleLinkList


//-------------------------------------------------------------------------
template<class Type>
bool DoubleLinkList<Type>::IsEmpty() const
{
	return ((m_iNumItems == 0) ? HV_TRUE : HV_FALSE);
} // End of IsEmpty on DoubleLinkList


//-------------------------------------------------------------------------
template<class Type>
int32 DoubleLinkList<Type>::GetNumItems() const
{
	return m_iNumItems;
} // End of GetNumItems on DoubleLinkList


//-------------------------------------------------------------------------
template<class Type>
void DoubleLinkList<Type>::Clear( bool bDelete )
{
	while ( m_iNumItems > 0 )
	{
		Type pItem = PopFront();

		if ( bDelete == HV_TRUE )
		{
			DeleteItem( pItem );
		} // End if
	} // End while
} // End of IsEmpty on DoubleLinkList


//-------------------------------------------------------------------------
template<class Type>
void DoubleLinkList<Type>::DeleteItem( Type pItem )
{
	delete( pItem );
}; // End of DeleteItem on DoubleLinkList


//=============================================================================
/// 簡化建立使用double link list物件的macro
//=============================================================================
template<class Type>
class DoubleLinkedListElement
{
public :
	Type    *m_pPrev;
	Type    *m_pNext;

	DoubleLinkedListElement() : m_pPrev(HV_NULL), m_pNext(HV_NULL)
	{
	}; // End of constructor
}; // End of DoubleLinkedListElement


//-----------------------------------------------------------------------------
#define HV_DECLARE_DOUBLE_LINKEDLIST_ITEM(Type)     \
public :                                            \
	void SetPrev( Type *pItem )                  \
    {                                               \
	    m_listElement.m_pPrev = pItem;              \
    };                                              \
	void SetNext( Type *pItem )                  \
    {                                               \
	    m_listElement.m_pNext = pItem;              \
    };                                              \
	Type* GetPrev()                        \
    {                                               \
	    return m_listElement.m_pPrev;               \
    };                                              \
	const Type* GetPrev() const                     \
    {                                               \
	    return m_listElement.m_pPrev;               \
    };                                              \
	Type* GetNext()                        \
    {                                               \
	    return m_listElement.m_pNext;               \
    };                                              \
	const Type* GetNext() const                     \
    {                                               \
	    return m_listElement.m_pNext;               \
    };                                              \
private :                                           \
    DoubleLinkedListElement<Type> m_listElement;


//=============================================================
/// 記憶體管理函式
/// Debug模式下會有除錯資訊
/// Release模式下就只是對應到一般的malloc和free而已
//=============================================================
void MemoryDebug_Initialize();

HV_Core_API uint8* AllocMemEx( size_t nSize, 
                                const char *szFileName, 
                                int32 nLine );

HV_Core_API uint8* AllocMemEx( size_t nSize, 
                                const wchar *szFileName, 
                                int32 nLine );

HV_Core_API bool HV_DeallocateMem( void *pBuffer );

//! Allocates memory for an object.
#define HV_AllocMem(x)		AllocMemEx(x, __FILE__, __LINE__)
#define HV_AllocNew( Type, constructor )	(new (HV_AllocMem(sizeof(Type))) constructor )

template <class Type>
void HV_DeallocDel( Type *pObject )
{
	pObject->~Type();
	HV_DeallocateMem(pObject);
}

#ifdef __HV_SECURITY_CRT__
    #define HV_MemCopy( dstBuf, dstSize, srcBuf, srcSize )  memcpy_s( dstBuf, dstSize, srcBuf, srcSize )
#else
    #define HV_MemCopy( dstBuf, dstSize, srcBuf, srcSize )  memcpy( dstBuf, srcBuf, srcSize )
#endif

} // End of namespace hive

#endif // End of HIVE_MEMORY_H