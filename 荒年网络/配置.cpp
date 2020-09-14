#include "pch.h"

void 获取配置路径()
{
	GetEnvironmentVariableW(L"USERPROFILE", 配置路径, MAX_PATH);//取系统用户路径
	wchar_t temp[MAX_PATH] = L"\\Desktop\\南樱.ini";
	wcscat_s(配置路径, temp);
}

void 写配置(wstring 节名称, wstring 项名称, wstring 数据)
{
	WritePrivateProfileStringW(节名称.c_str(), 项名称.c_str(), 数据.c_str(), 配置路径);
}

int 读配置(wstring 节名称, wstring 项名称)
{
	return GetPrivateProfileIntW(节名称.c_str(), 项名称.c_str(), 0, 配置路径);
}

bool 文件是否存在(wstring 文件路径)
{

	if (GetFileAttributesW(文件路径.c_str()) == INVALID_FILE_ATTRIBUTES)return false;
	else return true;
}