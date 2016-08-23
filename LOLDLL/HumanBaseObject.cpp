#include "stdafx.h"
#include "HumanBaseObject.h"

CHumanBaseObject::CHumanBaseObject() : CBaseObject(NULL), fDis(0)
{

}
CHumanBaseObject::CHumanBaseObject(_In_ DWORD dwNodeBase_) : CBaseObject(dwNodeBase_), fDis(0)
{

}

CHumanBaseObject::~CHumanBaseObject()
{
}

DWORD CHumanBaseObject::GetId() CONST
{
	return 0;
}

DWORD CHumanBaseObject::GetHp() CONST
{
	return 0;
}

DWORD CHumanBaseObject::GetMaxHp() CONST
{
	return 0;
}

DWORD CHumanBaseObject::GetPercentHp() CONST
{
	return 0;
}

DWORD CHumanBaseObject::GetMp() CONST
{
	return 0;
}

DWORD CHumanBaseObject::GetMaxMp() CONST
{
	return 0;
}

DWORD CHumanBaseObject::GetPercentMp() CONST
{
	return 0;
}

Point CHumanBaseObject::GetPoint() CONST
{
	return Point();
}

float CHumanBaseObject::GetDis(CONST Point& TarPoint) CONST
{
	return 0;
}

float CHumanBaseObject::GetDis() CONST
{
	return 0;
}

DWORD CHumanBaseObject::GetTargetId() CONST
{
	return 0;
}

BOOL CHumanBaseObject::IsShowInFog() CONST
{
	return TRUE;
}

BOOL CHumanBaseObject::Attack() CONST
{
	return TRUE;
}

BOOL CHumanBaseObject::IsDead() CONST
{
	return TRUE;
}

bool CHumanBaseObject::operator<(CONST CHumanBaseObject& itm) CONST
{
	return fDis < itm.fDis;
}

