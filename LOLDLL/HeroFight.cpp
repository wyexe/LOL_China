#include "stdafx.h"
#include "HeroFight.h"
#include <MyTools/CLPublic.h>
#include <MyTools/CLLog.h>
#include "Person.h"
#include "SkillServices.h"
#include "ObjectExtend.h"

#define _SELF L"HeroFight.cpp"

CHeroFight::CHeroFight(_In_ CSkillServices* pCSkillServices_)
{
	pSkillServices = pCSkillServices_;
}

CHeroFight::~CHeroFight()
{
}

CHeroFight& CHeroFight::GetInstance()
{
	static CHeroFight HeroFight(&CSkillServices::GetInstance());
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

BOOL CHeroFight::KillHero(_In_ CONST CHero& EnemyHero) CONST
{
	static tagHeroPtr* pHeroPtr = nullptr;
	if (pHeroPtr == nullptr)
	{
		pHeroPtr = const_cast<tagHeroPtr*>(ExistHeroWorker(CPerson::GetInstance().GetHeroPro()));
		if (pHeroPtr == nullptr)
		{
			LogMsgBox(LOG_LEVEL_EXCEPTION, L"当前这个英雄的逻辑还没写呐!:emHeroPro:%X", CPerson::GetInstance().GetHeroPro());
			return FALSE;
		}
	}

	return pHeroPtr->Worker(EnemyHero);
}

auto CHeroFight::ExistHeroWorker(_In_ em_Hero_Pro emHeroPro) CONST -> CONST tagHeroPtr*
{
	CONST static vector<tagHeroPtr> vlst = {
		{ em_Hero_Pro_Ryze, std::bind(&CHeroFight::Hero_Ryze, this, std::placeholders::_1) },
		{ em_Hero_Pro_Ashe, std::bind(&CHeroFight::Hero_Ashe, this, std::placeholders::_1) },
		{ em_Hero_Pro_MasterYi, std::bind(&CHeroFight::Hero_MasterYi, this, std::placeholders::_1) },
		{ em_Hero_Pro_MissFortune, std::bind(&CHeroFight::Hero_MissFortune, this, std::placeholders::_1) },
		{ em_Hero_Pro_Garen, std::bind(&CHeroFight::Hero_Garen, this, std::placeholders::_1) },
		{ em_Hero_Pro_Malzahar, std::bind(&CHeroFight::Hero_Malzahar, this, std::placeholders::_1) },
		{ em_Hero_Pro_Ezreal, std::bind(&CHeroFight::Hero_Ezreal, this, std::placeholders::_1) },
		{ em_Hero_Pro_Chogath, std::bind(&CHeroFight::Hero_Chogath, this, std::placeholders::_1) },
		{ em_Hero_Pro_Nunu, std::bind(&CHeroFight::Hero_Nunu, this, std::placeholders::_1) },
		{ em_Hero_Pro_Heimerdinger, std::bind(&CHeroFight::Hero_Heimerdinger, this, std::placeholders::_1) },
		{ em_Hero_Pro_Graves, std::bind(&CHeroFight::Hero_Graves, this, std::placeholders::_1) },
		{ em_Hero_Pro_Swain, std::bind(&CHeroFight::Hero_Swain, this, std::placeholders::_1) },
		{ em_Hero_Pro_Vayne, std::bind(&CHeroFight::Hero_Vayne, this, std::placeholders::_1) },
		{ em_Hero_Pro_Maokai, std::bind(&CHeroFight::Hero_Maokai, this, std::placeholders::_1) },
		{ em_Hero_Pro_Veigar, std::bind(&CHeroFight::Hero_Veigar, this, std::placeholders::_1) },
		{ em_Hero_Pro_Sejuani, std::bind(&CHeroFight::Hero_Sejuani, this, std::placeholders::_1) },
		{ em_Hero_Pro_Tristana, std::bind(&CHeroFight::Hero_Tristana, this, std::placeholders::_1) },
		{ em_Hero_Pro_Galio, std::bind(&CHeroFight::Hero_Galio, this, std::placeholders::_1) },
		{ em_Hero_Pro_Lucian, std::bind(&CHeroFight::Hero_Lucian, this, std::placeholders::_1) },
		{ em_Hero_Pro_Trundle, std::bind(&CHeroFight::Hero_Trundle, this, std::placeholders::_1) },
		{ em_Hero_Pro_Aatrox, std::bind(&CHeroFight::Hero_Aatrox, this, std::placeholders::_1) },
		{ em_Hero_Pro_Taric, std::bind(&CHeroFight::Hero_Taric, this, std::placeholders::_1) },
		{ em_Hero_Pro_Rumble, std::bind(&CHeroFight::Hero_Rumble, this, std::placeholders::_1) },
		{ em_Hero_Pro_Diana, std::bind(&CHeroFight::Hero_Diana, this, std::placeholders::_1) },
		{ em_Hero_Pro_Urgot, std::bind(&CHeroFight::Hero_Urgot, this, std::placeholders::_1) },
		{ em_Hero_Pro_Teemo, std::bind(&CHeroFight::Hero_Teemo, this, std::placeholders::_1) },
		{ em_Hero_Pro_Caitlyn, std::bind(&CHeroFight::Hero_Caitlyn, this, std::placeholders::_1) },
		{ em_Hero_Pro_Corki, std::bind(&CHeroFight::Hero_Corki, this, std::placeholders::_1) },
		{ em_Hero_Pro_Fiora, std::bind(&CHeroFight::Hero_Fiora, this, std::placeholders::_1) },
		{ em_Hero_Pro_Mordekaiser, std::bind(&CHeroFight::Hero_Mordekaiser, this, std::placeholders::_1) },
		{ em_Hero_Pro_Nautilus, std::bind(&CHeroFight::Hero_Nautilus, this, std::placeholders::_1) },
		{ em_Hero_Pro_Sivir, std::bind(&CHeroFight::Hero_Sivir, this, std::placeholders::_1) },
		{ em_Hero_Pro_KogMaw, std::bind(&CHeroFight::Hero_KogMaw, this, std::placeholders::_1) },
		{ em_Hero_Pro_Annie, std::bind(&CHeroFight::Hero_Annie, this, std::placeholders::_1) },
		{ em_Hero_Pro_Akali, std::bind(&CHeroFight::Hero_Akali, this, std::placeholders::_1) },
		{ em_Hero_Pro_Alistar, std::bind(&CHeroFight::Hero_Alistar, this, std::placeholders::_1) },
		{ em_Hero_Pro_Amumu, std::bind(&CHeroFight::Hero_Amumu, this, std::placeholders::_1) },
		{ em_Hero_Pro_Blitzcrank, std::bind(&CHeroFight::Hero_Blitzcrank, this, std::placeholders::_1) },
		{ em_Hero_Pro_Brand, std::bind(&CHeroFight::Hero_Brand, this, std::placeholders::_1) },
		{ em_Hero_Pro_Cassiopeia, std::bind(&CHeroFight::Hero_Cassiopeia, this, std::placeholders::_1) },
		{ em_Hero_Pro_Darius, std::bind(&CHeroFight::Hero_Darius, this, std::placeholders::_1) },
		{ em_Hero_Pro_DrMundo, std::bind(&CHeroFight::Hero_DrMundo, this, std::placeholders::_1) },
		{ em_Hero_Pro_Ekko, std::bind(&CHeroFight::Hero_Ekko, this, std::placeholders::_1) },
		{ em_Hero_Pro_FiddleSticks, std::bind(&CHeroFight::Hero_FiddleSticks, this, std::placeholders::_1) },
		{ em_Hero_Pro_Fizz, std::bind(&CHeroFight::Hero_Fizz, this, std::placeholders::_1) },
		{ em_Hero_Pro_Gragas, std::bind(&CHeroFight::Hero_Gragas, this, std::placeholders::_1) },
		{ em_Hero_Pro_Illaoi, std::bind(&CHeroFight::Hero_Illaoi, this, std::placeholders::_1) },
		{ em_Hero_Pro_Itrlia, std::bind(&CHeroFight::Hero_Itrlia, this, std::placeholders::_1) },
		{ em_Hero_Pro_JarvanIV, std::bind(&CHeroFight::Hero_JarvanIV, this, std::placeholders::_1) },
		{ em_Hero_Pro_Jax, std::bind(&CHeroFight::Hero_Jax, this, std::placeholders::_1) },
		{ em_Hero_Pro_Jhin, std::bind(&CHeroFight::Hero_Jhin, this, std::placeholders::_1) },
		{ em_Hero_Pro_Jinx, std::bind(&CHeroFight::Hero_Jinx, this, std::placeholders::_1) },
		{ em_Hero_Pro_Karma, std::bind(&CHeroFight::Hero_Karma, this, std::placeholders::_1) },
		{ em_Hero_Pro_Katarina, std::bind(&CHeroFight::Hero_Katarina, this, std::placeholders::_1) },
		{ em_Hero_Pro_Leona, std::bind(&CHeroFight::Hero_Leona, this, std::placeholders::_1) },
		{ em_Hero_Pro_Lux, std::bind(&CHeroFight::Hero_Lux, this, std::placeholders::_1) },
		{ em_Hero_Pro_Malphite, std::bind(&CHeroFight::Hero_Malphite, this, std::placeholders::_1) },
		{ em_Hero_Pro_MonkeyKing, std::bind(&CHeroFight::Hero_MonkeyKing, this, std::placeholders::_1) },
		{ em_Hero_Pro_Morgana, std::bind(&CHeroFight::Hero_Morgana, this, std::placeholders::_1) },
		{ em_Hero_Pro_Nasus, std::bind(&CHeroFight::Hero_Nasus, this, std::placeholders::_1) },
		{ em_Hero_Pro_Olaf, std::bind(&CHeroFight::Hero_Olaf, this, std::placeholders::_1) },
		{ em_Hero_Pro_Sion, std::bind(&CHeroFight::Hero_Sion, this, std::placeholders::_1) },
		{ em_Hero_Pro_Poppy, std::bind(&CHeroFight::Hero_Poppy, this, std::placeholders::_1) },
		{ em_Hero_Pro_Rammus, std::bind(&CHeroFight::Hero_Rammus, this, std::placeholders::_1) },
		{ em_Hero_Pro_Renekton, std::bind(&CHeroFight::Hero_Renekton, this, std::placeholders::_1) },
		{ em_Hero_Pro_Sona, std::bind(&CHeroFight::Hero_Sona, this, std::placeholders::_1) },
		{ em_Hero_Pro_Velkoz, std::bind(&CHeroFight::Hero_Velkoz, this, std::placeholders::_1) },
		{ em_Hero_Pro_XinZhao, std::bind(&CHeroFight::Hero_XinZhao, this, std::placeholders::_1) },
		{ em_Hero_Pro_Ziggs, std::bind(&CHeroFight::Hero_Ziggs, this, std::placeholders::_1) },
	};

	return CLPublic::Vec_find_if(vlst, [&emHeroPro](CONST tagHeroPtr& itm) { return itm.emHeroPro == emHeroPro; });
}

BOOL CHeroFight::Hero_Ryze(_In_ CONST CHero& EnemyHero) CONST
{
	// 瑞兹起手Q, E, W, Q
	if (pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_Q))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_Q, EnemyHero);

	if (pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_E))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_E, EnemyHero);

	if (pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_W))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_W, EnemyHero);

	if (pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_Q))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_Q, EnemyHero);
	
	// 普通攻击!
	return EnemyHero.Attack();
}

BOOL CHeroFight::Hero_Ashe(_In_ CONST CHero& EnemyHero) CONST
{
	// 有W用W
	if (EnemyHero.GetDis() < 7.0f && pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_W))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_W, EnemyHero);
	// 只有打英雄的时候才用R!
	if (EnemyHero.GetPercentHp() < 50 && pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_R))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_R, EnemyHero);

	// 只有存在Q的BUFF才用Q
	if (EnemyHero.GetDis() < 6.0f && pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_Q) && CObjectExtend::GetInstance().ExistBuffById(HERO_BUFF_ASHE_Q, nullptr))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_Q, EnemyHero);

	return EnemyHero.Attack();
}

BOOL CHeroFight::Hero_MasterYi(_In_ CONST CHero& EnemyHero) CONST
{
	// 剑圣有Q用Q
	if (pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_Q))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_Q, EnemyHero);

	// 当HP < 50
	if (CPerson::GetInstance().GetPercentHp() < 50 && pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_W))
	{
		pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_W, EnemyHero);
		// 判断加血BUFF是否存在!
		LOLSleep(1 * 1000);
		while (GameRun && CObjectExtend::GetInstance().ExistBuffById(HERO_BUFF_MASTERYI_W, nullptr) && LOLSleep(500));
		return TRUE;
	}

	// 有E用E， 真实伤害
	if (pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_E))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_E, EnemyHero);

	// 有R用R, 加攻速
	if (pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_R))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_R, EnemyHero);

	return EnemyHero.Attack();
}

BOOL CHeroFight::Hero_MissFortune(_In_ CONST CHero& EnemyHero) CONST
{
	if (pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_E))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_E, EnemyHero);

	if (pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_Q))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_Q, EnemyHero);

	// 低于50%才用R
	if (EnemyHero.GetPercentHp() < 50 && pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_R))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_R, EnemyHero);

	if (EnemyHero.GetDis() < 6.0f && pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_W) && !CObjectExtend::GetInstance().ExistBuffById(HERO_BUFF_MISSFORTUNE_W, nullptr))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_W, EnemyHero);

	return EnemyHero.Attack();
}

BOOL CHeroFight::Hero_Garen(_In_ CONST CHero& EnemyHero) CONST
{
	if (EnemyHero.GetPercentHp() < 30 && pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_R))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_R, EnemyHero);

	if (EnemyHero.GetDis() < 5.0f && !CObjectExtend::GetInstance().ExistBuffById(HERO_BUFF_GAREN_W, nullptr) && pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_W))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_W, EnemyHero);

	// 盖伦的E施法至少是3秒
	static ULONGLONG ulTickE = NULL;
	if (::GetTickCount64() - ulTickE >= 4 * 1000 && pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_E))
	{
		pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_E, EnemyHero);
		ulTickE = ::GetTickCount64();
		return TRUE;
	}

	if (EnemyHero.GetDis() < 3.0f && !CObjectExtend::GetInstance().ExistBuffById(HERO_BUFF_GAREN_Q,nullptr) && pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_Q))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_Q, EnemyHero);
	
	return EnemyHero.Attack();
}

BOOL CHeroFight::Hero_Malzahar(_In_ CONST CHero& EnemyHero) CONST
{
	if (pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_Q))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_Q, EnemyHero);

	if (pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_W))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_W, EnemyHero);

	if (pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_E))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_E, EnemyHero);

	if (pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_R))
	{
		pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_R, EnemyHero);
		while (GameRun && CObjectExtend::GetInstance().ExistBuffById(HERO_BUFF_MALZAHAR_R, nullptr) && LOLSleep(500));
		return TRUE;
	}

	return EnemyHero.Attack();
}

BOOL CHeroFight::Hero_Ezreal(_In_ CONST CHero& EnemyHero) CONST
{
	if (pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_R))
	{
		pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_R, EnemyHero);
		return LOLSleep(1000);
	}

	if (pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_Q))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_Q, EnemyHero);

	if (pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_W))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_W, EnemyHero);

	if (pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_E))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_E, EnemyHero);
	
	return EnemyHero.Attack();
}

BOOL CHeroFight::Hero_Chogath(_In_ CONST CHero& EnemyHero) CONST
{
	if (pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_Q))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_Q, EnemyHero);

	if (pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_W))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_W, EnemyHero);

	if (EnemyHero.GetPercentHp() < 30 && pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_R))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_R, EnemyHero);

	return EnemyHero.Attack();
}

BOOL CHeroFight::Hero_Nunu(_In_ CONST CHero& EnemyHero) CONST
{
	if (pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_W))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_W, EnemyHero);

	if (pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_E))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_E, EnemyHero);

	if (EnemyHero.GetDis() < 3.0f && pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_R))
	{
		pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_R, EnemyHero);
		while (GameRun && CObjectExtend::GetInstance().ExistBuffById(HERO_BUFF_NUNU_R, nullptr) && LOLSleep(500));
		return TRUE;
	}

	return EnemyHero.Attack();
}

BOOL CHeroFight::Hero_Heimerdinger(_In_ CONST CHero& EnemyHero) CONST
{
	static ULONGLONG ulTickQ = 0;
	if (::GetTickCount64() - ulTickQ >= 25 * 1000 && pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_Q))
	{
		if (pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_R))
			pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_R, EnemyHero);

		pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_Q, EnemyHero);
		ulTickQ = ::GetTickCount64();
		return TRUE;
	}

	if (pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_W))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_W, EnemyHero);

	if (pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_E))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_E, EnemyHero);

	return EnemyHero.Attack();
}

BOOL CHeroFight::Hero_Graves(_In_ CONST CHero& EnemyHero) CONST
{
	if (pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_Q))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_Q, EnemyHero);

	if (pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_W))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_W, EnemyHero);

	if (pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_E))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_E, EnemyHero);

	if (pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_R))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_R, EnemyHero);

	return EnemyHero.Attack();
}

BOOL CHeroFight::Hero_Swain(_In_ CONST CHero& EnemyHero) CONST
{
	if (pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_Q))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_Q, EnemyHero);

	if (pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_W))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_W, EnemyHero);

	if (pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_E))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_E, EnemyHero);

	static ULONGLONG ulTickR = 0;
	if (::GetTickCount64() - ulTickR >= 10 * 1000 && CPerson::GetInstance().GetPercentHp() < 75 && pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_R))
	{
		pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_R, EnemyHero);
		ulTickR = ::GetTickCount64();
		return TRUE;
	}

	return EnemyHero.Attack();
}

BOOL CHeroFight::Hero_Vayne(_In_ CONST CHero& EnemyHero) CONST
{
	if (pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_Q))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_Q, EnemyHero);

	if (pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_E))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_E, EnemyHero);

	if (pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_R))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_R, EnemyHero);

	return EnemyHero.Attack();
}

BOOL CHeroFight::Hero_Maokai(_In_ CONST CHero& EnemyHero) CONST
{
	static ULONGLONG ulTickW = 0;
	if (::GetTickCount64() - ulTickW >= 2 * 1000 && pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_Q))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_Q, EnemyHero);

	if (pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_W))
	{
		pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_W, EnemyHero);
		ulTickW = GetTickCount64();
		return TRUE;
	}

	if (pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_E))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_E, EnemyHero);

	if (CPerson::GetInstance().GetPercentHp() < 75 && pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_R))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_R, EnemyHero);

	return EnemyHero.Attack();
}

BOOL CHeroFight::Hero_Veigar(_In_ CONST CHero& EnemyHero) CONST
{
	if (pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_Q))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_Q, EnemyHero);

	if (pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_W))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_W, EnemyHero);

	if (pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_E))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_E, EnemyHero);

	if (EnemyHero.GetPercentHp() < 50 && pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_R))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_R, EnemyHero);

	return EnemyHero.Attack();
}

BOOL CHeroFight::Hero_Sejuani(_In_ CONST CHero& EnemyHero) CONST
{
	if (pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_Q))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_Q, EnemyHero);

	if (EnemyHero.GetDis() < 2.0f && !CObjectExtend::GetInstance().ExistBuffById(HERO_BUFF_SJUANI_W, nullptr) && pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_W))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_W, EnemyHero);

	if (EnemyHero.GetDis() < 2.0f && pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_E))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_E, EnemyHero);

	if (pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_R))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_R, EnemyHero);

	return EnemyHero.Attack();
}

BOOL CHeroFight::Hero_Tristana(_In_ CONST CHero& EnemyHero) CONST
{
	if (!CObjectExtend::GetInstance().ExistBuffById(HERO_BUFF_TRISTANA_Q, nullptr) && pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_Q))
			return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_Q, EnemyHero);

	if (EnemyHero.GetPercentHp() < 20 && pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_W))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_W, EnemyHero);

	if (pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_E))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_E, EnemyHero);

	if ((EnemyHero.GetDis() < 2.0f || EnemyHero.GetPercentHp() < 20) && pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_R))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_R, EnemyHero);

	return EnemyHero.Attack();
}

BOOL CHeroFight::Hero_Galio(_In_ CONST CHero& EnemyHero) CONST
{
	if (pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_Q))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_Q, EnemyHero);

	if (CPerson::GetInstance().GetPercentHp() < 70 && pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_W))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_W, EnemyHero);

	if (pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_E))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_E, EnemyHero);

	if (pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_R))
	{
		pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_R, EnemyHero);
		LOLSleep(2 * 1000);
		return TRUE;
	}

	return EnemyHero.Attack();
}

BOOL CHeroFight::Hero_Lucian(_In_ CONST CHero& EnemyHero) CONST
{
	if (pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_Q))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_Q, EnemyHero);

	if (pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_W))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_W, EnemyHero);

	if (pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_E))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_E, EnemyHero);

	static ULONGLONG ulTickR = 0;
	if (::GetTickCount64() - ulTickR >= 5 * 1000 && pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_R))
	{
		pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_R, EnemyHero);
		ulTickR = ::GetTickCount64();
		return TRUE;
	}

	return EnemyHero.Attack();
}

BOOL CHeroFight::Hero_Trundle(_In_ CONST CHero& EnemyHero) CONST
{
	if (EnemyHero.GetDis() < 3.0f && !CObjectExtend::GetInstance().ExistBuffById(HERO_BUFF_TRUNDLE_Q, nullptr) &&  pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_Q))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_Q, EnemyHero);

	if (pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_W))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_W, EnemyHero);

	if (pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_E))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_E, EnemyHero);

	if (pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_R))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_R, EnemyHero);

	return EnemyHero.Attack();
}

BOOL CHeroFight::Hero_Aatrox(_In_ CONST CHero& EnemyHero) CONST
{
	if (pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_Q))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_Q, EnemyHero);

	static ULONGLONG ulTickW = 0;
	if (::GetTickCount64() - ulTickW >= 5 * 1000 && pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_W))
	{
		pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_W, EnemyHero);
		ulTickW = ::GetTickCount64();
		return TRUE;
	}

	if (pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_E))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_E, EnemyHero);

	if (pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_R))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_R, EnemyHero);

	return EnemyHero.Attack();
}

BOOL CHeroFight::Hero_Taric(_In_ CONST CHero& EnemyHero) CONST
{
	if (CPerson::GetInstance().GetPercentHp() < 50 && pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_Q))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_Q, EnemyHero);

	if (pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_W))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_W, EnemyHero);

	if (pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_E))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_E, EnemyHero);

	if (CPerson::GetInstance().GetPercentHp() < 50 && pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_R))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_R, EnemyHero);

	return EnemyHero.Attack();
}

BOOL CHeroFight::Hero_Rumble(_In_ CONST CHero& EnemyHero) CONST
{
	if (!CObjectExtend::GetInstance().ExistBuffById(HERO_BUFF_RUMBLE_Q, nullptr))
	{
		if (pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_Q))
			return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_Q, EnemyHero);

		if (EnemyHero.GetDis() < 2.0f && !CObjectExtend::GetInstance().ExistBuffById(HERO_BUFF_RUMBLE_W, nullptr) && pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_W))
			return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_W, EnemyHero);

		if (pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_E))
			return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_E, EnemyHero);

		if (pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_R))
			return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_R, EnemyHero);
	}
	
	return EnemyHero.Attack();
}

BOOL CHeroFight::Hero_Diana(_In_ CONST CHero& EnemyHero) CONST
{
	if (pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_Q))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_Q, EnemyHero);

	if (pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_W))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_W, EnemyHero);

	if (EnemyHero.GetDis() < 2.0f && pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_E))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_E, EnemyHero);

	if (pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_R))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_R, EnemyHero);

	return EnemyHero.Attack();
}

BOOL CHeroFight::Hero_Urgot(_In_ CONST CHero& EnemyHero) CONST
{
	if (pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_Q))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_Q, EnemyHero);

	if (EnemyHero.GetDis() < 2.0f && !CObjectExtend::GetInstance().ExistBuffById(HERO_BUFF_URGOT_W, nullptr) && pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_W))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_W, EnemyHero);

	if (pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_E))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_E, EnemyHero);

	if (pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_R))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_R, EnemyHero);

	return EnemyHero.Attack();
}

BOOL CHeroFight::Hero_Teemo(_In_ CONST CHero& EnemyHero) CONST
{
	if (pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_Q))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_Q, EnemyHero);

	if (EnemyHero.GetDis() < 5.0f && !CObjectExtend::GetInstance().ExistBuffById(HERO_BUFF_TEEMO_W, nullptr) && pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_W))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_W, EnemyHero);

	static ULONGLONG ulTickR = 0;
	if (::GetTickCount64() - ulTickR >= 3 * 1000 && pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_R))
	{
		pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_R, EnemyHero);
		ulTickR = ::GetTickCount64();
		return TRUE;
	}

	return EnemyHero.Attack();
}

BOOL CHeroFight::Hero_Caitlyn(_In_ CONST CHero& EnemyHero) CONST
{
	if (pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_Q))
	{
		pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_Q, EnemyHero);
		return LOLSleep(1000);
	}

	if (pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_W))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_W, EnemyHero);

	if (pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_E))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_E, EnemyHero);

	if (pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_R))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_R, EnemyHero);

	return EnemyHero.Attack();
}

BOOL CHeroFight::Hero_Corki(_In_ CONST CHero& EnemyHero) CONST
{
	if (pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_Q))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_Q, EnemyHero);

	if (pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_W))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_W, EnemyHero);

	if (pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_E))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_E, EnemyHero);

	if (pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_R))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_R, EnemyHero);

	return EnemyHero.Attack();
}

BOOL CHeroFight::Hero_Fiora(_In_ CONST CHero& EnemyHero) CONST
{
	if (pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_Q))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_Q, EnemyHero);

	if (pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_W))
	{
		pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_W, EnemyHero);
		return LOLSleep(1000);
	}

	if (EnemyHero.GetDis() < 2.0f && !CObjectExtend::GetInstance().ExistBuffById(HERO_BUFF_FIORA_E, nullptr) && pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_E))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_E, EnemyHero);

	if (pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_R))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_R, EnemyHero);

	return EnemyHero.Attack();
}

BOOL CHeroFight::Hero_Mordekaiser(_In_ CONST CHero& EnemyHero) CONST
{
	if (EnemyHero.GetDis() < 2.0f && !CObjectExtend::GetInstance().ExistBuffById(HERO_BUFF_MORDEKAISER_Q, nullptr) && pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_Q))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_Q, EnemyHero);

	static ULONGLONG ulTickW = 0;
	CHero AlianceHero;
	if (::GetTickCount64() - ulTickW >= 5 * 1000 && CObjectExtend::GetInstance().GetLatelyHeroByCamp(CPerson::GetInstance().GetCurrentCamp(), 5.0f, &AlianceHero))
	{
		if (pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_W))
		{
			pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_W, AlianceHero);
			ulTickW = ::GetTickCount64();
			return TRUE;
		}
	}

	
	if (EnemyHero.GetDis() < 2.0f && pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_E))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_E, EnemyHero);

	if (EnemyHero.GetPercentHp() < 30 && pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_R))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_R, EnemyHero);

	return EnemyHero.Attack();
}

BOOL CHeroFight::Hero_Nautilus(_In_ CONST CHero& EnemyHero) CONST
{
	if (pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_Q))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_Q, EnemyHero);

	if (EnemyHero.GetDis() < 4.0f && !CObjectExtend::GetInstance().ExistBuffById(HERO_BUFF_NAUTILUS_W, nullptr) && pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_W))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_W, EnemyHero);

	if (pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_E))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_E, EnemyHero);

	if (pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_R))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_R, EnemyHero);

	return EnemyHero.Attack();
}

BOOL CHeroFight::Hero_Sivir(_In_ CONST CHero& EnemyHero) CONST
{
	if (pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_Q))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_Q, EnemyHero);

	if (EnemyHero.GetDis() < 6.0f && !CObjectExtend::GetInstance().ExistBuffById(HERO_BUFF_SIVIR_W, nullptr) && pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_W))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_W, EnemyHero);

	if (EnemyHero.GetDis() < 5.0f && !CObjectExtend::GetInstance().ExistBuffById(HERO_BUFF_SIVIR_E, nullptr) && pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_E))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_E, EnemyHero);

	if (EnemyHero.GetPercentHp() < 50 && pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_R))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_R, EnemyHero);

	return EnemyHero.Attack();
}

BOOL CHeroFight::Hero_KogMaw(_In_ CONST CHero& EnemyHero) CONST
{
	if (pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_Q))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_Q, EnemyHero);

	if (EnemyHero.GetDis() < 5.0f && !CObjectExtend::GetInstance().ExistBuffById(HERO_BUFF_KOGMAW_W, nullptr) && pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_W))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_W, EnemyHero);

	if (pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_E))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_E, EnemyHero);

	return EnemyHero.Attack();
}

BOOL CHeroFight::Hero_Annie(_In_ CONST CHero& EnemyHero) CONST
{
	if (pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_Q))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_Q, EnemyHero);

	if (EnemyHero.GetDis() < 2.0f && pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_W))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_W, EnemyHero);

	if (EnemyHero.GetDis() < 5.0f && !CObjectExtend::GetInstance().ExistBuffById(HERO_BUFF_ANNIE_E, nullptr) && pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_E))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_E, EnemyHero);

	if (EnemyHero.GetPercentHp() < 60 && !CObjectExtend::GetInstance().ExistBuffById(HERO_BUFF_ANNIE_R, nullptr) && pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_R))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_R, EnemyHero);

	return EnemyHero.Attack();
}

BOOL CHeroFight::Hero_Akali(_In_ CONST CHero& EnemyHero) CONST
{
	if (pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_Q))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_Q, EnemyHero);

	if (pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_W))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_W, EnemyHero);

	if (EnemyHero.GetDis() < 2.0f && pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_E))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_E, EnemyHero);

	if (pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_R))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_R, EnemyHero);

	return EnemyHero.Attack();
}

BOOL CHeroFight::Hero_Alistar(_In_ CONST CHero& EnemyHero) CONST
{
	if (EnemyHero.GetDis() < 2.0f && pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_Q))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_Q, EnemyHero);

	if (pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_W))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_W, EnemyHero);

	if (CPerson::GetInstance().GetPercentHp() < 50 && pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_E))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_E, EnemyHero);

	if (CPerson::GetInstance().GetPercentHp() < 50 && pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_R))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_R, EnemyHero);

	return EnemyHero.Attack();
}

BOOL CHeroFight::Hero_Amumu(_In_ CONST CHero& EnemyHero) CONST
{
	if (EnemyHero.GetDis() < 5.0f &&pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_Q))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_Q, EnemyHero);

	if (EnemyHero.GetDis() < 3.0f && !CObjectExtend::GetInstance().ExistBuffById(HERO_BUFF_AMUMU_W, nullptr) && pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_W))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_W, EnemyHero);
	else if (EnemyHero.GetDis() > 3.0f && CObjectExtend::GetInstance().ExistBuffById(HERO_BUFF_AMUMU_W, nullptr) && pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_W))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_W, EnemyHero);

	if (EnemyHero.GetDis() < 3.0f &&pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_E))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_E, EnemyHero);

	if (EnemyHero.GetDis() < 3.0f &&pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_R))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_R, EnemyHero);

	return EnemyHero.Attack();
}

BOOL CHeroFight::Hero_Blitzcrank(_In_ CONST CHero& EnemyHero) CONST
{
	if (pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_Q))
	{
		pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_Q, EnemyHero);
		return LOLSleep(1 * 1000);
	}

	if (EnemyHero.GetDis() < 3.0f && !CObjectExtend::GetInstance().ExistBuffById(HERO_BUFF_BLITZCRANK_W, nullptr) && pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_W))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_W, EnemyHero);

	if (EnemyHero.GetDis() < 3.0f && !CObjectExtend::GetInstance().ExistBuffById(HERO_BUFF_BLITZCRANK_E, nullptr) && pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_E))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_E, EnemyHero);

	if (EnemyHero.GetDis() < 3.0f && pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_R))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_R, EnemyHero);

	return EnemyHero.Attack();
}

BOOL CHeroFight::Hero_Brand(_In_ CONST CHero& EnemyHero) CONST
{
	if (pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_Q))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_Q, EnemyHero);

	if (pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_W))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_W, EnemyHero);

	if (pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_E))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_E, EnemyHero);

	if (CPerson::GetInstance().GetPercentHp() < 50 && pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_R))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_R, EnemyHero);

	return EnemyHero.Attack();
}

BOOL CHeroFight::Hero_Cassiopeia(_In_ CONST CHero& EnemyHero) CONST
{
	if (EnemyHero.GetDis() < 5 && pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_Q))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_Q, EnemyHero);

	if (pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_W))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_W, EnemyHero);

	if (EnemyHero.GetDis() < 5 && pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_E))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_E, EnemyHero);

	if (EnemyHero.GetPercentHp() < 50 && pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_R))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_R, EnemyHero);

	return EnemyHero.Attack();
}

BOOL CHeroFight::Hero_Darius(_In_ CONST CHero& EnemyHero) CONST
{
	if (EnemyHero.GetDis() < 2.0f && pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_Q))
	{
		pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_Q, EnemyHero);
		return LOLSleep(1000);
	}

	if (EnemyHero.GetDis() < 2.0f && !CObjectExtend::GetInstance().ExistBuffById(HERO_BUFF_DARIUS_W, nullptr) && pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_W))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_W, EnemyHero);

	if (EnemyHero.GetDis() < 4.0f && pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_E))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_E, EnemyHero);

	if (EnemyHero.GetPercentHp() < 20 && pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_R))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_R, EnemyHero);

	return EnemyHero.Attack();
}

BOOL CHeroFight::Hero_DrMundo(_In_ CONST CHero& EnemyHero) CONST
{
	if (EnemyHero.GetDis() < 5.0f && pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_Q))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_Q, EnemyHero);

	if (EnemyHero.GetDis() < 3.0f && !CObjectExtend::GetInstance().ExistBuffById(HERO_BUFF_DRMUNDO_W, nullptr))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_W, EnemyHero);

	if(EnemyHero.GetDis() > 3.0f && CObjectExtend::GetInstance().ExistBuffById(HERO_BUFF_DRMUNDO_W, nullptr))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_W, EnemyHero);

	if (EnemyHero.GetDis() < 3.0f && !CObjectExtend::GetInstance().ExistBuffById(HERO_BUFF_DRMUNDO_E, nullptr) && pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_E))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_E, EnemyHero);

	if (CPerson::GetInstance().GetPercentHp() < 70 && pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_R))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_R, EnemyHero);

	return EnemyHero.Attack();
}

BOOL CHeroFight::Hero_Ekko(_In_ CONST CHero& EnemyHero) CONST
{
	if (pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_Q))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_Q, EnemyHero);

	if (EnemyHero.GetDis() < 2.0f && pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_W))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_W, EnemyHero);

	if (EnemyHero.GetDis() < 5.0f && pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_E))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_E, EnemyHero);

	if (CPerson::GetInstance().GetPercentHp() < 50 && pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_R))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_R, EnemyHero);

	return EnemyHero.Attack();
}

BOOL CHeroFight::Hero_FiddleSticks(_In_ CONST CHero& EnemyHero) CONST
{
	if (pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_Q))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_Q, EnemyHero);

	if (pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_W))
	{
		pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_W, EnemyHero);
		while (GameRun && CObjectExtend::GetInstance().ExistBuffById(HERO_BUFF_FIDDLESTICKS_W, nullptr) && LOLSleep(500));
		return TRUE;
	}

	if (pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_E))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_E, EnemyHero);

	if (pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_R))
	{
		pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_R, EnemyHero);
		LOLSleep(1500);
		return TRUE;
	}

	return EnemyHero.Attack();
}

BOOL CHeroFight::Hero_Fizz(_In_ CONST CHero& EnemyHero) CONST
{
	if (pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_Q))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_Q, EnemyHero);

	if (!CObjectExtend::GetInstance().ExistBuffById(HERO_BUFF_FIZZ_W, nullptr) && pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_W))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_W, EnemyHero);

	if (pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_E))
	{
		pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_E, EnemyHero);
		return LOLSleep(1000);
	}

	if (EnemyHero.GetPercentHp() < 50 && pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_R))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_R, EnemyHero);

	return EnemyHero.Attack();
}

BOOL CHeroFight::Hero_Gragas(_In_ CONST CHero& EnemyHero) CONST
{
	if (pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_Q))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_Q, EnemyHero);

	if (!CObjectExtend::GetInstance().ExistBuffById(HERO_BUFF_GRAGAS_W, nullptr) && pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_W))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_W, EnemyHero);

	if (pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_E))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_E, EnemyHero);

	if (EnemyHero.GetPercentHp() < 50 && pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_R))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_R, EnemyHero);

	return EnemyHero.Attack();
}

BOOL CHeroFight::Hero_Illaoi(_In_ CONST CHero& EnemyHero) CONST
{
	if (pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_Q))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_Q, EnemyHero);

	if (EnemyHero.GetDis() < 2.0f && !CObjectExtend::GetInstance().ExistBuffById(HERO_BUFF_ILLAOI_W, nullptr) && pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_W))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_W, EnemyHero);

	if (pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_E))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_E, EnemyHero);

	if (EnemyHero.GetDis() < 2.0f && pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_R))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_R, EnemyHero);

	return EnemyHero.Attack();
}

BOOL CHeroFight::Hero_Itrlia(_In_ CONST CHero& EnemyHero) CONST
{
	if (pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_Q))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_Q, EnemyHero);

	if (EnemyHero.GetDis() < 2.0f && !CObjectExtend::GetInstance().ExistBuffById(HERO_BUFF_IRELIA_W, nullptr) && pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_W))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_W, EnemyHero);

	if (pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_E))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_E, EnemyHero);

	if (pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_R))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_R, EnemyHero);

	return EnemyHero.Attack();
}

BOOL CHeroFight::Hero_JarvanIV(_In_ CONST CHero& EnemyHero) CONST
{
	if (pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_Q))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_Q, EnemyHero);

	if (EnemyHero.GetDis() < 3.0f && !CObjectExtend::GetInstance().ExistBuffById(HERO_BUFF_JARVANIV_W, nullptr) && pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_W))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_W, EnemyHero);

	if (pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_E))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_E, EnemyHero);

	static ULONGLONG ulTickR = 0;
	if (::GetTickCount64() - ulTickR >= 4 * 1000 && pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_R))
	{
		pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_R, EnemyHero);
		ulTickR = ::GetTickCount64();
		return TRUE;
	}

	return EnemyHero.Attack();
}

BOOL CHeroFight::Hero_Jax(_In_ CONST CHero& EnemyHero) CONST
{
	if (pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_Q))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_Q, EnemyHero);

	if (EnemyHero.GetDis() < 2.0f && !CObjectExtend::GetInstance().ExistBuffById(HERO_BUFF_JAX_W, nullptr) && pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_W))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_W, EnemyHero);

	if (pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_E))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_E, EnemyHero);

	if (pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_R))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_R, EnemyHero);

	return EnemyHero.Attack();
}

BOOL CHeroFight::Hero_Jhin(_In_ CONST CHero& EnemyHero) CONST
{
	if (EnemyHero.GetDis() > 7.0f && pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_R))
	{
		pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_R, EnemyHero);
		LOLSleep(1000);
		while (GameRun && CObjectExtend::GetInstance().ExistBuffById(HERO_BUFF_JHIN_R, nullptr))
		{
			pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_R, EnemyHero);
			LOLSleep(500);
		}
	}

	if (pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_Q))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_Q, EnemyHero);

	if (pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_W))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_W, EnemyHero);

	if (pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_E))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_E, EnemyHero);

	
	return EnemyHero.Attack();
}

BOOL CHeroFight::Hero_Jinx(_In_ CONST CHero& EnemyHero) CONST
{
	if (pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_W))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_W, EnemyHero);

	if (pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_E))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_E, EnemyHero);

	if (EnemyHero.GetPercentHp() < 50 && pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_R))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_R, EnemyHero);

	return EnemyHero.Attack();
}

BOOL CHeroFight::Hero_Karma(_In_ CONST CHero& EnemyHero) CONST
{
	if (pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_Q))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_Q, EnemyHero);

	static ULONGLONG ulTickW = ::GetTickCount64();
	if (::GetTickCount64() - ulTickW >= 3 * 1000 && EnemyHero.GetDis() < 2.0f && pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_W))
	{
		pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_W, EnemyHero);
		ulTickW = ::GetTickCount64();
		return TRUE;
	}

	if (EnemyHero.GetDis() < 2.0f && !CObjectExtend::GetInstance().ExistBuffById(HERO_BUFF_KARMA_E, nullptr) && pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_E))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_E, EnemyHero);

	if (!CObjectExtend::GetInstance().ExistBuffById(HERO_BUFF_KARMA_R, nullptr) && pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_R))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_R, EnemyHero);

	return EnemyHero.Attack();
}

BOOL CHeroFight::Hero_Katarina(_In_ CONST CHero& EnemyHero) CONST
{
	if (pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_Q))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_Q, EnemyHero);

	if (pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_W))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_W, EnemyHero);

	if (pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_E))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_E, EnemyHero);

	if (pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_R))
	{
		pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_R, EnemyHero);
		LOLSleep(1000);
		while (GameRun && CObjectExtend::GetInstance().ExistBuffById(HERO_BUFF_KATARINA_R, nullptr) && LOLSleep(500));
		return TRUE;
	}

	return EnemyHero.Attack();
}

BOOL CHeroFight::Hero_Leona(_In_ CONST CHero& EnemyHero) CONST
{
	if (EnemyHero.GetDis() < 2.0f && !CObjectExtend::GetInstance().ExistBuffById(HERO_BUFF_LEONA_Q, nullptr) && pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_Q))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_Q, EnemyHero);

	if (EnemyHero.GetDis() < 3.0f && pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_W))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_W, EnemyHero);

	if (pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_E))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_E, EnemyHero);

	if (EnemyHero.GetDis() < 2.0f && pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_R))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_R, EnemyHero);

	return EnemyHero.Attack();
}

BOOL CHeroFight::Hero_Lux(_In_ CONST CHero& EnemyHero) CONST
{
	if (pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_Q))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_Q, EnemyHero);

	if (EnemyHero.GetTargetId() == CPerson::GetInstance().GetId() && pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_W))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_W, EnemyHero);

	if (pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_E))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_E, EnemyHero);

	if (pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_R))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_R, EnemyHero);

	return EnemyHero.Attack();
}

BOOL CHeroFight::Hero_Malphite(_In_ CONST CHero& EnemyHero) CONST
{
	if (pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_Q))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_Q, EnemyHero);

	if (EnemyHero.GetDis() < 2.0f && !CObjectExtend::GetInstance().ExistBuffById(HERO_BUFF_MALPHITE_W, nullptr) && pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_W))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_W, EnemyHero);

	if (EnemyHero.GetDis() < 2.0f && pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_E))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_E, EnemyHero);

	if (EnemyHero.GetPercentHp() < 50 && pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_R))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_R, EnemyHero);

	return EnemyHero.Attack();
}

BOOL CHeroFight::Hero_MonkeyKing(_In_ CONST CHero& EnemyHero) CONST
{
	if (EnemyHero.GetDis() < 3.0f && !CObjectExtend::GetInstance().ExistBuffById(HERO_BUFF_MONKEYKING_Q, nullptr) && pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_Q))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_Q, EnemyHero);

	if (EnemyHero.GetDis() < 3.0f && !CObjectExtend::GetInstance().ExistBuffById(HERO_BUFF_MONKEYKING_W, nullptr) && pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_W))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_W, EnemyHero);

	if (pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_E))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_E, EnemyHero);

	if (EnemyHero.GetDis() < 3.0f && pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_R))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_R, EnemyHero);

	return EnemyHero.Attack();
}

BOOL CHeroFight::Hero_Morgana(_In_ CONST CHero& EnemyHero) CONST
{
	if (EnemyHero.GetDis() < 5.0f && pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_Q))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_Q, EnemyHero);

	if (pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_W))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_W, EnemyHero);

	if (CPerson::GetInstance().GetPercentHp() < 50 && EnemyHero.GetTargetId() == CPerson::GetInstance().GetId() && !CObjectExtend::GetInstance().ExistBuffById(HERO_BUFF_MORGANA_E, nullptr) && pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_E))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_E, EnemyHero);

	if (EnemyHero.GetDis() < 5.0f && pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_R))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_R, EnemyHero);

	return EnemyHero.Attack();
}

BOOL CHeroFight::Hero_Nasus(_In_ CONST CHero& EnemyHero) CONST
{
	if (EnemyHero.GetDis() < 2.0f && !CObjectExtend::GetInstance().ExistBuffById(HERO_BUFF_NASUS_Q, nullptr) && pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_Q))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_Q, EnemyHero);

	if (EnemyHero.GetDis() < 4.0f && pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_W))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_W, EnemyHero);

	if (EnemyHero.GetDis() < 5.0f && pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_E))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_E, EnemyHero);

	static ULONGLONG ulTickR = 0;
	if (::GetTickCount64() - ulTickR >= 2 * 1000 && EnemyHero.GetDis() < 3.0f && pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_R))
	{
		pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_R, EnemyHero);
		ulTickR = ::GetTickCount64();
		return TRUE;
	}

	return EnemyHero.Attack();
}

BOOL CHeroFight::Hero_Olaf(_In_ CONST CHero& EnemyHero) CONST
{
	if (EnemyHero.GetDis() < 4.0f && pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_Q))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_Q, EnemyHero);

	if (EnemyHero.GetDis() < 2.0f && !CObjectExtend::GetInstance().ExistBuffById(HERO_BUFF_OLAF_W, nullptr) && pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_W))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_W, EnemyHero);

	if (EnemyHero.GetDis() < 2.0f && pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_E))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_E, EnemyHero);

	if (EnemyHero.GetPercentHp() < 50 &&  EnemyHero.GetDis() < 3.0f && !CObjectExtend::GetInstance().ExistBuffById(HERO_BUFF_OLAF_R, nullptr) && pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_R))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_R, EnemyHero);

	return EnemyHero.Attack();
}

BOOL CHeroFight::Hero_Sion(_In_ CONST CHero& EnemyHero) CONST
{
	if (EnemyHero.GetDis() < 2.0f && pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_Q))
	{
		pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_Q, EnemyHero);
		return LOLSleep(2 * 1000);
	}

	if (EnemyHero.GetDis() < 2.0f && !CObjectExtend::GetInstance().ExistBuffById(HERO_BUFF_SION_W, nullptr) && pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_W))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_W, EnemyHero);

	if (pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_E))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_E, EnemyHero);

	if (EnemyHero.GetPercentHp() < 50 && pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_R))
	{
		pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_R, EnemyHero);
		return LOLSleep(3 * 1000);
	}

	return EnemyHero.Attack();
}

BOOL CHeroFight::Hero_Poppy(_In_ CONST CHero& EnemyHero) CONST
{
	if (EnemyHero.GetDis() < 2.0f && pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_Q))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_Q, EnemyHero);

	if (EnemyHero.GetDis() < 3.0f && !CObjectExtend::GetInstance().ExistBuffById(HERO_BUFF_POPPY_W, nullptr) && pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_W))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_W, EnemyHero);

	if (pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_E))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_E, EnemyHero);

	if (EnemyHero.GetDis() < 2.0f &&pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_R))
	{
		pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_R, EnemyHero);
		return LOLSleep(1 * 1000);
	}

	return EnemyHero.Attack();
}

BOOL CHeroFight::Hero_Rammus(_In_ CONST CHero& EnemyHero) CONST
{
	static ULONGLONG ulTickQ = 0;
	if (::GetTickCount64() - ulTickQ >= 8 * 1000 && EnemyHero.GetDis() < 3.0f && pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_Q))
	{
		pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_Q, EnemyHero);
		ulTickQ = ::GetTickCount64();
		return TRUE;
	}

	if (EnemyHero.GetDis() < 3.0f && !CObjectExtend::GetInstance().ExistBuffById(HERO_BUFF_RAMMUS_W, nullptr) && pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_W))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_W, EnemyHero);

	if (pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_E))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_E, EnemyHero);

	if (EnemyHero.GetDis() < 2.0f && pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_R))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_R, EnemyHero);

	return EnemyHero.Attack();
}

BOOL CHeroFight::Hero_Renekton(_In_ CONST CHero& EnemyHero) CONST
{
	if (EnemyHero.GetDis() < 2.0f && pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_Q))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_Q, EnemyHero);

	if (EnemyHero.GetDis() < 2.0f && !CObjectExtend::GetInstance().ExistBuffById(HERO_BUFF_RENEKTON_W, nullptr) && pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_W))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_W, EnemyHero);

	if (pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_E))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_E, EnemyHero);

	if (EnemyHero.GetDis() < 3.0f && pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_R))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_R, EnemyHero);

	return EnemyHero.Attack();
}

BOOL CHeroFight::Hero_Sona(_In_ CONST CHero& EnemyHero) CONST
{
	if (CObjectExtend::GetInstance().ExistBuffById(HERO_BUFF_SONA, nullptr))
		return EnemyHero.Attack();

	if (EnemyHero.GetDis() < 3.0f  && pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_W))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_W, EnemyHero);

	if (EnemyHero.GetDis() < 3.0f  &&pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_E))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_E, EnemyHero);

	if (EnemyHero.GetDis() < 3.0f && pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_Q))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_Q, EnemyHero);

	if (EnemyHero.GetDis() < 5.0f && EnemyHero.GetPercentHp() < 50 && pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_R))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_R, EnemyHero);

	return EnemyHero.Attack();
}

BOOL CHeroFight::Hero_Velkoz(_In_ CONST CHero& EnemyHero) CONST
{
	static ULONGLONG ulTickQ = 0;
	if (::GetTickCount64() - ulTickQ >= 5 * 1000 && pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_Q))
	{
		pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_Q, EnemyHero);
		ulTickQ = ::GetTickCount64();
		return TRUE;
	}

	if (EnemyHero.GetDis() < 5.0f && pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_W))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_W, EnemyHero);

	if (EnemyHero.GetDis() < 3.0f && pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_E))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_E, EnemyHero);

	if (EnemyHero.GetDis() < 5.0f && EnemyHero.GetPercentHp() < 50 && pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_R))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_R, EnemyHero);

	return EnemyHero.Attack();
}

BOOL CHeroFight::Hero_XinZhao(_In_ CONST CHero& EnemyHero) CONST
{
	if (EnemyHero.GetDis() < 2.0f && !CObjectExtend::GetInstance().ExistBuffById(HERO_BUFF_XINZHAO_Q, nullptr) && pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_Q))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_Q, EnemyHero);

	if (EnemyHero.GetDis() < 2.0f && !CObjectExtend::GetInstance().ExistBuffById(HERO_BUFF_XINZHAO_W, nullptr) && pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_W))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_W, EnemyHero);

	if (pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_E))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_E, EnemyHero);

	if (pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_R))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_R, EnemyHero);

	return EnemyHero.Attack();
}

BOOL CHeroFight::Hero_Ziggs(_In_ CONST CHero& EnemyHero) CONST
{
	if (pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_Q))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_Q, EnemyHero);

	if (EnemyHero.GetDis() < 2.0f && pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_W))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_W, EnemyHero);

	if (EnemyHero.GetDis() < 3.0f &&pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_E))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_E, EnemyHero);

	if (EnemyHero.GetPercentHp() < 30 && pSkillServices->IsSkillCooldown(em_Skill_Index::em_Skill_Index_R))
		return pSkillServices->UseSkill(em_Skill_Index::em_Skill_Index_R, EnemyHero);

	return EnemyHero.Attack();
}

