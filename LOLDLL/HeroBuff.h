#ifndef __LOL_CHINA_LOLDLL_GAME_OBJECT_OTHER_HEROBUFF_H__
#define __LOL_CHINA_LOLDLL_GAME_OBJECT_OTHER_HEROBUFF_H__

#include "BaseObject.h"

class CHeroBuff : public CBaseObject
{
public:
	CHeroBuff();
	CHeroBuff(_In_ DWORD dwNodeBase_);
	~CHeroBuff();

	// Buff Id
	DWORD GetId() CONST;

	// Count
	DWORD GetCount() CONST;

	// Name
	virtual cwstring& GetName() CONST;
private:

};



#endif