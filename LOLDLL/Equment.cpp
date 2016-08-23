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
	return 0;
}

DWORD CEqument::GetObject() CONST throw()
{
	return 0;
}

DWORD CEqument::GetId() CONST throw()
{
	return 0;
}
