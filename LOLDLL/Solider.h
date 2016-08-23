#ifndef __LOL_CHINA_LOLDLL_GAME_OBJECT_HUMANTYPE_SOLIDER_H__
#define __LOL_CHINA_LOLDLL_GAME_OBJECT_HUMANTYPE_SOLIDER_H__

#include "HumanBaseObject.h"

class CSolider : public CHumanBaseObject
{
public:
	CSolider();
	CSolider(_In_ DWORD dwNodeBase_);
	~CSolider();

	// Ð¡±øÃû³Æ
	virtual cwstring& GetName() CONST;

	// ÃÔÎí
	virtual BOOL IsShowInFog() CONST;

private:

};



#endif