#include "stdafx.h"
#include "EqumentServices.h"
#include <MyTools/CLLog.h>
#include "GameRes.h"
#include "Person.h"
#include "GameCALL.h"

#define _SELF L"EqumentServices.cpp"
CEqumentServices::CEqumentServices() : dwLastEqumentId(NULL)
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
		auto pResEqument = CGameRes::GetInstance().GetNextEqumentId(CPerson::GetInstance().GetHeroPro(), dwLastEqumentId);
		if (pResEqument == nullptr)
			break;

		if (CPerson::GetInstance().GetMoney() < pResEqument->dwPrice)
			break;

		dwLastEqumentId = pResEqument->dwEqumentId;
		auto bResult = FALSE;
		CGameVariable::GetInstance().PushMainThreadActionPtr([&pResEqument, &bResult] {
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
	DWORD dwMoney = CPerson::GetInstance().GetMoney();
	DWORD dwCount = dwMoney / EQUMENT_PRICE_∫Ï“©;
	for (DWORD i = 0;i < dwCount; ++i)
	{
		CGameVariable::GetInstance().PushMainThreadActionPtr([] {
			CGameCALL::GetInstance().PurchaseItemByShore(EQUMENT_ID_∫Ï“©);
		});
	}
	return TRUE;
}
