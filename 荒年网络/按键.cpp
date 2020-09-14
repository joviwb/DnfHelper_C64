#include "pch.h"
#define F2 1002
//#define LFET 1012
//#define RIGHT 1013
//#define UP 1014
//#define DOWN 1015



int RegHotKey::InitMsg(MSG msg)
{
	if (msg.message == WM_HOTKEY)
	{
		if (msg.wParam == F2)
		{

           /*
			if (跳过数据()== true)
			{
				游戏公告(L"可以跳");
				跳过Call();
			}
			else
			{
				游戏公告(L"不可以跳");
			}*/
			//游戏公告(L"南樱人间_南樱PL：" + 到文本(取疲劳()));
		}
		/*if (msg.wParam == UP)//上
		{
			坐标过图(2);
		}
		if (msg.wParam == DOWN)//下
		{
			坐标过图(3);
		}
		if (msg.wParam == LFET)//左
		{
			坐标过图(0);
		}
		if (msg.wParam == RIGHT)//右
		{
			坐标过图(1);
		}
		if (msg.wParam == END)
		{
			int 副本编号 = 等级自动();
			区域call(192);
			组包_选图();

		}*/
	}

	return 0;
}

//热键
RegHotKey::RegHotKey()
{

}

RegHotKey::~RegHotKey()
{

}

int RegHotKey::exec()
{
	MSG msg;
	InitRegHotKey();
	while (GetMessage(&msg, NULL, 0, 0))
	{
		InitMsg(msg); //按键消息获取
	}
	UninstallRegHotKey();

	return 0;
}

void RegHotKey::InitRegHotKey()
{
	//RegisterHotKey(0, HOME, 0, VK_HOME);
	//RegisterHotKey(0, F1, 0, VK_F1);
	RegisterHotKey(0, F2, 0, VK_F2);
	//RegisterHotKey(0, F3, 0, VK_F3);
	//RegisterHotKey(0, V, 0, 86);
	//RegisterHotKey(0, DOWN, 0, VK_DOWN);
	//RegisterHotKey(0, LFET, 0, VK_LEFT);
	//RegisterHotKey(0, RIGHT, 0, VK_RIGHT);
	//RegisterHotKey(0, UP, 0, VK_UP);
	//RegisterHotKey(0, END, 0, VK_END);
}

void RegHotKey::UninstallRegHotKey()
{

}

DWORD WINAPI 收包线程(LPVOID lpObject)
{
	收包();

	return 0;
}

BOOL RegHotKey::JudgeFristrLoad() //判断是否第一次加载
{
	DWORD currentprocessId;
	DWORD processId;
	HWND hWnd;

	hWnd = NULL;
	currentprocessId = GetCurrentProcessId(); //获取当前进程ID 判断是否DNF进程加载的DLL,如果不是直接退出该线程
	for (int i = 0; i < 60; ++i)
	{
		hWnd = FindWindow(L"地下城与勇士", L"地下城与勇士");
		if (hWnd > 0)
		{
			CreateThread(NULL, 0, 收包线程, NULL, 0, NULL);
			GetWindowThreadProcessId(hWnd, &processId);
			break;
		}
		Sleep(1000);
	}
	if (processId != currentprocessId)
	{
		return FALSE; //不是DNF进程调用的
	}
	return TRUE;
}

