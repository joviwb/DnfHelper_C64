#include "pch.h"

void ��ȡ����·��()
{
	GetEnvironmentVariableW(L"USERPROFILE", ����·��, MAX_PATH);//ȡϵͳ�û�·��
	wchar_t temp[MAX_PATH] = L"\\Desktop\\��ӣ.ini";
	wcscat_s(����·��, temp);
}

void д����(wstring ������, wstring ������, wstring ����)
{
	WritePrivateProfileStringW(������.c_str(), ������.c_str(), ����.c_str(), ����·��);
}

int ������(wstring ������, wstring ������)
{
	return GetPrivateProfileIntW(������.c_str(), ������.c_str(), 0, ����·��);
}

bool �ļ��Ƿ����(wstring �ļ�·��)
{

	if (GetFileAttributesW(�ļ�·��.c_str()) == INVALID_FILE_ATTRIBUTES)return false;
	else return true;
}