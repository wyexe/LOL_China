#ifndef __LOL_CHINA_LOLDLL_GAME_OBJECTSERVICES_OBJECTFUNCTION_H__
#define __LOL_CHINA_LOLDLL_GAME_OBJECTSERVICES_OBJECTFUNCTION_H__

#include "ObjectTraverse.h"

class CHero;
class CObjectExtend : public CObjectTraverse
{
public:
	CObjectExtend();
	~CObjectExtend();

	static CObjectExtend& GetInstance();

	// 只能被继承类实例化!
	virtual VOID AbstractClass();
public:
	// 条件遍历装备
	BOOL ExistEqumentByCondition(_Out_ CEqument* pEqument ,_In_ std::function<BOOL(CONST CEqument&)> Finder) CONST;

	// 根据ID判断是否存在装备
	BOOL ExistEqumentById(_In_ DWORD dwEqumentId, _Out_ CEqument* pEqument) CONST;

	// 条件遍历Buff
	BOOL ExistHeroBuffByCondition(_Out_ CHeroBuff* pHeroBuff, _In_ std::function<BOOL(CONST CHeroBuff&)> Finder) CONST;

	// 根据BUFFID判断是否存在buff
	BOOL ExistBuffById(_In_ DWORD dwBuffId, _Out_ CHeroBuff* pHeroBuff) CONST;

	// 条件遍历野怪
	BOOL ExistCreepByCondition(_Out_ CReep* pReep, _In_ std::function<BOOL(CONST CReep&)> Finer) CONST;

	// 根据ID查找野怪
	BOOL ExistCreepById(_In_ DWORD dwCreepId, _Out_ CReep* pReep) CONST;
	BOOL ExistCreepByName(_In_ cwstring& wsCreepName, _Out_ CReep* pReep) CONST;

	// 技能
	BOOL ExistSkillByCondition(_Out_ CSkill* pSkill, _In_ std::function<BOOL(CONST CSkill&)> Finder) CONST;
	BOOL ExistSkillByIndex(_In_ em_Skill_Index emSkillIndex, _Out_ CSkill* pSkill) CONST;
	BOOL ExistSkillByName(_In_ cwstring& wsSkillName, _Out_ CSkill* pSkill) CONST;

	// 
	BOOL ExistTurretByName(_In_ cwstring& wsTurretName, _In_ em_Camp emCamp, _Out_ CTurret* pTurret) CONST;
	BOOL GetLatelyTurretByCamp(_In_ em_Camp emCamp, _In_ float fDis, _Out_ CTurret* pTurret) CONST;

	//
	BOOL ExistSoliderByCondition(_In_ em_Camp emCamp, _Out_ CSolider* pSolider, _In_ std::function<BOOL(CONST CSolider&)> Finder) CONST;
	BOOL ExistSoliderByName(_In_ cwstring& wsSoliderName, _In_ em_Camp emCamp, _Out_ CSolider* pSolider) CONST;

	// 获取最近的小兵
	BOOL GetLatelySoliderByCamp(_In_ em_Camp emCamp, _In_ float fDis, _Out_ CSolider* pSolider) CONST;

	// 获取附近敌方小兵的数量
	UINT GetEnemySoliderCountByDis(_In_ float fDis) CONST;

	// 获取附近己方小兵的数量
	UINT GetAllySoliderCountByDis(_In_ CONST Point& FixPt, _In_ float fDis) CONST;

	// 获取敌方残血的小兵
	BOOL GetAnemiaSoliderByDis(_In_ float fDis, _Out_ CSolider* pSolider) CONST;

	// 获取敌方小兵攻击自己的数量
	UINT GetEnemyAttackSoliderCountByDis(_In_ float fDis) CONST;

	UINT GetEnemyHeroCountByDis(_In_ float fDis) CONST;
	BOOL GetLatelyHeroByCamp(_In_ em_Camp emCamp, _In_ float fDis, _Out_ CHero* pHero) CONST;

	// 获取敌方英雄攻击自己的数量
	UINT GetEnemyAttackHeroCountByDis(_In_ float fDis) CONST;
private:
	DSIABLE_COPY_AND_ASSIGN(CObjectExtend);
};



#endif