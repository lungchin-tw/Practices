/**
*
* @file     FileSystem.h
* @author   Steve Tsai
* @version  1.0
*
* @section  LICENSE
*
* (C) 2010 XPEC Entertainment Inc. All rights reserved.
*
* @section	Description
*
* File Management System: to manage working path, avoid file reopen
*
*
*/

#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include "Core/Types.h"
#include "Core/FileHandle.h"
#include "Core/ConfigFile.h"
#include "Core/Singleton.h"
#include "Core/StringW.h"
#include "Core/StringA.h"

namespace hive
{

enum EFileOpenResult
{
	OPEN_FAIL = 0, 
	OPEN_SUCCESS, 
	OPENED,
};

enum EFileCloseResult
{
	CLOSE_FAIL = 0, 
	INVALID, 
	CLOSE_SUCCESS, 
	NOT_FOUND, 
	CLOSE_ERROR,
};

class HV_Core_API FileManager
{
public:
	// 2. Set property (Not used, please Use CheckFile())
	// [bReopenCheck]:	Whether FileManager should performe reopen check mechanizm
	//					set true for the other parameters to work.
	// [bUniqueName]:	Check if the file name is unique in the direcctory tree.
	//					The file manager reports error and the current opened file, 
	//					when the same file name at different path is opened.
	// 
	//void Set (bool bReopenCheck = HV_TRUE, bool bUniqueName = HV_TRUE);

	// 3. Set Path & SubDir
	//  sub directory is designed for temporary change, ex. resource sub dir.
	//  sub directory don't include char '/' at the begin & the end.
	//  However, the program checks if '/' exist, 
	//  Work Path include '/' at the end.
	//
	//  Work Path = root path + subdirectory + '/'
	//  File open is defined by full path = root path + subdirectory + file name
	//  todo: HV_TCHAR, wchar cause compiler error.

	bool	SetRootPath(const tchar *szPath);
	tchar*	GetRootPath();

	bool	SetSubDir(const tchar *szSubDir);
	tchar*	GetSubDir();

	tchar*	GetWorkPath();

	//--------------------------------------------------------------------------------------
	// 4.a Open File
	// If the same name & full path is found, simply return the exist file handle object.
	// The application need to check the return file object type, then cast to the desire object.
	// If the file is opened, the object type may be different.
	// The application should release the object after use. or simply call ClearAll ()
	//
	/// @param	[in]	eType file object type
	//			[in]	uMode same at define in FileHandle, when eType = FILE_HANDLE
	///			[out]	a file base object pointer
	/// @return			Open Result 
	//--------------------------------------------------------------------------------------

	EFileOpenResult	OpenFile( const tchar* szFileName, 
									 FileBase **,
									const EFileType eType = FILE_HANDLE, 
									const FileHandle::EFileOpen_Type uMode = FileHandle::EFileOpen_Type::FOPEN_READ );

	//--------------------------------------------------------------------------------------
	// 4.b Check File
	// If the same name & full path is found, simply return the exist file handle object.
	// The application should release the object after use. or simply call ClearAll ()
	// This function is similar to OpenFile (), except it only stores file name, not open it.
	// Application can check the result if 'OPENED'
	//
	///	@param	[out]	a New or previous file handle object pointer
	///	@param	[out]	work path of a new or previous file.
	/// @return			Open Result 
	//--------------------------------------------------------------------------------------

	EFileOpenResult	CheckFile(const tchar* szFileName,  FileBase **, 
									 tchar **ppWorkPath = HV_NULL);
	
	// Do Close file Directly, regardless reference count
	// Application should call FileBase::Release () to close the file
	EFileCloseResult	Close(FileBase *);

	// 5. Clean all File Memory and stored file data
	//    Call this function before re-set the property
	void		ClearAll ();

	FileManager ();
	~FileManager ();

protected:
	void InitValues ();
	void CloseAllFiles ();

	FileHandle* OpenFileWithPath(const tchar* szFileName, const FileHandle::EFileOpen_Type uMode);
	FileMemory* OpenFileMemoryWithPath(const tchar* szFileName);
	ConfigFile* OpenConfigFileWithPath(const tchar* szFileName);

private:
	typedef Array<StringT>	WorkPathArray;

	// only Full path equal is equal
	class FileData
	{
	public:
		FileBase		*pHandle;
		uint			iPathIdx;	// ptr to a work path in PathArray

		FileData () { pHandle = 0; iPathIdx = 0; }

		bool IsEqualPath ();		// if this file path the same with current path
		bool IsEqualPath (FileData *);
	};

	// FileData array is to store all file data with the same file name 
	// but at different paths
	typedef Array<FileData> FileDataArray;

	// file name map to search opened file
	// file name may be the same but different path
	// file handle map <Key, Value>  file name is the key
	typedef Map<StringT, FileDataArray> FileDataMap;

	WorkPathArray	m_arrWorkPath;
	FileDataMap		m_mapFileData;

	// find if a file is opened with current open file
	FileBase* FindOpenedFileByName (StringT fName, FileDataArray **ppArrFile);

	StringT m_RootPath;
	StringT m_SubDir;

	// path dirty flags
	bool	m_bModifyRootPath;
	bool m_bModifySubDir;

	// properties
	bool	m_bReopenCheck;
	bool	m_bUniqueName;

	friend class FileData;
};

extern "C"
{
	// 1. New a file Manager object, and Get singleton object
	// we want it compiled into the implementation of the class based on the Singleton. 
	// This method just delegates to the template version, preventing link errors.
	//
	HV_Core_API FileManager& FileManagerGetInstance();
};

}  // End of namespace hive

#endif // FILEMANAGER_H
