#include "pch.h"


int ���_��(int ����һ, int ������, int ������, int ������, int ������, int ������)
{
	__asm
	{
		mov eax, [������]
		add eax, [������]
		add eax, [������]
		add eax, [������]
		add eax, [������]
		add[����һ], eax
	}
	return ����һ;
}

int ���_��(int ����һ, int ������, int ������, int ������, int ������, int ������)
{
	int ��� = 0;
	__asm
	{
		mov eax, ����һ
		sub eax, ������
		sub eax, ������
		sub eax, ������
		sub eax, ������
		sub eax, ������
		mov ���, eax
	}
	return ���;
}

int ���_��(int ����һ, int ������)
{
	__asm
	{
		mov eax, ����һ
		mov ecx, ������
		imul eax, ecx
		leave
		retn 0008h
	}
	return 0;
}

int ���_��(int ����һ, int ������)
{
	__asm
	{
		pop ebp
		mov eax, ����һ
		mov ecx, ������
		cdq
		div ecx
		retn 0008h
	}
	return 0;
}

void JMP��ת(INT64 ��ַ, INT64 ��ת��ַ)
{
	byte Cpi[17] = { 255, 37, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 144, 144, 144 };
	*(INT64*)(Cpi + 6) = ��ת��ַ;
	WriteProcessMemory(GetCurrentProcess(), (LPVOID)��ַ, Cpi, 17, 0);
}

wstring ���ı�(int a)
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

wstring ���ı�(INT64 �ڴ��ַ, int ����)
{
	wchar_t * temp = new wchar_t[����];
	memset(temp, 0, ����);
	wstring text = L"";
	if (IsBadReadPtr(reinterpret_cast<void*>(�ڴ��ַ), ����)) return text;
	memcpy(temp, reinterpret_cast<void*>(�ڴ��ַ), ����);
	text = temp;
	delete[]temp;
	return text;
}

wstring ͨ��ʱ��(int duration)
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
	wstring hou;// Сʱ
	wstring min; // ����
	wstring sec; // ��
	wstring msec; // ����
	if (hour != 0) {
		hou = ���ı�(hour);
	}
	if (minute != 0) {
		min = ���ı�(minute);
	}
	if (second != 0) {
		sec = ���ı�(second);
	}
	if (milliSecond != 0) {
		msec = ���ı�(milliSecond);
	}
	wstring ret;
	ret.append((hou.empty() ? L"" : hou + L"Сʱ") + (min.empty() ? L"" : min + L"��") + (sec.empty() ? L"" : sec + L"��") + (msec.empty() ? L"" : msec + L""));
	return ret;
}

wstring ȡ����ʱ��()
{
	SYSTEMTIME ʱ��ṹ;
	GetLocalTime(&ʱ��ṹ);
	wstring �� = to_wstring(ʱ��ṹ.wYear);
	wstring �� = to_wstring(ʱ��ṹ.wMonth);
	wstring �� = to_wstring(ʱ��ṹ.wDay);
	wstring ����;
	if (ʱ��ṹ.wDayOfWeek == 0) ���� = L"������";
	if (ʱ��ṹ.wDayOfWeek == 1) ���� = L"����һ";
	if (ʱ��ṹ.wDayOfWeek == 2) ���� = L"���ڶ�";
	if (ʱ��ṹ.wDayOfWeek == 3) ���� = L"������";
	if (ʱ��ṹ.wDayOfWeek == 4) ���� = L"������";
	if (ʱ��ṹ.wDayOfWeek == 5) ���� = L"������";
	if (ʱ��ṹ.wDayOfWeek == 6) ���� = L"������";

	wstring ʱ = to_wstring(ʱ��ṹ.wHour);
	if (ʱ��ṹ.wHour < 10) ʱ = L"0" + to_wstring(ʱ��ṹ.wHour);

	wstring �� = to_wstring(ʱ��ṹ.wMinute);
	if (ʱ��ṹ.wMinute < 10) �� = L"0" + to_wstring(ʱ��ṹ.wMinute);

	wstring �� = to_wstring(ʱ��ṹ.wSecond);
	if (ʱ��ṹ.wSecond < 10) �� = L"0" + to_wstring(ʱ��ṹ.wSecond);

	wstring ���� = to_wstring(ʱ��ṹ.wMilliseconds);

	return �� + L"��" + �� + L"��" + �� + L"�� " + ʱ + L":" + �� + L":" + ��;
}


INT64 ��ƫ����(INT64 address, vector<int> vec)
{
	INT64 tempaddress;
	tempaddress = address;
	for (size_t i = 0; i < vec.size(); ++i)
	{
		tempaddress = ��д_��������(tempaddress);
		tempaddress = tempaddress + vec.at(i);
	}
	return tempaddress;
}



double   ��д_��С����(ULONG64 ��_�ڴ��ַ)
{
	if (IsBadReadPtr((VOID*)��_�ڴ��ַ, 8))
	{
		return 0;
	}
	return *(double*)��_�ڴ��ַ;
}

DWORD    ��д_��������(ULONG64 ��_�ڴ��ַ)
{
	if (IsBadReadPtr((VOID*)��_�ڴ��ַ, 4))
	{
		return 0;
	}
	return *(DWORD*)��_�ڴ��ַ;
}

ULONG64  ��д_��������(ULONG64 ��_�ڴ��ַ)
{
	if (IsBadReadPtr((VOID*)��_�ڴ��ַ, 8))
	{
		return 0;
	}
	return *(ULONG64*)��_�ڴ��ַ;
}

BYTE     ��д_���ֽ���(ULONG64 ��_�ڴ��ַ)
{
	if (IsBadReadPtr((VOID*)��_�ڴ��ַ, 1))
	{
		return 0;
	}
	return *(BYTE*)��_�ڴ��ַ;
}

ULONG64     ��д_��������(ULONG64 ��_�ڴ��ַ)
{
	if (IsBadReadPtr((VOID*)��_�ڴ��ַ, 2))
	{
		return 0;
	}
	return *(ULONG64*)��_�ڴ��ַ;
}

vector<BYTE> ��д_���ֽڼ�(ULONG64 ��_�ڴ��ַ, DWORD ��_��ȡ����)
{
	vector<BYTE> ��_����ֵ;
	if (IsBadReadPtr((VOID*)��_�ڴ��ַ, ��_��ȡ����))
	{
		return {};
	}
	for (int i = 0; i < ��_��ȡ����; i++)
	{
		��_����ֵ.insert(��_����ֵ.end(), *(BYTE*)��_�ڴ��ַ++);
	}
	return ��_����ֵ;

}

VOID ��д_д������(ULONG64 ��_�ڴ��ַ, ULONG64 ��_д������)
{
	if (IsBadReadPtr((VOID*)��_�ڴ��ַ, 8))
	{
		return;
	}
	DWORD old_protect;
	VirtualProtect((LPVOID)��_�ڴ��ַ, 8, 64, &old_protect);
	*(ULONG64*)��_�ڴ��ַ = ��_д������;
	VirtualProtect((LPVOID)��_�ڴ��ַ, 8, old_protect, &old_protect);
}

VOID ��д_д�ֽ���(ULONG64 ��_�ڴ��ַ, BYTE ��_д������)
{
	if (IsBadReadPtr((VOID*)��_�ڴ��ַ, 4))
	{
		return;
	}
	DWORD old_protect;
	VirtualProtect((LPVOID)��_�ڴ��ַ, 1, 64, &old_protect);
	*(BYTE*)��_�ڴ��ַ = ��_д������;
	VirtualProtect((LPVOID)��_�ڴ��ַ, 1, old_protect, &old_protect);
}

VOID ��д_д������(ULONG64 ��_�ڴ��ַ, DWORD ��_д������)
{
	if (IsBadReadPtr((VOID*)��_�ڴ��ַ, 4))
	{
		return;
	}
	DWORD old_protect;
	VirtualProtect((LPVOID)��_�ڴ��ַ, 4, 64, &old_protect);
	*(DWORD*)��_�ڴ��ַ = ��_д������;
	VirtualProtect((LPVOID)��_�ڴ��ַ, 4, old_protect, &old_protect);
}

VOID ��д_дС����(ULONG64 ��_�ڴ��ַ, float ��_д������)
{
	if (IsBadReadPtr((VOID*)��_�ڴ��ַ, 4))
	{
		return;
	}
	DWORD old_protect;
	VirtualProtect((LPVOID)��_�ڴ��ַ, 4, 64, &old_protect);
	*(float*)��_�ڴ��ַ = ��_д������;
	VirtualProtect((LPVOID)��_�ڴ��ַ, 4, old_protect, &old_protect);
}

VOID ��д_д�ֽڼ�(ULONG64 ��_�ڴ��ַ, vector<BYTE> ��_д������)
{
	if (IsBadReadPtr((VOID*)��_�ڴ��ַ, 1))
	{
		return;
	}
	DWORD old_protect;
	VirtualProtect((LPVOID)��_�ڴ��ַ, ��_д������.size(), 64, &old_protect);//�޸��ڴ�����
	for (size_t i = 0; i < ��_д������.size(); i++)
	{
		*(BYTE*)��_�ڴ��ַ++ = ��_д������[i];
	}
	VirtualProtect((LPVOID)��_�ڴ��ַ, ��_д������.size(), old_protect, &old_protect);//��ԭ�ڴ�����
}

VOID ��д_д������(ULONG64 ��_�ڴ��ַ, WORD ��_д������)
{
	if (IsBadReadPtr((VOID*)��_�ڴ��ַ, 4))
	{
		return;
	}
	DWORD old_protect;
	VirtualProtect((LPVOID)��_�ڴ��ַ, 4, 64, &old_protect);
	*(WORD*)��_�ڴ��ַ = ��_д������;
	VirtualProtect((LPVOID)��_�ڴ��ַ, 4, old_protect, &old_protect);
}

wstring �������ı�(DWORD ��_��ֵ)
{
	wstring ��_����ֵ;
	WCHAR ��_������[10] = { 0 };
	_itow_s(��_��ֵ, ��_������, 10);
	��_����ֵ = ��_������;
	return ��_����ֵ;
}

wstring  ���������ı�(ULONG64 ��_��ֵ)
{
	wstring ��_����ֵ;
	WCHAR ��_������[30] = { 0 };
	_i64tow_s(��_��ֵ, ��_������, 30, 10);
	��_����ֵ = ��_������;
	return ��_����ֵ;
}

wstring  ��������ʮ������(ULONG64 ��_��ֵ)
{
	wstring ��_����ֵ;
	WCHAR ��_������[30] = { 0 };
	_i64tow_s(��_��ֵ, ��_������, 30, 16);
	wstring ��_��ʱ�ı� = ��_������;
	transform(��_��ʱ�ı�.begin(), ��_��ʱ�ı�.end(), back_inserter(��_����ֵ), toupper);
	return ��_����ֵ;
}

wstring UnicodeתAnsi(vector<BYTE> ��_�ֽڼ�)
{
	DWORD ��_�ֽڳ��� = ��_�ֽڼ�.size();
	CHAR* ��_Unicode = new CHAR[��_�ֽڳ���];
	for (size_t i = 0; i < ��_�ֽڳ���; i++)
	{
		��_Unicode[i] = ��_�ֽڼ�[i];
	}
	//UniCode��Ansi
	DWORD ��_���� = WideCharToMultiByte(936, 512, (LPCWCH)��_Unicode, -1, 0, 0, 0, FALSE);
	CHAR* ������ = new CHAR[��_����];
	WideCharToMultiByte(936, 512, (LPCWCH)��_Unicode, -1, ������, ��_����, NULL, NULL);

	// stringתwstring
	DWORD nLen = MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, ������, -1, NULL, 0);
	if (nLen == 0)
	{
		return NULL;
	}
	WCHAR* pResult = new WCHAR[nLen];
	MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, ������, -1, pResult, nLen);

	return pResult;
}


int ��������(ULONG64 ��_���ܵ�ַ)
{
	// | λ��
	// & λ��
	// ^ λ���
	// << ����
	// >> ����

	DWORD nEax, nEdx;
	ULONG64 nEsi;
	nEax = ��д_��������(��_���ܵ�ַ);
	nEsi = ��д_��������(���ܻ�ַ);
	nEdx = nEax;
	nEdx >>= 16;
	nEdx = ��д_��������(nEsi + nEdx * 8 + 0x38);
	nEax &= 0xFFFF;
	nEax = ��д_��������(nEdx + nEax * 4 + 0x211C);
	nEax &= 0xFFFF;
	nEdx = nEax;
	nEsi = nEdx;
	nEsi <<= 16;
	nEsi += nEdx;
	nEdx = ��д_��������(��_���ܵ�ַ + 4);
	nEax = nEsi ^ nEdx;
	return nEax;
}


VOID ��������(ULONG64 ��_���ܵ�ַ, DWORD ��_�޸���ֵ)
{
	DWORD ��_����ID = ��д_��������(��_���ܵ�ַ);
	DWORD ��_ƫ�Ʋ��� = ��д_��������(��д_��������(���ܻ�ַ) + (��_����ID >> 16) * 8 + 56);
	DWORD ��_ƫ�Ƶ�ַ = ��_ƫ�Ʋ��� + (��_����ID & 65535) * 4 + 8476;
	��_ƫ�Ʋ��� = ��д_��������(��_ƫ�Ƶ�ַ);
	DWORD data = ��_ƫ�Ʋ��� & 65535;
	data = data + (data << 16);
	WORD ax, si;
	ax = ��_ƫ�Ʋ��� & 65535;
	ULONG64 ��_��ַβ = ��_���ܵ�ַ & 15;
	if (��_��ַβ == 0)
	{
		si = (��_�޸���ֵ >> 16);
		si = si - ax;
		si = si + ��_�޸���ֵ;
	}
	else if (��_��ַβ == 4)
	{
		si = (��_�޸���ֵ & 65535) - (��_�޸���ֵ >> 16);
	}
	else if (��_��ַβ == 8)
	{
		si = (��_�޸���ֵ >> 16);
		si = si * ��_�޸���ֵ;
	}
	else if (��_��ַβ == 12)
	{
		si = (��_�޸���ֵ >> 16);
		si = si + ��_�޸���ֵ;
		si = si + ax;
	}
	else
	{
		return;
	}
	ax = si ^ ax;
	��д_д������(��_ƫ�Ƶ�ַ + 2, ax);
	��д_д������(��_���ܵ�ַ + 4, (data ^ ��_�޸���ֵ));
}



