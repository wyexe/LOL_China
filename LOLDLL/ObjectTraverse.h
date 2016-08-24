#ifndef __LOL_CHINA_LOLDLL_GAME_OBJECTSERVICES_OBJECTTRAVERSE_H__
#define __LOL_CHINA_LOLDLL_GAME_OBJECTSERVICES_OBJECTTRAVERSE_H__

#include "GameVariable.h"
#include <MyTools/CLPublic.h>

class CHeroBuff;
class CEqument;
class CSkill;
class CReep;
class CObjectTraverse
{
public:
	CObjectTraverse();
	~CObjectTraverse();

	// 获取当前英雄的Buff
	UINT GetCurrentHeroBuffList(_Out_ vector<CHeroBuff>& vlst) CONST;

	enum em_Human_Type
	{
		em_Human_Type_Solider,
		em_Human_Type_Turret,
		em_Human_Type_Hero,
	};

	// 人物类的Object遍历
	template<class T>
	UINT GetHumanTypeListByType(_In_ em_Human_Type emHumanType, _In_ em_Camp emCamp, vector<T>& vlst) CONST
	{
		vlst.clear();
		return 0;
	}

	template<class T>
	UINT GetAroundHumanTypeCount(_In_ em_Human_Type emHumanType, _In_ em_Camp emCamp, _In_ float fDis) CONST
	{
		vector<T> vlst;
		GetHumanTypeListByType(emHumanType, emCamp, vlst);
		return CLPublic::Vec_erase_if(vlst, [&fDis](CONST T& itm) {
			return itm.GetDis() > fDis;
		});
	}

	// 遍历当前英雄的装备
	UINT GetCurrentHeroEqumentList(_Out_ vector<CEqument>& vlst) CONST;

	// 初始化技能列表
	BOOL GetSkillList(_Out_ vector<CSkill>& vlst) CONST;

	// 野怪遍历
	BOOL GetCreepList(_Out_ vector<CReep>& vlst) CONST;

	virtual void AbstractClass() = NULL;
private:
	DSIABLE_COPY_AND_ASSIGN(CObjectTraverse);
};



#endif