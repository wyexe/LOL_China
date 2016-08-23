#include "stdafx.h"
#include "HeroBuff.h"

CHeroBuff::CHeroBuff() : CBaseObject(NULL)
{
}

CHeroBuff::CHeroBuff(_In_ DWORD dwNodeBase_) : CBaseObject(dwNodeBase_)
{

}

CHeroBuff::~CHeroBuff()
{
}

DWORD CHeroBuff::GetId() CONST
{
	return 0;
}

DWORD CHeroBuff::GetCount() CONST
{
	return 0;
}

cwstring& CHeroBuff::GetName() CONST
{
	return wsName;
}
