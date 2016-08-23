#ifndef __LOL_CHINA_LOLDLL_GAME_OBJECT_OTHER_BASEOBJECT_H__
#define __LOL_CHINA_LOLDLL_GAME_OBJECT_OTHER_BASEOBJECT_H__

#include "GameVariable.h"

class CBaseObject
{
public:
	CBaseObject(_In_ DWORD dwNodeBase_);
	~CBaseObject();

	// ½ÚµãBase
	DWORD GetNodeBase() CONST;

	// Name
	virtual cwstring& GetName() CONST;
protected:
	DWORD dwNodeBase;
	mutable wstring wsName;
};



#endif