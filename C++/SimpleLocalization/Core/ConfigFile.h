/**
*
* @file     ConfigFile.h
* @author   Steve Tsai
* @version  1.0
*
* @section  LICENSE
*
* (C) 2010 XPEC Entertainment Inc. All rights reserved.
*
* @section	Description
*
* Confige File: Class for loading settings from a text file.
*				This class is designed to parse a simple file containing
*				key/value pairs, mainly for use in configuration settings.
*				No multiple values per key are allowed.
*
*				By default the key/values pairs are tokenised based on a
*				separator of Tab, the colon (:) or equals (=) character. Each
*				key - value pair must end in a carriage return.
*
*				Settings can be optionally grouped in sections, Ex. [SectionName]. 
*
* Usage:		Call FileManager::Open ()
*				Call ConfigFile::GetValue ()
*/

#ifndef HIVE_CONFIG_FILE_H__
#define HIVE_CONFIG_FILE_H__

#include "Core/FileHandle.h"

namespace hive
{

class HV_Core_API ConfigFile :public FileBase
{
public:
	// 1. Open Config file
	static ConfigFile* Open(const tchar* szPath);

	ConfigFile();
	~ConfigFile();

	// 2. Parse the content with key value seperators
	bool Parse(const StringT &seps = HV_T("\t:="));

	// 3. Gets the first value from the file with the named key. 
	// @param key			The name of the value
	// @param section		The name of the section it must be in (if any)
	// @param defaultValue	The value to return if the setting is not found
	//
	StringT GetValue(const StringT &key, 
						 const StringT &section = HV_T(""), 
						 const StringT &defaultValue =  HV_T("")) const;

	virtual long GetSize();
	virtual bool	Close() { return Clear (); }

	bool Clear();

private:
	// a map of <Key / Value> pair settings is a section.
	typedef Map<StringT, StringT>	Section;
	typedef Section::Iterator		SettingIterator;

	// a config file comprises a group of sections
	typedef Map<StringT, Section *>	SectionMap;
	typedef SectionMap::Iterator	SectionIterator;

	// Get an iterator to traverse all avaiable Sections.
	SectionIterator GetSectionIterator();

	// Get an iterator to traverse all avaiable Settings for a specific section
	SettingIterator GetSettingIterator(const StringT &section);

	SectionMap	m_mapSections;

	StringT		m_seps;
	long		m_lSize;
	FileHandle	*m_pHandle;
};

} // End of namespace hive

#endif  // HIVE_CONFIG_FILE_H__
