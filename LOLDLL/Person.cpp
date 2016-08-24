#include "stdafx.h"
#include "Person.h"
#include "GameCALL.h"

CPerson::CPerson(_In_ DWORD dwNodeBase_) : CHero(dwNodeBase_)
{
}

CPerson::~CPerson()
{
}

CPerson& CPerson::GetInstance()
{
	static CPerson Person_(0);
	Person_.SetPersonBase(0);
	return Person_;
}

BOOL CPerson::SetPersonBase(_In_ DWORD dwNodeBase_)
{
	dwNodeBase = dwNodeBase_;
	return TRUE;
}

em_Camp CPerson::GetEnemyCamp() CONST
{
	return em_Camp_Blue;
}

DWORD CPerson::GetLevel() CONST
{
	return 0;
}

DWORD CPerson::GetObject() CONST
{
	return 0;
}

DWORD CPerson::GetSp() CONST
{
	return 0;
}

float CPerson::GetNormalAttackDis() CONST
{
	return 0;
}

em_Hero_Pro CPerson::GetHeroPro() CONST
{
	return em_Hero_Pro::em_Hero_Pro_Aatrox;
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
