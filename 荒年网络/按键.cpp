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
			if (��������()== true)
			{
				��Ϸ����(L"������");
				����Call();
			}
			else
			{
				��Ϸ����(L"��������");
			}*/
			//��Ϸ����(L"��ӣ�˼�_��ӣPL��" + ���ı�(ȡƣ��()));
		}
		/*if (msg.wParam == UP)//��
		{
			�����ͼ(2);
		}
		if (msg.wParam == DOWN)//��
		{
			�����ͼ(3);
		}
		if (msg.wParam == LFET)//��
		{
			�����ͼ(0);
		}
		if (msg.wParam == RIGHT)//��
		{
			�����ͼ(1);
		}
		if (msg.wParam == END)
		{
			int ������� = �ȼ��Զ�();
			����call(192);
			���_ѡͼ();

		}*/
	}

	return 0;
}

//�ȼ�
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
		InitMsg(msg); //������Ϣ��ȡ
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

DWORD WINAPI �հ��߳�(LPVOID lpObject)
{
	�հ�();

	return 0;
}

BOOL RegHotKey::JudgeFristrLoad() //�ж��Ƿ��һ�μ���
{
	DWORD currentprocessId;
	DWORD processId;
	HWND hWnd;

	hWnd = NULL;
	currentprocessId = GetCurrentProcessId(); //��ȡ��ǰ����ID �ж��Ƿ�DNF���̼��ص�DLL,�������ֱ���˳����߳�
	for (int i = 0; i < 60; ++i)
	{
		hWnd = FindWindow(L"���³�����ʿ", L"���³�����ʿ");
		if (hWnd > 0)
		{
			CreateThread(NULL, 0, �հ��߳�, NULL, 0, NULL);
			GetWindowThreadProcessId(hWnd, &processId);
			break;
		}
		Sleep(1000);
	}
	if (processId != currentprocessId)
	{
		return FALSE; //����DNF���̵��õ�
	}
	return TRUE;
}

