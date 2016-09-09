#ifndef __LOL_CHINA_LOLDLL_GAME_CALL_GAMECALL_H__
#define __LOL_CHINA_LOLDLL_GAME_CALL_GAMECALL_H__

#include "GameVariable.h"

class CGameCALL
{
public:
	CGameCALL() = default;
	~CGameCALL() = default;

	static CGameCALL& GetInstance();

	// 走路
	BOOL PlayerMove(_In_ CONST Point& TarPoint) CONST;

	// 暂停英雄动作
	BOOL StopAction() CONST;

	// 商店购物
	BOOL PurchaseItemByShore(_In_ DWORD dwItemId) CONST;

	// 锁定视角
	BOOL LockView() CONST;

	// 升级技能
	BOOL UpgradeSkill(_In_ em_Skill_Index emSkillIndex) CONST;

	// 英雄普通攻击
	BOOL HeroAttack(_In_ DWORD dwTarNodeBase, _In_ CONST Point& AttackPoint) CONST;

	// 使用技能(当前人物坐标,技能施法点坐标,技能索引,目标ID,技能Parameter)
	BOOL UseSkill(_In_ CONST std::tuple<Point,Point,em_Skill_Index,DWORD,DWORD>& tup) CONST;

	// 获取游戏时间
	float GetClientTick() CONST;
private:
	DSIABLE_COPY_AND_ASSIGN(CGameCALL);
};


#endif