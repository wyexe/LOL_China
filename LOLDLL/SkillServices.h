#ifndef __LOL_CHINA_LOLDLL_GAME_OBJECTSERVICES_SKILLSERVICES_H__
#define __LOL_CHINA_LOLDLL_GAME_OBJECTSERVICES_SKILLSERVICES_H__

#include "ObjectTraverse.h"

class CSkillServices
{
public:
	CSkillServices();
	~CSkillServices();

	static CSkillServices& GetInstance();

	// 技能是否冷却
	BOOL IsSkillCooldown(_In_ em_Skill_Index emSkillIndex) CONST;

	// 使用技能
	BOOL UseSkill(_In_ em_Skill_Index emSkillIndex) CONST;

	// 技能加点
	BOOL LevelUpSkill() CONST;

	// 检查技能加点
	BOOL CheckLevelupSkill() CONST;

	// 获取当前英雄的技能介绍
	CONST ResSkill* GetCurrentHeroSkillConfig() CONST;

	// 使用物品技能
	BOOL UseItemSkill(_In_ cwstring& wsItemSkillName) CONST;

	// 使用BUFF技能(疾跑, 加血, 回城)
	BOOL UseBuffSkill(_In_ cwstring& wsSkillName) CONST;

	// 使用非指向性的物品技能
	BOOL UseUnDirectionalItemSkill(_In_ cwstring& wsSkillName) CONST;
private:
	DSIABLE_COPY_AND_ASSIGN(CSkillServices);
};



#endif