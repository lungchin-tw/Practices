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
	szFile �]���n���ӷ�@�ɮצ@�ηj�M������, �V�u�V�n, �ɶq�O�[�J path, �� filename �̦��Ĳv
	*/
	bool Open (const char* szFile, const uint32 Mode);

private:
	FileHandle *m_phFile;
};

} // End of namespace hive


#endif // End of HIVE_FILE_H
