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
	return ReadDWORD(GetNodeBase() + 0x10);
}

cwstring& CSkill::GetName() CONST
{
	if (wsName.empty())
	{
		CHAR szText[64] = { 0 };
		CCharacter::ReadUTF8Text(ReadDWORD(GetNodeBase() + 技能OBJ偏移) + 0x18, wsName);
	}
	return wsName;
}

DWORD CSkill::GetExpendMp() CONST
{
	return static_cast<DWORD>(ReadFloat(ReadDWORD((GetNodeBase() + 技能OBJ偏移) + 技能耗蓝偏移1) + GetLevel() * 4 + 技能耗蓝偏移2));
}

BOOL CSkill::IsCooldown() CONST
{
	return CGameCALL::GetInstance().GetClientTick() > ReadFloat(GetNodeBase() + 0x14);
}

BOOL CSkill::IsCouldUse() CONST
{
	return GetLevel() > 0 && CPerson::GetInstance().GetMp() >= GetExpendMp() && IsCooldown();
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
	return GetNodeBase();
}
