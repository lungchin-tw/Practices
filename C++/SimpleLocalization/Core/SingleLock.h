/**
*
* @file     SingleLock.h
* @author   Feynman Su
* @version  1.0
*
* @section  LICENSE
*
* (C) 2009 XPEC Entertainment Inc. All rights reserved.
*
* @section	Description
*
* Multi-Thread object single lock class
*
*/
#ifndef HIVE_SingleLock_H
#define HIVE_SingleLock_H

namespace hive
{

//=============================================================================
/// SingleLock
//=============================================================================
class SingleLock
{
public:
                            SingleLock        (  SyncObjBase *pSyncObjBase,
                                                       const bool bInitialLock = HV_TRUE );
    virtual                 ~SingleLock       ();

                bool     Lock                    ();
                bool     Unlock                  ();


    HV_INLINE   bool     IsLocked                ();

private :
                SyncObjBase   *m_pSyncObjBase;
    volatile    bool	             m_bLocked;
}; // End of SingleLock

}  // End of namespace hive

#endif // End of HIVE_SingleLock_H