#include "stdafx.h"
#include "Turret.h"

CTurret::CTurret(_In_ DWORD dwNodeBase_) : CHumanBaseObject(dwNodeBase_)
{

}
CTurret::CTurret() : CHumanBaseObject(NULL)
{
}

CTurret::~CTurret()
{
}

cwstring& CTurret::GetName() CONST
{
	return wsName;
}

BOOL CTurret::IsCrystalTurret() CONST
{
	return TRUE;
}
