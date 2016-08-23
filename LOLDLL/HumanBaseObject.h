#ifndef __LOL_CHINA_LOLDLL_GAME_OBJECT_HUMANTYPE_HUMANBASEOBJECT_H__
#define __LOL_CHINA_LOLDLL_GAME_OBJECT_HUMANTYPE_HUMANBASEOBJECT_H__

#include "BaseObject.h"

class CHumanBaseObject : public CBaseObject
{
public:
	CHumanBaseObject();
	CHumanBaseObject(_In_ DWORD dwNodeBase_);
	~CHumanBaseObject();

	// ID
	DWORD GetId() CONST;

	// HP
	DWORD GetHp() CONST;
	DWORD GetMaxHp() CONST;
	DWORD GetPercentHp() CONST;

	// MP
	DWORD GetMp() CONST;
	DWORD GetMaxMp() CONST;
	DWORD GetPercentMp() CONST;

	// 坐标
	Point GetPoint() CONST;

	// 获取距离
	float GetDis(CONST Point& TarPoint) CONST;
	float GetDis() CONST;

	// 当前的阵营
	em_Camp GetCurrentCamp() CONST;

	// 目标ID
	DWORD GetTargetId() CONST;

	// 是否显示(否表示在迷雾中)
	virtual BOOL IsShowInFog() CONST;

	// 普通攻击!
	BOOL Attack() CONST;

	// 重载< 用来排序的
	bool operator < (CONST CHumanBaseObject& itm) CONST;

	// 是否挂了
	BOOL IsDead() CONST;
private:
	float fDis;
};



#endif