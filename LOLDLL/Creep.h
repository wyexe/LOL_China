#ifndef __LOL_CHINA_LOLDLL_GAME_OBJECT_OTHER_CREEP_H__
#define __LOL_CHINA_LOLDLL_GAME_OBJECT_OTHER_CREEP_H__

#include "BaseObject.h"

class CReep : public CBaseObject
{
public:
	CReep();
	CReep(_In_ DWORD dwNodeBase_);
	~CReep();

	// 野怪名字
	virtual cwstring& GetName() CONST;

	// 野怪ID
	DWORD GetId() CONST;

	// 是否刷新了!
	BOOL IsRefresh() CONST;

};



#endif