/**
*
* @file     SyncObjBase.h
* @author   Feynman Su
* @version  1.0
*
* @section  LICENSE
*
* (C) 2009 XPEC Entertainment Inc. All rights reserved.
*
* @section	Description
*
* Multi-Thread object synchronization classes
*
*/
#ifndef HIVE_SYNC_OBJ_BASE_H
#define HIVE_SYNC_OBJ_BASE_H

namespace hive
{

// Pure virtual function
class SyncObjBase
{
public:
                        SyncObjBase       ();
    virtual             ~SyncObjBase      ();

    virtual bool     Lock                    () = 0;
    virtual bool	 Unlock                  () = 0;
    virtual HV_HANDLE		  GetHandle               () const = 0;
}; // End of SyncObjBase

} // End of namespace hive

#endif // End of HIVE_SYNC_OBJ_BASE_H