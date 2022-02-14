/**
*
* @file     CriticalSection.h
* @author   Feynman Su
* @version  1.0
*
* @section  LICENSE
*
* (C) 2009 XPEC Entertainment Inc. All rights reserved.
*
* @section	Description
*
* Multi-Thread object critical section class
*
*/
#ifndef HIVE_CRITICAL_SECTION_H
#define HIVE_CRITICAL_SECTION_H

namespace hive
{

//=============================================================================
/// CriticalSection
//=============================================================================
class CriticalSection : public SyncObjBase
{
public:
                        CriticalSection       ();
    virtual             ~CriticalSection      ();

    virtual bool     Lock							();
    virtual bool	 Unlock							();
    virtual HV_HANDLE   GetHandle                   () const;

private :
#ifdef __HV_OS_WINDOWS__
    CRITICAL_SECTION    m_stCritialSection;
#endif
}; // End of CriticalSection

} // End of namespace hive

#endif // End of HIVE_CRITICAL_SECTION_H