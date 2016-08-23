#include "stdafx.h"
#include "Hero.h"

CHero::CHero(_In_ DWORD dwNodeBase_) : CHumanBaseObject(dwNodeBase_)
{

}
CHero::CHero() : CHumanBaseObject(NULL)
{
}

CHero::~CHero()
{
}

cwstring& CHero::GetName() CONST
{
	return wsName;
}

BOOL CHero::IsShowInFog() CONST
{
	return TRUE;
}

