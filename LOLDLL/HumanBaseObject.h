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
	virtual DWORD GetHp() CONST;
	virtual DWORD GetMaxHp() CONST;
	virtual DWORD GetPercentHp() CONST;

	// MP
	virtual DWORD GetMp() CONST;
	virtual DWORD GetMaxMp() CONST;
	virtual DWORD GetPercentMp() CONST;

	// 坐标
	Point GetPoint() CONST;

	// 获取距离
	float GetDis(_In_ CONST Point& TarPoint) CONST;
	float GetDis() CONST;
	float SetDis(_In_ CONST Point& TarPoint);

	// 当前的阵营
	em_Camp GetCurrentCamp() CONST;

	// 获取类型
	em_Human_Type GetHumanType() CONST;

	// 是否显示(否表示在迷雾中)
	virtual BOOL IsShowInFog() CONST;

	// 普通攻击!
	BOOL Attack() CONST;

	// 重载< 用来排序的
	bool operator < (CONST CHumanBaseObject& itm) CONST;

	// 是否挂了
	BOOL IsDead() CONST;

	// 获取技能释放参数
	DWORD GetSkillParameter() CONST;

	// 目标
	DWORD GetTargetId() CONST;

private:
	float fDis;
};



#endif