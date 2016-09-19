#ifndef __LOL_CHINA_LOLDLL_GAME_OBJECTSERVICES_EQUMENTSERVICES_H__
#define __LOL_CHINA_LOLDLL_GAME_OBJECTSERVICES_EQUMENTSERVICES_H__

#include "ObjectExtend.h"

class CEqumentServices
{
public:
	CEqumentServices();
	~CEqumentServices();

	static CEqumentServices& GetInstance();

	// 买下一件装备
	BOOL BuyEqument();

	// 初始化购物, 买药!
	BOOL BuyMedicine() CONST;

	// Eat Medicine!
	BOOL CheckMedicine() CONST;
private:
	DSIABLE_COPY_AND_ASSIGN(CEqumentServices);
};



#endif