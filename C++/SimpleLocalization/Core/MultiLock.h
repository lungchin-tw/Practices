/**
*
* @file     MultiLock.h
* @author   Feynman Su
* @version  1.0
*
* @section  LICENSE
*
* (C) 2009 XPEC Entertainment Inc. All rights reserved.
*
* @section	Description
*
* Multi-Thread object multi lock class
*
*/
#ifndef HIVE_MultiLock_H
#define HIVE_MultiLock_H

#ifndef INFINITE
	#define INFINITE 0xFFFFFFFF 
#endif

namespace hive
{

//=============================================================================
/// CriticalSection
//=============================================================================
class MultiLock
{
public:
                            MultiLock         (  const dword       dwNumSyncObjects,
                                                       const bool        bWaitForAll,
                                                       SyncObjBase    **ppSyncObjBase,
                                                       const bool        bInitialLock = HV_TRUE );
    virtual                 ~MultiLock        ();

                bool		Lock                    ();
                bool		Unlock                  ();


    HV_INLINE   bool	    IsLocked                ();

private :
    enum { MLOCK_MAX_LOCK_COUNT = 8,
           SYNC_OBJ_INFINITE_TIMEOUT = INFINITE };

private :
                dword			    m_dwNumSyncObjects;
                bool		        m_bWaitForAll;
                SyncObjBase			*m_pSyncObjBaseArray[MLOCK_MAX_LOCK_COUNT];
                HV_HANDLE           m_hHandles[MLOCK_MAX_LOCK_COUNT];
                bool	            m_bLockedArray[MLOCK_MAX_LOCK_COUNT];

                SyncObjBase			*m_pSyncObjBase;
    volatile    bool	            m_bLocked;
}; // End of MultiLock

}  // End of namespace hive

#endif // End of HIVE_MultiLock_H