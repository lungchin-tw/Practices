#ifndef RAPIDJSONLOADER_H_
#define RAPIDJSONLOADER_H_
#include "RapidJsonNode.h"

namespace hive
{

template <typename Encoding>
class RapidJsonLoader : public RapidJsonNode<Encoding>
{
public:
	typedef typename Encoding::Value Value;
	typedef typename Encoding::Document Document;
	typedef typename Encoding::CH CH;
	typedef typename Encoding::string string;
	RapidJsonLoader()
	{
		Init();
	}

	virtual ~RapidJsonLoader()
	{
		if(m_Value)
			HV_DeallocDel( m_Value );
	}

	void Init()
	{
		if(m_Value)
			HV_DeallocDel( m_Value );

		Value*	pValue = HV_AllocNew( Document, Document);
		InitNode(pValue, static_cast< Document * > (pValue), GetType());

		SetToObjectNode(); // default root is object
	}

	virtual bool Reload()
	{
		Init();
		return Encoding::LoadFile(m_sPathName.CString(), static_cast< Document * > (m_Value), true);
	}

	bool LoadFile(const tchar * FilePath, bool bShowError = true)
	{
		m_sPathName = FilePath;
		return Encoding::LoadFile(FilePath, static_cast< Document * > (m_Value), bShowError);
	}

	bool LoadByString(const CH* Str, bool bShowError = true)
	{
		return Encoding::LoadByString(Str, static_cast< Document * > (m_Value), bShowError);
	}

	void SaveFile(bool bPretty = true, bool bWithBOM = true, bool bSort = false)
	{
		RapidJsonNode<Encoding>::SaveFile(m_sPathName.CString(), bPretty, bWithBOM, bSort);
	}

	void SaveFile(const tchar * path, bool bPretty = true, bool bWithBOM = true, bool bSort = false)
	{
		RapidJsonNode<Encoding>::SaveFile(path, bPretty, bWithBOM, bSort);
	}

	IJsonNode & GetRootNode()
	{
		return *this;
	}

	//don't use this
	void SetFileName(StringT & Name)      {m_sName = Name;}
	StringT GetFileName()                 {return m_sName;}
	void SetPathName(const tchar * pName) {m_sPathName = pName;}
	StringT GetPathName()                 {return m_sPathName;}

private:
	StringT m_sName;
	StringT m_sPathName;
};

typedef RapidJsonLoader<JsonUTF16> JsonLoaderUTF16;
typedef RapidJsonLoader<JsonUTF8> JsonLoaderUTF8;

typedef RapidJsonNode<JsonUTF16> JsonNodeUTF16;
typedef RapidJsonNode<JsonUTF8> JsonNodeUTF8;
//#endif

}//hive

#endif