#include "stdafx.h"
#include "Skill.h"
#include "HumanBaseObject.h"

CSkill::CSkill() : CBaseObject(NULL), uIndex(NULL)
{
}

CSkill::CSkill(_In_ UINT uIndex_, _In_ DWORD dwNodeBase_) : CBaseObject(dwNodeBase_), uIndex(uIndex_)
{

}

em_Skill_Index CSkill::GetSkillIndex() CONST
{
	return static_cast<em_Skill_Index>(uIndex);
}

DWORD CSkill::GetLevel() CONST
{
	return 0;
}

cwstring& CSkill::GetName() CONST
{
	return wsName;
}

DWORD CSkill::GetExpendMp() CONST
{
	return 0;
}

BOOL CSkill::IsCooldown() CONST
{
	return TRUE;
}

BOOL CSkill::IsCouldUse() CONST
{
	return TRUE;
}

BOOL CSkill::UseSkill(_In_ CONST CHumanBaseObject& HumanBaseObject_, _In_ em_Skill_Type emSkillType) CONST
{
	return TRUE;
}

DWORD CSkill::GetItemSkillParameter() CONST
{
	return 0;
}
