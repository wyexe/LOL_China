#include "stdafx.h"
#include "FightServices.h"
#include <MyTools/CLLog.h>
#include "ObjectExtend.h"
#include "GameRes.h"
#include "Person.h"
#include "Turret.h"
#include "Solider.h"

#define _SELF L"CFightServices.cpp"

CFightServices::CFightServices()
{
}

CFightServices::~CFightServices()
{
}


CFightServices& CFightServices::GetInstance()
{
	static CFightServices FightServices;
	return FightServices;
}


VOID CFightServices::WaitToShowSolider() CONST
{
	while (GameRun && (CPerson::GetInstance().GetNodeBase() == NULL || CPerson::GetInstance().GetMoney() == 0) && LOLSleep(1000));
	while (GameRun && CObjectExtend::GetInstance().GetAroundHumanTypeCount<CSolider>(em_Human_Type_Solider, CPerson::GetInstance().GetCurrentCamp(), 1000.0f) == 0 && LOLSleep(1000));
}


BOOL CFightServices::ExistMiddleCrystalTurret() CONST
{
	// get middle crystal turret name
	cwstring* pCryStalTurretName = CGameRes::GetInstance().GetCrystalTurretNameByCampAndType(CPerson::GetInstance().GetCurrentCamp(), CPerson::GetInstance().GetHeroPath());
	if (pCryStalTurretName == nullptr)
	{
		LogMsgBox(LOG_LEVEL_EXCEPTION, L"pCryStalTurretName = nullptr, Camp=%X,Path=%X", CPerson::GetInstance().GetCurrentCamp(), CPerson::GetInstance().GetHeroPath());
		return FALSE;
	}

	// find all of self turret!
	return CObjectExtend::GetInstance().ExistTurretByName(*pCryStalTurretName, CPerson::GetInstance().GetCurrentCamp(), nullptr);
}

BOOL CFightServices::IsAtBase() CONST
{
	CTurret BlueTurret;
	CTurret RedTurret;
	if (CPerson::GetInstance().GetCurrentCamp() == em_Camp_Blue && CObjectExtend::GetInstance().ExistTurretByName(BLUE_CAMP_SPRING_NAME, em_Camp_Blue, &BlueTurret) && BlueTurret.GetDis() < 15.0f)
		return TRUE;
	else if (CPerson::GetInstance().GetCurrentCamp() == em_Camp_Red && CObjectExtend::GetInstance().ExistTurretByName(RED_CAMP_SPRING_NAME, em_Camp_Red, &RedTurret) && RedTurret.GetDis() < 15.0f)
		return TRUE;

	return FALSE;
}

BOOL CFightServices::IsHaveToBackToBase() CONST
{
	return CPerson::GetInstance().GetPercentHp() < 25 || (CPerson::GetInstance().GetMaxMp() > 100 && CPerson::GetInstance().GetPercentMp() < 5) || CPerson::GetInstance().GetMoney() >= 3000;
}

BOOL CFightServices::IsDodgeTurret() CONST
{
	CTurret Turret;
	if (!CObjectExtend::GetInstance().GetLatelyTurretByCamp(CPerson::GetInstance().GetEnemyCamp(), MAX_ATTACK_DIS + 2.0f, &Turret))
		return FALSE;

	// didn't dodge Crystal turret
	if (Turret.IsCrystalTurret())
		return FALSE;

	// Turret attack
	if (Turret.GetTargetId() == CPerson::GetInstance().GetId())
	{
		Log(LOG_LEVEL_NORMAL, L"Turret TargetId = Self!");
		return TRUE;
	}

	// Hero Attack
	CHero EnemyHero;
	if (CObjectExtend::GetInstance().GetLatelyHeroByCamp(CPerson::GetInstance().GetEnemyCamp(), MAX_ATTACK_DIS, &EnemyHero) && EnemyHero.GetTargetId() == CPerson::GetInstance().GetId())
		return TRUE;
	
	// more then 2 enemy hero defense turret
	if (CObjectExtend::GetInstance().GetEnemyHeroCountByDis(MAX_ATTACK_DIS) >= 2)
		return TRUE;

	return CObjectExtend::GetInstance().GetAllySoliderCountByDis(Turret.GetPoint(), 10.0f) <= 2;
}

BOOL CFightServices::IsAttackTurret() CONST
{
	CTurret Turret;
	if (!CObjectExtend::GetInstance().GetLatelyTurretByCamp(CPerson::GetInstance().GetEnemyCamp(), MAX_ATTACK_DIS + 2.0f, &Turret))
		return FALSE;

	if (Turret.IsCrystalTurret() && CObjectExtend::GetInstance().GetEnemyHeroCountByDis(MAX_ATTACK_DIS) > 0)
		return FALSE;

	// Turret around have to unexist solider!
	return CObjectExtend::GetInstance().GetEnemySoliderCountByDis(7.0f) == NULL;
}

BOOL CFightServices::IsDogeSolider() CONST
{
	DWORD dwLevel = CPerson::GetInstance().GetLevel();
	DWORD dwEnemySoliderCount = CObjectExtend::GetInstance().GetEnemyAttackSoliderCountByDis(7.0f);
	
	// Level < 8 
	if (dwLevel < 8 && dwEnemySoliderCount >= 2)
		return TRUE;
	return dwLevel >= 8 && dwEnemySoliderCount >= 4;
}

BOOL CFightServices::IsClearSolider() CONST
{
	return CObjectExtend::GetInstance().GetEnemySoliderCountByDis(7.0f) > 0;
}

BOOL CFightServices::IsDodgeHero() CONST
{
	return CObjectExtend::GetInstance().GetEnemyAttackHeroCountByDis(MAX_ATTACK_DIS) > 0 && CPerson::GetInstance().GetLevel() < 6;
}

BOOL CFightServices::IsAttackHero() CONST
{
	if (CObjectExtend::GetInstance().GetEnemyHeroCountByDis(MAX_ATTACK_DIS) == 0)
		return FALSE;
	else if (CObjectExtend::GetInstance().GetEnemyAttackHeroCountByDis(MAX_ATTACK_DIS) > 0)
		return TRUE;

	DWORD dwLevel = CPerson::GetInstance().GetLevel();
	UINT uCount = CObjectExtend::GetInstance().GetEnemyAttackSoliderCountByDis(MAX_ATTACK_DIS);
	if (dwLevel < 6 && uCount >= 3)
		return FALSE;

	return dwLevel >= 8 && uCount >= 5 ? FALSE : TRUE;
}
