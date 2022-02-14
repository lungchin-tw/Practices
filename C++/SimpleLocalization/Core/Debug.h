/**
*
* @file     Debug.h
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
#ifndef HIVE_DEBUG_H
#define HIVE_DEBUG_H


//#ifdef __HV_OS_WINDOWS__		// adjust for emscripten
    #include <assert.h>

namespace hive
{
    #define ASSERT(express) assert(express)
#ifdef __HV_OS_WINDOWS__		// adjust for emscripten
    /// 定義Windows下的VS視窗輸出函式
    #ifdef __HV_DEBUG_VERSION__
        void HV_Core_API WinOutput(  wchar *szString,  ... );
        void HV_Core_API WinOutput(  char  *szString,  ... );
    #else
		// Steve added to disable warning, Feynman please check it
		#pragma warning(disable: 4390)  // ';' : empty controlled statement found; is this the intent?
        #define WinOutput(x,...)
    #endif
#else
    #define WinOutput(x,...)
#endif // End of __HV_OS_WINDOWS__

} // End of namespace hive

#endif // End of HIVE_DEBUG_H