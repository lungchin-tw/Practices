#ifndef JSONLOADER_H_
#define JSONLOADER_H_

#include "JsonNode.h"

namespace hive
{

#pragma warning( push )
#pragma warning( disable: 4100 )

class IJsonLoader : public IJsonNode
{
public:
	virtual bool Reload()													{return false;}
	virtual bool LoadFile(const tchar * FilePath, bool bShowError = true)	{return false;}
	virtual bool LoadByString(const char* Str, bool bShowError = true)		{return false;}
	virtual bool LoadByString(const wchar_t* Str, bool bShowError = true)	{return false;}
	virtual void SaveFile(bool bPretty = true, bool bWithBOM = true, bool bSort = false)					{}
	virtual void SaveFile(const tchar * path, bool bPretty = true, bool bWithBOM = true, bool bSort = false){}
	virtual IJsonNode & GetRootNode()										{return *this;}
	virtual StringT GetFileName()                                           {return StringT();}
	virtual StringT GetPathName()                                           {return StringT();}
};

#pragma warning( pop )

}//hive
#endif