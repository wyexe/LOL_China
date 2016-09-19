#ifndef __LOL_CHINA_LOLDLL_GAME_OBJECTSERVICES_OBJECTTRAVERSE_H__
#define __LOL_CHINA_LOLDLL_GAME_OBJECTSERVICES_OBJECTTRAVERSE_H__

#include "GameVariable.h"
#include <MyTools/CLPublic.h>

class CHeroBuff;
class CEqument;
class CSkill;
class CSolider;
class CTurret;
class CObjectTraverse
{
public:
	CObjectTraverse();
	~CObjectTraverse();

	// 获取当前英雄的Buff
	UINT GetCurrentHeroBuffList(_Out_ vector<CHeroBuff>& vlst) CONST;

	
	// 人物类的Object遍历
	template<class T>
	UINT GetHumanTypeListByType(_In_ em_Human_Type emHumanType, _In_ em_Camp emCamp, _In_ vector<T>& vlst) CONST
	{
		vlst.clear();
		DWORD dwArrayHead = ReadDWORD(环境基址 + 0x0);
		UINT uCount = (ReadDWORD(环境基址 + 0x4) - dwArrayHead) >> 0x2;
		for (UINT i = 0;i < uCount; ++i)
		{
			DWORD dwObj = ReadDWORD(dwArrayHead + i * 4);
			if(ReadDWORD(dwObj + 判断是否可见偏移) == 0x0)
				continue;

			T tmp(dwObj);
			if(emHumanType != em_Human_Type_Unknow && (tmp.GetHp() == NULL || tmp.GetCurrentCamp() != emCamp || tmp.GetHumanType() != emHumanType || !tmp.IsShowInFog()))
				continue;

			tmp.SetDis();
			vlst.push_back(tmp);
		}
		sort(vlst.begin(), vlst.end());
		return vlst.size();
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

	virtual void AbstractClass() = NULL;
private:
	DSIABLE_COPY_AND_ASSIGN(CObjectTraverse);
};



#endif