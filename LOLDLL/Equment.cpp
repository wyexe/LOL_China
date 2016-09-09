#include "stdafx.h"
#include "Equment.h"

CEqument::CEqument() : CBaseObject(NULL)
{
	
}

CEqument::CEqument(_In_ DWORD dwNodeBase_) : CBaseObject(dwNodeBase_)
{

}


UINT CEqument::GetCount() CONST throw()
{
	return ReadDWORD(GetNodeBase() + 0x4);
}

DWORD CEqument::GetId() CONST throw()
{
	return ReadDWORD(((GetNodeBase()) + 0xC) + ×°±¸IDÆ«ÒÆ);
}
