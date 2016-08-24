#ifndef __LOL_CHINA_LOLDLL_GAME_FIGHT_HEROFIGHT_H__
#define __LOL_CHINA_LOLDLL_GAME_FIGHT_HEROFIGHT_H__

#include "GameVariable.h"

class CSolider;
class CHero;
class CHeroFight
{
public:
	CHeroFight();
	~CHeroFight();

	static CHeroFight& GetInstance();

	BOOL KillSolider(_In_ CONST CSolider& Solider, _In_ BOOL bQ, _In_ BOOL bW, _In_ BOOL bE) CONST;
	BOOL KillSolider(_In_ CONST CSolider& Solider) CONST;

	BOOL KillHero(_In_ CONST CHero& Hero) CONST;
private:
	DSIABLE_COPY_AND_ASSIGN(CHeroFight);
};



#endif