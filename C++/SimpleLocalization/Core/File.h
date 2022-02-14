/**
* @file     File.h
* @author   Steve Tsai
* @version  1.0
*
* @section  LICENSE
*
* (C) 2010 XPEC Entertainment Inc. All rights reserved.
*
* @section	Description
*
* File: for application to use
*
*/

#ifndef HIVE_FILE_H
#define HIVE_FILE_H

#include "Core/FileHandle.h"
#include "Core/FileSystem.h"

namespace hive
{

class HV_Core_API File
{
public:
	/* 
	szFile 因為要拿來當作檔案共用搜尋的索引, 越短越好, 盡量別加入 path, 僅 filename 最有效率
	*/
	bool Open (const char* szFile, const uint32 Mode);

private:
	FileHandle *m_phFile;
};

} // End of namespace hive


#endif // End of HIVE_FILE_H
