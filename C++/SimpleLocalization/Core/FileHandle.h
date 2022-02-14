/**
*
* @file     File_Handle.h
* @author   Steve Tsai
* @version  1.0
*
* @section  LICENSE
*
* (C) 2010 XPEC Entertainment Inc. All rights reserved.
*
* @section	Description
*
* File Handle : a file handle physically associate with a file, one on one.
*				it wraps file operations to achive platform independency.
*
*/
#ifndef FILEHANDLE_H
#define FILEHANDLE_H

#include "Core/Reference.h"

namespace hive
{

class FileManager;

// File Base class is designed to interact with FileManager.

enum EFileType
{
	FILE_HANDLE, 
	FILE_MEMORY, 
	FILE_CONFIG,
};

class HV_Core_API FileBase : public Reference
{
public:
	FileBase () { m_pParent = HV_NULL; }

	EFileType	Type () { return m_eType; }
	StringT&	Name () { return m_sFileName; }

	virtual long GetSize () = 0;
	virtual bool	Close () = 0;

protected:
	EFileType	m_eType;

private:
	// override class Reference
	// Application should call Reference::Release () to close file or Free Memory
	// return true if the object is close successfully, and deleted.
	virtual bool DoRelease ();

	// store parent ptr for every handle
	// it takes more space, but good for multi- FileManagers due to multi-thread.
	FileManager	*m_pParent;		

	// we need the file name as key for FileManager to close file
	StringT		m_sFileName;		

	friend class FileManager;
};

//----------------------------------------------------------------------

enum EFileLoadResult
{
	LOAD_FAIL,  LOAD_SUCCESS, LOADED_ALREADY, 
	EMPTY_FILE, ALLOC_MEMORY_FAIL, PARTLY_LOADED,
	FILE_NOT_OPENED,
};

class HV_Core_API FileHandle : public FileBase
{
public:
	// 1. Specify Open Mode to open a file Text or binary
	typedef enum 
	{
		FOPEN_READ	=	0,
		FOPEN_WRITE	=	1,		
		FOPEN_APPEND =	2,
		FOPEN_READ_T =	3,
		FOPEN_WRITE_T =	4,
		FOPEN_APPEND_T = 5
	} EFileOpen_Type;
	

	// Open a file with full path
	// [szPath]: Full path 
	// Another option is call FileManager::OpenFile () with file name only
	// & FileManager::GetWorkPath ()
	// Remember Open () 'new' a FileHandle object
	// and     Release () may 'delete' object
	static FileHandle* Open(const wchar *szPath, const EFileOpen_Type uMode);

	// Open a file with full path
	// [szPath]: Full path 
	// Another option is call FileManager::OpenFile () with file name only
	// & FileManager::GetWorkPath ()
	// Remember Open () 'new' a FileHandle object
	// and     Release () may 'delete' object
	static FileHandle* Open(const char *szPath, const EFileOpen_Type uMode);

	// this function return file pointer
	static void* OpenFile(const wchar *szPath, const EFileOpen_Type uMode);

	// this function return file pointer
	static void* OpenFile(const char *szPath, const EFileOpen_Type uMode);

	// the function writes to appropriate files the contents of all buffers associated with open output streams.
	// All streams remain open after the call.
	// returns the number of open streams (input and output). 
	static int	FlushAll();

	// 2. Operate the file using the class methods

	// for PC, fp = (FILE *)
	FileHandle (void *fp = 0);
	~FileHandle () {}

	void*	GetHandle() { return m_fp; }

	bool		Read( void *pBuffer, const uint32 uSize,  int32 *pByteRead );
	bool		Write( const void *pBuffer, const uint32 uSize,  int32 *pByteWrite );

	bool		Write( const StringA &str,  int32 *pByteWrite);
	bool		Write( const StringW &str,  int32 *pByteWrite);

	char*	ReadLine(char *pCh, int iMax);
	wchar*	ReadLine(wchar *pCh, int iMax);

	// Read text from FileHandle, outputStr Output the text.
	void		ReadText( StringA &outputStr );
	
	// Read text from FileHandle, outputStr Output the text.
	void		ReadText( StringW &outputStr );

	//
	// Seeking : Move the current file pointer to initPos + offset
	//
	#define HE_SEEK_SET       SEEK_SET
	#define HE_SEEK_CUR       SEEK_CUR
	#define HE_SEEK_END       SEEK_END

	bool Seek(const long offset, const int32 initPos = HE_SEEK_CUR);

	// Get current position of file pointer
	long Tell();

	// returns true if a read operation has attempted to read past the end of the file,
	// returns false otherwise.	
	bool EndOfFile();

	int	Flush();

	// Get total size of the file
	virtual long GetSize();

	// Do file close, an application should call Release () if this object is multiply referenced.
	// If the application chooses to call this directly, instead of Release (),
	// it's application's responsibility to delete this object.
	virtual bool	Close();

	// Special function only for Unicode file
	// All file content is loaded into a Wild String buffer object.
	EFileLoadResult GetUTFContent( StringW &strBuffer);

private:
	void		*m_fp;

	// Unicode type for Text File
	#define HE_ANSI			0
	#define HE_UTF_8		1
	#define HE_UTF_16BE		2
	#define HE_UTF_16LE		3

	uint8		m_bUnicodeType;
};

//----------------------------------------------------------------------

class HV_Core_API FileMemory : public FileBase
{
public:
	// Open a file and load all contents in the memory
	// Then Close the file
	static FileMemory* Open (const tchar* szPath);

	FileMemory ();
	~FileMemory () {}

	EFileLoadResult	LoadInMemory (FileHandle *);

	uint8* GetMemory () { return m_pMem; }

	// Get total size of the file, or memory size
	virtual long GetSize () { return m_lSize; }

	// Do file close, an application should call Release () if this object is multiply referenced.
	// If the application chooses to call this directly, instead of Release (),
	// it's application's responsibility to delete this object.
	virtual bool	Close ();

private:
	uint8		*m_pMem;	// ptr to a memory store file content
	long		m_lSize;	// memory size
};

} // End of namespace hive

#endif // FILEHANDLE_H
