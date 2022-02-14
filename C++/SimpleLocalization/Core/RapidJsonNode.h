#ifndef RAPIDJSONNODE_H_
#define RAPIDJSONNODE_H_

#include "RapidJsonEncode.h"
#include "JsonLoader.h"

namespace hive
{

#pragma warning( push )
#pragma warning( disable: 4310 )

template <typename Encoding>
class JsonStringStream
{
public:	
	typedef typename Encoding::CH CH;
	typedef typename Encoding::string string;
	JsonStringStream(bool bWithBOM)
	{
		if(bWithBOM)
		{
			if(Encoding::IsUTF16())			//UTF16 must add header BOM
				_StringStream += CH(0xfeff);//UTF16 BE BOM
			else
			{
				_StringStream += CH(0xef);//UTF8 BOM
				_StringStream += CH(0xbb);
				_StringStream += CH(0xbf);
			}
		}
	}
	void Put(CH c)
	{
		if(Encoding::IsUTF16())
		{
			//add carriage return '\r'
			if(c == 0x000a)
				_StringStream += CH(0x000d);
		}
		else
		{
			//add carriage return '\r'
			if(c == 0x0a)
				_StringStream += CH(0x0d);
		}
		_StringStream += c;
	}
	void Flush()  {}
	string& str() { return _StringStream; }
private:
	string _StringStream;
};

#pragma warning( pop )

template <typename Encoding>
class RapidJsonNode : public IJsonLoader
{
public:
	typedef typename Encoding::UTF UTF;
	typedef typename Encoding::Document Document;
	typedef typename Encoding::Value Value;
	typedef typename Encoding::Member Member;
	typedef typename Encoding::CH CH;
	typedef typename Encoding::string string;

	RapidJsonNode()	: m_Value(NULL), m_Document(NULL) {}
	RapidJsonNode(Value* value, Document* root) : m_Value(value), m_Document(root) {}
	~RapidJsonNode()
	{
		for(unsigned int i = 0; i < m_VecIter.Size() ; ++i)
			HV_DeallocDel(m_VecIter[i]);

		for(unsigned int i = 0; i < m_VecNode.Size() ; ++i)
			HV_DeallocDel(m_VecNode[i]);

		for(unsigned int i = 0; i < m_VecStr.Size() ; ++i)
			HV_DeallocDel(m_VecStr[i]);
	}

	void InitNode(Value* value, Document* root, int iType)
	{
		m_Value = value;
		m_Document = root;
		SetType(iType);
	}

	//only for object type
	class Iterator : public IJsonNode::IIterator
	{
	public:
		Iterator() {}
		Iterator(Member* iter, Document* root) : m_Member(iter), m_Loader(root), m_iType(0) {}
		virtual ~Iterator()
		{
			for(unsigned int i = 0; i < m_VecNode.Size() ; ++i)
				HV_DeallocDel(m_VecNode[i]);
		}
		bool operator==(IJsonNode::IIterator & other)
		{
			return m_Member == other.getValue();
		}
		bool operator!=(IJsonNode::IIterator & other)
		{
			return m_Member != other.getValue();
		}
		IJsonNode::IIterator& operator++ ()     // ++i
        {
           ++m_Member;
           return *this;
        }
        IJsonNode::IIterator  operator++ (int)  // i++
        {
           ++m_Member;
           return *this;
        }
		const CH* Name()
		{
			return m_Member->name.GetString();
		}
		const char*    NameA()
		{
			return (const char*)m_Member->name.GetString();
		}
		const wchar_t* NameW()
		{
			return (const wchar_t*)m_Member->name.GetString();
		}
		IJsonNode & Node()
		{
			RapidJsonNode<Encoding>* pNode = HV_AllocNew( RapidJsonNode<Encoding>, RapidJsonNode<Encoding>() );
			m_VecNode.PushBack(pNode);
			pNode->InitNode(&m_Member->value, m_Loader, m_iType);
			return *pNode;
		}
		//dont't use
		void SetIter(Member* iter, Document* root, int iType)
		{
			m_Member = iter;
			m_Loader = root;
			m_iType  = iType;
		}
		//dont't use
		void* getValue()
		{
			return m_Member;
		}
	protected:
		
		Member* m_Member; // first : name, second : value
		Document* m_Loader;
		Array<RapidJsonNode<Encoding>* > m_VecNode;
		int m_iType;
	};
	//only for object type
	IJsonNode::IIterator & Begin()
	{
		if( IsObject() == false )
			assert(false);
		Iterator* pIter = HV_AllocNew( Iterator, Iterator );
		m_VecIter.PushBack(pIter);
		pIter->SetIter(m_Value->MemberBegin(), m_Document, GetType());
		return *pIter;
	}
	//only for object type
	IJsonNode::IIterator & End()
	{
		if( IsObject() == false )
			assert(false);
		Iterator* pIter = HV_AllocNew( Iterator, Iterator );
		m_VecIter.PushBack(pIter);
		pIter->SetIter(m_Value->MemberEnd(), m_Document, GetType());
		return *pIter;
	}

	IJsonNode::IIterator & Find(const CH* name)
	{
		Member* Node = m_Value->FindMember(name);
		Iterator* pIter = HV_AllocNew( Iterator, Iterator );
		m_VecIter.PushBack(pIter);
		if(Node)
			pIter->SetIter(Node, m_Document, GetType());
		else
			pIter->SetIter(m_Value->MemberEnd(), m_Document, GetType());
		return *pIter;
	}

	bool HasMember(const CH* name)
	{
		return (m_Value->FindMember(name) != NULL)? true : false;
	}

	//only for object type
	bool Get(const CH* name, const CH** ouput)
	{
		Member* Node = m_Value->FindMember(name);
		if(Node == NULL)
			return false;

		if(Node->value.IsString() == false)
			return false;

		*ouput = Node->value.GetString();
		return true;
	}

	//only for object type
	bool Get(const CH* name, string& ouput)
	{
		Member* Node = m_Value->FindMember(name);
		if(Node == NULL)
			return false;

		if(Node->value.IsString() == false)
			return false;

		ouput = Node->value.GetString();
		return true;
	}

	//only for object type
	bool Get(const CH* name, int& ouput)
	{
		Member* Node = m_Value->FindMember(name);
		if(Node == NULL)
			return false;

		if(Node->value.IsNumber() == false)
			return false;

		if(Node->value.IsInt())
			ouput = Node->value.GetInt();
		else
			ouput = (int)Node->value.GetDouble();
		return true;
	}

	//only for object type
	bool Get(const CH* name, unsigned int& ouput)
	{
		Member* Node = m_Value->FindMember(name);
		if(Node == NULL)
			return false;

		if(Node->value.IsNumber() == false)
			return false;

		if(Node->value.IsUint())
			ouput = Node->value.GetUint();
		else
			ouput = (unsigned int)Node->value.GetDouble();
		return true;
	}

	//only for object type
	bool Get(const CH* name, int64_t& ouput)
	{
		Member* Node = m_Value->FindMember(name);
		if(Node == NULL)
			return false;

		if(Node->value.IsInt64())
		{
			ouput = Node->value.GetInt64();
			return true;
		}
		return false;
	}

	//only for object type
	bool Get(const CH* name, uint64_t& ouput)
	{
		Member* Node = m_Value->FindMember(name);
		if(Node == NULL)
			return false;

		if(Node->value.IsUint64())
		{
			ouput = Node->value.GetUint64();
			return true;
		}
		return false;
	}
	
	//only for object type
	bool Get(const CH* name, float& ouput)
	{
		Member* Node = m_Value->FindMember(name);
		if(Node == NULL)
			return false;

		if(Node->value.IsNumber() == false)
			return false;

		ouput = (float)Node->value.GetDouble();
		return true;
	}

	//only for object type
	bool Get(const CH* name, double& ouput)
	{
		Member* Node = m_Value->FindMember(name);
		if(Node == NULL)
			return false;

		if(Node->value.IsNumber() == false)
			return false;

		ouput = Node->value.GetDouble();
		return true;
	}

	//only for object type
	bool Get(const CH* name, bool& ouput)
	{
		Member* Node = m_Value->FindMember(name);
		if(Node == NULL)
			return false;

		if(Node->value.IsBool() == false)
			return false;

		ouput = Node->value.GetBool();
		return true;
	}

	//only for object type
	bool Get(const CH* name, IJsonNode** ouput)
	{
		Member* Node = m_Value->FindMember(name);
		
		if(Node)
		{
			RapidJsonNode<Encoding>* pNode = HV_AllocNew( RapidJsonNode<Encoding>, RapidJsonNode<Encoding>() );
			m_VecNode.PushBack(pNode);
			*ouput = pNode;
			pNode->InitNode( &Node->value, m_Document, GetType() );
			return true;
		}
		return false;
	}

	////only for array type
	//bool GetStringArray(const CH* name, std::vector<string> & values)
	//{
	//	RapidJsonNode<Encoding> ArrayNode;
	//	if(GetMemberArray(name, ArrayNode))
	//	{
	//		values.clear();
	//		values.reserve(ArrayNode.Size());
	//		for(unsigned int i = 0; i < ArrayNode.Size(); ++i)
	//			values.push_back(string(ArrayNode[i].GetString()));

	//		return true;
	//	}
	//	return false;
	//}

	////only for array type
	//bool GetDoubleArray(const CH* name, std::vector<double> & values)
	//{
	//	RapidJsonNode ArrayNode;
	//	if(GetMemberArray(name, ArrayNode))
	//	{
	//		values.clear();
	//		values.reserve(ArrayNode.Size());
	//		for(unsigned int i = 0; i < ArrayNode.Size(); ++i)
	//			values.push_back(ArrayNode[i].GetDouble());

	//		return true;
	//	}
	//	return false;
	//}

	////only for array type
	//bool GetFloatArray(const CH* name, std::vector<float> & values)
	//{
	//	RapidJsonNode ArrayNode;
	//	if(GetMemberArray(name, ArrayNode))
	//	{
	//		values.clear();
	//		values.reserve(ArrayNode.Size());
	//		for(unsigned int i = 0; i < ArrayNode.Size(); ++i)
	//			values.push_back(ArrayNode[i].GetFloat());

	//		return true;
	//	}
	//	return false;
	//}

	////only for array type
	//bool GetIntArray(const CH* name, std::vector<int> & values)
	//{
	//	RapidJsonNode ArrayNode;
	//	if(GetMemberArray(name, ArrayNode))
	//	{
	//		values.clear();
	//		values.reserve(ArrayNode.Size());
	//		for(unsigned int i = 0; i < ArrayNode.Size(); ++i)
	//			values.push_back(ArrayNode[i].GetInt());

	//		return true;
	//	}
	//	return false;
	//}

	//only for array type
	IJsonNode& AddObjectNode()
	{
		return _AddNode(rapidjson::kObjectType);
	}

	//only for array type
	IJsonNode& AddArrayNode()
	{
		return _AddNode(rapidjson::kArrayType);
	}

	//only for object type
	IJsonNode& AddObjectNode(const CH* name)
	{
		return _AddNode(name, rapidjson::kObjectType);
	}

	//only for object type
	IJsonNode& AddArrayNode(const CH* name)
	{
		return _AddNode(name, rapidjson::kArrayType);
	}

	//only for object type, if member exist then replace it
	bool Set(const CH* name, bool input)
	{
		return _Set(name, input);
	}
	//only for object type, if member exist then replace it
	bool Set(const CH* name, int input)
	{
		return _Set(name, input);
	}
	//only for object type, if member exist then replace it
	bool Set(const CH* name, unsigned int input)
	{
		return _Set(name, input);
	}
	//only for object type, if member exist then replace it
	bool Set(const CH* name, int64_t& input)
	{
		return _Set(name, input);
	}
	bool Set(const CH* name, uint64_t& input)
	{
		return _Set(name, input);
	}
	//only for object type, if member exist then replace it
	bool Set(const CH* name, double input)
	{
		return _Set(name, input);
	}
	//only for object type, if member exist then replace it
	bool Set(const CH* name, const CH* input)
	{
		if(IsObject() == false)
			return false;

		//if(Encoding::IsUTF16())
		//	return false;
		name = NewString(name);
		input = NewString(input);

		Member* Node = m_Value->FindMember(name);
		if(Node == NULL)
			m_Value->AddMember(name, input, m_Document->GetAllocator());
		else
		{
			m_Value->RemoveMember(name);
			m_Value->AddMember(name, input, m_Document->GetAllocator());
		}

		return true;
	}

	////only for object type, if member exist then replace it
	//bool Set(const CH * name, const wchar_t * input)
	//{
	//	if(IsObject() == false)
	//		return false;

	//	if(Encoding::IsUTF16() == false)
	//		return false;

	//	Member* Node = m_Value->FindMember(name);
	//	if(Node == NULL)
	//		m_Value->AddMember(name, input, m_Document->GetAllocator());
	//	else
	//	{
	//		m_Value->RemoveMember(name);
	//		m_Value->AddMember(name, input, m_Document->GetAllocator());
	//	}

	//	return true;
	//}

	//only for array type
	bool SetArrayData(unsigned int Idx, bool input)
	{
		if(IsArray() == false)
			return false;

		if(Idx >= Size())
			return false;

		(*m_Value)[Idx].SetBool(input);
		return true;
	}

	//only for array type
	bool SetArrayData(unsigned int Idx, int input)
	{
		if(IsArray() == false)
			return false;

		if(Idx >= Size())
			return false;

		(*m_Value)[Idx].SetInt(input);
		return true;
	}

	//only for array type
	bool SetArrayData(unsigned int Idx, unsigned int input)
	{
		if(IsArray() == false)
			return false;

		if(Idx >= Size())
			return false;

		(*m_Value)[Idx].SetUint(input);
		return true;
	}

	//only for array type
	bool SetArrayData(unsigned int Idx, int64_t& input)
	{
		if(IsArray() == false)
			return false;

		if(Idx >= Size())
			return false;

		(*m_Value)[Idx].SetInt64(input);
		return true;
	}

	//only for array type
	bool SetArrayData(unsigned int Idx, uint64_t& input)
	{
		if(IsArray() == false)
			return false;

		if(Idx >= Size())
			return false;

		(*m_Value)[Idx].SetUint64(input);
		return true;
	}

	//only for array type
	bool SetArrayData(unsigned int Idx, double input)
	{
		if(IsArray() == false)
			return false;

		if(Idx >= Size())
			return false;

		(*m_Value)[Idx].SetDouble(input);
		return true;
	}

	//only for array type
	bool SetArrayData(unsigned int Idx, const CH* input)
	{
		if(IsArray() == false)
			return false;

		if(Idx >= Size())
			return false;
		
		input = NewString(input);

		(*m_Value)[Idx].SetString(input);
		return true;
	}

	//only for array type
	bool GetArrayData(unsigned int Idx, const CH** ouput)
	{
		if(IsArray() == false)
			return false;

		if(Idx >= Size())
			return false;
		
		if((*m_Value)[Idx].IsString() == false)
			return false;

		*ouput = (*m_Value)[Idx].GetString();
		return true;
	}

	//only for array type
	bool GetArrayData(unsigned int Idx, string& ouput)
	{
		if(IsArray() == false)
			return false;

		if(Idx >= Size())
			return false;
		
		if((*m_Value)[Idx].IsString() == false)
			return false;

		ouput = (*m_Value)[Idx].GetString();
		return true;
	}

	//only for array type
	bool GetArrayData(unsigned int Idx, int& ouput)
	{
		if(IsArray() == false)
			return false;

		if(Idx >= Size())
			return false;
		
		if((*m_Value)[Idx].IsInt() == false)
			return false;

		ouput = (*m_Value)[Idx].GetInt();
		return true;
	}

	//only for array type
	bool GetArrayData(unsigned int Idx, unsigned int& ouput)
	{
		if(IsArray() == false)
			return false;

		if(Idx >= Size())
			return false;

		if((*m_Value)[Idx].IsUint() == false)
			return false;

		ouput = (*m_Value)[Idx].GetUint();
		return true;
	}

	//only for array type
	bool GetArrayData(unsigned int Idx, int64_t& ouput)
	{
		if(IsArray() == false)
			return false;

		if(Idx >= Size())
			return false;
		
		if((*m_Value)[Idx].IsInt() == false)
			return false;

		ouput = (*m_Value)[Idx].GetInt64();
		return true;
	}

	//only for array type
	bool GetArrayData(unsigned int Idx, uint64_t& ouput)
	{
		if(IsArray() == false)
			return false;

		if(Idx >= Size())
			return false;

		if((*m_Value)[Idx].IsUint64() == false)
			return false;

		ouput = (*m_Value)[Idx].GetUint64();
		return true;
	}
	
	//only for array type
	bool GetArrayData(unsigned int Idx, float& ouput)
	{
		if(IsArray() == false)
			return false;

		if(Idx >= Size())
			return false;
		
		if((*m_Value)[Idx].IsNumber() == false)
			return false;

		ouput = (float)(*m_Value)[Idx].GetDouble();
		return true;
	}

	//only for array type
	bool GetArrayData(unsigned int Idx, double& ouput)
	{
		if(IsArray() == false)
			return false;

		if(Idx >= Size())
			return false;
		
		if((*m_Value)[Idx].IsNumber() == false)
			return false;

		ouput = (*m_Value)[Idx].GetDouble();
		return true;
	}

	//only for array type
	bool GetArrayData(unsigned int Idx, bool& ouput)
	{
		if(IsArray() == false)
			return false;

		if(Idx >= Size())
			return false;
		
		if((*m_Value)[Idx].IsBool() == false)
			return false;

		ouput = (*m_Value)[Idx].GetBool();
		return true;
	}

	//only for object type
	bool Erase(const CH* name)
	{
		if(IsObject() == false)
			return false;

		return m_Value->RemoveMember(name);
	}

	bool EraseAll()
	{
		if(IsArray())
		{
			m_Value->Clear();
			return true;
		}

		if(IsObject())
		{
			Iterator * Iter = static_cast<Iterator*>(&Begin());
			for(; *Iter != *static_cast<Iterator*>(&End()) ;(*Iter)++)
				m_Value->RemoveMember(Iter->Name());

			return true;
		}
		return false;
	}

	//only for array type
	bool Push(bool input)
	{
		return _Push(input);
	}
	//only for array type
	bool Push(int input)
	{
		return _Push(input);
	}
	//only for array type
	bool Push(unsigned int input)
	{
		return _Push(input);
	}
	//only for array type
	bool Push(int64_t& input)
	{
		return _Push(input);
	}
	//only for array type
	bool Push(uint64_t& input)
	{
		return _Push(input);
	}
	//only for array type
	bool Push(double input)
	{
		return _Push(input);
	}
	//only for array type
	bool Push(const CH* input)
	{
		if(IsArray() == false)
			return false;

		input = NewString(input);
		m_Value->PushBack(input, m_Document->GetAllocator());
		return true;
	}

	////only for array type
	//bool Push(const wchar_t * input)
	//{
	//	if(IsArray() == false)
	//		return false;

	//	if(Encoding::IsUTF16() == false)
	//		return false;

	//	m_Value->PushBack(input, m_Document->GetAllocator());
	//	return true;
	//}

	//only for array type
	bool Pop()
	{
		if(IsArray() == false)
			return false;
		if(Size() == 0)
			return false;

		m_Value->PopBack();
		return true;
	}

	//only for array type
	unsigned int Size()
	{
		if(IsArray())
			return m_Value->Size();
		else
			return 0;
	}

	void SetString(const CH* input)
	{
		m_Value->SetString(input);
	}
	void SetInt(int input)
	{
		m_Value->SetInt(input);
	}
	void SetUInt(unsigned int input)
	{
		m_Value->SetUint(input);
	}
	void SetInt64(int64_t& input)
	{
		m_Value->SetInt64(input);
	}
	void SetUInt64(uint64_t& input)
	{
		m_Value->SetUint64(input);
	}
	void SetDouble(double input)
	{
		m_Value->SetDouble(input);
	}
	void SetBool(bool input)
	{
		m_Value->SetBool(input);
	}
	//set node to empty object format {}
	void SetToObjectNode()
	{
		m_Value->SetObject();
	}
	//set node to empty array format []
	void SetToArrayNode()
	{
		m_Value->SetArray();
	}

	const CH* GetString()
	{
		try
		{
			if(m_Value->IsString() == false)
				throw _T("RapidJsonNode::GetString() is not string");
		}
		catch(tchar * e)
		{
			OutputDebugString( StringT( e ) + _T("\n") );
			return NULL;
		}
		return m_Value->GetString();
	}
	virtual const char* GetStringA()
	{
		try
		{
			if(m_Value->IsString() == false)
				throw _T("RapidJsonNode::GetStringA() : is not string");
			if(Encoding::IsUTF16())
				throw _T("RapidJsonNode::GetStringA() : is not single char, try GetStringW()?");
		}
		catch(tchar * e)
		{
			OutputDebugString( StringT( e ) + _T("\n") );
			return NULL;
		}
		return (const char*)m_Value->GetString();
	}
	virtual const wchar_t* GetStringW()
	{
		try
		{
			if(m_Value->IsString() == false)
				throw _T("RapidJsonNode::GetStringW() : is not string");
			if(Encoding::IsUTF16() == false)
				throw _T("RapidJsonNode::GetStringW() : is not wide char, try GetStringA()?");
		}
		catch(tchar * e)
		{
			OutputDebugString( StringT( e ) + _T("\n") );
			return NULL;
		}
		return (const wchar_t*)m_Value->GetString();
	}

	int GetInt()
	{
		try
		{
			if(m_Value->IsNumber() == false)
			{
				throw _T("RapidJsonNode::GetInt() is not number");
			}
		}
		catch(tchar * e)
		{
			OutputDebugString( StringT( e ) + _T("\n") );
			return 0;
		}
		if(m_Value->IsInt())
			return m_Value->GetInt();
		else
			return (int)m_Value->GetDouble();
	}

	unsigned int GetUInt()
	{
		try
		{
			if(m_Value->IsNumber() == false)
			{
				throw _T("RapidJsonNode::GetUInt() is not number");
			}
		}
		catch(tchar * e)
		{
			OutputDebugString( StringT( e ) + _T("\n") );
			return 0;
		}
		if(m_Value->IsUint())
			return m_Value->GetUint();
		else
			return (unsigned int)m_Value->GetDouble();
	}

	int64_t GetInt64()
	{
		try
		{
			if(m_Value->IsNumber() == false)
			{
				throw _T("RapidJsonNode::GetInt() is not number");
			}
		}
		catch(tchar * e)
		{
			OutputDebugString( StringT( e ) + _T("\n") );
			return 0;
		}
		return m_Value->GetInt64();
	}

	uint64_t GetUInt64()
	{
		try
		{
			if(m_Value->IsNumber() == false)
			{
				throw _T("RapidJsonNode::GetUInt64() is not number");
			}
		}
		catch(tchar * e)
		{
			OutputDebugString( StringT( e ) + _T("\n") );
			return 0;
		}
		return m_Value->GetUint64();
	}

	float GetFloat()
	{
		try
		{
			if(m_Value->IsNumber() == false)
			{
				throw _T("RapidJsonNode::GetFloat() is not number");
			}
		}
		catch(tchar * e)
		{
			OutputDebugString( StringT( e ) + _T("\n") );
			return 0.0f;
		}
		return (float)m_Value->GetDouble();
	}

	double GetDouble()
	{
		try
		{
			if(m_Value->IsNumber() == false)
			{
				throw _T("RapidJsonNode::GetDouble() is not number");
			}
		}
		catch(tchar * e)
		{
			OutputDebugString( StringT( e ) + _T("\n") );
			return 0.0;
		}
		return m_Value->GetDouble();
	}

	bool GetBool()
	{
		try
		{
			if(m_Value->IsBool() == false)
			{
				throw _T("RapidJsonNode::GetBool() is not bool");
			}
		}
		catch(tchar * e)
		{
			OutputDebugString( StringT( e ) + _T("\n") );
			return false;
		}
		return m_Value->GetBool();
	}

	//only for array type
	IJsonNode& operator[](unsigned int index)
	{
		RapidJsonNode<Encoding>* pNode = HV_AllocNew( RapidJsonNode<Encoding>, RapidJsonNode<Encoding>() );
		m_VecNode.PushBack(pNode);
		if(index >= Size())
			pNode->InitNode( NULL, NULL, GetType() );
		else
			pNode->InitNode( &(*m_Value)[index], m_Document, GetType() );
		return *pNode;
	}

	//only for object type
	IJsonNode& operator[](string name)
	{
		Member* Node = m_Value->FindMember(name.CString());
		RapidJsonNode<Encoding>* pNode = HV_AllocNew( RapidJsonNode<Encoding>, RapidJsonNode<Encoding>() );
		m_VecNode.PushBack(pNode);
		if(Node)
			pNode->InitNode( &Node->value, m_Document, GetType() );
		else
			pNode->InitNode( NULL, NULL, GetType() );
		return *pNode;
	}

	IJsonNode& operator=(int input)
	{
		m_Value->SetInt(input);
		return *this;
	}
	IJsonNode& operator=(unsigned int input)
	{
		m_Value->SetUint(input);
		return *this;
	}
	IJsonNode& operator=(int64& input)
	{
		m_Value->SetInt64(input);
		return *this;
	}
	IJsonNode& operator=(uint64_t& input)
	{
		m_Value->SetUint64(input);
		return *this;
	}
	IJsonNode& operator=(double input)					
	{
		m_Value->SetDouble(input);
		return *this;
	}
	IJsonNode& operator=(const CH* input)				
	{
		m_Value->SetString(input);
		return *this;
	}
	IJsonNode& operator=(bool input)						
	{
		m_Value->SetBool(input);
		return *this;
	}

	bool IsArray()	 {return IsValid() && m_Value->IsArray();	}
	bool IsObject()	 {return IsValid() && m_Value->IsObject();	}
	bool IsString()	 {return IsValid() && m_Value->IsString();	}
	bool IsDouble()	 {return IsValid() && m_Value->IsDouble();	}
	bool IsInt()   	 {return IsValid() && m_Value->IsInt();		}
	bool IsUInt()    {return IsValid() && m_Value->IsUint();	}
	bool IsInt64() 	 {return IsValid() && m_Value->IsInt64();	}
	bool IsUInt64()  {return IsValid() && m_Value->IsUint64();	}
	bool IsBool()  	 {return IsValid() && m_Value->IsBool();	}
	bool IsNullChar(){return IsValid() && m_Value->IsNull();	}
	bool IsValid() 	 {return m_Value != NULL && m_Document != NULL;}

	//print all json data on Output Window, for debug
	void Print()
	{
		string Str;
		ToJsonString(Str, true);

		Encoding::Print(Str.CString());
	}
	virtual bool Reload()
	{
		return false;
	}

	void SaveFile(const tchar* path, bool bPretty = true, bool bWithBOM = true, bool bSort = false)
	{
		string Str;
		ToJsonString(Str, bPretty, bWithBOM, bSort);
		std::ofstream fileStream(path, std::ofstream::binary);

		if(Encoding::IsUTF16())
			fileStream.write((const char *)Str.CString(), Str.GetLength() * 2);
		else
			fileStream.write((const char *)Str.CString(), Str.GetLength());
	}

	//prtty mode will get pretty but larger string
	void ToJsonString(string& Str, bool bPretty = false, bool bWithBOM = false, bool bSort = false)
	{
		JsonStringStream<Encoding> foo(bWithBOM);
		if(bPretty)
		{
			rapidjson::PrettyWriter<JsonStringStream<Encoding>, UTF, UTF> writer(foo);
			m_Value->Accept(writer, bSort);
		}
		else
		{
			rapidjson::Writer<JsonStringStream<Encoding>, UTF, UTF> writer(foo);
			m_Value->Accept(writer, bSort);
		}
		Str = foo.str();
	}

protected:
	//for array
	RapidJsonNode& _AddNode(rapidjson::Type type)
	{
		RapidJsonNode<Encoding>* pNode = HV_AllocNew( RapidJsonNode<Encoding>, RapidJsonNode<Encoding>() );
		m_VecNode.PushBack(pNode);

		if(IsArray() == false)
		{
			pNode->InitNode( NULL, NULL, GetType() );
			return *pNode;
		}

		Value obj(type);
		m_Value->PushBack(obj, m_Document->GetAllocator());
		Value * ret = m_Value->End() - 1;
		
		pNode->InitNode( ret, m_Document, GetType() );
		return *pNode;
	}

	//for object
	RapidJsonNode& _AddNode(const CH* name, rapidjson::Type type)
	{
		RapidJsonNode<Encoding>* pNode = HV_AllocNew( RapidJsonNode<Encoding>, RapidJsonNode<Encoding>() );
		m_VecNode.PushBack(pNode);
		if(IsObject() == false)
		{
			pNode->InitNode( NULL, NULL, GetType() );
			return *pNode;
		}

		name = NewString(name);

		Value obj(type);
		Value * ret = NULL;

		Value::Member* Node = m_Value->FindMember(name);
		if(Node == NULL)
			m_Value->AddMember(name, obj, m_Document->GetAllocator());
		else
		{
			m_Value->RemoveMember(name);
			m_Value->AddMember(name, obj, m_Document->GetAllocator());
		}
		ret = &(*m_Value)[name];

		pNode->InitNode( ret, m_Document, GetType() );
		return *pNode;
	}

	template <typename T>
	bool _Set(const CH* name, T input)
	{
		if(IsObject() == false)
			return false;

		name = NewString(name);

		Member* Node = m_Value->FindMember(name);
		if(Node == NULL)
			m_Value->AddMember(name, input, m_Document->GetAllocator());
		else
		{
			m_Value->RemoveMember(name);
			m_Value->AddMember(name, input, m_Document->GetAllocator());
		}

		return true;
	}

	template <typename T>
	bool _Push(T input)
	{
		if(IsArray() == false)
			return false;

		m_Value->PushBack(input, m_Document->GetAllocator());
		return true;
	}

	Value* GetValue()
	{
		return m_Value;
	}

	const CH* NewString(const CH* str)
	{
		string * tmp = HV_AllocNew(string, string(str));
		m_VecStr.PushBack(tmp);
		return tmp->CString();
	}

	Value* m_Value;
	Document* m_Document;
	Array<Iterator* > m_VecIter;
	Array<RapidJsonNode<Encoding>* > m_VecNode;
	Array<string* > m_VecStr;
};

}//hive

#endif