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

BOOL CTurret::IsCrystalTurret() CONST
{
	return TRUE;
}
