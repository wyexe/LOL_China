#ifndef __LOL_CHINA_LOLDLL_GAME_OBJECT_HUMANTYPE_PERSON_H__
#define __LOL_CHINA_LOLDLL_GAME_OBJECT_HUMANTYPE_PERSON_H__

#include "Hero.h"

class CPerson : public CHero
{
public:
	CPerson(_In_ DWORD dwNodeBase_);
	~CPerson();

	CPerson& GetInstance();

	BOOL SetPersonBase(_In_ DWORD dwNodeBase_);

	// 人物等级
	DWORD GetLevel() CONST;

	// 获取当前英雄的敌对阵营
	em_Camp GetEnemyCamp() CONST;

	// 英雄Object
	DWORD GetObject() CONST;

	// 获取技能点
	DWORD GetSp() CONST;

	// 金币
	DWORD GetMoney() CONST;

	// 获取普通攻击距离
	float GetNormalAttackDis() CONST;
private:
	DSIABLE_COPY_AND_ASSIGN(CPerson);
};



#endif
