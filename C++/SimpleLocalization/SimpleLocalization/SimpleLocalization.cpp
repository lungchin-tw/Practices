// SimpleLocalization.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <Windows.h>
#include <winnt.h>
#include "Core\Core.h"
#include <locale.h>
#include <iostream>
#include <atlstr.h>

TCHAR GPath[ 1024 ];
TCHAR GFullFilePath[ 1024 ];

void MBCS2Simplified( StringA& );
StringW UTF82WideChar( const StringA& );

void UTF8ToMBCS( StringA& data, uint code_page  )
{
	StringW wstr = UTF82WideChar( data );

	int mb_len = WideCharToMultiByte( code_page, 0, wstr.CString(), -1, nullptr, 0, nullptr, nullptr );

	if(mb_len == 0) return;
	
	char* mbcs = new char[ mb_len + 1 ];
	memset( mbcs, 0, mb_len + 1 );
	int result = WideCharToMultiByte( code_page, 0, wstr.CString(), -1, mbcs, mb_len, "x", nullptr );

	data = mbcs;
	
	delete[] mbcs;
};

StringW UTF82WideChar( const StringA& data )
{
	const char* cs = data.CString();
	int wc_len = MultiByteToWideChar( CP_UTF8, 0, cs, -1, nullptr, 0 );

	if( wc_len == 0 ) return StringW();

	wchar* buffer = new wchar[ wc_len + 1 ];
	int result = MultiByteToWideChar( CP_UTF8, 0, cs, -1, buffer, wc_len );
	StringW wstr = buffer;
	delete[] buffer;
	return wstr;
}

bool ReadDataByNode( IJsonNode* node, StringA& data )
{
	if( node->GetType() == ConfigManager::UTF8Json )
	{	
		return node->Get( _T("name"), data );
	}

	return false;
}

void ReadAmericaEnglishFile( StringA& data )
{	
	sprintf_s<1024>( GFullFilePath, "%s%s", GPath, "\\data\\AmericaEnglish.txt" );

	IJsonNode* node = ConfigManagerGetInstance().LoadJsonConfig( GFullFilePath );

	assert( node != nullptr );

	if( ReadDataByNode( node, data ) )
	{
		UTF8ToMBCS( data, CP_ACP );
		std::cout<<data.CString()<<std::endl;
	}
}

void ReadSimplifiedChineseFile( StringA& data )
{	
	sprintf_s<1024>( GFullFilePath, "%s%s", GPath, "\\data\\SimplifiedChinese.txt" );

	IJsonNode* node = ConfigManagerGetInstance().LoadJsonConfig( GFullFilePath );

	assert( node != nullptr );

	if( ReadDataByNode( node, data ) )
	{	
		UTF8ToMBCS( data, CP_ACP );
		std::cout<<data.CString()<<std::endl;
	}
}

void ReadTraditionalChineseFile( StringA& data )
{	
	sprintf_s<1024>( GFullFilePath, "%s%s", GPath, "\\data\\TraditionalChinese.txt" );

	IJsonNode* node = ConfigManagerGetInstance().LoadJsonConfig( GFullFilePath );

	assert( node != nullptr );

	if( ReadDataByNode( node, data ) )
	{
		UTF8ToMBCS( data, CP_ACP );
		std::cout<<data.CString()<<std::endl;
	}
}

void TestTraditionalToSimplified( StringA& data )
{
	sprintf_s<1024>( GFullFilePath, "%s%s", GPath, "\\data\\Test.txt" );

	IJsonNode* node = ConfigManagerGetInstance().LoadJsonConfig( GFullFilePath );

	assert( node != nullptr );

	if( ReadDataByNode( node, data ) == false ) return;
	
	UTF8ToMBCS( data, CP_ACP );

	MBCS2Simplified( data );
}

void MBCS2Simplified( StringA& data )
{
	const char* tc = data.CString();
	int len = LCMapString( LOCALE_SYSTEM_DEFAULT, LCMAP_SIMPLIFIED_CHINESE, tc, -1, nullptr, 0 );

	if( len == 0 ) return;

	char* buff = new char[ len +1 ];
	LCMapString( LOCALE_SYSTEM_DEFAULT, LCMAP_SIMPLIFIED_CHINESE, tc, -1, buff, len );
	data = buff;

	delete[] buff;
}

int _tmain(int argc, _TCHAR* argv[])
{
	GetCurrentDirectory( 1023, GPath );

	StringA data;
	ReadAmericaEnglishFile( data );
	ReadSimplifiedChineseFile( data );
	ReadTraditionalChineseFile( data );

	//TestTraditionalToSimplified( data );
	
	
	return 0;
}

