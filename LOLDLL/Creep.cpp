#include "stdafx.h"
#include "Creep.h"

CReep::CReep(_In_ DWORD dwNodeBase_) : CBaseObject(dwNodeBase_)
{

}
CReep::CReep() : CBaseObject(NULL)
{
}

CReep::~CReep()
{
}

cwstring& CReep::GetName() CONST
{
	return wsName;
}

DWORD CReep::GetId() CONST
{
	return 0;
}

BOOL CReep::IsRefresh() CONST
{
	return TRUE;
}
