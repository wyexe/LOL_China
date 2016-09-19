#include "stdafx.h"
#include "HumanBaseObject.h"
#include <MyTools/CLPublic.h>
#include "Person.h"
#include "GameCALL.h"

CHumanBaseObject::CHumanBaseObject() : CBaseObject(NULL), fDis(0)
{

}
CHumanBaseObject::CHumanBaseObject(_In_ DWORD dwNodeBase_) : CBaseObject(dwNodeBase_), fDis(0)
{

}

CHumanBaseObject::~CHumanBaseObject()
{
}

DWORD CHumanBaseObject::GetId() CONST
{
	return ReadDWORD(GetNodeBase() + 0x8);
}

DWORD CHumanBaseObject::GetHp() CONST
{
	return static_cast<DWORD>(ReadFloat(GetNodeBase() + HPÆ«ÒÆ));
}

DWORD CHumanBaseObject::GetMaxHp() CONST
{
	return static_cast<DWORD>(ReadFloat(GetNodeBase() + MAXHPÆ«ÒÆ));
}

DWORD CHumanBaseObject::GetPercentHp() CONST
{
	float fHp = static_cast<float>(GetHp());
	float fMaxHp = static_cast<float>(GetMaxHp());
	if (fHp == 0 || fMaxHp == 0)
		return 0;
	return static_cast<DWORD>(fHp / fMaxHp * 100);
}

DWORD CHumanBaseObject::GetMp() CONST
{
	return static_cast<DWORD>(ReadFloat(GetNodeBase() + MPÆ«ÒÆ));
}

DWORD CHumanBaseObject::GetMaxMp() CONST
{
	return static_cast<DWORD>(ReadFloat(GetNodeBase() + MAXMPÆ«ÒÆ));
}

DWORD CHumanBaseObject::GetPercentMp() CONST
{
	float fMp = static_cast<float>(GetMp());
	float fMaxMp = static_cast<float>(GetMaxMp());
	if (fMp == 0 || fMaxMp == 0)
		return 0;
	return static_cast<DWORD>(fMp / fMaxMp * 100);
}

Point CHumanBaseObject::GetPoint() CONST
{
	return Point(ReadFloat(GetNodeBase() + ×ø±êÆ«ÒÆX), ReadFloat(GetNodeBase() + ×ø±êÆ«ÒÆZ), ReadFloat(GetNodeBase() + ×ø±êÆ«ÒÆY));
}

float CHumanBaseObject::GetDis(_In_ CONST Point& TarPoint) CONST
{
	return CLPublic::GetDisBy2D(TarPoint, GetPoint()) / 100.0f;
}

float CHumanBaseObject::GetDis() CONST
{
	return GetDis(CPerson::GetInstance().GetPoint());
}

float CHumanBaseObject::SetDis(_In_ CONST Point& TarPoint)
{
	fDis = CLPublic::GetDisBy2D(TarPoint, GetPoint()) / 100.0f;
	return fDis;
}

void CHumanBaseObject::SetDis()
{
	fDis = GetDis();
}

em_Camp CHumanBaseObject::GetCurrentCamp() CONST
{
	switch (ReadDWORD(GetNodeBase() + 0x14))
	{
	case 0x64:
		return em_Camp::em_Camp_Blue;
	case 0xC8:
		return em_Camp::em_Camp_Red;
	case 0x12C:
		return em_Camp::em_Camp_Neutral;
	default:
		break;
	}
	return em_Camp::em_Camp_UnKnow;
}

em_Human_Type CHumanBaseObject::GetHumanType() CONST
{
	switch (ReadDWORD(GetNodeBase() + 0x18))
	{
	case 0x20005: case 0x2401:
		return em_Human_Type_Turret;
	case 0x1401:
		return em_Human_Type_Hero;
	case 0xC01:
		return em_Human_Type_Solider;
	default:
		break;
	};
	return em_Human_Type_Unknow;
}

BOOL CHumanBaseObject::IsShowInFog() CONST
{
	if (GetHumanType() != em_Human_Type::em_Human_Type_Hero)
		return TRUE;

	return ReadBYTE(ReadDWORD(GetNodeBase() + ÃÔÎíÆ«ÒÆ1) + ÃÔÎíÆ«ÒÆ2 + ÃÔÎíÆ«ÒÆ3) == 1 ? FALSE : TRUE;
}

BOOL CHumanBaseObject::Attack() CONST
{
	return CGameVariable::GetInstance().PushMainThreadActionPtr([this] {
		CGameCALL::GetInstance().HeroAttack(GetNodeBase(), GetPoint());
	});
}

BOOL CHumanBaseObject::IsDead() CONST
{
	return ReadDWORD(GetNodeBase() + ÈËÎïËÀÍöÆ«ÒÆ) != NULL;
}

DWORD CHumanBaseObject::GetSkillParameter() CONST
{
	return ReadDWORD(GetNodeBase() + ¼¼ÄÜOBJÆ«ÒÆ);
}

DWORD CHumanBaseObject::GetTargetId() CONST
{
	return ReadDWORD(ReadDWORD(ReadDWORD(GetNodeBase() + TargetÆ«ÒÆ1) + TargetÆ«ÒÆ2) + TargetÆ«ÒÆ3);
}

bool CHumanBaseObject::operator<(CONST CHumanBaseObject& itm) CONST
{
	return fDis < itm.fDis;
}

