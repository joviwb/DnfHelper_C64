#include "pch.h"

void ���_�����ƶ�(int ��������, int ������, int �������, int ��������)
{
	Send_����Call(36);
	Send_����Call(��������, 1);
	Send_����Call(������, 1);
	Send_����Call(�������, 2);
	Send_����Call(��������, 2);
	Send_����Call(5, 1);
	Send_����Call(��������, 2);
	Send_����Call(0, 2);
	Send_����Call(0, 4);
	Send_����Call(0, 1);
	Send_����Call();
}

void ���_ʰȡ(int ������)
{
	Send_����Call(43);
	Send_����Call(������, 4);
	Send_����Call(0, 1);
	Send_����Call(1, 1);
	Send_����Call(566, 2);
	Send_����Call(291, 2);
	Send_����Call(9961, 2);
	Send_����Call(553, 2);
	Send_����Call(285, 2);
	Send_����Call(18802, 2);
	Send_����Call(24743, 2);
	Send_����Call();
}
void ���_ͨ�ط���()
{
	Send_����Call(69);
	Send_����Call();
	Send_����Call(70);
	Send_����Call();
	Send_����Call(71);
	Send_����Call(0, 1);
	Send_����Call(0, 1);
	Send_����Call();
	Send_����Call(1434);
	Send_����Call();
	Sleep(500);
	Send_����Call(42);
	Send_����Call();
}

void ���_��ȡ����()
{

	Send_����Call(1434);
	Send_����Call();
}


void Send_�������()
{
	int ��ʼ���, ��ǰ���, ��ʼID, ��ǰID, I;
	��ʼ��� = 100000003;
	��ǰ��� = ȫ��_�հ�����.��_��ͼ���;
	��ʼID = 0x2325;
	��ǰID = ��ǰ��� - ��ʼ���;
	I = ��ʼID + ��ǰID;
	if (���ı�(��ƫ����(�̵��ַ - 16, { ʱ���ַ, ����ƫ��, ��ͼ����, 0 }), 64) == L"�ǻ۵�����")
	{
		Send_����Call(34);
		Send_����Call(34, 2);
		Send_����Call(9000, 2);
		Send_����Call(65535, 2);
		Send_����Call(1, 2);
		Send_����Call(65535, 2);
		Send_����Call();
	}
	if (���ı�(��ƫ����(�̵��ַ - 16, { ʱ���ַ, ����ƫ��, ��ͼ����, 0 }), 64) == L"�籩��·")
	{
		Send_����Call(34);
		Send_����Call(34, 2);
		Send_����Call(I, 2);
		Send_����Call(65535, 2);
		Send_����Call(1, 2);
		Send_����Call(65535, 2);
		Send_����Call();
	}
}

void ���_ǿ�ƻس�()
{
	Send_����Call(42);
	Send_����Call();
}

void ���_��ͼ(int x, int y)
{
	Send_����Call(45);
	Send_����Call(x, 1);
	Send_����Call(y, 1);
	Send_����Call(0, 4);
	Send_����Call(0, 4);
	Send_����Call(0, 1);

	for (int i = 0; i < 9; i++)
	{
		Send_����Call(0, 2);
	}

	for (int i = 0; i < 8; i++)
	{
		Send_����Call(0, 4);
	}

	for (int i = 0; i < 7; i++)
	{
		Send_����Call(0, 2);
	}

	Send_����Call(0, 4);
	Send_����Call(0, 2);
	Send_����Call(0, 2);
	Send_����Call(0, 2);
	Send_����Call(0, 2);
	Send_����Call(0, 2);
	Send_����Call(0, 2);

	for (int i = 0; i < 16; i++)
	{
		Send_����Call(0, 4);
	}
	Send_����Call();

}


void ���_�ֽ�(int װ��λ��)
{
	Send_����Call(26);
	Send_����Call(0, 1);
	Send_����Call(65535, 2);
	Send_����Call(317, 4);
	Send_����Call(1, 1);
	Send_����Call(װ��λ��, 2);
	Send_����Call();
}

void ���_����(int λ��, int ����)
{

	Send_����Call(22);
	Send_����Call(0, 1);
	Send_����Call(λ��, 2);
	Send_����Call(����, 4);
	Send_����Call(29, 4);
	Send_����Call(49, 4);
	Send_����Call(λ�� * 2 + ���� * 2 + 1, 4);
	Send_����Call();



}

void ���_����(int װ��ָ��)
{
	Send_����Call(18);
	Send_����Call(װ��ָ��, 4);
	Send_����Call(װ��ָ��, 18);
	Send_����Call(0, 1);
	Send_����Call();
}

void �����ɱ(unsigned short ������ID)
{
	Send_����Call(39);
	Send_����Call(������ID, 2);
	Send_����Call(0, 2);
	for (int i = 0; i < 4; i++)
	{
		Send_����Call(0, 4);
	}
	Send_����Call(1, 1);
	Send_����Call(273, 2);
	Send_����Call(0, 2);
	Send_����Call(0, 4);
	Send_����Call(0, 2);
	Send_����Call(0, 2);
	Send_����Call(0, 2);
	for (int a = 0; a < 4; a++)
	{
		Send_����Call(0, 1);
	}
	Send_����Call(0, 2);
	Send_����Call(0, 1);
	Send_����Call(0, 4);
	Send_����Call(0, 4);
	for (int b = 0; b < 7; b++)
	{
		Send_����Call(0, 2);
	}
	Send_����Call(0, 1);
	for (int c = 0; c < 16; c++)
	{
		Send_����Call(0, 4);
	}
	Send_����Call();
}

void ���_ѡͼ()
{
	Send_����Call(15);
	Send_����Call(0, 4);
	Send_����Call();
}

void ���_��ͼ(int ��ͼ����,int ��ͼ�Ѷ�, int ��ԨͶ��, int ������,int �ǿ���Ԩ)
{
	Send_����Call(16);
	Send_����Call(��ͼ����, 4);
	Send_����Call(��ͼ�Ѷ�, 1);
	Send_����Call(0, 2);
	Send_����Call(��ԨͶ��, 1);
	Send_����Call(0, 1);
	Send_����Call(65535, 2);
	Send_����Call(0, 4);
	Send_����Call(0, 1);
	Send_����Call(������, 4);
	Send_����Call(�ǿ���Ԩ, 1);
	Send_����Call(0, 4);
	Send_����Call();

}


void ���_�˳���ɫ()
{
	Send_����Call(7);
	Send_����Call();
}

void ���_ѡ���ɫ(int ��ɫλ��)
{
	Send_����Call(4);
	Send_����Call(��ɫλ��, 2);
	Send_����Call();
}

void ���_������()
{
	Send_����Call(20);
	Send_����Call(6, 4);
	Send_����Call(16, 1);
	Send_����Call(0, 1);
	Send_����Call(24, 1);
	Send_����Call(1, 1);
	Send_����Call(32, 1);
	Send_����Call(0, 1);
	Send_����Call();

}

void ���_��������(unsigned short ������ID)
{

	Send_����Call(39);
	Send_����Call(������ID, 4);
	Send_����Call(1164, 2);
	Send_����Call(0, 8);
	Send_����Call(0, 4);
	Send_����Call(0, 8);
	Send_����Call(5, 4);
	Send_����Call(1, 1);
	Send_����Call(273, 2);
	Send_����Call(1164, 2);
	Send_����Call(0, 8);
	Send_����Call(5, 2);
	Send_����Call(1253, 2);
	Send_����Call(321, 2);
	Send_����Call(0, 1);
	Send_����Call(0, 1);
	Send_����Call(0, 1);
	Send_����Call(0, 1);
	Send_����Call(22908, 2);
	Send_����Call(0, 1);
	Send_����Call(91, 4);
	Send_����Call(0, 8);
	Send_����Call(900, 2);
	Send_����Call(418, 2);
	Send_����Call(1174, 2);
	Send_����Call(332, 2);
	Send_����Call(12, 2);
	Send_����Call(25, 2);
	Send_����Call(35, 2);
	Send_����Call(0, 1);
	Send_����Call(0, 1);
	Send_����Call();
}

void ���_����(int ����)
{

	Send_����Call(307);
	Send_����Call(����, 4);
	Send_����Call();

}


void ���_����(int ����λ��, int ��Ʒ����, int ��������, int ���λ��)
{
	Send_����Call(19);
	Send_����Call(0, 1);
	Send_����Call(����λ��, 2);
	Send_����Call(��Ʒ����, 4);
	Send_����Call(��������, 4);
	Send_����Call(12, 1);
	Send_����Call(���λ��, 2);
	Send_����Call(0, 4);
	Send_����Call(0, 4);
	Send_����Call(-1, 4);
	Send_����Call(0, 1);
	Send_����Call(0, 1);
	Send_����Call();
}

