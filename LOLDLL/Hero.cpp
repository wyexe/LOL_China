#include "stdafx.h"
#include "Hero.h"
#include <MyTools/CLLog.h>
#define _SELF L"Hero.cpp"

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
	if (wsName.empty())
		CCharacter::ReadUTF8Text(GetNodeBase() + Ó¢ÐÛÃû³ÆÆ«ÒÆ, wsName);
	return wsName;
}

DWORD CHero::GetLevel() CONST
{
	__try
	{
		DWORD dwLevel = 0;
		DWORD dwECX = GetNodeBase();
		__asm
		{
			PUSHAD;
			MOV ECX, dwECX;
			MOV EDX, DWORD PTR DS : [ECX];
			MOV EDX, DWORD PTR DS : [EDX + Ó¢ÐÛµÈ¼¶Ðéº¯ÊýÆ«ÒÆ];
			CALL EDX;
			MOV dwLevel, EAX
			POPAD;
		}
		return dwLevel;
	}
	__except(1)
	{
		Log(LOG_LEVEL_EXCEPTION, L"GetLevelÒì³£!");
	}
	return 0;
}