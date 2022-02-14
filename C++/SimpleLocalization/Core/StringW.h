/**
*
* @file     StringW.h
* @author   Shawn Hsiao
* @version  1.0
*
* @section  LICENSE
*
* (C) 2009 XPEC Entertainment Inc. All rights reserved.
*
* @section	Description
*
* Wide char string class
*
*/

#ifndef HIVE_STRING_W_H
#define HIVE_STRING_W_H


#define HE_STRING_INIT_SIZE 50

namespace hive
{

class HV_Core_API StringW
{    
public:
    //--------------------------------------------------------------------------------------
    /// @brief Constructor
    /// 
    /// @param [in] iInitSize Initial number of characters to allocate
    //--------------------------------------------------------------------------------------
    StringW( uint iInitSize = HE_STRING_INIT_SIZE );

    //--------------------------------------------------------------------------------------
    /// @brief Copy constructor
    /// 
    /// @param [in] s C-style NULL terminated string to copy from
    //--------------------------------------------------------------------------------------
    StringW( const wchar* s );

    //--------------------------------------------------------------------------------------
    /// @brief Copy constructor
    /// 
    /// @param [in] s String to copy from
    //--------------------------------------------------------------------------------------
    StringW( const StringW& rhs );

    //--------------------------------------------------------------------------------------
    /// @brief Destructor
    //--------------------------------------------------------------------------------------
    ~StringW();

public:
    //--------------------------------------------------------------------------------------
    /// @brief Resize to contain specified number of characters, so a GetLength() call immediately
    ///        after this function returns the new size
    /// 
    /// @param [in] iSize New number of characters
    //--------------------------------------------------------------------------------------
    void Resize( uint iSize );

    //--------------------------------------------------------------------------------------
    /// @brief Resize to contain specified number of characters, so a GetLength() call immediately
    ///        after this function returns the new size
    /// 
    /// @param [in] iSize New number of characters
    /// 
    /// @param [in] padding If the new size specified is larger the current size, this is used to pad
    ///                     characters newly created  
    //--------------------------------------------------------------------------------------
    void Resize( uint iSize, const wchar& padding );

    //--------------------------------------------------------------------------------------
    /// @brief Get number of characters of string, note that this does NOT include the NULL character
    /// 
    /// @return Number of characters in string
    //--------------------------------------------------------------------------------------
    HV_INLINE uint GetLength() const { return m_iLength; };

    //--------------------------------------------------------------------------------------
    /// @brief Get number of reserved characters
    /// 
    /// @return Number of reserved characters
    //--------------------------------------------------------------------------------------
    HV_INLINE uint32 GetReservedSize() const { return m_iReservedSize; };
 
    //--------------------------------------------------------------------------------------
    /// @brief Reserve characters, only work when the passed size is larger than current one
    /// 
    /// @param [in] iSize Number of characters to reserve
    /// 
    /// @return True on success
    //--------------------------------------------------------------------------------------
    bool Reserve( uint32 iSize );

    //--------------------------------------------------------------------------------------
    /// @brief Make current string an empty string
    //--------------------------------------------------------------------------------------
    void EmptyString();

    //--------------------------------------------------------------------------------------
    /// @brief Access a character, index must be within string's length
    ///
    /// @param [in] iIndex Index to character, start from zero
    /// 
    /// @return Reference to the character
    //--------------------------------------------------------------------------------------
    HV_INLINE wchar& operator[] ( uint32 iIndex ) { return m_pBuffer[iIndex]; };

    //--------------------------------------------------------------------------------------
    /// @brief Access a character, index must be within string's length
    ///
    /// @param [in] iIndex Index to character, start from zero
    /// 
    /// @return Reference to the character
    //--------------------------------------------------------------------------------------
    HV_INLINE const wchar& operator[] ( uint32 iIndex ) const { return m_pBuffer[iIndex]; };

    //--------------------------------------------------------------------------------------
    /// @brief This function is to simulate C-style NULL terminated string
    ///
    /// @return Pointer to the first character in string
    //--------------------------------------------------------------------------------------
    HV_INLINE operator       wchar * () { return m_pBuffer; };

    //--------------------------------------------------------------------------------------
    /// @brief This function is to simulate C-style NULL terminated string
    ///
    /// @return Pointer to the first character in string
    //--------------------------------------------------------------------------------------
    HV_INLINE operator const wchar * () const { return m_pBuffer; };

    //--------------------------------------------------------------------------------------
    /// @brief Get C-style NULL terminated string
    ///
    /// @return Pointer to the first character in string
    //--------------------------------------------------------------------------------------
    HV_INLINE wchar* CString() { return m_pBuffer; };

    //--------------------------------------------------------------------------------------
    /// @brief Get C-style NULL terminated string
    ///
    /// @return Pointer to the first character in string
    //--------------------------------------------------------------------------------------
    HV_INLINE const wchar* CString() const { return m_pBuffer; };
  
    //--------------------------------------------------------------------------------------
    /// @brief Copy operator
    /// 
    /// @param [in] rhs String to copy from
    //--------------------------------------------------------------------------------------
    void operator = (  const StringW& rhs );

    //--------------------------------------------------------------------------------------
    /// @brief Copy operator
    /// 
    /// @param [in] rhs String to copy from
    //--------------------------------------------------------------------------------------
    void operator = (  const wchar* s );

    //--------------------------------------------------------------------------------------
    /// @brief Assign a sub string to current string
    /// 
    /// @param [in] rhs   String to copy from
    /// @param [in] iStar Index of the start character of the substring
    /// @param [in] iEnd  Index of the end character of the substring
    //--------------------------------------------------------------------------------------
    void Assign(  const StringW& rhs, 
                  uint iStar = 0, uint iEnd = 0xFFFFFFFF );

    //--------------------------------------------------------------------------------------
    /// @brief Assign a sub string to current string
    /// 
    /// @param [in] s     C-style string to copy from
    /// @param [in] iStar Index of the start character of the substring
    /// @param [in] iEnd  Index of the end character of the substring
    //--------------------------------------------------------------------------------------
    void Assign(  const wchar* s, 
                  uint iStar = 0,  uint iEnd = 0xFFFFFFFF );

    //--------------------------------------------------------------------------------------
    /// @brief Append string
    /// 
    /// @param [in] rhs String to append    
    //--------------------------------------------------------------------------------------
    void operator += (  const StringW& rhs );

    //--------------------------------------------------------------------------------------
    /// @brief Append string
    /// 
    /// @param [in] s C-style string to append    
    //--------------------------------------------------------------------------------------
    void operator += (  const wchar* s );

    //--------------------------------------------------------------------------------------
    /// @brief Append character
    /// 
    /// @param [in] c Character to append    
    //--------------------------------------------------------------------------------------
    void operator += (  const wchar c );

	//--------------------------------------------------------------------------------------
	/// @brief Add 2 strings
	/// 
	/// @param [in] rhs String to add
	//--------------------------------------------------------------------------------------
	StringW  operator + (  const StringW &rhs ) const;

    //--------------------------------------------------------------------------------------
    /// @brief Append a sub string to current string
    /// 
    /// @param [in] rhs   String to append
    /// @param [in] iStar Index of the start character of the substring
    /// @param [in] iEnd  Index of the end character of the substring
    //--------------------------------------------------------------------------------------
    void Append( const StringW& rhs,
                  uint iStar = 0,  uint iEnd = 0xFFFFFFFF );

    //--------------------------------------------------------------------------------------
    /// @brief Append a sub string to current string
    /// 
    /// @param [in] s     C-style string to append
    /// @param [in] iStar Index of the start character of the substring
    /// @param [in] iEnd  Index of the end character of the substring
    //--------------------------------------------------------------------------------------
    void Append( const wchar* s,
                  uint iStar = 0, uint iEnd = 0xFFFFFFFF );    

    //--------------------------------------------------------------------------------------
    /// @brief Comparison operator, it treats string as bit sequence to compare
    /// 
    /// @param [in] rhs String to compare
    /// 
    /// @return True if equal
    //--------------------------------------------------------------------------------------
    bool operator == ( const StringW& rhs ) const;

    //--------------------------------------------------------------------------------------
    /// @brief Comparison operator, it treats string as bit sequence to compare
    /// 
    /// @param [in] rhs C-Style string to compare
    /// 
    /// @return True if equal
    //--------------------------------------------------------------------------------------
    bool operator == ( const wchar* rhs ) const;

    //--------------------------------------------------------------------------------------
    /// @brief Comparison operator, it treats string as bit sequence to compare
    /// 
    /// @param [in] rhs String to compare
    /// 
    /// @return True if not equal
    //--------------------------------------------------------------------------------------
    bool operator != ( const StringW& rhs ) const;

    //--------------------------------------------------------------------------------------
    /// @brief Comparison operator, it treats string as bit sequence to compare
    /// 
    /// @param [in] rhs C-style string to compare
    /// 
    /// @return True if not equal
    //--------------------------------------------------------------------------------------
    bool operator != ( const wchar* rhs ) const;

    //--------------------------------------------------------------------------------------
    /// @brief Comparison operator, it treats string as bit sequence to compare
    /// 
    /// @param [in] rhs String to compare
    /// 
    /// @return True if less
    //--------------------------------------------------------------------------------------
    bool operator <  ( const StringW& rhs ) const;

    //--------------------------------------------------------------------------------------
    /// @brief Comparison operator, it treats string as bit sequence to compare
    /// 
    /// @param [in] rhs C-style string to compare
    /// 
    /// @return True if less
    //--------------------------------------------------------------------------------------
    bool operator <  ( const wchar* rhs ) const;

    //--------------------------------------------------------------------------------------
    /// @brief Comparison operator, it treats string as bit sequence to compare
    /// 
    /// @param [in] rhs String to compare
    /// 
    /// @return True if less equal
    //--------------------------------------------------------------------------------------
    bool operator <= ( const StringW& rhs ) const;

    //--------------------------------------------------------------------------------------
    /// @brief Comparison operator, it treats string as bit sequence to compare
    /// 
    /// @param [in] rhs C-style string to compare
    /// 
    /// @return True if less equal
    //--------------------------------------------------------------------------------------
    bool operator <= ( const wchar* rhs ) const;

    //--------------------------------------------------------------------------------------
    /// @brief Comparison operator, it treats string as bit sequence to compare
    /// 
    /// @param [in] rhs String to compare
    /// 
    /// @return True if greater
    //--------------------------------------------------------------------------------------
    bool operator > ( const StringW& rhs ) const;

    //--------------------------------------------------------------------------------------
    /// @brief Comparison operator, it treats string as bit sequence to compare
    /// 
    /// @param [in] rhs C-Style string to compare
    /// 
    /// @return True if greater
    //--------------------------------------------------------------------------------------
    bool operator >  ( const wchar* rhs ) const;

    //--------------------------------------------------------------------------------------
    /// @brief Comparison operator, it treats string as bit sequence to compare
    /// 
    /// @param [in] rhs String to compare
    /// 
    /// @return True if greater equal
    //--------------------------------------------------------------------------------------
    bool operator >= ( const StringW& rhs ) const;

    //--------------------------------------------------------------------------------------
    /// @brief Comparison operator, it treats string as bit sequence to compare
    /// 
    /// @param [in] rhs C-style string to compare
    /// 
    /// @return True if greater equal
    //--------------------------------------------------------------------------------------
    bool operator >= ( const wchar* rhs ) const;

    //--------------------------------------------------------------------------------------
    /// @brief Insert a sub string to current string
    /// 
    /// @param [in] iPos  Index to current string to insert
    /// @param [in] s     String to insert
    /// @param [in] iStar Index of the start character of the substring
    /// @param [in] iEnd  Index of the end character of the substring
    //--------------------------------------------------------------------------------------
    void Insert(  uint iPos, const StringW& s, uint iStart = 0, uint iEnd = 0xFFFFFFFF);    

    //--------------------------------------------------------------------------------------
    /// @brief Insert a sub string to current string
    /// 
    /// @param [in] iPos  Index to current string to insert
    /// @param [in] s     C-style string to insert
    /// @param [in] iStar Index of the start character of the substring
    /// @param [in] iEnd  Index of the end character of the substring
    //--------------------------------------------------------------------------------------
    void Insert( uint iPos, const wchar* s, uint iStart = 0, uint iEnd = 0xFFFFFFFF );

    //--------------------------------------------------------------------------------------
    /// @brief Replace a sub string to current string
    /// 
    /// @param [in] iFrom Index to the start character of current substring to be replaced
    /// @param [in] iTo   Index to the end character of current substring to be replaced
    /// @param [in] s     String to replace
    /// @param [in] iStar Index of the start character of the substring to replace
    /// @param [in] iEnd  Index of the end character of the substring to replace
    //--------------------------------------------------------------------------------------
    void Replace(  uint iFrom,  uint iTo, 
                   const StringW& s,
                   uint iStart = 0,  uint iEnd = 0xFFFFFFFF );

    //--------------------------------------------------------------------------------------
    /// @brief Replace a sub string to current string
    /// 
    /// @param [in] iFrom Index to the start character of current substring to be replaced
    /// @param [in] iTo   Index to the end character of current substring to be replaced
    /// @param [in] s     C-style String to replace
    /// @param [in] iStar Index of the start character of the substring to replace
    /// @param [in] iEnd  Index of the end character of the substring to replace
    //--------------------------------------------------------------------------------------
    void Replace(  uint iFrom,  uint iTo, 
                   const wchar* s,
                   uint iStart = 0,  uint iEnd = 0xFFFFFFFF );

	//--------------------------------------------------------------------------------------
	/// @brief Replace a sub string to current string
	/// 
	/// @param [in] from C-style String to be replaced	
	/// @param [in] to   C-style String to replace	
	//--------------------------------------------------------------------------------------
	void Replace( const StringW& from, const StringW& to );

    //--------------------------------------------------------------------------------------
    /// @brief Erase a substring 
    ///
    /// @param [in] iStar Index of the start character of the substring to erase
    /// @param [in] iEnd  Index of the end character of the substring to erase
    //--------------------------------------------------------------------------------------
    void Erase(  uint iStart,  uint iEnd );

    //--------------------------------------------------------------------------------------
    /// @brief Find if current string has a substring from left to right
    ///
    /// @param [in]  s       String to match
    /// @param [out] iOutPos If found, this stores index of the start character of the substring,
    ///                      otherwise it's not set
    /// @param [in]  iFrom   Index of character to start search from
    ///
    /// @return True if found
    //--------------------------------------------------------------------------------------
    bool Find(  const StringW& s,  uint& iOutPos,  uint iFrom = 0 ) const;    

    //--------------------------------------------------------------------------------------
    /// @brief Find if current string has a substring from left to right
    ///
    /// @param [in]  s       C-style string to match
    /// @param [out] iOutPos If found, this stores index of the start character of the substring,
    ///                      otherwise it's not set
    /// @param [in]  iFrom   Index of character to start search from
    /// 
    /// @return True if found
    //--------------------------------------------------------------------------------------
    bool Find(  const wchar* s,  uint& iOutPos,  uint iFrom = 0 ) const;

    //--------------------------------------------------------------------------------------
    /// @brief Find if current string has a character from left to right
    ///
    /// @param [in]  c       Character to match
    /// @param [out] iOutPos If found, this stores index of the character, otherwise it's not set    
    /// @param [in]  iFrom   Index of character to start search from
    /// 
    /// @return True if found
    //--------------------------------------------------------------------------------------
    bool Find(  const wchar c,   uint& iOutPos,  uint iFrom = 0 ) const;

    //--------------------------------------------------------------------------------------
    /// @brief Find if current string has a substring from right to left
    ///
    /// @param [in]  s       String to match
    /// @param [out] iOutPos If found, this stores index of the start character of the substring,
    ///                      otherwise it's not set
    /// @param [in]  iFrom   Index of character to start search from
    ///
    /// @return True if found
    //--------------------------------------------------------------------------------------
    bool RFind(  const StringW& s,  uint& iOutPos,  uint iFrom = 0xFFFFFFFF ) const;

    //--------------------------------------------------------------------------------------
    /// @brief Find if current string has a substring from right to left
    ///
    /// @param [in]  s       C-style string to match
    /// @param [out] iOutPos If found, this stores index of the start character of the substring,
    ///                      otherwise it's not set
    /// @param [in]  iFrom   Index of character to start search from
    /// 
    /// @return True if found
    //--------------------------------------------------------------------------------------
    bool RFind(  const wchar* s,  uint& iOutPos,  uint iFrom = 0xFFFFFFFF ) const;

    //--------------------------------------------------------------------------------------
    /// @brief Find if current string has a character from right to left
    ///
    /// @param [in]  c       Character to match
    /// @param [out] iOutPos If found, this stores index of the character, otherwise it's not set    
    /// @param [in]  iFrom   Index of character to start search from
    /// 
    /// @return True if found
    //--------------------------------------------------------------------------------------
    bool RFind(  const wchar c,   uint& iOutPos,  uint iFrom = 0xFFFFFFFF ) const;

    //--------------------------------------------------------------------------------------
    /// @brief Find first appearance of any character in string passed in from left to right
    ///
    /// @param [in]  s       String which contains characters to match
    /// @param [out] iOutPos If found, this stores index of the character, otherwise it's not set    
    /// @param [in]  iFrom   Index of character to start search from
    /// 
    /// @return True if found
    //--------------------------------------------------------------------------------------
    bool FindFirstOf(  const StringW& s,  uint& iOutPos,  uint iFrom = 0  ) const;

    //--------------------------------------------------------------------------------------
    /// @brief Find first appearance of any character in string passed in from left to right
    ///
    /// @param [in]  s       C-style string which contains characters to match
    /// @param [out] iOutPos If found, this stores index of the character, otherwise it's not set    
    /// @param [in]  iFrom   Index of character to start search from
    /// 
    /// @return True if found
    //--------------------------------------------------------------------------------------
    bool FindFirstOf(  const wchar* s,  uint& iOutPos,  uint iFrom = 0  ) const;

    //--------------------------------------------------------------------------------------
    /// @brief Find first appearance of any character in string passed in from right to left
    ///
    /// @param [in]  s       String which contains characters to match
    /// @param [out] iOutPos If found, this stores index of the character, otherwise it's not set    
    /// @param [in]  iFrom   Index of character to start search from
    /// 
    /// @return True if found
    //--------------------------------------------------------------------------------------
    bool FindLastOf(  const StringW& s,  uint& iOutPos,  uint iFrom = 0xFFFFFFFF  ) const;

    //--------------------------------------------------------------------------------------
    /// @brief Find first appearance of any character in string passed in from right to left
    ///
    /// @param [in]  s       C-style string which contains characters to match
    /// @param [out] iOutPos If found, this stores index of the character, otherwise it's not set    
    /// @param [in]  iFrom   Index of character to start search from
    /// 
    /// @return True if found
    //--------------------------------------------------------------------------------------
    bool FindLastOf(  const wchar* s,  uint& iOutPos,  uint iFrom = 0xFFFFFFFF  ) const;    

    //--------------------------------------------------------------------------------------
    /// @brief Make all ascii characters in string to upper case
    //--------------------------------------------------------------------------------------
    void ToUpper();

    //--------------------------------------------------------------------------------------
    /// @brief Make all ascii characters in string to lower case
    //--------------------------------------------------------------------------------------
    void ToLower();

    //--------------------------------------------------------------------------------------
    /// @brief Same as sprintf function, users must make enough memory to hold the result before
    ///        calling this function, not enough memory makes the resulting string get chopped off
    /// 
    /// @param s   Format string
    /// @param ... Optional arguments
    //--------------------------------------------------------------------------------------
    uint Format(  const wchar* s, ... );

	/// Added by steve 2010/8/5, begin   ///////////////////////////////////////////////////
	//--------------------------------------------------------------------------------------
	/// @brief Trim out  all white space, tab, new line, and carriage return from 2 sides
	///
	/// @param [in]  left or right side of the string
	//--------------------------------------------------------------------------------------
	void Trim(bool left = true, bool right = true, const StringW delims = L" \t\r\n");

	//--------------------------------------------------------------------------------------
	/// @brief Find first appearance of not any character in string passed in from left to right
	///
	/// @param [in]  s       String which contains characters to match
	/// @param [out] iOutPos If found (return true), this stores index of the character not any char,
	///						 otherwise it's not set.    
	/// @param [in]  iFrom   Index of character to start search from
	/// 
	/// @return True if found
	//--------------------------------------------------------------------------------------
	bool FindFirstNotOf(  const StringW& s,  uint& iOutPos,  uint iFrom = 0) const;

	//--------------------------------------------------------------------------------------
	/// @brief Find first appearance of not any character in string passed in from right to left
	///
	/// @param [in]  s       String which contains characters to match
	/// @param [out] iOutPos If found (return true), this stores index of the character not any char,
	///						 otherwise it's not set.    
	/// @param [in]  iFrom   Index of character to start search from
	/// 
	/// @return True if found
	//--------------------------------------------------------------------------------------
	bool FindLastNotOf(  const StringW& s,  uint& iOutPos,  uint iFrom = 0xFFFFFFFF) const;
	/// Added by steve End   /////////////////////////////////////////////////////////////

	//--------------------------------------------------------------------------------------
	/// @brief Find sub string from start to end-1, ex: abc.txt SubString(0,4) = abc
	///
	/// @param [in]  start   start index for substring
	/// @param [in]  end     end index for substring
	/// @param [out] outStr  return string
	/// 
	/// @return True if found
	//--------------------------------------------------------------------------------------
	void SubString( uint start, uint end, StringW& outStr );

	//--------------------------------------------------------------------------------------
	/// @brief Find sub string from start to end, ex: abc.txt SubStr(0,3) = abc
	///
	/// @param [in]  start   start index for substring
	/// @param [in]  end     end index for substring
	/// @param [out] outStr  return string
	/// 
	/// @return True if found
	//--------------------------------------------------------------------------------------
	void SubStr( uint start, uint end, StringW& outStr );
	
	//--------------------------------------------------------------------------------------
	int Compare(  const wchar* s ) const;

protected:
    //--------------------------------------------------------------------------------------
    int Compare(  const StringW& s1,  const StringW& s2 ) const;

    //--------------------------------------------------------------------------------------
    bool Match(  const wchar* s1,  const wchar* s2,  uint iSize ) const;

    //--------------------------------------------------------------------------------------
    void ReplaceCommon(  uint iFrom,  uint iTo, 
                         const wchar* s,  uint iRLength,
                         uint iStart,  uint iEnd );

    //--------------------------------------------------------------------------------------
    void InsertCommon(  uint iPos,  const wchar* s,  uint iStart,  uint iEnd );

    //--------------------------------------------------------------------------------------
    void GrowBuffer(  uint iNewSize );

    //--------------------------------------------------------------------------------------
    void GrowBuffer(  uint iNewSize,  const wchar* s,  int iCount );

    //--------------------------------------------------------------------------------------
    uint StrLength(  const wchar* s ) const;

protected:
    uint m_iLength; // not include NULL character
    uint m_iReservedSize;
    wchar*   m_pBuffer;
};

}  // End of namespace hive

/// Constant blank string, to avoid export dll, place static variable outside of exported class
//extern HV_Core_API StringW HE_sBLANKStringW;


#endif  // End of HIVE_STRING_W_H
