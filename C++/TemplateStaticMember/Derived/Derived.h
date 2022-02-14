// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the DERIVED_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// DERIVED_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef DERIVED_EXPORTS
#define DERIVED_API __declspec(dllexport)
#else
#define DERIVED_API __declspec(dllimport)
#endif

#pragma once

#include "Base.h"


class DERIVED_API ComDerived : public ComTemplate<int>
{};

// This class is exported from the Derived.dll
class DERIVED_API CDerived {
public:
	CDerived(void);
	// TODO: add your methods here.
};

extern DERIVED_API int nDerived;

DERIVED_API int fnDerived(void);
