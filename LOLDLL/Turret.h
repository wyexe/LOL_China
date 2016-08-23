#ifndef __LOL_CHINA_LOLDLL_GAME_OBJECT_HUMANTYPE_TURRET_H__
#define __LOL_CHINA_LOLDLL_GAME_OBJECT_HUMANTYPE_TURRET_H__

#include "HumanBaseObject.h"

class CTurret : public CHumanBaseObject
{
public:
	CTurret();
	CTurret(_In_ DWORD dwNodeBase_);
	~CTurret();

	// ÅÚËþÃû×Ö
	virtual cwstring& GetName() CONST;

	// ÊÇ·ñË®¾§Ëþ
	BOOL IsCrystalTurret() CONST;
private:

};



#endif