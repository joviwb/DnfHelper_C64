#include "pch.h"


int 汇编_加(int 参数一, int 参数二, int 参数三, int 参数四, int 参数五, int 参数六)
{
	__asm
	{
		mov eax, [参数二]
		add eax, [参数三]
		add eax, [参数四]
		add eax, [参数五]
		add eax, [参数六]
		add[参数一], eax
	}
	return 参数一;
}

int 汇编_减(int 参数一, int 参数二, int 参数三, int 参数四, int 参数五, int 参数六)
{
	int 结果 = 0;
	__asm
	{
		mov eax, 参数一
		sub eax, 参数二
		sub eax, 参数三
		sub eax, 参数四
		sub eax, 参数五
		sub eax, 参数六
		mov 结果, eax
	}
	return 结果;
}

int 汇编_乘(int 参数一, int 参数二)
{
	__asm
	{
		mov eax, 参数一
		mov ecx, 参数二
		imul eax, ecx
		leave
		retn 0008h
	}
	return 0;
}

int 汇编_除(int 参数一, int 参数二)
{
	__asm
	{
		pop ebp
		mov eax, 参数一
		mov ecx, 参数二
		cdq
		div ecx
		retn 0008h
	}
	return 0;
}

void JMP跳转(INT64 地址, INT64 跳转地址)
{
	byte Cpi[17] = { 255, 37, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 144, 144, 144 };
	*(INT64*)(Cpi + 6) = 跳转地址;
	WriteProcessMemory(GetCurrentProcess(), (LPVOID)地址, Cpi, 17, 0);
}

wstring 到文本(int a)
{
	wstring result;
	WCHAR str[10];
	_itow_s(a, str, 10);
	result = str;
	return result;
}

ULONG_PTR Alloc(SIZE_T size)
{
	return (ULONG_PTR)VirtualAlloc(NULL, size, MEM_COMMIT | MEM_TOP_DOWN, PAGE_EXECUTE_READWRITE);
}

wstring 读文本(INT64 内存地址, int 长度)
{
	wchar_t * temp = new wchar_t[长度];
	memset(temp, 0, 长度);
	wstring text = L"";
	if (IsBadReadPtr(reinterpret_cast<void*>(内存地址), 长度)) return text;
	memcpy(temp, reinterpret_cast<void*>(内存地址), 长度);
	text = temp;
	delete[]temp;
	return text;
}

wstring 通关时间(int duration)
{
	int ss = 1000;
	int mi = ss * 60;
	int hh = mi * 60;
	int dd = hh * 24;
	long day = duration / dd;
	long hour = (duration - day * dd) / hh;
	long minute = (duration - day * dd - hour * hh) / mi;
	long second = (duration - day * dd - hour * hh - minute * mi) / ss;
	long milliSecond = duration - day * dd - hour * hh - minute * mi - second * ss;
	wstring hou;// 小时
	wstring min; // 分钟
	wstring sec; // 秒
	wstring msec; // 毫秒
	if (hour != 0) {
		hou = 到文本(hour);
	}
	if (minute != 0) {
		min = 到文本(minute);
	}
	if (second != 0) {
		sec = 到文本(second);
	}
	if (milliSecond != 0) {
		msec = 到文本(milliSecond);
	}
	wstring ret;
	ret.append((hou.empty() ? L"" : hou + L"小时") + (min.empty() ? L"" : min + L"分") + (sec.empty() ? L"" : sec + L"秒") + (msec.empty() ? L"" : msec + L""));
	return ret;
}

wstring 取现行时间()
{
	SYSTEMTIME 时间结构;
	GetLocalTime(&时间结构);
	wstring 年 = to_wstring(时间结构.wYear);
	wstring 月 = to_wstring(时间结构.wMonth);
	wstring 日 = to_wstring(时间结构.wDay);
	wstring 星期;
	if (时间结构.wDayOfWeek == 0) 星期 = L"星期日";
	if (时间结构.wDayOfWeek == 1) 星期 = L"星期一";
	if (时间结构.wDayOfWeek == 2) 星期 = L"星期二";
	if (时间结构.wDayOfWeek == 3) 星期 = L"星期三";
	if (时间结构.wDayOfWeek == 4) 星期 = L"星期四";
	if (时间结构.wDayOfWeek == 5) 星期 = L"星期五";
	if (时间结构.wDayOfWeek == 6) 星期 = L"星期六";

	wstring 时 = to_wstring(时间结构.wHour);
	if (时间结构.wHour < 10) 时 = L"0" + to_wstring(时间结构.wHour);

	wstring 分 = to_wstring(时间结构.wMinute);
	if (时间结构.wMinute < 10) 分 = L"0" + to_wstring(时间结构.wMinute);

	wstring 秒 = to_wstring(时间结构.wSecond);
	if (时间结构.wSecond < 10) 秒 = L"0" + to_wstring(时间结构.wSecond);

	wstring 毫秒 = to_wstring(时间结构.wMilliseconds);

	return 年 + L"年" + 月 + L"月" + 日 + L"日 " + 时 + L":" + 分 + L":" + 秒;
}


INT64 读偏移型(INT64 address, vector<int> vec)
{
	INT64 tempaddress;
	tempaddress = address;
	for (size_t i = 0; i < vec.size(); ++i)
	{
		tempaddress = 读写_读长整数(tempaddress);
		tempaddress = tempaddress + vec.at(i);
	}
	return tempaddress;
}



double   读写_读小数型(ULONG64 参_内存地址)
{
	if (IsBadReadPtr((VOID*)参_内存地址, 8))
	{
		return 0;
	}
	return *(double*)参_内存地址;
}

DWORD    读写_读整数型(ULONG64 参_内存地址)
{
	if (IsBadReadPtr((VOID*)参_内存地址, 4))
	{
		return 0;
	}
	return *(DWORD*)参_内存地址;
}

ULONG64  读写_读长整数(ULONG64 参_内存地址)
{
	if (IsBadReadPtr((VOID*)参_内存地址, 8))
	{
		return 0;
	}
	return *(ULONG64*)参_内存地址;
}

BYTE     读写_读字节型(ULONG64 参_内存地址)
{
	if (IsBadReadPtr((VOID*)参_内存地址, 1))
	{
		return 0;
	}
	return *(BYTE*)参_内存地址;
}

ULONG64     读写_读短整数(ULONG64 参_内存地址)
{
	if (IsBadReadPtr((VOID*)参_内存地址, 2))
	{
		return 0;
	}
	return *(ULONG64*)参_内存地址;
}

vector<BYTE> 读写_读字节集(ULONG64 参_内存地址, DWORD 参_读取长度)
{
	vector<BYTE> 局_返回值;
	if (IsBadReadPtr((VOID*)参_内存地址, 参_读取长度))
	{
		return {};
	}
	for (int i = 0; i < 参_读取长度; i++)
	{
		局_返回值.insert(局_返回值.end(), *(BYTE*)参_内存地址++);
	}
	return 局_返回值;

}

VOID 读写_写长整数(ULONG64 参_内存地址, ULONG64 参_写入数据)
{
	if (IsBadReadPtr((VOID*)参_内存地址, 8))
	{
		return;
	}
	DWORD old_protect;
	VirtualProtect((LPVOID)参_内存地址, 8, 64, &old_protect);
	*(ULONG64*)参_内存地址 = 参_写入数据;
	VirtualProtect((LPVOID)参_内存地址, 8, old_protect, &old_protect);
}

VOID 读写_写字节型(ULONG64 参_内存地址, BYTE 参_写入数据)
{
	if (IsBadReadPtr((VOID*)参_内存地址, 4))
	{
		return;
	}
	DWORD old_protect;
	VirtualProtect((LPVOID)参_内存地址, 1, 64, &old_protect);
	*(BYTE*)参_内存地址 = 参_写入数据;
	VirtualProtect((LPVOID)参_内存地址, 1, old_protect, &old_protect);
}

VOID 读写_写整数型(ULONG64 参_内存地址, DWORD 参_写入数据)
{
	if (IsBadReadPtr((VOID*)参_内存地址, 4))
	{
		return;
	}
	DWORD old_protect;
	VirtualProtect((LPVOID)参_内存地址, 4, 64, &old_protect);
	*(DWORD*)参_内存地址 = 参_写入数据;
	VirtualProtect((LPVOID)参_内存地址, 4, old_protect, &old_protect);
}

VOID 读写_写小数型(ULONG64 参_内存地址, float 参_写入数据)
{
	if (IsBadReadPtr((VOID*)参_内存地址, 4))
	{
		return;
	}
	DWORD old_protect;
	VirtualProtect((LPVOID)参_内存地址, 4, 64, &old_protect);
	*(float*)参_内存地址 = 参_写入数据;
	VirtualProtect((LPVOID)参_内存地址, 4, old_protect, &old_protect);
}

VOID 读写_写字节集(ULONG64 参_内存地址, vector<BYTE> 参_写入数据)
{
	if (IsBadReadPtr((VOID*)参_内存地址, 1))
	{
		return;
	}
	DWORD old_protect;
	VirtualProtect((LPVOID)参_内存地址, 参_写入数据.size(), 64, &old_protect);//修改内存属性
	for (size_t i = 0; i < 参_写入数据.size(); i++)
	{
		*(BYTE*)参_内存地址++ = 参_写入数据[i];
	}
	VirtualProtect((LPVOID)参_内存地址, 参_写入数据.size(), old_protect, &old_protect);//还原内存属性
}

VOID 读写_写短整数(ULONG64 参_内存地址, WORD 参_写入数据)
{
	if (IsBadReadPtr((VOID*)参_内存地址, 4))
	{
		return;
	}
	DWORD old_protect;
	VirtualProtect((LPVOID)参_内存地址, 4, 64, &old_protect);
	*(WORD*)参_内存地址 = 参_写入数据;
	VirtualProtect((LPVOID)参_内存地址, 4, old_protect, &old_protect);
}

wstring 整数到文本(DWORD 参_数值)
{
	wstring 局_返回值;
	WCHAR 局_缓冲区[10] = { 0 };
	_itow_s(参_数值, 局_缓冲区, 10);
	局_返回值 = 局_缓冲区;
	return 局_返回值;
}

wstring  长整数到文本(ULONG64 参_数值)
{
	wstring 局_返回值;
	WCHAR 局_缓冲区[30] = { 0 };
	_i64tow_s(参_数值, 局_缓冲区, 30, 10);
	局_返回值 = 局_缓冲区;
	return 局_返回值;
}

wstring  长整数到十六进制(ULONG64 参_数值)
{
	wstring 局_返回值;
	WCHAR 局_缓冲区[30] = { 0 };
	_i64tow_s(参_数值, 局_缓冲区, 30, 16);
	wstring 局_临时文本 = 局_缓冲区;
	transform(局_临时文本.begin(), 局_临时文本.end(), back_inserter(局_返回值), toupper);
	return 局_返回值;
}

wstring Unicode转Ansi(vector<BYTE> 参_字节集)
{
	DWORD 局_字节长度 = 参_字节集.size();
	CHAR* 局_Unicode = new CHAR[局_字节长度];
	for (size_t i = 0; i < 局_字节长度; i++)
	{
		局_Unicode[i] = 参_字节集[i];
	}
	//UniCode到Ansi
	DWORD 局_计数 = WideCharToMultiByte(936, 512, (LPCWCH)局_Unicode, -1, 0, 0, 0, FALSE);
	CHAR* 缓冲区 = new CHAR[局_计数];
	WideCharToMultiByte(936, 512, (LPCWCH)局_Unicode, -1, 缓冲区, 局_计数, NULL, NULL);

	// string转wstring
	DWORD nLen = MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, 缓冲区, -1, NULL, 0);
	if (nLen == 0)
	{
		return NULL;
	}
	WCHAR* pResult = new WCHAR[nLen];
	MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, 缓冲区, -1, pResult, nLen);

	return pResult;
}


int 超级解密(ULONG64 参_解密地址)
{
	// | 位或
	// & 位与
	// ^ 位异或
	// << 左移
	// >> 右移

	DWORD nEax, nEdx;
	ULONG64 nEsi;
	nEax = 读写_读整数型(参_解密地址);
	nEsi = 读写_读长整数(解密基址);
	nEdx = nEax;
	nEdx >>= 16;
	nEdx = 读写_读整数型(nEsi + nEdx * 8 + 0x38);
	nEax &= 0xFFFF;
	nEax = 读写_读整数型(nEdx + nEax * 4 + 0x211C);
	nEax &= 0xFFFF;
	nEdx = nEax;
	nEsi = nEdx;
	nEsi <<= 16;
	nEsi += nEdx;
	nEdx = 读写_读整数型(参_解密地址 + 4);
	nEax = nEsi ^ nEdx;
	return nEax;
}


VOID 超级加密(ULONG64 参_加密地址, DWORD 参_修改数值)
{
	DWORD 局_加密ID = 读写_读整数型(参_加密地址);
	DWORD 局_偏移参数 = 读写_读整数型(读写_读长整数(解密基址) + (局_加密ID >> 16) * 8 + 56);
	DWORD 局_偏移地址 = 局_偏移参数 + (局_加密ID & 65535) * 4 + 8476;
	局_偏移参数 = 读写_读整数型(局_偏移地址);
	DWORD data = 局_偏移参数 & 65535;
	data = data + (data << 16);
	WORD ax, si;
	ax = 局_偏移参数 & 65535;
	ULONG64 局_地址尾 = 参_加密地址 & 15;
	if (局_地址尾 == 0)
	{
		si = (参_修改数值 >> 16);
		si = si - ax;
		si = si + 参_修改数值;
	}
	else if (局_地址尾 == 4)
	{
		si = (参_修改数值 & 65535) - (参_修改数值 >> 16);
	}
	else if (局_地址尾 == 8)
	{
		si = (参_修改数值 >> 16);
		si = si * 参_修改数值;
	}
	else if (局_地址尾 == 12)
	{
		si = (参_修改数值 >> 16);
		si = si + 参_修改数值;
		si = si + ax;
	}
	else
	{
		return;
	}
	ax = si ^ ax;
	读写_写短整数(局_偏移地址 + 2, ax);
	读写_写整数型(参_加密地址 + 4, (data ^ 参_修改数值));
}



