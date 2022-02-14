/**
*
* @file     Log.h
* @author   Steve Tsai
* @version  1.0
*
* @section  LICENSE
*
* (C) 2010 XPEC Entertainment Inc. All rights reserved.
*
* @section	Description
*
* Log
*
*/

#ifndef HIVE_LOG_H
#define HIVE_LOG_H

namespace hive
{

// The importance of a logged message.

enum ELogMsgLevel
{
	LML_DETAIL  = 0,		// start with "   "
	LML_NORMAL  = 1,		// start with "---"
	LML_WARNING = 2,		// start with "***"
	LML_ERROR   = 3,		// start with "!!!"
};

/** @remarks derive this class and register to the Log to listen to log messages */

class HV_Core_API LogListener
{
public:
	virtual ~LogListener() {};

	/**
	@remarks
	This is called whenever the log receives a message and is about to write it out
	@param bDebug
	If we are printing to the console or not
	@param logName
	the name of this log (so you can have several listeners for different logs, and identify them)
	*/
	virtual void MessageLogged(const char *pMsg, ELogMsgLevel lv, bool bDebug, const tchar *pLogName) = 0;
	virtual void MessageLogged(const wchar *pMsg, ELogMsgLevel lv, bool bDebug, const tchar *pLogName) = 0;
};

class HV_Core_API Log : public FileHandle
{
public:
	Log (void *fp = 0);
	~Log ();

	static Log* Open(const tchar *szPath, const FileHandle::EFileOpen_Type uMoe);

	// Messages are output only level >= Threshold, 
	// default all messages are output.
	static void OutputThreshold(ELogMsgLevel eLv = LML_DETAIL);

	/** Log a message to the debugger and to log file (the default is "<code>Game.log</code>"),
	*/
	void LogMessage( const StringW &msg, ELogMsgLevel eLv = LML_NORMAL, bool bDebug = false );
	void LogMessage( const StringA &msg, ELogMsgLevel eLv = LML_NORMAL, bool bDebug = false );

	/// whether debug output is enabled for this log
	void SetDebugOutputEnabled(bool bDebugOut) { m_bDebugOut = bDebugOut; }

	bool IsDebugOutputEnabled() const { return m_bDebugOut; }

	/// whether time stamps are printed for this log
	void SetTimeStampEnabled(bool bTimeStamp) { m_bTimeStamp = bTimeStamp; }

	bool IsTimeStampEnabled() const { return m_bTimeStamp; }

	/**
	@remarks	Register a listener to this log
	@param		A valid listener derived class
	*/
	void AddListener(LogListener *listener);

	bool RemoveListener(LogListener *listener);

protected:
	bool			m_bDebugOut;
	bool			m_bTimeStamp;

	typedef Array<LogListener *>  LogListenerList;
	LogListenerList		m_arrListeners;
};

} // End of namespace hive

#endif // End of HIVE_LOG_H
