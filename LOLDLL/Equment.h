#ifndef __LOL_CHINA_LOLDLL_GAME_OBJECT_OTHER_EQUMENT_H__
#define __LOL_CHINA_LOLDLL_GAME_OBJECT_OTHER_EQUMENT_H__

#include "BaseObject.h"

class CEqument : public CBaseObject
{
public:
	CEqument();
	CEqument(_In_ DWORD dwNodeBase_);
	~CEqument() = default;

	// ÊýÁ¿
	UINT  GetCount() CONST throw();

	// ID
	DWORD GetId() CONST throw();
};



#endif