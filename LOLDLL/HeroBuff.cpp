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
	return ReadDWORD(GetNodeBase() + 0x1C);
}

DWORD CHeroBuff::GetCount() CONST
{
	return ReadDWORD(GetNodeBase() + 0x28);
}

cwstring& CHeroBuff::GetName() CONST
{
	if (wsName.empty())
		CCharacter::ReadUTF8Text(GetNodeBase() + 0xC, wsName);
	return wsName;
}
