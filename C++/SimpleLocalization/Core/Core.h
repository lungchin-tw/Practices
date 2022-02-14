/**
*
* @file     Core.h
* @author   Feynman Su
* @version  1.0
*
* @section  LICENSE
*
* (C) 2009 XPEC Entertainment Inc. All rights reserved.
*
* @section	Description
*
* Main include for Core
*
*/
#ifndef HIVE_CORE_H
#define HIVE_CORE_H

#ifdef _WIN32
    #include <Windows.h>
    #include <tchar.h>	// modify for supporting html5, clang
#endif


#include <math.h>

#include <Core/Compiler_Options.h>
#include <Core/Types.h>
#include <Core/Debug.h>
#include <Core/Kernel.h>
#include <Core/SyncObjBase.h>
#include <Core/CriticalSection.h>
#include <Core/SingleLock.h>
#include <Core/MultiLock.h>
#include <Core/Memory.h>
#include <Core/StringA.h>
#include <Core/StringW.h>
#include <Core/Utility.h>
#include <Core/Array.h>
#include <Core/MemoryPool.h>
#include <Core/MemoryTracker.h>
#include <Core/Vector2D.h>
#include <Core/Vector3D.h>
#include <Core/Vector3DSSE.h>
#include <Core/Vector4D.h>
#include <Core/Vector4DSSE.h>
#include <Core/Matrix3x3.h>
#include <Core/Matrix4x4.h>
#include <Core/Matrix4x4SSE.h>
#include <Core/Quaternion.h>
#include <Core/QuaternionSSE.h>
#include <Core/Map.h>
#include <Core/Reference.h>
#include <Core/FileHandle.h>
#include <Core/FileManager.h>
#include <Core/Any.h>
#include <Core/Log.h>
#include <Core/LogManager.h>
#include <Core/ConfigFile.h>
#include <Core/List.h>
#include <Core/SmartPtr.h>
#include <Core/Parse.h>
#include <Core/Identifier.h>
#include <Core/UUID.h>
#include <Core/TypeInfo.h>
#include <Core/TypeDatabase.h>
#include <Core/Factory.h>
#include <Core/ConfigManager.h>
#include <Core/TypeSerializer.h>
#include <Core/JSONSerializer.h>
#include <Core/Recycle.h>
#include <Core/SharedInstanceCollection.h>
#include <Core/GlobalSetting.h>
#include <Core/EventDispatcher.h>


namespace hive
{

#ifdef __HV_OS_WINDOWS__
	typedef Vector2D<int>     Vector2Dint;
	typedef Vector2D<uint>    Vector2Duint;

	typedef Vector3D<uint>    Vector3Duint;
	typedef Vector3D<float>   Vector3Df;
    typedef Vector4D<float>   Vector4Df;
	typedef Matrix3x3<float>  Matrix3x3f;
    typedef Matrix4x4<float>  Matrix4x4f;
    typedef Quaternion<float> Quaternionf;

    typedef Vector3D<double>   Vector3Dd;
    typedef Vector4D<double>   Vector4Dd;
    typedef Matrix4x4<double>  Matrix4x4d;
    typedef Quaternion<double> Quaterniond;
#else
	typedef Vector2D<int>   Vector2Dint;
	typedef Vector2D<uint>   Vector2Duint;

    typedef Vector3D<float>   Vector3Df;
    typedef Vector4D<float>   Vector4Df;
    typedef Matrix3x3<float>  Matrix3x3f;
    typedef Matrix4x4<float>  Matrix4x4f;
    typedef Quaternion<float> Quaternionf;

    typedef Vector3D<double>   Vector3Dd;
    typedef Vector4D<double>   Vector4Dd;
    typedef Matrix4x4<double>  Matrix4x4d;
    typedef Quaternion<double> Quaterniond;
#endif

}

#endif // End of HIVE_CORE_H