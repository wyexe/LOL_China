#ifndef __LOL_CHINA_LOLDLL_GAME_SCAN_SCANBASE_H__
#define __LOL_CHINA_LOLDLL_GAME_SCAN_SCANBASE_H__

#include "GameVariable.h"

class CScanBase
{
public:
	CScanBase();
	~CScanBase();

	static CScanBase& GetInstance();

	BOOL Begin() CONST;
private:

};

#endif