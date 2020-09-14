#include "pch.h"

void Send_缓冲Call(int cdov)
{
	__asm {
		mov rax, 发包基址//发包基址
		mov rcx, [rax]
		mov edx, cdov
		mov rax, 缓冲CALL//缓冲CALL
		call rax
	}
}
void Send_加密Call(int 数值, INT64 加密CALL1)
{
	INT64 cdov = 0;
	if (加密CALL1 == 1)cdov = 加密CALL;
	if (加密CALL1 == 2)cdov = 加密CALL + 64;
	if (加密CALL1 == 4)cdov = 加密CALL + 128;
	if (加密CALL1 == 8)cdov = 加密CALL + 192;
	__asm {
		mov rax, 发包基址//发包基址
		mov rcx, [rax]
		mov edx, 数值
		mov rax, cdov//加密包
		call rax
	}
}
void Send_发包Call()
{
	__asm {
		mov rax, 发包CALL//发包CALL
		call rax
	}
}

void 评分Call(int 评分数值)
{
	INT64 空白地址 = 游戏空白地址;
	*(int*)(空白地址) = 评分数值;
	INT64 评分数据 = *(INT64*)(评分基址) + 评分偏移;
	__asm {
		mov rcx, 评分数据
		mov r8, rcx
		add r8, 0x4
		mov rdx, 空白地址
		mov rax, 评分CALL
		call rax
	}
}

void 技能Call(INT64 触发指针, int 代码, int 伤害, int x, int y, int z, int 大小)
{
	INT64 空白地址 = Alloc(0x200);
	float speed = 大小;
	*(int*)(空白地址 + 0) = 触发指针;
	*(int*)(空白地址 + 16) = 代码;
	*(int*)(空白地址 + 20) = 伤害;
	*(int*)(空白地址 + 32) = x;
	*(int*)(空白地址 + 36) = y;
	*(int*)(空白地址 + 40) = z;
	*(int*)(空白地址 + 140) = *(long*)& speed;
	*(int*)(空白地址 + 144) = 65535;
	*(int*)(空白地址 + 148) = 65535;
	__asm
	{
		sub rsp, 0x200
		mov rcx, 空白地址
		call 技能CALL
		add rsp, 0x200
	}
}

void 坐标call(INT64 触发指针, INT64 X, INT64 Y, INT64 Z)
{
	__asm
	{
		mov rcx, 触发指针
		mov rdx, X
		mov r8, Y
		mov r9, Z
		mov rax, [rcx]
		mov rax, [rax + 0x1A0]
		call rax
	}
}

void 丢弃Call(int 背包位置)
{
	INT64 背包数据 = *(INT64*)(*(INT64*)(人物基址) + 背包偏移);
	__asm
	{
		 mov r9d, 0x1
		 mov r8d, 0x1
		 mov edx, 背包位置
		 mov rcx, 背包数据
		 mov rax, 丢弃CALL
		 call rax
}
}

void 区域call(int 副本)
{
	int 大区域;
	int 小区域;
	int X;
	int Y;
	INT64 区域_基址 = *(INT64*)(区域基址);
	_asm
	{
		mov r8d, 副本
		mov rdx, -0x1
		mov rcx, 区域_基址
		call 区域CALL
	}
	大区域 = *(int*)(*(INT64*)(区域基址) + 区域偏移);
	小区域 = *(int*)(*(INT64*)(区域基址) + 区域偏移 + 4);
	X = *(int*)(*(INT64*)(区域基址) + 区域偏移 + 8);
	Y = *(int*)(*(INT64*)(区域基址) + 区域偏移 + 12);
	组包_城镇移动(大区域, 小区域, X, Y);
}

void 跳过Call()
{
	__asm
	{
		or r9d, -1
		or r8d, r9d
		mov edx, 1
		mov rcx, 任务基址
		mov rcx, [rcx]
		call 跳过CALL
}
}

void 接受Call(int 参_任务)
{
	__asm
	{
		 mov edx, 参_任务
		 call 接受CALL
}
}

void 完成Call(int 参_任务, int 参_次数)
{
	for (size_t i = 1; i <= 参_次数; i++)
	{
		__asm
		{
			mov bl, 0xFF
			movzx r9d, bl
			mov r8b, 0xFF
			mov edx, 参_任务
			call 完成CALL
		}
	}
}

void 提交Call(int 参_任务)
{
	__asm
	{
		 mov r13d, 1
		 mov r14d, 0xFFFFFFFF
		 mov r9d, r13d
		 mov r8d, r14d
		 mov rcx, 任务基址
		 mov rcx, [rcx]
	     mov edx, 参_任务
		 call 提交CALL
}
}

void 物品Call(int 物品代码)
{
	__asm
	{
		mov rax, 0x14A6805F0  //人物地址
		mov rax, [rax]
		mov r8, [rax]
		mov edx, 物品代码
		mov rcx, rax
		call[r8 + 0x1260]
	}
}

void 地图Call()
{
	INT64 地图指针 = 游戏空白地址;
	*(int*)地图指针 = 3;
	__asm
	{
		mov rcx, 地图指针
		mov rcx, [rcx]
		mov rax, 地图CALL
		call rax
		mov rbx, 游戏空白地址
		mov [rbx], rax
	}
}