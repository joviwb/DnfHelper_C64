// dllmain.cpp : 定义 DLL 应用程序的入口点。
#include "pch.h"
#include "网络验证系统MT.h"
unsigned int _stdcall MainThread(void* lpobject)
{
	if (!RegHotKey::JudgeFristrLoad())
	{
		return -1;
	}
	RegHotKey reghotkey;
	return reghotkey.exec();
}
string 读配置项文本(string 文件路径, string 节, string 项)
{
	char ip[16];
	GetPrivateProfileStringA(节.c_str(), 项.c_str(), "", ip, sizeof(ip), 文件路径.c_str());
	return ip;
}
BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:

		DisableThreadLibraryCalls(hModule);
		_beginthreadex(nullptr, 0, MainThread, nullptr, 0, nullptr);
		//string 账号 = 读配置项文本("C:\\ACC.ini", "账号配置", "账号");
		//string 密码 = 读配置项文本("C:\\ACC.ini", "账号配置", "密码");
	//	验证_初始化("4IRQVCCYHPY", 9653, &MainThread);//这里改成你的软件标识和PIN
	//	验证_账号登录(账号, 密码);
	//	string 返回结果 = 验证_账号登录(账号, 密码);
		//if (atoi(返回结果.c_str()) != 1)
	//	{
		//	MessageBoxA(NULL, 返回结果.c_str(), "", 4096);
		//	验证_结束自身进程();
			//	string 登录提示文本 = "到期日期：" + 验证_读取服务器信息(1015) + "\n";



	///	}
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

