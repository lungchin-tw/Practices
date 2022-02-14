#ifndef RAPIDJSONENCODE_H_
#define RAPIDJSONENCODE_H_
#include "rapidjson/document.h"
#include "rapidjson/prettywriter.h"
#include "rapidjson/filestream.h"
#include <string>
#include <fstream>
#include <iostream>
#include <vector>

namespace hive
{

class JsonUTF8
{
public:
	typedef rapidjson::UTF8<> UTF;
	typedef rapidjson::GenericDocument<rapidjson::UTF8<> > Document;
	typedef rapidjson::GenericValue<rapidjson::UTF8<> > Value;
	typedef rapidjson::GenericValue<rapidjson::UTF8<> >::Member Member;
	typedef char CH;
	typedef StringA string;
	typedef std::ofstream ofstream;
	typedef std::ifstream ifstream;
	typedef std::ostringstream ostringstream;
	static bool LoadFile(const tchar* pFilePath, Document *pDocument, bool bShowError = true)
	{
		Array<char> readBuffer;

		ifstream is (pFilePath, ifstream::binary);
		if(is.fail())
			return false;

		is.seekg (0, is.end);
		uint length = (uint)is.tellg();
		is.seekg (0, is.beg);

		readBuffer.Resize(length + 1, char(0));

		// read data as a block:
		is.read (&readBuffer[uint(0)], length);
		is.close();
		
		if(length >= 2 && unsigned char(readBuffer[uint(0)]) == 0xfe && unsigned char(readBuffer[uint(1)]) == 0xff)	//UTF16 BE
		{
			return false;
		}
		else if(length >= 2 && unsigned char(readBuffer[uint(0)]) == 0xff && unsigned char(readBuffer[uint(1)]) == 0xfe)//UTF16 LE
		{
			return false;
		}
		else if(length >= 3 && readBuffer[uint(0)] == -17 && readBuffer[uint(1)] ==  -69 && readBuffer[uint(2)] == -65) //utf8 BOM
		{
			readBuffer[uint(0)] = 32;//space " "
			readBuffer[uint(1)] = 32;
			readBuffer[uint(2)] = 32;
		}
		readBuffer[length] = 0; //must add null end.

		bool bRes = LoadByString(&readBuffer[uint(0)], pDocument, bShowError);
		return bRes;
	}

	static bool LoadByString(const CH* Str, Document *pDocument, bool bShowError = true)
	{
		//parse
		if (pDocument->Parse<0>(Str).HasParseError())
		{
			if(bShowError)
				OutputDebugStringA( StringA("JsonUTF8::LoadByString() : ") + pDocument->GetParseError() + "\n" );
			return false;
		}
		return true;
	}
	static void Print(const CH* Str)
	{
		OutputDebugStringA( StringA(Str) + "\n" );
	}
	static bool IsUTF16() { return false; }
};

class JsonUTF16
{
public:
	typedef rapidjson::UTF16<> UTF;
	typedef rapidjson::GenericDocument<UTF> Document;
	typedef rapidjson::GenericValue<UTF> Value;
	typedef rapidjson::GenericValue<UTF>::Member Member;
	typedef wchar_t CH;
	typedef StringW string;
	typedef std::wofstream ofstream;
	typedef std::ifstream ifstream;
	typedef std::wostringstream ostringstream;
	static bool LoadFile(const tchar* pFilePath, Document * pDocument, bool bShowError = true)
	{
		Array<char> readBuffer;
		Array<wchar_t> readBufferW;

		ifstream is (pFilePath, ifstream::binary);
		if(is.fail())
			return false;

		is.seekg (0, is.end);
		uint length = (uint)is.tellg();
		is.seekg (0, is.beg);

		readBuffer.Resize(length + 1, char(0));

		// read data as a block:
		is.read (&readBuffer[uint(0)], length);
		is.close();

		//2 char combine to 1 wchar
		if(length >= 2 && unsigned char(readBuffer[uint(0)]) == 0xfe && unsigned char(readBuffer[uint(1)]) == 0xff)	//UTF16 BE
		{
			if((length % 2) == 1)//error
				return false;
			readBufferW.Resize((length / 2) + 1, wchar_t(0));
			for(uint i = 0 ; i < length; i = i + 2)
				readBufferW[i / 2] = (readBuffer[i] << 8) + (unsigned char)readBuffer[i + 1];

			readBufferW[length / 2] = 0;	//string end
		}
		else if(length >= 2 && unsigned char(readBuffer[uint(0)]) == 0xff && unsigned char(readBuffer[uint(1)]) == 0xfe)//UTF16 LE to BE
		{
			if((length % 2) == 1)//error
				return false;
			readBufferW.Resize((length / 2) + 1, wchar_t(0));
			for(uint i = 0 ; i < length; i = i + 2)
				readBufferW[i / 2] = (readBuffer[i + 1] << 8) + (unsigned char)readBuffer[i];

			readBufferW[length / 2] = 0;	//string end
		}
		else if(length >= 3 && unsigned char(readBuffer[uint(0)]) == 0xef && unsigned char(readBuffer[uint(1)]) ==  0xbb && unsigned char(readBuffer[uint(2)]) == 0xbf) //utf8 BOM
		{
			return false;
		}
		else    //ascii to UTF16 BE
		{
			readBufferW.Resize(length + 2, wchar_t(0));//header and string end
			readBufferW[uint(0)] = 0xfeff;
			for(uint i = 0 ; i < length; ++i)
				readBufferW[i + 1] = (unsigned char)readBuffer[i];

			readBufferW[length + 1] = 0;	//string end
		}

		//skip first char
		bool bRes = LoadByString(&readBufferW[uint(1)], pDocument, bShowError);
		return bRes;
	}

	static bool LoadByString(const CH* Str, Document *pDocument, bool bShowError = true)
	{
		//parse
		if (pDocument->Parse<0>(Str).HasParseError())
		{
			if(bShowError)
				OutputDebugStringA( StringA("JsonUTF16::LoadByString() : ") + pDocument->GetParseError() + "\n" );
			return false;
		}
		return true;
	}
	static void Print(const CH* Str)
	{
		OutputDebugStringW( StringW(Str) + L"\n" );
	}
	static bool IsUTF16() { return true; }
};

}//hive

#endif