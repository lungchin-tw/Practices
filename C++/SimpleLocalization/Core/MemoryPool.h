/**
*
* @file     MemoryPool.h
* @author   Steve Tsai
* @version  1.0
*
* @section  LICENSE
*
* (C) 2010 XPEC Entertainment Inc. All rights reserved.
*
* @section	Description
*
* MemoryPool
*
*/
/**
* 
* @author   Ellison Mu
* @version  2010/9/9
*
* Modify memory usage interface, and supply overflow reallocate mechanism
*
*/

#ifndef HIVE_MEMORY_POOL_H
#define HIVE_MEMORY_POOL_H

namespace hive
{

typedef enum {
	GLOBAL,
	DYNAMIC,
	ALL_POOL_NUM
} EMemPoolType;

class Node
{
public:
	Node() : pNext(HV_NULL), pPrev(HV_NULL) {};
	
	Node		*pPrev;
	Node		*pNext;
};


// 1. Memory initialization
//@param uGlobalSize   Pre-allocated global pool size, size must than sizeof(Block)
//@param uDynamicSize  Pre-allocated dynamic pool size, size must than sizeof(Block)
//
#if defined (__HV_DEBUG_VERSION__)
HV_Core_API bool	HV_MemInitialize(uint32 uGlobalSize, uint32 uDynamicSize, bool bTrace = HV_TRUE);
#else
HV_Core_API bool	HV_MemInitialize(uint32 uGlobalSize, uint32 uDynamicSize, bool bTrace = HV_FALSE);
#endif

HV_Core_API bool	HV_MemTerminate();

// 2. Use / Free memory
#define HV_MallocGlobal(x)		Malloc_GlobalEx(x, __FILE__, __LINE__)
#define HV_MallocDynamic(x)		Malloc_DynamicEx(x, __FILE__, __LINE__)

HV_Core_API bool  HV_Free( void *pMem );


HV_Core_API void* Malloc_GlobalEx( uint32 uSize,
									   const char *szFile = 0, 
									   int32 nLine = 0 );

HV_Core_API void* Malloc_DynamicEx( uint32 uSize,
									    const char *szFile = 0, 
									    int32 nLine = 0 );

// 3. New / Delete memory
//! Allocates memory for an object.
#define HV_NewGlobal( Type, constructor)	(new (HV_MallocGlobal(sizeof(Type))) constructor)
#define HV_NewDynamic( Type, constructor)	(new (HV_MallocDynamic(sizeof(Type))) constructor)

//! Allocates memory for an object array.
#define HV_NewArrayGlobal( pArray, Type, count )	\
{ 	(pArray) = (Type*)HV_MallocGlobal(sizeof(Type)*(count));	\
	for ( uint32 i=0; i < (count); i++) { new (&(pArray[i])) Type; }	}

#define HV_NewArrayDynamic( pArray, Type, count )	\
{ 	(pArray) = (Type*)HV_MallocDynamic(sizeof(Type)*(count));	\
	for ( uint32 i=0; i < (count); i++) { new (&(pArray[i])) Type; }	}

//! Deallocates a block of memory for an object array. 
//param pObjectArray Destination C++ class object array
//param uCount Size of object array.
template <class Type>
void HV_DeleteArray( Type *pObjectArray, uint32 uCount )
{
	for ( uint32 i=0; i < uCount; i++ )	{	pObjectArray[i].~Type();	}
	HV_Free(pObjectArray);
}

template <class Type>
void HV_Delete(Type *pObject)
{
	pObject->~Type();
	HV_Free(pObject);
}

#define HV_DELETE_INSTANCE( instance )\
	if( instance != nullptr )\
	{\
		HV_Delete( instance );\
		instance = nullptr;\
	}\



#define HV_SAFE_DELETE( ptr ) \
{	if ( ptr != HV_NULL ) { HV_Delete( ptr ); ptr = HV_NULL; }	}


// 4. Memory Pool Infomation
struct MemPoolInfo : public Node
{
	uint32	m_uTotalSize;			//	Memory Pool available size
	uint32	m_uUsedSize;			//	Memory Pool currently used size
	uint32	m_uMaxUsedSize;			//	Memory Pool Max used size

	uint32	m_uCurAllocCnt;			//	Memory Pool Current Alloc Count
	uint32	m_uMaxAllocCnt;			//	Memory Pool Max Alloc Count

	MemPoolInfo()
		: m_uTotalSize(0),m_uUsedSize(0),m_uMaxUsedSize(0),m_uCurAllocCnt(0),m_uMaxAllocCnt(0) {}
};

// 5. Memory trace function enable/disable
//@param bEnable   true/false, enable/disable
//
HV_Core_API void	HV_MemSetTraceStatus( bool bEnable );

//Get Memory Pool info
//@param uIndex Memory Pool Index
//@param pMemInfo Memory Pool Information, a totalsize = 0, if not available
//
HV_Core_API MemPoolInfo HV_MemGetMemPoolInfo( EMemPoolType type );

} // End of namespace hive

#endif  // End of HIVE_MEMORY_POOL_H

