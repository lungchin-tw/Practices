/**
*
* @file     Types.h
* @author   Feynman Su
* @version  1.0
*
* @section  LICENSE
*
* (C) 2009 XPEC Entertainment Inc. All rights reserved.
*
* @section	Description
*
* Main include for XELib
*
*/
#ifndef HIVE_TYPES_H
#define HIVE_TYPES_H


#ifdef _UNICODE
    #ifndef UNICODE
        #define UNICODE
    #endif
#endif

//=============================================================================
/// Define OS
//=============================================================================
#if (_WIN32) || (_WIN64)
    #define __HV_OS_WINDOWS__
#else
    #undef __HV_OS_WINDOWS__
#endif

//=============================================================================
// Disable warnings on dll export of template
//=============================================================================
#ifdef __HV_OS_WINDOWS__
    #pragma warning ( disable : 4251 )
#endif

//=============================================================================
/// Define API convention
//=============================================================================
#if defined (__HV_OS_WINDOWS__)
    #define HV_API_EXPORT __declspec(dllexport)
    #define HV_API_IMPORT __declspec(dllimport)
#else
    #define HV_API_EXPORT
    #define HV_API_IMPORT
#endif

#if defined (__HV_CORE_STATIC__)
    #define HV_Core_API
#elif defined (__HV_CORE_DLL__)
    #define HV_Core_API HV_API_EXPORT
#else
	#if defined ( _USRDLL )
		 #define HV_Core_API HV_API_IMPORT
	#else 
		#define HV_Core_API
	#endif
#endif

//=============================================================================
// 開啟Debug memory的選項 (目前只支援Windows)
//=============================================================================
#ifdef _DEBUG
#define __HV_DEBUG_VERSION__
#ifdef __HV_OS_WINDOWS__
//#define __HV_DEBUG_MEMORY__
#else
#undef __HV_DEBUG_MEMORY__
#endif	// End of __HV_OS_WINDOWS__
#else
#undef __HV_DEBUG_VERSION__
#endif // End of _DEBUG

#define HV_INLINE           inline
#define HV_STATIC           static

//=============================================================================
// 定義函式呼叫規則
//=============================================================================
#ifdef __HV_OS_WINDOWS__
    #define HV_CDECL            __cdecl
    #define HV_STDCALL          __stdcall
    #define HV_DECLNOTHROW      __declspec(nothrow)
#else
    #define HV_CDECL
    #define HV_STDCALL
    #define HV_DECLNOTHROW
#endif

namespace hive
{

//=============================================================================
/// Basic Types
//=============================================================================
typedef wchar_t                 wchar;   ///< \typedef Unicode character type ( 2 or 4 bytes depending on platform )          
typedef unsigned char           uchar;   ///< \typedef Unsigned character
typedef char                    int8;    ///< \typedef 8 bits integer
typedef unsigned char           uint8;   ///< \typedef 8 bits integer unsigned
typedef short                   int16;   ///< \typedef 16 bits integer
typedef unsigned short          uint16;  ///< \typedef 16 bits integer unsigned
typedef int                     int32;   ///< \typedef 32 bits integer 
typedef unsigned int            uint32;  ///< \typedef 32 bits integer unsigned

typedef unsigned int            uint;    ///< \typedef Native unsigned integer ( 32 bit on 32 bit machine, 64 bit on 64 bit machine )

#if defined __HV_OS_WINDOWS__
    typedef __int64             int64;   ///< \typedef 64 bits integer
    typedef unsigned __int64    uint64;  ///< \typedef 64 bits integer unsigned
#else
    typedef long long           int64;   ///< \typedef 64 bits integer
    typedef unsigned long long  uint64;  ///< \typedef 64 bits integer unsigned
#endif

//typedef unsigned char           byte;    ///< \typedef Byte
typedef unsigned short          word;    ///< \typedef Word ( 2 bytes )
typedef unsigned int            dword;   ///< \typedef Double word ( 4 bytes )
typedef uint64		            qword;   ///< \typedef Quad word ( 8 bytes )

typedef unsigned long           ulong;   ///< \typedef unsigned long type

#ifdef __HV_OS_WINDOWS__
    typedef HANDLE              HV_HANDLE;                   ///< Generic handle
    typedef HINSTANCE			HV_MODULE;           
	typedef HWND				HV_HWND;				
    typedef HDC					HV_DISPLAYTYPE;
	typedef HGLRC				HV_GLRC;
    typedef RECT				RectEdges;            
#else
    //#define HV_HANDLE           void*         ///< Generic handle
	typedef void*				HV_HANDLE;           
    typedef int					HV_MODULE;          
    typedef void*				HV_HWND;				
    typedef void*				HV_WINDOWTYPE;		
    
    #if !defined(_TRUNCATE)
			#define _TRUNCATE ((size_t)-1)
		#endif
    
    typedef struct  
    {
        long left;
        long top;
        long right;
        long bottom;
    } RectEdges;
#endif

#define HV_NULL                 (0)
#define HV_HANDLE_NULL          ((HV_HANDLE)0)
#define HV_MODULE_NULL          ((HV_MODULE)0)

#define HV_TRUE                 true
#define HV_FALSE                false

#ifdef UNICODE
    typedef wchar				tchar;
	#define StringT				StringW				
	#define HV_T(x)				L ## x	
#else
    typedef char				tchar;            
	#define HV_T(x)				x
	#define StringT				StringA
#endif


#ifdef __HV_COMPILER_VC__
    #define HV_ALIGN(x) __declspec(align(x))
#else
    #define HV_ALIGN(x) 
#endif

enum EAngleType
{
    ANGLE_TYPE_DEGREE,
    ANGLE_TYPE_RADIAN,
};

const float HV_HALF_PI = 1.57079632f;
const float HV_PI      = 3.14159265f;
const float HV_TWO_PI  = 6.28318530f;

} // End of namespace hive

#endif // End of HIVE_TYPES_H