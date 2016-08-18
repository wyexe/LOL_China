#include "stdafx.h"
#include "GameCALL.h"

BOOL CGameCALL::PlayerMove(_In_ CONST Point& TarPoint) CONST
{
	return TRUE;
}

BOOL CGameCALL::StopAction() CONST
{
	return TRUE;
}

DWORD CGameCALL::GetGameRunTime() CONST
{
	return 0;
}

BOOL CGameCALL::PurchaseItemByShore(_In_ DWORD dwItemId) CONST
{
	return TRUE;
}

BOOL CGameCALL::LockView() CONST
{
	return TRUE;
}

BOOL CGameCALL::UpgradeSkill(_In_ em_Skill_Index emSkillIndex) CONST
{
	return TRUE;
}

BOOL CGameCALL::HeroAttack(_In_ CONST Point& AttackPoint) CONST
{
	return TRUE;
}

BOOL CGameCALL::StopHeroAttack() CONST
{
	return TRUE;
}

BOOL CGameCALL::UseSkill(_In_ CONST std::tuple<Point, Point, em_Skill_Index, DWORD, DWORD>& tup) CONST
{
	return TRUE;
}

BOOL CGameCALL::GetObjectNamePtrByAddr(_In_ DWORD dwObjectAddr, _Out_ wstring& ObjectName) CONST
{
	return TRUE;
}
