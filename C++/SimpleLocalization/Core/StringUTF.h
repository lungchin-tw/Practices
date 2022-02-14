/**
*
* @file     StringUTF.h
* @author   Steve Tsai
* @version  1.0
*
* @section  LICENSE
*
* (C) 2010 XPEC Entertainment Inc. All rights reserved.
*
* @section	Description
*
* UTF string class
*
*/

#ifndef HIVE_STRING_UTF_H
#define	HIVE_STRING_UTF_H

namespace hive
{

class HV_Core_API StringUTF : public StringW
{
public:
	StringUTF ();
	~StringUTF ();

	//	- char* (UTF-8)
	//	- wstring (autodetected UTF-16)
	//	- wchar_t* (autodetected UTF-16)

	// a single 32-bit Unicode character
	typedef uint32 HE_UNICODE_CHAR;

	// a single UTF-16 code point
	typedef uint16 HE_CODE_POINT;

	static bool UTF8StartChar( uchar cp );

	static uint8 UTF8CharLength( uchar cp );

	static uint8 UTF8CharLength( HE_UNICODE_CHAR uc );

private:

	//! buffer data type identifier
	enum EBufferType 
	{
		BUFFER_TYPE_NONE,
		BUFFER_TYPE_STRING,
		BUFFER_TYPE_WSTRING,
		BUFFER_TYPE_UTF32STRING
	};
	
	EBufferType	m_bufferType; // identifies the data type held in m_buffer
	uint		m_bufferSize; // size of the CString buffer

	// multi-purpose buffer used everywhere we need a throw-away buffer
	union 
	{
		mutable void	*mVoidBuffer;
		mutable char	*mStrBuffer;
		mutable wchar	*mWStrBuffer;
		mutable uint32	*mUTF32StrBuffer;
	}
	m_buffer;
};

} // End of namespace hive

#endif // End of HIVE_STRING_UTF_H
