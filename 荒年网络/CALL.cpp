#include "pch.h"

void Send_����Call(int cdov)
{
	__asm {
		mov rax, ������ַ//������ַ
		mov rcx, [rax]
		mov edx, cdov
		mov rax, ����CALL//����CALL
		call rax
	}
}
void Send_����Call(int ��ֵ, INT64 ����CALL1)
{
	INT64 cdov = 0;
	if (����CALL1 == 1)cdov = ����CALL;
	if (����CALL1 == 2)cdov = ����CALL + 64;
	if (����CALL1 == 4)cdov = ����CALL + 128;
	if (����CALL1 == 8)cdov = ����CALL + 192;
	__asm {
		mov rax, ������ַ//������ַ
		mov rcx, [rax]
		mov edx, ��ֵ
		mov rax, cdov//���ܰ�
		call rax
	}
}
void Send_����Call()
{
	__asm {
		mov rax, ����CALL//����CALL
		call rax
	}
}

void ����Call(int ������ֵ)
{
	INT64 �հ׵�ַ = ��Ϸ�հ׵�ַ;
	*(int*)(�հ׵�ַ) = ������ֵ;
	INT64 �������� = *(INT64*)(���ֻ�ַ) + ����ƫ��;
	__asm {
		mov rcx, ��������
		mov r8, rcx
		add r8, 0x4
		mov rdx, �հ׵�ַ
		mov rax, ����CALL
		call rax
	}
}

void ����Call(INT64 ����ָ��, int ����, int �˺�, int x, int y, int z, int ��С)
{
	INT64 �հ׵�ַ = Alloc(0x200);
	float speed = ��С;
	*(int*)(�հ׵�ַ + 0) = ����ָ��;
	*(int*)(�հ׵�ַ + 16) = ����;
	*(int*)(�հ׵�ַ + 20) = �˺�;
	*(int*)(�հ׵�ַ + 32) = x;
	*(int*)(�հ׵�ַ + 36) = y;
	*(int*)(�հ׵�ַ + 40) = z;
	*(int*)(�հ׵�ַ + 140) = *(long*)& speed;
	*(int*)(�հ׵�ַ + 144) = 65535;
	*(int*)(�հ׵�ַ + 148) = 65535;
	__asm
	{
		sub rsp, 0x200
		mov rcx, �հ׵�ַ
		call ����CALL
		add rsp, 0x200
	}
}

void ����call(INT64 ����ָ��, INT64 X, INT64 Y, INT64 Z)
{
	__asm
	{
		mov rcx, ����ָ��
		mov rdx, X
		mov r8, Y
		mov r9, Z
		mov rax, [rcx]
		mov rax, [rax + 0x1A0]
		call rax
	}
}

void ����Call(int ����λ��)
{
	INT64 �������� = *(INT64*)(*(INT64*)(�����ַ) + ����ƫ��);
	__asm
	{
		 mov r9d, 0x1
		 mov r8d, 0x1
		 mov edx, ����λ��
		 mov rcx, ��������
		 mov rax, ����CALL
		 call rax
}
}

void ����call(int ����)
{
	int ������;
	int С����;
	int X;
	int Y;
	INT64 ����_��ַ = *(INT64*)(�����ַ);
	_asm
	{
		mov r8d, ����
		mov rdx, -0x1
		mov rcx, ����_��ַ
		call ����CALL
	}
	������ = *(int*)(*(INT64*)(�����ַ) + ����ƫ��);
	С���� = *(int*)(*(INT64*)(�����ַ) + ����ƫ�� + 4);
	X = *(int*)(*(INT64*)(�����ַ) + ����ƫ�� + 8);
	Y = *(int*)(*(INT64*)(�����ַ) + ����ƫ�� + 12);
	���_�����ƶ�(������, С����, X, Y);
}

void ����Call()
{
	__asm
	{
		or r9d, -1
		or r8d, r9d
		mov edx, 1
		mov rcx, �����ַ
		mov rcx, [rcx]
		call ����CALL
}
}

void ����Call(int ��_����)
{
	__asm
	{
		 mov edx, ��_����
		 call ����CALL
}
}

void ���Call(int ��_����, int ��_����)
{
	for (size_t i = 1; i <= ��_����; i++)
	{
		__asm
		{
			mov bl, 0xFF
			movzx r9d, bl
			mov r8b, 0xFF
			mov edx, ��_����
			call ���CALL
		}
	}
}

void �ύCall(int ��_����)
{
	__asm
	{
		 mov r13d, 1
		 mov r14d, 0xFFFFFFFF
		 mov r9d, r13d
		 mov r8d, r14d
		 mov rcx, �����ַ
		 mov rcx, [rcx]
	     mov edx, ��_����
		 call �ύCALL
}
}

void ��ƷCall(int ��Ʒ����)
{
	__asm
	{
		mov rax, 0x14A6805F0  //�����ַ
		mov rax, [rax]
		mov r8, [rax]
		mov edx, ��Ʒ����
		mov rcx, rax
		call[r8 + 0x1260]
	}
}

void ��ͼCall()
{
	INT64 ��ͼָ�� = ��Ϸ�հ׵�ַ;
	*(int*)��ͼָ�� = 3;
	__asm
	{
		mov rcx, ��ͼָ��
		mov rcx, [rcx]
		mov rax, ��ͼCALL
		call rax
		mov rbx, ��Ϸ�հ׵�ַ
		mov [rbx], rax
	}
}