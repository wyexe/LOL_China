#include "stdafx.h"
#include "Solider.h"

CSolider::CSolider(_In_ DWORD dwNodeBase_) : CHumanBaseObject(dwNodeBase_)
{

}

CSolider::CSolider() : CHumanBaseObject(NULL)
{
}

CSolider::~CSolider()
{
}

cwstring& CSolider::GetName() CONST
{
	return wsName;
}

BOOL CSolider::IsShowInFog() CONST
{
	return TRUE;
}
