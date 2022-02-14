/**
*
* @file     Compiler_Options.h
* @author   Feynman Su
* @version  1.0
*
* @section  LICENSE
*
* (C) 2009 XPEC Entertainment Inc. All rights reserved.
*
* @section	Description
*
* 定義和編譯器相關的define
*
*/
#ifndef HIVE_COMPILER_OPTIONS_H
#define HIVE_COMPILER_OPTIONS_H


// 如果compiler是使用Visual C++,檢查它的版本
#ifdef _MSC_VER
    #define __HV_COMPILER_VC__

    #if _MSC_VER >= 1500   // Visual C++ 2008
        #define __HV_COMPILER_VC_2008__

    #elif _MSC_VER >= 1400 // Visual C++ 2005
        #define __HV_VC_COMPILER_2005__

    #elif _MSC_VER >= 1310 // Visual C++ 2003
        #define __HV_COMPILER_VC_2003__

    #elif _MSC_VER >= 1300 // Visual C++ 2002
        #define __HV_COMPILER_VC_2002__

    #elif _MSC_VER >= 1200 // Visual C++ 6
        #define __HV_COMPILER_VC_6__
    #endif
#endif // End of _MSC_VER

#ifdef __HV_COMPILER_VC_2008__
    #define __HV_SECURITY_CRT__
#elif defined __HV_VC_COMPILER_2005__
    #define __HV_SECURITY_CRT__
#else
    #undef __HV_SECURITY_CRT__
#endif


#endif // End of HIVE_COMPILER_OPTIONS_H