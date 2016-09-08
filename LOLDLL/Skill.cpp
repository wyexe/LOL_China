#include "stdafx.h"
#include "Skill.h"
#include "HumanBaseObject.h"
#include "GameCALL.h"
#include "Person.h"

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

BOOL CSkill::UseSkill(_In_ CONST CHumanBaseObject& Tar, _In_ em_Skill_Type emSkillType) CONST
{
	std::tuple<Point, Point, em_Skill_Index, DWORD, DWORD> tup;
	switch (emSkillType)
	{
	case em_Skill_Type_Directional:
		tup = make_tuple(CPerson::GetInstance().GetPoint(), Tar.GetPoint(), GetSkillIndex(), Tar.GetSkillParameter(), GetNodeBase());
		break;
	case em_Skill_Type_UnDirectional:
		tup = make_tuple(Tar.GetPoint(), Tar.GetPoint(), GetSkillIndex(), 0, GetNodeBase());
		break;
	case em_Skill_Type_Buff_Self:
		tup = make_tuple(CPerson::GetInstance().GetPoint(), CPerson::GetInstance().GetPoint(), GetSkillIndex(), CPerson::GetInstance().GetSkillParameter(), GetNodeBase());
		break;
	case em_Skill_Type_Self_UnDirectional:
		tup = make_tuple(CPerson::GetInstance().GetPoint(), CPerson::GetInstance().GetPoint(), GetSkillIndex(), 0, GetNodeBase());
		break;
	default:
		break;
	}
	return CGameVariable::GetInstance().PushMainThreadActionPtr([&tup] {
		CGameCALL::GetInstance().UseSkill(tup);
	});
}

DWORD CSkill::GetItemSkillParameter() CONST
{
	return 0;
}
