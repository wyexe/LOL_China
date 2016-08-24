#include "stdafx.h"
#include "HeroFight.h"

CHeroFight::CHeroFight()
{
}

CHeroFight::~CHeroFight()
{
}

CHeroFight& CHeroFight::GetInstance()
{
	static CHeroFight HeroFight;
	return HeroFight;
}

BOOL CHeroFight::KillSolider(_In_ CONST CSolider& Solider, _In_ BOOL bQ, _In_ BOOL bW, _In_ BOOL bE) CONST
{
	return TRUE;
}

BOOL CHeroFight::KillSolider(_In_ CONST CSolider& Solider) CONST
{
	return TRUE;
}

BOOL CHeroFight::KillHero(_In_ CONST CHero& Hero) CONST
{
	return TRUE;
}
