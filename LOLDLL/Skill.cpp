#include "stdafx.h"
#include "Skill.h"
#include "HumanBaseObject.h"

CSkill::CSkill() : CBaseObject(NULL)
{
}

CSkill::CSkill(_In_ DWORD dwNodeBase_) : CBaseObject(dwNodeBase_)
{

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

BOOL CSkill::UseSkill(CONST CHumanBaseObject& HumanBaseObject_) CONST
{
	return TRUE;
}
