#include "pch.h"

void ��Ϸ����(wstring ��������)
{
	LPCWSTR tempStr;
	�������� = L"��ӣ  " + �������� + L" ";
	tempStr = ��������.c_str();
	__asm	mov rsi, 0
	__asm	mov rcx, �̵��ַ
	__asm	mov rcx, [rcx]
	__asm	mov rcx, [rcx + 0xA0]
	__asm	mov rdx, tempStr
	__asm	mov qword ptr[rsp + 0x40], rsi
	__asm	mov byte ptr[rsp + 0x38], 00
	__asm	mov byte ptr[rsp + 0x30], 00
	__asm	mov qword ptr[rsp + 0x28], rsi
	__asm	mov qword ptr[rsp + 0x20], rsi
	__asm	mov r8d, 0xFF00FF00
	__asm	mov r9d, 0x25
	__asm	call ���ȹ���
}

void ϵͳ����(wstring ��������)
{
	LPCWSTR tempStr;
	�������� = L"��ӣ  " + �������� + L" ";
	tempStr = ��������.c_str();
	__asm	mov rsi, 0
	__asm	mov rcx, �̵��ַ
	__asm	mov rcx, [rcx]
	__asm	mov rcx, [rcx + 0xA0]
	__asm	mov rdx, tempStr
	__asm	mov qword ptr[rsp + 0x40], rsi
	__asm	mov byte ptr[rsp + 0x38], 00
	__asm	mov byte ptr[rsp + 0x30], 00
	__asm	mov qword ptr[rsp + 0x28], rsi
	__asm	mov qword ptr[rsp + 0x20], rsi
	__asm	mov r8d, 0xFF0000FF
	__asm	mov r9d, 0x11
	__asm	call ���ȹ���
}

void OutputDebugPrintf(const char * strOutputString, ...)
{
#define PUT_PUT_DEBUG_BUF_LEN   1024
	char strBuffer[PUT_PUT_DEBUG_BUF_LEN] = { 0 };
	va_list vlArgs;

	va_start(vlArgs, strOutputString);
	_vsnprintf_s(strBuffer, sizeof(strBuffer) - 1, strOutputString, vlArgs);  //_vsnprintf_s  _vsnprintf
	va_end(vlArgs);
	strcat_s(strBuffer, "|print");
	OutputDebugStringA(strBuffer);  //OutputDebugString    // OutputDebugStringW

}




VOID �񻰹���(wstring ����, int ����)
{
	LPCWSTR tempStr;
	���� = L"��ӣ  " + ���� + L" ";
	tempStr = ����.c_str();
	ULONG64 �հ׵�ַ = ��Ϸ�հ׵�ַ;
	*(int*)(�հ׵�ַ + 8) = (INT64)tempStr;
	*(int*)(�հ׵�ַ + 24) = 0;
	*(int*)(�հ׵�ַ + 28) = -1;
	*(int*)(�հ׵�ַ + 32) = 0xFF00FF00;
	if (���� == 0)
	{
		*(int*)(�հ׵�ַ + 36) = 37;
	}
	if (���� == 1)
	{
		*(int*)(�հ׵�ַ + 36) = 17;
	}
	if (���� == 2)
	{
		*(int*)(�հ׵�ַ + 36) = 60;
	}
	*(int*)(�հ׵�ַ + 40) = 16;
	*(int*)(�հ׵�ַ + 108) = 65535;
	__asm
	{
		mov rdx, �հ׵�ַ
		mov rsi, ��������
		mov rsi, [rsi]
		mov rcx, rsi
		mov edi, -1
		call ����CALL
	}
}

