#ifndef __LOL_CHINA_LOLDLL_GAME_OBJECT_OTHER_SKILL_H__
#define __LOL_CHINA_LOLDLL_GAME_OBJECT_OTHER_SKILL_H__

#include "BaseObject.h"

class CHumanBaseObject;
class CSkill : public CBaseObject
{
public:
	CSkill();
	CSkill(_In_ UINT uIndex_, _In_ DWORD dwNodeBase_);
	~CSkill() = default;

	// 获取Index
	em_Skill_Index GetSkillIndex() CONST;

	// 技能等级
	DWORD GetLevel() CONST;

	// 技能名称
	virtual cwstring& GetName() CONST;

	// 当前技能消耗MP
	DWORD GetExpendMp() CONST;

	// 技能CD,是否冷却完毕
	BOOL IsCooldown() CONST;

	// 是否可以使用了
	BOOL IsCouldUse() CONST;

	// 使用技能
	BOOL UseSkill(_In_ CONST CHumanBaseObject& HumanBaseObject_, _In_ em_Skill_Type emSkillType) CONST;

	// 物品技能参数
	DWORD GetItemSkillParameter() CONST;
private:
	UINT uIndex;
};





#endif