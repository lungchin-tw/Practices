// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the DLLA_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// DLLA_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef BASE_EXPORTS
#define BASE_API __declspec(dllexport)
#else
#define BASE_API __declspec(dllimport)
#endif

#pragma once

class BASE_API BaseTemplate
{
public:
	static int ID;
};


template<int v>
struct Int2Type
{
	enum{ value = v };
};


template<typename TYPE, bool Enable = false>
class ComTemplate
{
public:
	static int GetID()
	{
		static int id = BaseTemplate::ID++;
		return id;
	}

	ComTemplate()
	{
		TestOverride();
	}

private:

	static void TestOverride( ) // Value is Class/Struct
	{}
};

template<typename TYPE>
class ComTemplate<TYPE, true>
{
public:
	static int GetID()
	{
		static int id = BaseTemplate::ID++;
		return id;
	}

private:

	static void TestOverride( ) // Value is Class/Struct
	{
		T::AddFields();
	}
};




// This class is exported from the DllA.dll
class BASE_API CBase {
public:
	CBase(void);
	// TODO: add your methods here.
};

extern BASE_API int nBase;

BASE_API int fnBase(void);
