/**
*
* @file     LogManager.h
* @author   Steve Tsai
* @version  1.0
*
* @section  LICENSE
*
* (C) 2010 XPEC Entertainment Inc. All rights reserved.
*
* @section	Description
*
* LogManager
*
*/

#ifndef HIVE_LOGMANAGER_H
#define HIVE_LOGMANAGER_H

namespace hive
{

class HV_Core_API LogManager
{
public:
	// 1. New a Log Manager object, and Get singleton object
	//
	static LogManager& GetSingleton();
	static LogManager* GetSingletonPtr();

public:
	LogManager();
	~LogManager();

	// 2. Create a Log file
	Log* CreateLog(const StringT &name, bool defaultLog = false, bool bDebugOut = false);

	/** 3. Sets the passed in log as the default log.
	@returns The previous default log.
	*/

	//Log* SetDefaultLog(Log *pNewDefault);
	Log* GetDefaultLog() { return m_pDefaultLog; }

	// Retrieves a log managed by this class.

	Log* FindLog(const StringT &name);

	// 4. Log a message to the default log.

	void LogMessage(const StringA &msg, ELogMsgLevel lml = LML_NORMAL, bool bDebug = false);
	void LogMessage(const StringW &msg, ELogMsgLevel lml = LML_NORMAL, bool bDebug = false);

	// Closes and removes a log file.

	void DestroyLog(Log* log);

	void DestroyLog(const StringT& name);

private:
	//--------------------------------------------------------------------------
	/// @brief Copy constructor, avoid to be called
	/// 
	//// @param [in] rhs LogManager to copy from
	//--------------------------------------------------------------------------
	LogManager( const LogManager& rhs ); 

private:
	/// The default log that the log messages write to.
	Log	*m_pDefaultLog;

	// log file map <Key, Value> file name is the key
	typedef Map<StringT, Log *> LogFileMap;

	LogFileMap	m_mapLogs;
};

extern "C"
{
	// 1. New a Log Manager object, and Get singleton object
	HV_Core_API LogManager& LogManagerGetInstance();
};

}  // End of namespace hive

#endif // End of HIVE_LOGMANAGER_H