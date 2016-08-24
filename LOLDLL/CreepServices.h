#ifndef __LOL_CHINA_LOLDLL_GAME_OBJECTSERVICES_CREEPSERVICES_H__
#define __LOL_CHINA_LOLDLL_GAME_OBJECTSERVICES_CREEPSERVICES_H__

#include "GameVariable.h"

class CCreepServices
{
public:
	CCreepServices();
	~CCreepServices();

	static CCreepServices& GetInstance();

	// 是否可以刷蓝BUFF了
	BOOL IsRefreshBlueBuff() CONST;

	// 是否可以刷红BUFF了
	BOOL IsRefreshRedBuff() CONST;

	// 是否刷小龙了
	BOOL IsRefreshDragonBuff() CONST;
	
	enum em_Creep_Buff_Type
	{
		em_Creep_Buff_Type_Blue,
		em_Creep_Buff_Type_Red,
		em_Creep_Buff_Type_Dragon
	};
	// 重新设置刷新BUFF的时间
	BOOL SetRefreshBuffTick(_In_ em_Creep_Buff_Type emType);

private:
	ULONGLONG ulBlueBuffTick;
	ULONGLONG ulRedBuffTick;
	ULONGLONG ulDragonTick;
private:
	DSIABLE_COPY_AND_ASSIGN(CCreepServices);
};



#endif