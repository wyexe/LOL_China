#ifndef __LOL_CHINA_LOLDLL_GAME_FIGHT_FIELDFIGHT_H__
#define __LOL_CHINA_LOLDLL_GAME_FIGHT_FIELDFIGHT_H__

#include "GameVariable.h"

class CHero;
class CSolider;
class CTurret;
class CFieldFight
{
public:
	CFieldFight();
	~CFieldFight();

	static CFieldFight& GetInstance();

	// 表演时间!
	VOID StartShowTime() CONST;

	// 游戏初始化
	VOID PartyInitialization() CONST;

	// 中路水晶塔没了的时候的换路操作
	BOOL SetHeroPath() CONST;

	// 复活操作
	BOOL Relive() CONST;

	// 刷BUFF
	BOOL KillBuffMonster(_In_ CONST Point& TarPoint, _In_ std::function<BOOL()> Worker) CONST;

	// 刷龙
	BOOL KillDragon() CONST;

	// 回城
	BOOL BackToBase() CONST;

	// 一直往前走
	BOOL MoveToEnemySpring() CONST;

	// 走到自己最近的防御塔下
	BOOL MoveToLatelyTurret() CONST;

	// 在泉水休息并且更新装备
	BOOL RestInSpring() CONST;

	// 后退
	BOOL BackOff() CONST;

	// 回城逻辑处理(是否需要回城)
	BOOL DoBackToBase() CONST;

	// 敌方的塔的处理
	BOOL DoTurret() CONST;

	// 躲避塔的动作
	BOOL DodgeTurret() CONST;

	// 攻击塔
	BOOL AttackTurret() CONST;

	// 敌方小兵的处理
	BOOL DoSolider() CONST;

	// 躲避小兵
	BOOL DodgeSolider() CONST;

	// 攻击小兵
	BOOL AttackSolider() CONST;

	// 敌方的英雄的处理
	BOOL DoHero() CONST;

	// 躲避英雄攻击
	BOOL DoDgeHero() CONST;

	// 攻击英雄
	BOOL AttackHero() CONST;
private:
	DSIABLE_COPY_AND_ASSIGN(CFieldFight);
};


#endif