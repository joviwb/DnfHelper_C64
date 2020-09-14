#include "pch.h"

void 游戏公告(wstring 公告内容)
{
	LPCWSTR tempStr;
	公告内容 = L"南樱  " + 公告内容 + L" ";
	tempStr = 公告内容.c_str();
	__asm	mov rsi, 0
	__asm	mov rcx, 商店基址
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
	__asm	call 喇叭公告
}

void 系统公告(wstring 公告内容)
{
	LPCWSTR tempStr;
	公告内容 = L"南樱  " + 公告内容 + L" ";
	tempStr = 公告内容.c_str();
	__asm	mov rsi, 0
	__asm	mov rcx, 商店基址
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
	__asm	call 喇叭公告
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




VOID 神话公告(wstring 内容, int 类型)
{
	LPCWSTR tempStr;
	内容 = L"南樱  " + 内容 + L" ";
	tempStr = 内容.c_str();
	ULONG64 空白地址 = 游戏空白地址;
	*(int*)(空白地址 + 8) = (INT64)tempStr;
	*(int*)(空白地址 + 24) = 0;
	*(int*)(空白地址 + 28) = -1;
	*(int*)(空白地址 + 32) = 0xFF00FF00;
	if (类型 == 0)
	{
		*(int*)(空白地址 + 36) = 37;
	}
	if (类型 == 1)
	{
		*(int*)(空白地址 + 36) = 17;
	}
	if (类型 == 2)
	{
		*(int*)(空白地址 + 36) = 60;
	}
	*(int*)(空白地址 + 40) = 16;
	*(int*)(空白地址 + 108) = 65535;
	__asm
	{
		mov rdx, 空白地址
		mov rsi, 公告数据
		mov rsi, [rsi]
		mov rcx, rsi
		mov edi, -1
		call 公告CALL
	}
}

