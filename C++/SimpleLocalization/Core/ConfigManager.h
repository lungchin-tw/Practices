#ifndef CONFIGMANAGER_H_
#define CONFIGMANAGER_H_

#include "JsonLoader.h"
#include <map>

namespace hive
{
//class

class HV_Core_API ConfigManager
{
public:
	enum {UTF8Json = 0, UTF16Json = 1};
	ConfigManager(){}
	~ConfigManager();

	ConfigBase* LoadConfigBase(const tchar * pPathName);
	ConfigBase* GetConfigBase(const tchar * pFileName);

	IJsonLoader* LoadUTF8JsonConfig(const tchar * pPathName);
	IJsonLoader* GetUTF8JsonConfig(const tchar * pPathName);
	IJsonLoader* CreateUTF8JsonConfig(const tchar * pPathName);
	IJsonLoader* NewUTF8JsonConfig();

	IJsonLoader* LoadUTF16JsonConfig(const tchar * pPathName);
	IJsonLoader* GetUTF16JsonConfig(const tchar * pPathName);
	IJsonLoader* CreateUTF16JsonConfig(const tchar * pPathName);
	IJsonLoader* NewUTF16JsonConfig();

	IJsonLoader* LoadJsonConfig(const tchar * pPathName);//usually for ASCII file
	IJsonLoader* GetJsonConfig(const tchar * pPathName);
	IJsonLoader* CreateJsonConfig(const tchar * pPathName);
	IJsonLoader* NewJsonConfig();

	bool Release(const tchar * pName);
	void ReleaseAll();

	bool Reload(const tchar * pName);
	void ReloadAll();

private:
	bool _GetFileName(const tchar * pPathName, StringT & sName);
	bool _GetFileExtName(const tchar * pPathName, StringT & sName);
	bool _GetFileAndExtName(const tchar * pPathName, StringT & sName);

	template <typename Encoding>
	IJsonLoader* _LoadJsonConfig(const tchar * pPathName, int iType);

	Map < StringT, ConfigBase* > m_mapConfigData;
};

extern "C"
{
	HV_Core_API ConfigManager& ConfigManagerGetInstance();
};


}//hive

#endif