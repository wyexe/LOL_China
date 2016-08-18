#ifndef __LOL_CHINA_LOLDLL_GAME_CALL_GAMECALL_H__
#define __LOL_CHINA_LOLDLL_GAME_CALL_GAMECALL_H__

#include "GameVariable.h"

class CGameCALL
{
public:
	CGameCALL() = default;
	~CGameCALL() = default;

	// 走路
	BOOL PlayerMove(_In_ CONST Point& TarPoint) CONST;

	// 暂停英雄动作
	BOOL StopAction() CONST;

	// 获取游戏开场时间/s
	DWORD GetGameRunTime() CONST;

	// 商店购物
	BOOL PurchaseItemByShore(_In_ DWORD dwItemId) CONST;

	// 锁定视角
	BOOL LockView() CONST;

	// 升级技能
	BOOL UpgradeSkill(_In_ em_Skill_Index emSkillIndex) CONST;

	// 英雄普通攻击
	BOOL HeroAttack(_In_ CONST Point& AttackPoint) CONST;

	// 停止普通攻击
	BOOL StopHeroAttack() CONST;

	// 使用技能(当前人物坐标,技能施法点坐标,技能索引,目标ID,技能Parameter)
	BOOL UseSkill(_In_ CONST std::tuple<Point,Point,em_Skill_Index,DWORD,DWORD>& tup) CONST;

	// 获取对象名称
	BOOL GetObjectNamePtrByAddr(_In_ DWORD dwObjectAddr, _Out_ wstring& ObjectName) CONST;

	// 使用物品
	BOOL UsingItem(_In_ DWORD dwItemParameter) CONST;
private:
	DSIABLE_COPY_AND_ASSIGN(CGameCALL);
};


#endif