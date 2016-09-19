#include "stdafx.h"
#include "EqumentServices.h"
#include <MyTools/CLLog.h>
#include "GameRes.h"
#include "Person.h"
#include "GameCALL.h"
#include "ObjectExtend.h"
#include "Equment.h"
#include "SkillServices.h"
#define _SELF L"EqumentServices.cpp"
CEqumentServices::CEqumentServices()
{
}

CEqumentServices::~CEqumentServices()
{
}

CEqumentServices& CEqumentServices::GetInstance()
{
	static CEqumentServices EqumentServices;
	return EqumentServices;
}

BOOL CEqumentServices::BuyEqument()
{
	while (GameRun)
	{
		vector<CEqument> vlst;
		CObjectExtend::GetInstance().GetCurrentHeroEqumentList(vlst);
		DWORD dwLastEqumentId = CGameRes::GetInstance().GetCurrentLastEqumentId(CPerson::GetInstance().GetHeroPro(), vlst);
		Log(LOG_LEVEL_NORMAL, L"Last EqumentId = %X", dwLastEqumentId);
		auto pResEqument = CGameRes::GetInstance().GetNextEqumentId(CPerson::GetInstance().GetHeroPro(), dwLastEqumentId);
		if (pResEqument == nullptr)
			break;

		if (CPerson::GetInstance().GetMoney() < pResEqument->dwPrice)
			break;

		dwLastEqumentId = pResEqument->dwEqumentId;
		auto bResult = FALSE;
		CGameVariable::GetInstance().PushMainThreadActionPtr([&pResEqument, &bResult] {
			Log(LOG_LEVEL_NORMAL, L"BuyItem:%X", pResEqument->dwEqumentId);
			bResult = CGameCALL::GetInstance().PurchaseItemByShore(pResEqument->dwEqumentId);
		});

		// BuyEqument Succ? set last equment id = current buy euqment id
		dwLastEqumentId = bResult ? pResEqument->dwEqumentId : dwLastEqumentId;
		LOLSleep(300);
	}
	
	return TRUE;
}

BOOL CEqumentServices::BuyMedicine() CONST
{
	if (CPerson::GetInstance().GetLevel() > 1)
		return TRUE;

	DWORD dwMoney = CPerson::GetInstance().GetMoney();
	DWORD dwCount = dwMoney / EQUMENT_PRICE_∫Ï“©;
	Log(LOG_LEVEL_NORMAL, L"Buy Medicine Count:%d", dwCount);
	for (DWORD i = 0;i < dwCount; ++i)
	{
		CGameVariable::GetInstance().PushMainThreadActionPtr([] {
			CGameCALL::GetInstance().PurchaseItemByShore(EQUMENT_ID_∫Ï“©);
		});
	}
	return TRUE;
}

BOOL CEqumentServices::CheckMedicine() CONST
{
	static ULONGLONG ulTick = NULL;
	if (GameRun && !CPerson::GetInstance().IsDead() && CPerson::GetInstance().GetPercentHp() <= 70 && CObjectExtend::GetInstance().ExistEqumentById(EQUMENT_ID_∫Ï“©, nullptr) && ::GetTickCount64() - ulTick >= 15 * 1000)
	{
		Log(LOG_LEVEL_NORMAL, L"Eat Medicine!");
		CSkillServices::GetInstance().UseBuffSkill(SKILLNAME_REGENERATIONPOTION);
		ulTick = ::GetTickCount64();
		return TRUE;
	}
	return FALSE;
}
