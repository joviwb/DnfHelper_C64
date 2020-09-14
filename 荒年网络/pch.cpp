// pch.cpp: 与预编译标头对应的源文件
#include "pch.h"
//输出函数
#pragma comment(linker, "/EXPORT:CreateInstance=ChangeSTDLLOrg.CreateInstance,@1")
#pragma comment(linker, "/EXPORT:RealeaseInstance=ChangeSTDLLOrg.RealeaseInstance,@2")
