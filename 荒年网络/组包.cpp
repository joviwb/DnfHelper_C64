#include "pch.h"

void 组包_城镇移动(int 城镇区域, int 城镇编号, int 城镇横轴, int 城镇纵轴)
{
	Send_缓冲Call(36);
	Send_加密Call(城镇区域, 1);
	Send_加密Call(城镇编号, 1);
	Send_加密Call(城镇横轴, 2);
	Send_加密Call(城镇纵轴, 2);
	Send_加密Call(5, 1);
	Send_加密Call(城镇区域, 2);
	Send_加密Call(0, 2);
	Send_加密Call(0, 4);
	Send_加密Call(0, 1);
	Send_发包Call();
}

void 组包_拾取(int 对象编号)
{
	Send_缓冲Call(43);
	Send_加密Call(对象编号, 4);
	Send_加密Call(0, 1);
	Send_加密Call(1, 1);
	Send_加密Call(566, 2);
	Send_加密Call(291, 2);
	Send_加密Call(9961, 2);
	Send_加密Call(553, 2);
	Send_加密Call(285, 2);
	Send_加密Call(18802, 2);
	Send_加密Call(24743, 2);
	Send_发包Call();
}
void 组包_通关翻牌()
{
	Send_缓冲Call(69);
	Send_发包Call();
	Send_缓冲Call(70);
	Send_发包Call();
	Send_缓冲Call(71);
	Send_加密Call(0, 1);
	Send_加密Call(0, 1);
	Send_发包Call();
	Send_缓冲Call(1434);
	Send_发包Call();
	Sleep(500);
	Send_缓冲Call(42);
	Send_发包Call();
}

void 组包_领取翻牌()
{

	Send_缓冲Call(1434);
	Send_发包Call();
}


void Send_组包特殊()
{
	int 初始编号, 当前编号, 初始ID, 当前ID, I;
	初始编号 = 100000003;
	当前编号 = 全局_收包数据.参_地图编号;
	初始ID = 0x2325;
	当前ID = 当前编号 - 初始编号;
	I = 初始ID + 当前ID;
	if (读文本(读偏移型(商店基址 - 16, { 时间基址, 门型偏移, 地图名称, 0 }), 64) == L"智慧的引导")
	{
		Send_缓冲Call(34);
		Send_加密Call(34, 2);
		Send_加密Call(9000, 2);
		Send_加密Call(65535, 2);
		Send_加密Call(1, 2);
		Send_加密Call(65535, 2);
		Send_发包Call();
	}
	if (读文本(读偏移型(商店基址 - 16, { 时间基址, 门型偏移, 地图名称, 0 }), 64) == L"风暴航路")
	{
		Send_缓冲Call(34);
		Send_加密Call(34, 2);
		Send_加密Call(I, 2);
		Send_加密Call(65535, 2);
		Send_加密Call(1, 2);
		Send_加密Call(65535, 2);
		Send_发包Call();
	}
}

void 组包_强制回城()
{
	Send_缓冲Call(42);
	Send_发包Call();
}

void 组包_过图(int x, int y)
{
	Send_缓冲Call(45);
	Send_加密Call(x, 1);
	Send_加密Call(y, 1);
	Send_加密Call(0, 4);
	Send_加密Call(0, 4);
	Send_加密Call(0, 1);

	for (int i = 0; i < 9; i++)
	{
		Send_加密Call(0, 2);
	}

	for (int i = 0; i < 8; i++)
	{
		Send_加密Call(0, 4);
	}

	for (int i = 0; i < 7; i++)
	{
		Send_加密Call(0, 2);
	}

	Send_加密Call(0, 4);
	Send_加密Call(0, 2);
	Send_加密Call(0, 2);
	Send_加密Call(0, 2);
	Send_加密Call(0, 2);
	Send_加密Call(0, 2);
	Send_加密Call(0, 2);

	for (int i = 0; i < 16; i++)
	{
		Send_加密Call(0, 4);
	}
	Send_发包Call();

}


void 组包_分解(int 装备位置)
{
	Send_缓冲Call(26);
	Send_加密Call(0, 1);
	Send_加密Call(65535, 2);
	Send_加密Call(317, 4);
	Send_加密Call(1, 1);
	Send_加密Call(装备位置, 2);
	Send_发包Call();
}

void 组包_卖物(int 位置, int 数量)
{

	Send_缓冲Call(22);
	Send_加密Call(0, 1);
	Send_加密Call(位置, 2);
	Send_加密Call(数量, 4);
	Send_加密Call(29, 4);
	Send_加密Call(49, 4);
	Send_加密Call(位置 * 2 + 数量 * 2 + 1, 4);
	Send_发包Call();



}

void 组包_丢弃(int 装备指针)
{
	Send_缓冲Call(18);
	Send_加密Call(装备指针, 4);
	Send_加密Call(装备指针, 18);
	Send_加密Call(0, 1);
	Send_发包Call();
}

void 组包秒杀(unsigned short 服务器ID)
{
	Send_缓冲Call(39);
	Send_加密Call(服务器ID, 2);
	Send_加密Call(0, 2);
	for (int i = 0; i < 4; i++)
	{
		Send_加密Call(0, 4);
	}
	Send_加密Call(1, 1);
	Send_加密Call(273, 2);
	Send_加密Call(0, 2);
	Send_加密Call(0, 4);
	Send_加密Call(0, 2);
	Send_加密Call(0, 2);
	Send_加密Call(0, 2);
	for (int a = 0; a < 4; a++)
	{
		Send_加密Call(0, 1);
	}
	Send_加密Call(0, 2);
	Send_加密Call(0, 1);
	Send_加密Call(0, 4);
	Send_加密Call(0, 4);
	for (int b = 0; b < 7; b++)
	{
		Send_加密Call(0, 2);
	}
	Send_加密Call(0, 1);
	for (int c = 0; c < 16; c++)
	{
		Send_加密Call(0, 4);
	}
	Send_发包Call();
}

void 组包_选图()
{
	Send_缓冲Call(15);
	Send_加密Call(0, 4);
	Send_发包Call();
}

void 组包_进图(int 地图代码,int 地图难度, int 深渊投递, int 任务编号,int 星空深渊)
{
	Send_缓冲Call(16);
	Send_加密Call(地图代码, 4);
	Send_加密Call(地图难度, 1);
	Send_加密Call(0, 2);
	Send_加密Call(深渊投递, 1);
	Send_加密Call(0, 1);
	Send_加密Call(65535, 2);
	Send_加密Call(0, 4);
	Send_加密Call(0, 1);
	Send_加密Call(任务编号, 4);
	Send_加密Call(星空深渊, 1);
	Send_加密Call(0, 4);
	Send_发包Call();

}


void 组包_退出角色()
{
	Send_缓冲Call(7);
	Send_发包Call();
}

void 组包_选择角色(int 角色位置)
{
	Send_缓冲Call(4);
	Send_加密Call(角色位置, 2);
	Send_发包Call();
}

void 组包_整理背包()
{
	Send_缓冲Call(20);
	Send_加密Call(6, 4);
	Send_加密Call(16, 1);
	Send_加密Call(0, 1);
	Send_加密Call(24, 1);
	Send_加密Call(1, 1);
	Send_加密Call(32, 1);
	Send_加密Call(0, 1);
	Send_发包Call();

}

void 组包_修仙死亡(unsigned short 服务器ID)
{

	Send_缓冲Call(39);
	Send_加密Call(服务器ID, 4);
	Send_加密Call(1164, 2);
	Send_加密Call(0, 8);
	Send_加密Call(0, 4);
	Send_加密Call(0, 8);
	Send_加密Call(5, 4);
	Send_加密Call(1, 1);
	Send_加密Call(273, 2);
	Send_加密Call(1164, 2);
	Send_加密Call(0, 8);
	Send_加密Call(5, 2);
	Send_加密Call(1253, 2);
	Send_加密Call(321, 2);
	Send_加密Call(0, 1);
	Send_加密Call(0, 1);
	Send_加密Call(0, 1);
	Send_加密Call(0, 1);
	Send_加密Call(22908, 2);
	Send_加密Call(0, 1);
	Send_加密Call(91, 4);
	Send_加密Call(0, 8);
	Send_加密Call(900, 2);
	Send_加密Call(418, 2);
	Send_加密Call(1174, 2);
	Send_加密Call(332, 2);
	Send_加密Call(12, 2);
	Send_加密Call(25, 2);
	Send_加密Call(35, 2);
	Send_加密Call(0, 1);
	Send_加密Call(0, 1);
	Send_发包Call();
}

void 组包_存金币(int 数量)
{

	Send_缓冲Call(307);
	Send_加密Call(数量, 4);
	Send_发包Call();

}


void 组包_存金库(int 材料位置, int 物品代码, int 材料数量, int 金库位置)
{
	Send_缓冲Call(19);
	Send_加密Call(0, 1);
	Send_加密Call(材料位置, 2);
	Send_加密Call(物品代码, 4);
	Send_加密Call(材料数量, 4);
	Send_加密Call(12, 1);
	Send_加密Call(金库位置, 2);
	Send_加密Call(0, 4);
	Send_加密Call(0, 4);
	Send_加密Call(-1, 4);
	Send_加密Call(0, 1);
	Send_加密Call(0, 1);
	Send_发包Call();
}

