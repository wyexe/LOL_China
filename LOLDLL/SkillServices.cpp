#include "stdafx.h"
#include "SkillServices.h"
#include <MyTools/CLLog.h>
#include "Person.h"
#include "GameRes.h"
#include "GameCALL.h"
#include "ObjectExtend.h"
#include "Skill.h"

#define _SELF L"SkillServices.cpp"
CSkillServices::CSkillServices()
{
}

CSkillServices::~CSkillServices()
{
}

CSkillServices& CSkillServices::GetInstance()
{
	static CSkillServices SkillServices;
	return SkillServices;
}

BOOL CSkillServices::IsSkillCooldown(_In_ em_Skill_Index emSkillIndex) CONST
{
	return TRUE;
}

BOOL CSkillServices::UseSkill(_In_ em_Skill_Index emSkillIndex) CONST
{
	return TRUE;
}

BOOL CSkillServices::LevelUpSkill() CONST
{
	auto pemSkillIndex = CGameRes::GetInstance().GetSPByHeroLevel(CPerson::GetInstance().GetHeroPro(), CPerson::GetInstance().GetLevel());
	if (pemSkillIndex == nullptr)
	{
		LogMsgBox(LOG_LEVEL_EXCEPTION, L"pemSkillIndex=nullptr,Hero=%X,Level=%d", CPerson::GetInstance().GetHeroPro(), CPerson::GetInstance().GetLevel());
		return FALSE;
	}
	return CGameVariable::GetInstance().PushMainThreadActionPtr([&pemSkillIndex] {
		CGameCALL::GetInstance().UpgradeSkill(*pemSkillIndex);
	});
}

BOOL CSkillServices::CheckLevelupSkill() CONST
{
	return CPerson::GetInstance().GetSp() > 0 ? LevelUpSkill() : TRUE;
}

CONST ResSkill* CSkillServices::GetCurrentHeroSkillConfig() CONST
{
	static ResSkill* pResSkill = nullptr;
	if (pResSkill == nullptr)
	{
		pResSkill = const_cast<ResSkill*>(CGameRes::GetInstance().GetResSkillByHero(CPerson::GetInstance().GetHeroPro()));
	}
	return pResSkill;
}

BOOL CSkillServices::UseItemSkill(_In_ cwstring& wsItemSkillName) CONST
{
	vector<CSkill> vlst;
	CObjectExtend::GetInstance().GetSkillList(vlst);

	CSkill Skill;
	if (!CObjectExtend::GetInstance().ExistSkillByName(wsItemSkillName,&Skill))
		return FALSE;

	return CGameVariable::GetInstance().PushMainThreadActionPtr([&Skill] {
		CGameCALL::GetInstance().UsingItem(Skill.GetItemSkillParameter());
	});
}

BOOL CSkillServices::UseBuffSkill(_In_ cwstring& wsSkillName) CONST
{
	vector<CSkill> vlst;
	CObjectExtend::GetInstance().GetSkillList(vlst);

	CSkill Skill;
	if (!CObjectExtend::GetInstance().ExistSkillByName(wsSkillName, &Skill))
		return FALSE;

	return Skill.UseSkill(CPerson::GetInstance(), em_Skill_Type::em_Skill_Type_Buff_Self);
}

BOOL CSkillServices::UseUnDirectionalItemSkill(_In_ cwstring& wsSkillName) CONST
{
	vector<CSkill> vlst;
	CObjectExtend::GetInstance().GetSkillList(vlst);

	CSkill Skill;
	if (!CObjectExtend::GetInstance().ExistSkillByName(wsSkillName, &Skill))
		return FALSE;

	return Skill.UseSkill(CPerson::GetInstance(), em_Skill_Type::em_Skill_Type_Self_UnDirectional);
}
