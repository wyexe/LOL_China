#include "stdafx.h"
#include "ObjectTraverse.h"

CObjectTraverse::CObjectTraverse()
{
}

CObjectTraverse::~CObjectTraverse()
{
}

UINT CObjectTraverse::GetCurrentHeroBuffList(_Out_ vector<CHeroBuff>& vlst) CONST
{
	return 0;
}

UINT CObjectTraverse::GetCurrentHeroEqumentList(_Out_ vector<CEqument>& vlst) CONST
{
	return 0;
}

BOOL CObjectTraverse::InitSkill(_Out_ vector<CSkill>& vlst) CONST
{
	return 0;
}

BOOL CObjectTraverse::GetCreepList(_Out_ vector<CReep>& vlst) CONST
{
	return 0;
}
