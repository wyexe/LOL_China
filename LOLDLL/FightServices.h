#ifndef __LOL_CHINA_LOLDLL_GAME_FIGHT_FIGHTSERVICES_H__
#define __LOL_CHINA_LOLDLL_GAME_FIGHT_FIGHTSERVICES_H__

#include "GameVariable.h"

class CFightServices
{
public:
	CFightServices();
	~CFightServices();

	static CFightServices& GetInstance();

	// 等待游戏开始(出兵)!
	VOID WaitToShowSolider() CONST;

	// 判断中路水晶塔是否没了
	BOOL ExistMiddleCrystalTurret() CONST;

	// 判断是否在家里
	BOOL IsAtBase() CONST;

	// 是否需要回家了
	BOOL IsHaveToBackToBase() CONST;

	// 是否躲避塔的攻击
	BOOL IsDodgeTurret() CONST;

	// 是否需要攻击塔
	BOOL IsAttackTurret() CONST;

	// 是否需要躲避小兵的攻击
	BOOL IsDogeSolider() CONST;

	// 是否要攻击小兵
	BOOL IsClearSolider() CONST;

	// 是否躲避英雄的攻击
	BOOL IsDodgeHero() CONST;

	// 是否攻击英雄
	BOOL IsAttackHero() CONST;
private:
	DSIABLE_COPY_AND_ASSIGN(CFightServices);
};


#endif