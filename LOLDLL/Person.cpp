#include "stdafx.h"
#include "Person.h"
#include <MyTools/CLLog.h>
#include "GameCALL.h"
#include "GameRes.h"
#define _SELF L"Person.cpp"

CPerson::CPerson(_In_ DWORD dwNodeBase_) : CHero(dwNodeBase_)
{
}

CPerson::~CPerson()
{
}

CPerson& CPerson::GetInstance()
{
	static CPerson Person_(ReadDWORD(人物基址));
	Person_.SetPersonBase(ReadDWORD(人物基址));
	return Person_;
}

BOOL CPerson::SetPersonBase(_In_ DWORD dwNodeBase_)
{
	dwNodeBase = dwNodeBase_;
	return TRUE;
}

em_Camp CPerson::GetEnemyCamp() CONST
{
	return GetCurrentCamp() == em_Camp::em_Camp_Blue ? em_Camp::em_Camp_Red : em_Camp::em_Camp_Blue;
}

DWORD CPerson::GetSp() CONST
{
	__try
	{
		DWORD dwECX = GetNodeBase();
		DWORD dwSp = 0;
		__asm
		{
			PUSHAD;
			MOV ECX, dwECX;
			MOV EAX, DWORD PTR DS : [ECX];
			MOV EAX, DWORD PTR DS : [EAX + 人物技能点虚函数偏移];
			CALL EAX;
			CMP EAX, 0;
			JE lb_Exit;
			MOV EAX, DWORD PTR DS : [EAX + 人物技能点偏移];
			MOV dwSp, EAX;
		lb_Exit:;
			POPAD;
		}
		return dwSp;
	}
	__except (1)
	{
		Log(LOG_LEVEL_EXCEPTION, L"GetSp异常!");
	}
	return 0;
}

DWORD CPerson::GetMoney() CONST
{
	return static_cast<DWORD>(ReadFloat(GetNodeBase() + 金钱偏移));
}

float CPerson::GetNormalAttackDis() CONST
{
	switch (GetHeroPro())
	{
	case em_Hero_Pro_None:
		break;
	// 远程
	case em_Hero_Pro_Ryze: case em_Hero_Pro_Ashe: case em_Hero_Pro_MissFortune: case em_Hero_Pro_Malzahar: case em_Hero_Pro_Ezreal: case em_Hero_Pro_Graves: case em_Hero_Pro_Swain:
	case em_Hero_Pro_Vayne: case em_Hero_Pro_Veigar: case em_Hero_Pro_Tristana: case em_Hero_Pro_Lucian: case em_Hero_Pro_Aatrox: case em_Hero_Pro_Urgot: case em_Hero_Pro_Teemo:
	case em_Hero_Pro_Caitlyn: case em_Hero_Pro_Corki: case em_Hero_Pro_Sivir: case em_Hero_Pro_KogMaw: case em_Hero_Pro_Brand: case em_Hero_Pro_Cassiopeia: case em_Hero_Pro_FiddleSticks:
	case em_Hero_Pro_Jhin: case em_Hero_Pro_Jinx: case em_Hero_Pro_Karma: case em_Hero_Pro_Lux: case em_Hero_Pro_Morgana: case em_Hero_Pro_Velkoz: case em_Hero_Pro_Ziggs:
		return 7.0f;
	// 近战
	case em_Hero_Pro_MasterYi: case em_Hero_Pro_Garen: case em_Hero_Pro_Chogath: case em_Hero_Pro_Nunu: case em_Hero_Pro_Maokai: case em_Hero_Pro_Sejuani: 	case em_Hero_Pro_Galio:
	case em_Hero_Pro_Trundle: case em_Hero_Pro_Taric: case em_Hero_Pro_Rumble: case em_Hero_Pro_Diana: case em_Hero_Pro_Fiora: case em_Hero_Pro_Mordekaiser: case em_Hero_Pro_Nautilus:
	case em_Hero_Pro_Akali: case em_Hero_Pro_Alistar: case em_Hero_Pro_Amumu: case em_Hero_Pro_Blitzcrank: case em_Hero_Pro_Darius: case em_Hero_Pro_DrMundo: case em_Hero_Pro_Ekko:
	case em_Hero_Pro_Fizz: case em_Hero_Pro_Gragas: case em_Hero_Pro_Illaoi: case em_Hero_Pro_Itrlia: case em_Hero_Pro_JarvanIV: case em_Hero_Pro_Jax: case em_Hero_Pro_Katarina:
	case em_Hero_Pro_Leona: case em_Hero_Pro_Malphite: case em_Hero_Pro_MonkeyKing: case em_Hero_Pro_Olaf:case em_Hero_Pro_Nasus: case em_Hero_Pro_Sion: case em_Hero_Pro_Poppy:
	case em_Hero_Pro_Rammus: case em_Hero_Pro_Renekton: case em_Hero_Pro_XinZhao:
		return 2.0f;
	case em_Hero_Pro_Heimerdinger: case em_Hero_Pro_Annie: case em_Hero_Pro_Sona:
		return 5.5f;
	default:
		break;
	}
	LogMsgBox(LOG_LEVEL_EXCEPTION, L"这个英雄还没加到攻击范围:%X", GetHeroPro());
	return 0.0f;
}

em_Hero_Pro CPerson::GetHeroPro() CONST
{
	static em_Hero_Pro emHeroPro = em_Hero_Pro::em_Hero_Pro_None;
	if (emHeroPro == em_Hero_Pro::em_Hero_Pro_None)
	{
		auto pResSkill = CGameRes::GetInstance().GetResSkillByHero(GetName());
		if (pResSkill == nullptr)
		{
			LogMsgBox(LOG_LEVEL_EXCEPTION, L"pResSkill = nullptr!, Name=%s", GetName().c_str());
			return emHeroPro;
		}
		emHeroPro = pResSkill->emHeroPro;
	}
	return emHeroPro;
}

em_Path_Type& CPerson::GetHeroPath() CONST
{
	static em_Path_Type emPathType;
	return emPathType;
}

BOOL CPerson::Move(CONST Point& TarPoint) CONST
{
	return CGameVariable::GetInstance().PushMainThreadActionPtr([&TarPoint] {
		CGameCALL::GetInstance().PlayerMove(TarPoint);
	});
}

BOOL CPerson::MoveToPoint(_In_ CONST Point& TarPoint, _In_ float fDis) CONST
{
	auto nCount = 0;
	while (GameRun && !IsDead() && GetDis(TarPoint) > fDis)
	{
		if (nCount++ % 5 == 0)
			Move(TarPoint);

		LOLSleep(CCharacter::GetRand(100, 50));
	}

	return StopAction();
}

BOOL CPerson::StopAction() CONST
{
	return CGameVariable::GetInstance().PushMainThreadActionPtr([] {
		CGameCALL::GetInstance().StopAction();
	});
}

BOOL CPerson::LockView() CONST
{
	return CGameVariable::GetInstance().PushMainThreadActionPtr([] { CGameCALL::GetInstance().LockView(); });
}
