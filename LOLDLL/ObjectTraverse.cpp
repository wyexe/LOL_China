#include "stdafx.h"
#include "ObjectTraverse.h"
#include "HeroBuff.h"

CObjectTraverse::CObjectTraverse()
{
}

CObjectTraverse::~CObjectTraverse()
{
}

UINT CObjectTraverse::GetCurrentHeroBuffList(_Out_ vector<CHeroBuff>& vlst) CONST
{
	vlst.clear();
	auto dwArray = ReadDWORD(ReadDWORD(BUFF»ùÖ·) + 0x14);
	for (auto i = 0; i < 0x40; ++i)
	{
		auto dwBuffAddr = dwArray + i * 0x34;
		if(ReadDWORD(dwBuffAddr + 0x2C) == 0xFFFFFFFF)
			continue;
		vlst.push_back(CHeroBuff(dwBuffAddr));
	}
	return 0;
}

UINT CObjectTraverse::GetCurrentHeroEqumentList(_Out_ vector<CEqument>& vlst) CONST
{

	return 0;
}

BOOL CObjectTraverse::GetSkillList(_Out_ vector<CSkill>& vlst) CONST
{

	return TRUE;
}

BOOL CObjectTraverse::GetCreepList(_Out_ vector<CReep>& vlst) CONST
{
	return 0;
}
