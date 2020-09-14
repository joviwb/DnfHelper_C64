#include "pch.h"

void 遍历捡物()
{
	ULONG_PTR me = 读写_读长整数(人物基址);
	ULONG_PTR map = 读写_读长整数(me + 地图偏移);
	ULONG_PTR mapFirst = 读写_读长整数(map + 地图开始2);
	ULONG_PTR mapTail = 读写_读长整数(map + 地图结束2);
	int quantity = (mapTail - mapFirst) / 8;
	for (size_t i = 0; i < quantity; i++)
	{
		ULONG_PTR object = 读写_读长整数(mapFirst + 8 * i);
		int typeA = 读写_读整数型(object + 类型偏移);
		int typeB = 读写_读整数型(object + 类型偏移 + 4);
		if (typeA == 289 || typeB == 289)
		{
			组包_拾取(超级解密(object + 对象编号));
		}
	}
}

VOID 自动开关()
{
	全局_总开关.自动刷图开关 = !全局_总开关.自动刷图开关;
	if (全局_总开关.自动刷图开关)
	{
		SetTimer(全局_收包数据.游戏句柄, 5566, 500, (TIMERPROC)自动时钟);
		神话公告(L"开启自动",1);
	}
	else
	{
		KillTimer(全局_收包数据.游戏句柄, 5566);
		神话公告(L"关闭自动",1);
	}
}


VOID 自动时钟()
{
	ULONG 隐藏编号, 主线编号;
	if (读写_读长整数(游戏状态) == 1 && 全局_总开关.自动刷图开关 == true)
	{
		if (读配置(L"装备处理", L"装备分解") == 3)
		{
			::CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)装备丢弃, NULL, NULL, NULL);
		}
		if (读配置(L"自动模式", L"智能模式") == 1)
		{
			全局_自动.参_已经进图 = false;
			全局_自动.副本编号 = 读配置(L"自动模式", L"副本编号");
			全局_自动.副本难度 = 读配置(L"自动模式", L"副本难度");
			获取角色处理(全局_自动.副本编号);
			return;
		}
		if (读配置(L"自动模式", L"智能模式") == 2)
		{
			if (是否有主线任务() == true)
			{
				if (获取隐藏任务() > 0)
				{
					if (获取处理结果(获取隐藏任务()) == true)
					{
						全局_自动.参_已经进图 = false;
						获取角色处理(全局_自动.副本编号);
					}
					return;
				}
				if (获取主线任务() > 0)
				{
					if (获取处理结果(获取主线任务()) == true)
					{
						全局_自动.参_已经进图 = false;
						获取角色处理(全局_自动.副本编号);
					}
					return;
				}
			}
			else
			{
				全局_自动.副本编号 = 等级自动();
				全局_自动.参_已经进图 = false;
				获取角色处理(全局_自动.副本编号);
				return;
			}
			return;
		}
		if (读配置(L"自动模式", L"智能模式") == 3)
		{
			if (跳过数据() == true)
			{
				神话公告(L"跳过任务",1);
				跳过Call();
			}
			else
			{
				全局_自动.参_已经进图 = false;
				全局_自动.副本编号 = 等级自动();
				获取角色处理(全局_自动.副本编号);
			}
			return;
		}
		if (读配置(L"自动模式", L"智能模式") == 4)
		{
			if (全局_自动.参_皇宫根特 < 读配置(L"自动每日", L"皇宫根特"))
			{
				全局_自动.副本编号 = 100000002;
				全局_自动.参_皇宫根特 = 全局_自动.参_皇宫根特 + 1;
				系统公告(L"正在进行皇宫根特第 " + 到文本(全局_自动.参_皇宫根特) + L" 次");
			}
			else if (全局_自动.参_无底坑道 < 读配置(L"自动每日", L"无底坑道"))
			{
				全局_自动.副本编号 = 100000176;
				全局_自动.参_无底坑道 = +全局_自动.参_无底坑道 + 1;
				系统公告(L"正在进行无底坑道第 " + 到文本(全局_自动.参_无底坑道) + L" 次");
			}
			else if (全局_自动.参_记忆之地 < 读配置(L"自动每日", L"记忆之地"))
			{
				全局_自动.副本编号 = 100000177;
				全局_自动.参_记忆之地 = 全局_自动.参_记忆之地 + 1;
				系统公告(L"正在进行记忆之地第 " + 到文本(全局_自动.参_记忆之地) + L" 次");
			}
			else if (全局_自动.参_痛苦地下室 < 读配置(L"自动每日", L"痛苦地下室"))
			{
				全局_自动.副本编号 = 100000178;
				全局_自动.参_痛苦地下室 = 全局_自动.参_痛苦地下室 + 1;
				系统公告(L"正在进行痛苦地下室第 " + 到文本(全局_自动.参_痛苦地下室) + L" 次");
			}
			else if (全局_自动.参_暗黑神殿 < 读配置(L"自动每日", L"暗黑神殿"))
			{
				全局_自动.副本编号 = 100000179;
				全局_自动.参_暗黑神殿 = 全局_自动.参_暗黑神殿 + 1;
				系统公告(L"正在进行暗黑神殿第 " + 到文本(全局_自动.参_暗黑神殿) + L" 次");
			}
			else
			{
				全局_自动.参_皇宫根特 = 0, 全局_自动.参_无底坑道 = 0, 全局_自动.参_记忆之地 = 0, 全局_自动.参_痛苦地下室 = 0, 全局_自动.参_暗黑神殿 = 0;
				每日角色切换();
				return;
			}
			全局_自动.参_已经进图 = false;
			获取角色处理(全局_自动.副本编号);
			return;
		}
	}
	if (读写_读长整数(游戏状态) == 2 && 全局_总开关.自动刷图开关 == true)
	{
		return;
	}
	if (读写_读长整数(游戏状态) == 3 && 全局_总开关.自动刷图开关 == true)
	{
		if (是否开门() == false)
		{
			跟随遍历();
		}
		else if (是否在BOSS房() == false)
		{
			顺图处理();
		}
		return;
	}
}

void 获取角色处理(int 地图编号)
{
	if (取疲劳() <= 读配置(L"疲劳配置", L"预留疲劳"))
	{
		角色切换();
	}
	else
	{
		区域call(全局_自动.副本编号);
		组包_选图();
	}
}


VOID 角色切换()
{
	if (全局_自动.参_切换角色 == false)
	{
		return;
	}
	全局_自动.参_刷图角色 = 全局_自动.参_刷图角色 + 1;
	全局_自动.参_公告角色 = 全局_自动.参_刷图角色 + 1;
	if (全局_自动.参_刷图角色 >= 读配置(L"角色配置", L"角色数量"))
	{
		神话公告(L"已完成指定角色");
		自动开关();
		KillTimer(全局_收包数据.游戏句柄, 5566);
	}
	else
	{
		神话公告(L"切换角色 - 当前角色数 " + 到文本(全局_自动.参_刷图角色));
		组包_退出角色();
		全局_自动.参_切换角色 = false;
	}
}


VOID 顺图处理()
{
	if (全局_自动.参_已经进图 == false && 全局_自动.参_可以顺图 == false)
	{
		return;
	}
	if (是否在BOSS房() == true)
	{
		return;
	}
	if (是否开门() == false)
	{
		return;
	}
	遍历捡物();
	if (全局_收包数据.参_地图编号 == 100000002 || 全局_收包数据.参_地图编号 == 100000214)
	{
		皇宫顺图();
	}
	else
	{
		地图数据 局_地图数据;
		局_地图数据 = 寻路_地图数据();
		if (sizeof(局_地图数据.地图走法) >= 2)
		{
			顺图方向(寻路_计算方向(局_地图数据.地图走法[0], 局_地图数据.地图走法[1]));
		}
	}
}


VOID 顺图方向(int 方向)
{
	if (方向 == 2)
	{
		顺图调用(1);
	}
	else if (方向 == 3)
	{
		顺图调用(2);
	}
	else if (方向 == 0)
	{
		顺图调用(3);
	}
	else if (方向 == 1)
	{
		顺图调用(4);
	}
}


VOID 顺图调用(int 调用)
{
	if (是否开门() == false)
	{
		return;
	}
	if (全局_自动.副本编号 == 192)
	{
		if (读配置(L"自动模式", L"智能模式") == 1 || 读配置(L"自动模式", L"智能模式") == 3 || 读配置(L"自动模式", L"智能模式") == 4)
		{
			if (全局_收包数据.参_当前坐标.参_横轴坐标 == 0 && 全局_收包数据.参_当前坐标.参_纵轴坐标 == 0)
			{
				调用 = 4;
			}
			if (全局_收包数据.参_当前坐标.参_横轴坐标 == 1 && 全局_收包数据.参_当前坐标.参_纵轴坐标 == 0)
			{
				调用 = 4;
			}
			if (全局_收包数据.参_当前坐标.参_横轴坐标 == 2 && 全局_收包数据.参_当前坐标.参_纵轴坐标 == 0)
			{
				调用 = 2;
			}
			if (全局_收包数据.参_当前坐标.参_横轴坐标 == 2 && 全局_收包数据.参_当前坐标.参_纵轴坐标 == 1)
			{
				调用 = 3;
			}
			if (全局_收包数据.参_当前坐标.参_横轴坐标 == 1 && 全局_收包数据.参_当前坐标.参_纵轴坐标 == 1)
			{
				调用 = 3;
			}
			if (全局_收包数据.参_当前坐标.参_横轴坐标 == 0 && 全局_收包数据.参_当前坐标.参_纵轴坐标 == 1)
			{
				调用 = 2;
			}
			if (全局_收包数据.参_当前坐标.参_横轴坐标 == 0 && 全局_收包数据.参_当前坐标.参_纵轴坐标 == 2)
			{
				调用 = 2;
			}
			if (全局_收包数据.参_当前坐标.参_横轴坐标 == 0 && 全局_收包数据.参_当前坐标.参_纵轴坐标 == 3)
			{
				调用 = 4;
			}
			if (全局_收包数据.参_当前坐标.参_横轴坐标 == 1 && 全局_收包数据.参_当前坐标.参_纵轴坐标 == 3)
			{
				调用 = 1;
			}
			if (全局_收包数据.参_当前坐标.参_横轴坐标 == 1 && 全局_收包数据.参_当前坐标.参_纵轴坐标 == 2)
			{
				调用 = 4;
			}
			if (全局_收包数据.参_当前坐标.参_横轴坐标 == 2 && 全局_收包数据.参_当前坐标.参_纵轴坐标 == 2)
			{
				调用 = 4;
			}
		}
	}
	if (全局_自动.副本编号 == 104)
	{
		if (读配置(L"自动模式", L"智能模式") == 1 || 读配置(L"自动模式", L"智能模式") == 3 || 读配置(L"自动模式", L"智能模式") == 4)
		{
			if (全局_收包数据.参_当前坐标.参_横轴坐标 == 0 && 全局_收包数据.参_当前坐标.参_纵轴坐标 == 0)
			{
				调用 = 4;
			}
			if (全局_收包数据.参_当前坐标.参_横轴坐标 == 1 && 全局_收包数据.参_当前坐标.参_纵轴坐标 == 0)
			{
				调用 = 4;
			}
			if (全局_收包数据.参_当前坐标.参_横轴坐标 == 2 && 全局_收包数据.参_当前坐标.参_纵轴坐标 == 0)
			{
				调用 = 2;
			}
			if (全局_收包数据.参_当前坐标.参_横轴坐标 == 2 && 全局_收包数据.参_当前坐标.参_纵轴坐标 == 1)
			{
				调用 = 3;
			}
			if (全局_收包数据.参_当前坐标.参_横轴坐标 == 1 && 全局_收包数据.参_当前坐标.参_纵轴坐标 == 1)
			{
				调用 = 2;
			}
			if (全局_收包数据.参_当前坐标.参_横轴坐标 == 1 && 全局_收包数据.参_当前坐标.参_纵轴坐标 == 2)
			{
				调用 = 4;
			}
			if (全局_收包数据.参_当前坐标.参_横轴坐标 == 2 && 全局_收包数据.参_当前坐标.参_纵轴坐标 == 2)
			{
				调用 = 4;
			}
			if (全局_收包数据.参_当前坐标.参_横轴坐标 == 3 && 全局_收包数据.参_当前坐标.参_纵轴坐标 == 2)
			{
				调用 = 1;
			}
		}

	}
	if (全局_自动.副本编号 == 100000212)
	{
		if (读配置(L"自动模式", L"智能模式") == 1 || 读配置(L"自动模式", L"智能模式") == 3 || 读配置(L"自动模式", L"智能模式") == 4)
		{
			if (全局_收包数据.参_当前坐标.参_横轴坐标 == 0 && 全局_收包数据.参_当前坐标.参_纵轴坐标 == 1)
			{
				调用 = 4;
			}
			if (全局_收包数据.参_当前坐标.参_横轴坐标 == 1 && 全局_收包数据.参_当前坐标.参_纵轴坐标 == 1)
			{
				调用 = 2;
			}
			if (全局_收包数据.参_当前坐标.参_横轴坐标 == 1 && 全局_收包数据.参_当前坐标.参_纵轴坐标 == 2)
			{
				调用 = 4;
			}
			if (全局_收包数据.参_当前坐标.参_横轴坐标 == 2 && 全局_收包数据.参_当前坐标.参_纵轴坐标 == 2)
			{
				调用 = 4;
			}
			if (全局_收包数据.参_当前坐标.参_横轴坐标 == 3 && 全局_收包数据.参_当前坐标.参_纵轴坐标 == 2)
			{
				调用 = 4;
			}
			if (全局_收包数据.参_当前坐标.参_横轴坐标 == 4 && 全局_收包数据.参_当前坐标.参_纵轴坐标 == 2)
			{
				调用 = 1;
			}
			if (全局_收包数据.参_当前坐标.参_横轴坐标 == 4 && 全局_收包数据.参_当前坐标.参_纵轴坐标 == 1)
			{
				调用 = 4;
			}
			if (全局_收包数据.参_当前坐标.参_横轴坐标 == 5 && 全局_收包数据.参_当前坐标.参_纵轴坐标 == 1)
			{
				调用 = 1;
			}
		}

	}
	if (全局_自动.副本编号 == 100000177)
	{
		if (读配置(L"自动模式", L"智能模式") == 1 || 读配置(L"自动模式", L"智能模式") == 3 || 读配置(L"自动模式", L"智能模式") == 4)
		{
			if (全局_收包数据.参_当前坐标.参_横轴坐标 == 0 && 全局_收包数据.参_当前坐标.参_纵轴坐标 == 1)
			{
				调用 = 4;
			}
			if (全局_收包数据.参_当前坐标.参_横轴坐标 == 1 && 全局_收包数据.参_当前坐标.参_纵轴坐标 == 1)
			{
				调用 = 2;
			}
			if (全局_收包数据.参_当前坐标.参_横轴坐标 == 1 && 全局_收包数据.参_当前坐标.参_纵轴坐标 == 2)
			{
				调用 = 4;
			}
			if (全局_收包数据.参_当前坐标.参_横轴坐标 == 2 && 全局_收包数据.参_当前坐标.参_纵轴坐标 == 2)
			{
				调用 = 4;
			}
			if (全局_收包数据.参_当前坐标.参_横轴坐标 == 3 && 全局_收包数据.参_当前坐标.参_纵轴坐标 == 2)
			{
				调用 = 4;
			}
			if (全局_收包数据.参_当前坐标.参_横轴坐标 == 4 && 全局_收包数据.参_当前坐标.参_纵轴坐标 == 2)
			{
				调用 = 1;
			}
			if (全局_收包数据.参_当前坐标.参_横轴坐标 == 4 && 全局_收包数据.参_当前坐标.参_纵轴坐标 == 1)
			{
				调用 = 4;
			}
			if (全局_收包数据.参_当前坐标.参_横轴坐标 == 5 && 全局_收包数据.参_当前坐标.参_纵轴坐标 == 1)
			{
				调用 = 1;
			}
		}
	}
	if (全局_自动.副本编号 == 100000179)
	{
		if (读配置(L"自动模式", L"智能模式") == 1 || 读配置(L"自动模式", L"智能模式") == 3 || 读配置(L"自动模式", L"智能模式") == 4)
		{
			if (全局_收包数据.参_领主坐标.参_横轴坐标 == 5 && 全局_收包数据.参_领主坐标.参_纵轴坐标 == 0)
			{
				if (全局_收包数据.参_当前坐标.参_横轴坐标 != 5)
				{
					调用 = 4;
				}
				if (全局_收包数据.参_当前坐标.参_横轴坐标 == 5 && 全局_收包数据.参_当前坐标.参_纵轴坐标 == 1)
				{
					调用 = 1;
				}
			}
			else if (全局_收包数据.参_领主坐标.参_横轴坐标 == 0 && 全局_收包数据.参_领主坐标.参_纵轴坐标 == 1)
			{
				if (全局_收包数据.参_当前坐标.参_横轴坐标 == 5 && 全局_收包数据.参_当前坐标.参_纵轴坐标 == 0)
				{
					调用 = 2;
				}
				if (全局_收包数据.参_当前坐标.参_纵轴坐标 == 1)
				{
					调用 = 3;
				}
			}
		}
	}
	if (调用 == 1)
	{
		全局_自动.参_顺图方向 = 2;
	}
	if (调用 == 2)
	{
		全局_自动.参_顺图方向 = 3;
	}
	if (调用 == 3)
	{
		全局_自动.参_顺图方向 = 0;
	}
	if (调用 == 4)
	{
		全局_自动.参_顺图方向 = 1;
	}
	全局_自动.参_顺图计次 = 汇编_加(全局_自动.参_顺图计次, 1);
	if (全局_自动.参_顺图计次 >= 5)//这里是防止随机门的
	{
		全局_自动.参_顺图计次 = NULL;
		组包顺图(全局_自动.参_顺图方向);
	}
	else
	{
		if (读配置(L"顺图处理", L"顺图模式") == 1)
		{
			CreateThread(0, 0, (LPTHREAD_START_ROUTINE)普通顺图, NULL, 0, NULL);
		}
		if (读配置(L"顺图处理", L"顺图模式") == 2)
		{
			组包顺图(全局_自动.参_顺图方向);
		}	
	}
}


VOID 皇宫顺图()
{
		if (全局_自动.参_已经进图 == false && 全局_自动.参_可以顺图 == false)
		{
			return;
		}
		全局_自动.参_顺图计次 = 汇编_加(全局_自动.参_顺图计次, 1);
		if (全局_自动.参_顺图计次 >= 5)//这里是防止随机门的
		{
			全局_自动.参_顺图计次 = NULL;
			组包顺图(皇宫全图());
		}
		else
		{
			if (读配置(L"顺图处理", L"顺图模式") == 1)
			{
				CreateThread(0, 0, (LPTHREAD_START_ROUTINE)普通顺图2, NULL, 0, NULL);
			}
			if (读配置(L"顺图处理", L"顺图模式") == 2)
			{
				组包顺图(皇宫全图());
			}
		}
}

VOID 普通顺图()
{
	坐标过图(全局_自动.参_顺图方向);
}

VOID 普通顺图2()
{
	坐标过图(皇宫全图());
}

VOID 每日角色切换()
{
	if (全局_自动.参_切换角色 == false)
	{
		return;
	}
	全局_自动.参_每日角色 = 全局_自动.参_每日角色 + 1;
	全局_自动.参_公告角色 = 全局_自动.参_每日角色 + 1;
	if (全局_自动.参_刷图角色 >= 读配置(L"自动每日", L"角色个数"))
	{
		游戏公告(L"已完成指定每日角色");
		自动开关();
		KillTimer(全局_收包数据.游戏句柄, 5566);
	}
	else
	{
		游戏公告(L"切换角色中 当前每日角色数 " + 到文本(全局_自动.参_刷图角色));
		组包_退出角色();
		全局_自动.参_切换角色 = false;
	}
}

void 内存按键(INT 按键代码, INT 按键时长)
{
	DWORD 按键 = 0;
	if (按键代码 == VK_X)
		按键 = 314;
	else if (按键代码 == VK_SPACE)
		按键 = 326;
	else if (按键代码 == VK_ESCAPE)
		按键 = 270;
	读写_写字节集(读写_读长整数(按键基址) + 按键 + 8, { 1 });
	Sleep(按键时长);
	读写_写字节集(读写_读长整数 (按键基址)+ 按键 + 8, { 0 });
}
