#include "stdafx.h"
#include "Person.h"

CPerson::CPerson(_In_ DWORD dwNodeBase_) : CHero(dwNodeBase_)
{
}

CPerson::~CPerson()
{
}

CPerson& CPerson::GetInstance()
{
	static CPerson Person_(0);
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
