#ifndef __LOL_CHINA_LOLDLL_GAME_INIT_GAMEINIT_H__
#define __LOL_CHINA_LOLDLL_GAME_INIT_GAMEINIT_H__

#include "GameVariable.h"

class CGameInit
{
public:
	CGameInit();
	~CGameInit();

	static CGameInit& GetInstance();

	BOOL InitTimer() CONST;
private:
	DSIABLE_COPY_AND_ASSIGN(CGameInit);
};



#endif
