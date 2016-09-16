#include "stdafx.h"
#include "ScanBase.h"
#include <MyTools/CLLog.h>

#define _SELF L"ScanBase.cpp"
#define LOL_CHINA_CLIENT	L"League of Legends.exe"
CScanBase::CScanBase()
{
}

CScanBase::~CScanBase()
{
}

CScanBase& CScanBase::GetInstance()
{
	static CScanBase ScanBase;
	return ScanBase;
}

BOOL CScanBase::Begin() CONST
{
	DWORD dwBase, dwAddr, dwCALL = 0;
	DWORD dwClient = (DWORD)::GetModuleHandleW(LOL_CHINA_CLIENT);
	//人物基址
	DWORD dwStartTick = ::GetTickCount();
	dwBase = CLSearchBase::FindBase("807E1000740E", 0x59 - 0x43, 1, 0, LOL_CHINA_CLIENT);
	CLLog::Print(__FUNCTIONW__, _SELF, 0, LOG_LEVEL_NORMAL, L"#define	人物基址	0x%X", dwBase);
	//邮寄CALL
	dwBase = CLSearchBase::FindCALL("83??60836C2414010F85", 0x0FC - 0x162, dwClient, 1, 0, LOL_CHINA_CLIENT);
	CLLog::Print(__FUNCTIONW__, _SELF, 0, LOG_LEVEL_NORMAL, L"#define	邮寄CALL	0x%X", dwBase);
	//人物瞬移钩挂地址
	dwAddr = CLSearchBase::FindAddr("7d0983c0018985????????6a00", 0x005AA81C - 0x005AA82C, 0, LOL_CHINA_CLIENT);
	CLLog::Print(__FUNCTIONW__, _SELF, 0, LOG_LEVEL_NORMAL, L"#define	人物瞬移钩挂地址	0x%X", dwAddr);
}
