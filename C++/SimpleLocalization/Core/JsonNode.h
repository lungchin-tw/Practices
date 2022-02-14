#ifndef JSONNODE_H_
#define JSONNODE_H_

#include <vector>

namespace hive
{

class ConfigBase
{
public:
	ConfigBase() : _iType(0) {}
	virtual ~ConfigBase(){}
	void SetType(int i) {_iType = i;}
	int  GetType()      {return _iType;}
	virtual bool Reload() = 0;
private:
	int _iType;       //UTF8Json = 0, UTF16Json = 1
};


#pragma warning( push )
#pragma warning( disable: 4100 )
#pragma warning( disable: 4239 )
#pragma warning( disable: 4172 )

class IJsonNode : public ConfigBase
{
public:
	typedef __int64 int64_t;
	typedef unsigned __int64 uint64_t;

	//only for object type
	class IIterator
	{
	public:
		virtual ~IIterator(){}
		virtual bool operator==(IIterator& other)					{return false;}
		virtual bool operator!=(IIterator& other)					{return false;}
		virtual IIterator& operator++ ()							{return *this;}
        virtual IIterator  operator++ (int)							{return *this;}
		virtual IIterator& operator= (IIterator& other)				{ASSERT( 0 && "WARNING: Cant't Copy IIterator" );return *this;}
#ifdef UNICODE
		const wchar_t* Name()										{return NameW();}
#else
		const char*    Name()										{return NameA();}
#endif
		//only for utf8
		virtual const char*    NameA()								{return NULL;}
		//only for utf16
		virtual const wchar_t* NameW()								{return NULL;}
		virtual IJsonNode & Node()									{return IJsonNode();}
		//dont't use
		virtual void* getValue()									{return NULL;}
	};

	virtual ~IJsonNode(){}

	////only for array type
	//virtual bool GetStringArray(const char* name, std::vector<StringA> & values){return false;}
	//virtual bool GetStringArray(const wchar_t* name, std::vector<StringW> & values){return false;}
	////only for array type
	//virtual bool GetDoubleArray(const char* name, std::vector<double> & values){return false;}
	//virtual bool GetDoubleArray(const wchar_t* name, std::vector<double> & values){return false;}
	////only for array type
	//virtual bool GetFloatArray(const char* name, std::vector<float> & values){return false;}
	//virtual bool GetFloatArray(const wchar_t* name, std::vector<float> & values){return false;}
	////only for array type
	//virtual bool GetIntArray(const char* name, std::vector<int> & values){return false;}
	//virtual bool GetIntArray(const wchar_t* name, std::vector<int> & values){return false;}

	////only for object type
	virtual IIterator& Begin()										{return IIterator();}
	virtual IIterator& End()										{return IIterator();}
	virtual IIterator& Find(const char* name)                       {return IIterator();}
	virtual IIterator& Find(const wchar_t* name)                    {return IIterator();}

	virtual bool HasMember(const char* name)						{return false;}
	virtual bool HasMember(const wchar_t* name)						{return false;}
	
	virtual IJsonNode& AddObjectNode()								{return *this;}
	virtual IJsonNode& AddArrayNode()								{return *this;}
	virtual IJsonNode& AddObjectNode(const char* name)				{return *this;}
	virtual IJsonNode& AddObjectNode(const wchar_t* name)			{return *this;}
	virtual IJsonNode& AddArrayNode(const char* name)				{return *this;}
	virtual IJsonNode& AddArrayNode(const wchar_t* name)			{return *this;}

	virtual bool Get(const char* name, const char** ouput)			{return false;}
	virtual bool Get(const wchar_t* name, const wchar_t** ouput)	{return false;}
	virtual bool Get(const char* name, StringA& ouput)				{return false;}
	virtual bool Get(const wchar_t* name, StringW& ouput)			{return false;}
	virtual bool Get(const char* name, int& ouput)					{return false;}
	virtual bool Get(const wchar_t* name, int& ouput)				{return false;}
	virtual bool Get(const char* name, unsigned int& ouput)			{return false;}
	virtual bool Get(const wchar_t* name, unsigned int& ouput)		{return false;}
	virtual bool Get(const char* name, int64_t& ouput)				{return false;}
	virtual bool Get(const wchar_t* name, int64_t& ouput)			{return false;}
	virtual bool Get(const char* name, uint64_t& ouput)				{return false;}
	virtual bool Get(const wchar_t* name, uint64_t& ouput)			{return false;}
	virtual bool Get(const char* name, float& ouput)				{return false;}
	virtual bool Get(const wchar_t* name, float& ouput)				{return false;}
	virtual bool Get(const char* name, double& ouput)				{return false;}
	virtual bool Get(const wchar_t* name, double& ouput)			{return false;}
	virtual bool Get(const char* name, bool& ouput)					{return false;}
	virtual bool Get(const wchar_t* name, bool& ouput)				{return false;}
	virtual bool Get(const char* name, IJsonNode** ouput)			{return false;}
	virtual bool Get(const wchar_t* name, IJsonNode** ouput)		{return false;}

	//only for object type, if member exist then replace it
	virtual bool Set(const char* name, bool input)					{return false;}
	virtual bool Set(const wchar_t* name, bool input)				{return false;}
	virtual bool Set(const char* name, int input)					{return false;}
	virtual bool Set(const wchar_t* name, int input)				{return false;}
	virtual bool Set(const char* name, unsigned int input)			{return false;}
	virtual bool Set(const wchar_t* name, unsigned int input)		{return false;}
	virtual bool Set(const char* name, int64_t& input)				{return false;}
	virtual bool Set(const wchar_t* name, int64_t& input)			{return false;}
	virtual bool Set(const char* name, uint64_t& input)				{return false;}
	virtual bool Set(const wchar_t* name, uint64_t& input)			{return false;}
	virtual bool Set(const char* name, double input)				{return false;}
	virtual bool Set(const wchar_t* name, double input)				{return false;}
	virtual bool Set(const char* name, const char* input)			{return false;}
	virtual bool Set(const wchar_t* name, const char* input)		{return false;}
	virtual bool Set(const char* name, const wchar_t* input)		{return false;}
	virtual bool Set(const wchar_t* name, const wchar_t* input)		{return false;}

	virtual bool Erase(const char* name)							{return false;}
	virtual bool Erase(const wchar_t* name)							{return false;}

	////only for array type
	virtual bool SetArrayData(unsigned int Idx, bool input)				{return false;}
	virtual bool SetArrayData(unsigned int Idx, int input)				{return false;}
	virtual bool SetArrayData(unsigned int Idx, unsigned int input)		{return false;}
	virtual bool SetArrayData(unsigned int Idx, int64_t& input)			{return false;}
	virtual bool SetArrayData(unsigned int Idx, uint64_t& input)		{return false;}
	virtual bool SetArrayData(unsigned int Idx, double input)			{return false;}
	virtual bool SetArrayData(unsigned int Idx, const char* input)		{return false;}
	virtual bool SetArrayData(unsigned int Idx, const wchar_t* input)	{return false;}

	virtual bool GetArrayData(unsigned int Idx, const char** ouput)		{return false;}
	virtual bool GetArrayData(unsigned int Idx, const wchar_t** ouput)	{return false;}
	virtual bool GetArrayData(unsigned int Idx, StringA& ouput)			{return false;}
	virtual bool GetArrayData(unsigned int Idx, StringW& ouput)			{return false;}
	virtual bool GetArrayData(unsigned int Idx, int& ouput)				{return false;}
	virtual bool GetArrayData(unsigned int Idx, unsigned int& ouput)	{return false;}
	virtual bool GetArrayData(unsigned int Idx, int64_t& ouput)			{return false;}
	virtual bool GetArrayData(unsigned int Idx, uint64_t& ouput)		{return false;}
	virtual bool GetArrayData(unsigned int Idx, float& ouput)			{return false;}
	virtual bool GetArrayData(unsigned int Idx, double& ouput)			{return false;}
	virtual bool GetArrayData(unsigned int Idx, bool& ouput)			{return false;}
	
	virtual bool Push(bool input)									{return false;}
	virtual bool Push(int input)									{return false;}
	virtual bool Push(unsigned int input)							{return false;}
	virtual bool Push(int64_t& input)								{return false;}
	virtual bool Push(uint64_t& input)								{return false;}
	virtual bool Push(double input)									{return false;}
	virtual bool Push(const char* input)							{return false;}
	virtual bool Push(const wchar_t* input)							{return false;}
	virtual bool Pop()												{return false;}
	virtual unsigned int Size()										{return 0;}

	////for all
	virtual void SetString(const char* input){}
	virtual void SetString(const wchar_t* input){}
#ifdef UNICODE
	const wchar_t* GetString()										{return GetStringW();}
#else
	const char* GetString()											{return GetStringA();}
#endif
	//only for utf8
	virtual const char* GetStringA()								{return 0;}
	//only for utf16
	virtual const wchar_t* GetStringW()								{return 0;}

	virtual void SetInt(int input){}
	virtual void SetUInt(unsigned int input){}
	virtual void SetInt64(int64_t& input){}
	virtual void SetUInt64(uint64_t& input){}
	virtual void SetDouble(double input){}
	virtual void SetBool(bool input){}

	virtual int      GetInt()										{return 0;}
	virtual unsigned int GetUInt()									{return 0;}
	virtual int64_t  GetInt64()										{return 0;}
	virtual uint64_t GetUInt64()									{return 0;}
	virtual float    GetFloat()										{return 0.0f;}	
	virtual double   GetDouble()									{return 0.0;}
	virtual bool     GetBool()										{return false;}

	//only for array type
	virtual IJsonNode& operator[](unsigned int index)				{return *this;}
	//only for object type
	virtual IJsonNode& operator[](StringA name)						{return *this;}
	virtual IJsonNode& operator[](StringW name)						{return *this;}

	////for all
	virtual IJsonNode& operator=(IJsonNode& other)					{ASSERT( 0 && "WARNING: Cant't Copy IJsonNode" );return *this;}
	virtual IJsonNode& operator=(int input)							{return *this;}
	virtual IJsonNode& operator=(unsigned int input)				{return *this;}
	virtual IJsonNode& operator=(int64_t& input)					{return *this;}
	virtual IJsonNode& operator=(uint64_t& input)					{return *this;}
	virtual IJsonNode& operator=(double  input)						{return *this;}
	virtual IJsonNode& operator=(const char* input)					{return *this;}
	virtual IJsonNode& operator=(const wchar_t* input)				{return *this;}
	virtual IJsonNode& operator=(bool  input)						{return *this;}

	virtual bool EraseAll()											{return false;}
	virtual void SetToObjectNode(){}
	virtual void SetToArrayNode(){}

	virtual bool IsArray()											{return false;}
	virtual bool IsObject()											{return false;}
	virtual bool IsString()											{return false;}
	virtual bool IsDouble()											{return false;}
	virtual bool IsInt()   											{return false;}
	virtual bool IsUInt()   										{return false;}
	virtual bool IsInt64()   										{return false;}
	virtual bool IsUInt64()   										{return false;}
	virtual bool IsBool()  											{return false;}
	virtual bool IsNullChar()										{return false;}
	virtual bool IsValid() 											{return false;}

	//print all json data on Output Window, for debug
	virtual void Print()											{}
	virtual bool Reload()											{return false;}
	virtual void SaveFile(const tchar* path, bool bPretty = true, bool bSort = false)	                    {}
	//prtty mode will get pretty but larger string
	virtual void ToJsonString(StringA& Str, bool bPretty = false, bool bWithBOM = false, bool bSort = false){}
	virtual void ToJsonString(StringW& Str, bool bPretty = false, bool bWithBOM = false, bool bSort = false){}
};

#pragma warning( pop )

}
#endif