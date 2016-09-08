#include "stdafx.h"
#include "ObjectExtend.h"
#include <MyTools/CLPublic.h>
#include "Equment.h"
#include "HeroBuff.h"
#include "Creep.h"
#include "Skill.h"
#include "Turret.h"
#include "Person.h"
#include "Solider.h"
CObjectExtend::CObjectExtend()
{
}

CObjectExtend::~CObjectExtend()
{
}

CObjectExtend& CObjectExtend::GetInstance()
{
	static CObjectExtend ObjectExtend;
	return ObjectExtend;
}

VOID CObjectExtend::AbstractClass()
{

}

BOOL CObjectExtend::ExistEqumentByCondition(_Out_ CEqument* pEqument, _In_ std::function<BOOL(CONST CEqument&)> Finder) CONST
{
	vector<CEqument> vlst;
	GetCurrentHeroEqumentList(vlst);
	return CLPublic::Vec_find_if(vlst, pEqument, Finder);
}

BOOL CObjectExtend::ExistEqumentById(_In_ DWORD dwEqumentId, _Out_ CEqument* pEqument) CONST
{
	return ExistEqumentByCondition(pEqument, [&dwEqumentId](CONST auto& itm) {
		return itm.GetId() == dwEqumentId;
	});
}

BOOL CObjectExtend::ExistHeroBuffByCondition(_Out_ CHeroBuff* pHeroBuff, _In_ std::function<BOOL(CONST CHeroBuff&)> Finder) CONST
{
	vector<CHeroBuff> vlst;
	GetCurrentHeroBuffList(vlst);
	return CLPublic::Vec_find_if(vlst, pHeroBuff, Finder);
}

BOOL CObjectExtend::ExistBuffById(_In_ DWORD dwBuffId, _Out_ CHeroBuff* pHeroBuff) CONST
{
	return ExistHeroBuffByCondition(pHeroBuff, [&dwBuffId](CONST auto& itm) {
		return itm.GetId() == dwBuffId;
	});
}

BOOL CObjectExtend::ExistCreepByCondition(_Out_ CReep* pReep, _In_ std::function<BOOL(CONST CReep&)> Finer) CONST
{
	vector<CReep> vlst;
	GetCreepList(vlst);
	return CLPublic::Vec_find_if(vlst, pReep, Finer);
}

BOOL CObjectExtend::ExistCreepById(_In_ DWORD dwCreepId, _Out_ CReep* pReep) CONST
{
	return ExistCreepByCondition(pReep, [&dwCreepId](CONST auto& itm) {
		return itm.GetId() == dwCreepId;
	});
}

BOOL CObjectExtend::ExistCreepByName(_In_ cwstring& wsCreepName, _Out_ CReep* pReep) CONST
{
	return ExistCreepByCondition(pReep, [&wsCreepName](CONST auto& itm) {
		return itm.GetName() == wsCreepName;
	});
}

BOOL CObjectExtend::ExistSkillByCondition(_Out_ CSkill* pSkill, _In_ std::function<BOOL(CONST CSkill&)> Finder) CONST
{
	vector<CSkill> vlst;
	GetSkillList(vlst);
	return CLPublic::Vec_find_if(vlst, pSkill, Finder);
}

BOOL CObjectExtend::ExistSkillByIndex(_In_ em_Skill_Index emSkillIndex, _Out_ CSkill* pSkill) CONST
{
	vector<CSkill> vlst;
	GetSkillList(vlst);
	return ExistSkillByCondition(pSkill, [&emSkillIndex](CONST CSkill& Skill) {
		return Skill.GetSkillIndex() == emSkillIndex;
	});
}

BOOL CObjectExtend::ExistSkillByName(_In_ cwstring& wsSkillName, _Out_ CSkill* pSkill) CONST
{
	vector<CSkill> vlst;
	GetSkillList(vlst);
	return ExistSkillByCondition(pSkill, [&wsSkillName](CONST CSkill& Skill) {
		return Skill.GetName() == wsSkillName;
	});
}

BOOL CObjectExtend::ExistTurretByName(_In_ cwstring& wsTurretName, _In_ em_Camp emCamp, _Out_ CTurret* pTurret) CONST
{
	vector<CTurret> vlst;
	GetHumanTypeListByType(em_Human_Type_Turret, emCamp, vlst);
	return CLPublic::Vec_find_if(vlst, pTurret, [&wsTurretName](CONST auto& itm) {
		return itm.GetName() == wsTurretName;
	});
}

BOOL CObjectExtend::GetLatelyTurretByCamp(_In_ em_Camp emCamp, _In_ float fDis, _Out_ CTurret* pTurret) CONST
{
	vector<CTurret> vlst;
	GetHumanTypeListByType(em_Human_Type_Turret, emCamp, vlst);
	return CLPublic::Vec_find_if(vlst, pTurret, [&fDis](CONST auto& itm) { return itm.GetDis() <= fDis; });
}

BOOL CObjectExtend::ExistSoliderByCondition(_In_ em_Camp emCamp, _Out_ CSolider* pSolider, _In_ std::function<BOOL(CONST CSolider&)> Finder) CONST
{
	vector<CSolider> vlst;
	GetHumanTypeListByType(em_Human_Type_Turret, emCamp, vlst);
	return CLPublic::Vec_find_if(vlst, pSolider, Finder);
}

BOOL CObjectExtend::ExistSoliderByName(_In_ cwstring& wsSoliderName, _In_ em_Camp emCamp, _Out_ CSolider* pSolider) CONST
{
	return ExistSoliderByCondition(emCamp, pSolider, [&wsSoliderName](CONST auto& itm) { return itm.GetName() == wsSoliderName; });
}

BOOL CObjectExtend::GetLatelySoliderByCamp(_In_ em_Camp emCamp, _In_ float fDis, _Out_ CSolider* pSolider) CONST
{
	return ExistSoliderByCondition(emCamp, pSolider, [&fDis](CONST auto& itm) {
		return itm.GetDis() <= fDis;
	});
}

UINT CObjectExtend::GetEnemyHeroCountByDis(_In_ float fDis) CONST
{
	return GetAroundHumanTypeCount<CHero>(em_Human_Type_Hero, CPerson::GetInstance().GetEnemyCamp(), fDis);
}

UINT CObjectExtend::GetEnemySoliderCountByDis(_In_ float fDis) CONST
{
	return GetAroundHumanTypeCount<CSolider>(em_Human_Type_Solider, CPerson::GetInstance().GetEnemyCamp(), fDis);
}

UINT CObjectExtend::GetAllySoliderCountByDis(_In_ CONST Point& FixPt, _In_ float fDis) CONST
{
	vector<CSolider> vlst;
	GetHumanTypeListByType(em_Human_Type_Solider, CPerson::GetInstance().GetCurrentCamp(), vlst);
	return CLPublic::Vec_erase_if(vlst, [&FixPt, &fDis](CONST auto& itm) { return itm.GetDis(FixPt) <= fDis; });
}

BOOL CObjectExtend::GetAnemiaSoliderByDis(_In_ float fDis, _Out_ CSolider* pSolider) CONST
{
	vector<CSolider> vlst;
	GetHumanTypeListByType(em_Human_Type_Solider, CPerson::GetInstance().GetEnemyCamp(), vlst);
	return CLPublic::Vec_find_if(vlst, pSolider, [&fDis](CONST auto& itm) { return itm.GetPercentHp() <= 20 && itm.GetDis() <= fDis; });
}

UINT CObjectExtend::GetEnemyAttackSoliderCountByDis(_In_ float fDis) CONST
{
	vector<CSolider> vlst;
	GetHumanTypeListByType(em_Human_Type_Solider, CPerson::GetInstance().GetEnemyCamp(), vlst);
	return CLPublic::Vec_erase_if(vlst, [&fDis](CONST auto& itm) { return itm.GetTargetId() == CPerson::GetInstance().GetId() && itm.GetDis() <= fDis; });
}

BOOL CObjectExtend::GetLatelyHeroByCamp(_In_ em_Camp emCamp, _In_ float fDis, _Out_ CHero* pHero) CONST
{
	vector<CHero> vlst;
	GetHumanTypeListByType(em_Human_Type_Hero, emCamp, vlst);
	return CLPublic::Vec_find_if(vlst, pHero, [&fDis](CONST auto& itm) { return itm.GetDis() <= fDis; });
}

UINT CObjectExtend::GetEnemyAttackHeroCountByDis(_In_ float fDis) CONST
{
	vector<CHero> vlst;
	GetHumanTypeListByType(em_Human_Type_Hero, CPerson::GetInstance().GetEnemyCamp(), vlst);
	return CLPublic::Vec_erase_if(vlst, [&fDis](CONST auto& itm) { return itm.GetTargetId() == CPerson::GetInstance().GetId() && itm.GetDis() <= fDis; });
}
