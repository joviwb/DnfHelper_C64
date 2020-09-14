#pragma once
#include <windows.h>
#include <vector>
#include <map>
#include <fstream>
#include <iostream>
#include <string>
#include<list>
#include <algorithm>
#include <sstream>
#include <process.h>
#include <tlhelp32.h>
#include <Subauth.h>
#include <shlobj.h>   
#include <Psapi.h>

using namespace std;
typedef unsigned char byte;
typedef unsigned int uint;
typedef void(*子程序指针)();





typedef struct 坐标型 {
	int X;
	int Y;
	int Z;
	int 参_横轴坐标;
	int 参_纵轴坐标;
	int 参_竖轴坐标;
};



//---------------------------------------按键---------------------------------------

class RegHotKey
{
public:
	RegHotKey();
	~RegHotKey();
	void InitRegHotKey();
	void UninstallRegHotKey();
	int InitMsg(MSG msg);
	int exec();
	static BOOL JudgeFristrLoad();
	/*static BOOL UnLoadThread();
	static unsigned int GetProcessIdFromName(string name);*/
private:
	static bool on_thread_off;

};



struct 开关结构
{
	bool 自动刷图开关;
	bool 技能全屏开关;

};

extern 开关结构 全局_总开关;

struct 遍历结构
{
	ULONG64 一级偏移;
	ULONG64 二级偏移;
	ULONG64 首地址;
	ULONG64 尾地址;
	DWORD 次数;
	size_t 怪物数量;
	ULONG64 怪物地址;
	ULONG 怪物类型A;
	ULONG 怪物类型B;
	ULONG 怪物阵营;
	ULONG64 怪物血量;
	DWORD 技能代码;
	DWORD 技能伤害;
	DWORD 技能个数 = NULL;
	DWORD 技能模式;
};



struct 全局自动
{
	DWORD 全局任务;
	DWORD 全_回走;
	DWORD 副本编号;
	DWORD 副本难度;
	bool 参_已经进图;
	bool 参_可以顺图;
	bool 参_切换角色;
	DWORD 参_刷图角色;
	DWORD 参_公告角色;
	DWORD 参_顺图方向;
	DWORD 参_顺图计次;
	DWORD 参_每日角色;
	DWORD 参_暗黑神殿;
	DWORD 参_无底坑道;
	DWORD 参_记忆之地;
	DWORD 参_皇宫根特;
	DWORD 参_痛苦地下室;
};

extern 全局自动 全局_自动;

struct 收包数据
{
	WNDPROC 进程;
	HWND 游戏句柄;
	坐标型 参_当前坐标;
	坐标型 参_领主坐标;
	ULONG64 参_人物指针;
	DWORD   参_地图编号;
	BYTE 参_地图难度;
	BYTE 参_地图序号;
	int 参_怪物数量;
	int 参_拾取变量;
	int 参_拾取数量;
	int 参_收包计次;
	int 参_物品编号;
	int 参_通关计次;
	int 参_怪物编号;
	int 怪物数量;
	wstring 参_通关时间;
};

extern 收包数据 全局_收包数据;

typedef struct 地图数据
{
	CHAR* 地图名称;
	DWORD 地图编号;
	vector<DWORD> 地图通道;
	坐标型 起始坐标;
	坐标型 终点坐标;
	DWORD 宽;
	DWORD 高;
	vector<坐标型> 地图走法;
	DWORD 消耗疲劳;
	DWORD 通道数量;
	ULONG64 临时变量;
};

typedef struct 游戏地图
{
	坐标型 地图坐标;
	BOOL 地图左边;
	BOOL 地图右边;
	BOOL 地图上边;
	BOOL 地图下边;
	DWORD 地图通道;
	DWORD 背景颜色;
};

typedef struct 地图节点
{
	DWORD 地图F点;
	DWORD 地图G点;
	DWORD 地图H点;
	坐标型 当前坐标;
	坐标型 最终坐标;
};

//---------------------------------------公告---------------------------------------

void 游戏公告(wstring 公告内容);
void 系统公告(wstring 公告内容);
VOID 神话公告(wstring 内容, int 类型 = NULL);
void OutputDebugPrintf(const char * strOutputString, ...);

//---------------------------------------模块---------------------------------------
int 汇编_加(int 参数一, int 参数二, int 参数三 = NULL, int 参数四 = NULL, int 参数五 = NULL, int 参数六 = NULL);
int 汇编_减(int 参数一, int 参数二, int 参数三 = NULL, int 参数四 = NULL, int 参数五 = NULL, int 参数六 = NULL);
int 汇编_乘(int 参数一, int 参数二);
int 汇编_除(int 参数一, int 参数二);

void JMP跳转(INT64 地址, INT64 跳转地址);
wstring 到文本(int a);
wstring 读文本(INT64 内存地址, int 长度);
wstring 通关时间(int duration);
wstring 取现行时间();
INT64 读偏移型(INT64 address, vector<int> vec);

ULONG_PTR Alloc(SIZE_T size);
double   读写_读小数型(ULONG64 参_内存地址);
DWORD    读写_读整数型(ULONG64 参_内存地址);
ULONG64  读写_读长整数(ULONG64 参_内存地址);
BYTE     读写_读字节型(ULONG64 参_内存地址);
ULONG64     读写_读短整数(ULONG64 参_内存地址);
vector<BYTE> 读写_读字节集(ULONG64 参_内存地址, DWORD 参_读取长度);
VOID 读写_写长整数(ULONG64 参_内存地址, ULONG64 参_写入数据);
VOID 读写_写字节型(ULONG64 参_内存地址, BYTE 参_写入数据);
VOID 读写_写整数型(ULONG64 参_内存地址, DWORD 参_写入数据);
VOID 读写_写小数型(ULONG64 参_内存地址, float 参_写入数据);
VOID 读写_写字节集(ULONG64 参_内存地址, vector<BYTE> 参_写入数据);
VOID 读写_写短整数(ULONG64 参_内存地址, WORD 参_写入数据);
wstring 整数到文本(DWORD 参_数值);
wstring  长整数到文本(ULONG64 参_数值);
wstring  长整数到十六进制(ULONG64 参_数值);
wstring Unicode转Ansi(vector<BYTE> 参_字节集);
int 超级解密(ULONG64 参_解密地址);
VOID 超级加密(ULONG64 参_加密地址, DWORD 参_修改数值);

//---------------------------------------模块---------------------------------------

void 收包();
void 指针拦截();
void 事件处理(int 封包标识, int 封包长度, UINT64 封包指针);

//---------------------------------------CALL---------------------------------------

void Send_缓冲Call(int cdov);
void Send_加密Call(int 数值, INT64 加密CALL1);
void Send_发包Call();
void 评分Call(int 评分数值);
void 技能Call(INT64 触发指针, int 代码, int 伤害, int x, int y, int z, int 大小 = NULL);
void 坐标call(INT64 触发指针, INT64 X, INT64 Y, INT64 Z);
void 丢弃Call(int 背包位置);
void 区域call(int 副本);
void 跳过Call();
void 接受Call(int 参_任务);
void 完成Call(int 参_任务, int 参_次数 = NULL);
void 提交Call(int 参_任务);
void 物品Call(int 物品代码);
void 地图Call();

//---------------------------------------组包---------------------------------------

void 组包_城镇移动(int 城镇区域, int 城镇编号, int 城镇横轴, int 城镇纵轴);
void 组包_拾取(int 对象编号);
void 组包_通关翻牌();
void 组包_领取翻牌();
void 组包_强制回城();
void 组包_过图(int x, int y);
void 组包_分解(int 装备位置);
void 组包_卖物(int 位置, int 数量 = NULL);
void 组包_丢弃(int 装备指针);
void 组包秒杀(unsigned short 服务器ID);
void 组包_修仙死亡(unsigned short 服务器ID);
void 组包_选图();
void 组包_进图(int 地图代码, int 地图难度, int 深渊投递 = NULL, int 任务编号 = NULL, int 星空深渊 = NULL);
void Send_组包特殊();
void 组包_退出角色();
void 组包_选择角色(int 角色位置);
void 组包_整理背包();

int 皇宫全图();
void 坐标过图(int 方向ID);
void 组包顺图(int 坐标值);
void 全屏遍历();
void 跟随遍历();
float 怪物_坐标(__int64 nPointer, int nMode);
float 人物_坐标(__int64 nPointer, int nMode);
void 装备分解();
void 装备丢弃();
void 装备出售();
void 技能全屏();
void 药品();
//-------------------------------------------------------------判断-------------------------------------------------------------
bool 坐标相等(坐标型 当前坐标, 坐标型 目标坐标);
bool 是否在BOSS房();
bool 是否开门();
int 取疲劳();
void 自动过图();
坐标型 读坐标(ULONG64 参数指针);
BOOL 存在物品();


//-------------------------------------------------------------路线-------------------------------------------------------------
地图数据 寻路_地图数据();
DWORD 寻路_获取走法(vector<DWORD> 参_地图通道, DWORD 参_宽度, DWORD 参_高度, 坐标型 参_地图起点, 坐标型 参_地图终点, vector<坐标型>& 参_真实走法);
VOID 寻路_生成地图(DWORD 参_宽度, DWORD 参_高度, vector<DWORD> 参_地图通道, vector<vector<游戏地图>>& 参_游戏地图);
VOID 寻路_显示地图(vector<vector<游戏地图>> 参_地图数组, DWORD 参_宽度, DWORD 参_高度, vector<vector<游戏地图>>& 参_地图标签);
VOID 寻路_路径算法(vector<vector<游戏地图>> 参_地图标签, 坐标型 参_地图起点, 坐标型 参_地图终点, DWORD 参_宽度, DWORD 参_高度, vector<坐标型>& 参_走法数组);
DWORD 寻路_整理坐标(vector<坐标型> 参_模拟走法, vector<坐标型>& 参_真实走法);
BOOL  寻路_判断方向(DWORD 参_通向, DWORD 参_方向);
DWORD 寻路_计算方向(坐标型 参_当前房间, 坐标型 参_下个房间);

int 等级自动();

//-------------------------------------------------------------配置-------------------------------------------------------------

extern wchar_t 配置路径[MAX_PATH];//声明全局变量 包含此头文件的都可以使用
void 获取配置路径();
void 写配置(wstring 节名称, wstring 项名称, wstring 数据);
int 读配置(wstring 节名称, wstring 项名称);
bool 文件是否存在(wstring 文件路径);



VOID 自动开关();
VOID 自动时钟();
VOID 获取角色处理(int 地图编号);
VOID 角色切换();
VOID 顺图处理();
VOID 顺图方向(int 方向);
VOID 顺图调用(int 调用);
VOID 皇宫顺图();
VOID 普通顺图();
VOID 普通顺图2();

bool 跳过数据();


//-------------------------------------------------------------剧情-------------------------------------------------------------

//-------------------------------------------------------------剧情-------------------------------------------------------------

int 任务名称();
int 获取隐藏任务();
int 获取主线任务();
int 完成次数(int 解密次数);
int 任务次数(int id);
bool 获取城镇完成(wstring 条件);
bool 获取进图完成(wstring 条件);
int 获取任务地图(int 任务编号);
bool 是否有主线任务();
int 获取处理方式(int 对象编号);
bool 获取处理结果(int 对象编号);
VOID 每日角色切换();