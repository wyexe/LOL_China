#include "stdafx.h"
#include "CreepServices.h"
#include "Person.h"
#include "ObjectExtend.h"

CCreepServices::CCreepServices() : ulBlueBuffTick(NULL), ulRedBuffTick(NULL), ulDragonTick(NULL)
{
}

CCreepServices::~CCreepServices()
{
}

CCreepServices& CCreepServices::GetInstance()
{
	static CCreepServices CreepServices;
	return CreepServices;
}

BOOL CCreepServices::IsRefreshBlueBuff() CONST
{
	if (CPerson::GetInstance().GetHeroPro() != MIDDLE_HERO_PRO)
		return FALSE;

	if (CPerson::GetInstance().GetLevel() < 6)
		return FALSE;

	return ulBlueBuffTick == NULL || ::GetTickCount64() - ulBlueBuffTick >= BLUE_BUFF_REFRESHTIME;
}

BOOL CCreepServices::IsRefreshRedBuff() CONST
{
	if (CPerson::GetInstance().GetHeroPro() != MIDDLE_HERO_PRO)
		return FALSE;

	if (CPerson::GetInstance().GetLevel() < 6)
		return FALSE;

	if (CObjectExtend::GetInstance().ExistBuffById(BLUE_BUFF_ID, nullptr))
		return FALSE;

	return ulRedBuffTick == NULL || ::GetTickCount64() - ulRedBuffTick >= RED_BUFF_REFRESHTIME;
}

BOOL CCreepServices::IsRefreshDragonBuff() CONST
{
	if (CPerson::GetInstance().GetHeroPro() == MIDDLE_HERO_PRO)
		return FALSE;

	if (ulDragonTick != NULL)
		return ::GetTickCount64() - ulDragonTick >= DRAGON_BUFF_REFRESHTIME;

	// count of team member level > 4  more then 4
	vector<CHero> vlst;
	CObjectExtend::GetInstance().GetHumanTypeListByType(CObjectExtend::em_Human_Type_Hero, CPerson::GetInstance().GetCurrentCamp(), vlst);
	return CLPublic::Vec_erase_if(vlst, [](CONST auto& itm) { return itm.GetLevel() < 5; });
}

BOOL CCreepServices::SetRefreshBuffTick(_In_ em_Creep_Buff_Type emType)
{
	switch (emType)
	{
	case CCreepServices::em_Creep_Buff_Type_Blue:
		ulBlueBuffTick = ::GetTickCount64();
		break;
	case CCreepServices::em_Creep_Buff_Type_Red:
		ulRedBuffTick = ::GetTickCount64();
		break;
	case CCreepServices::em_Creep_Buff_Type_Dragon:
		ulDragonTick = ::GetTickCount64();
		break;
	default:
		break;
	}
	return TRUE;
}