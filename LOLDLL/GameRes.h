#ifndef __LOL_CHINA_LOLDLL_GAME_RES_GAMERES_H__
#define __LOL_CHINA_LOLDLL_GAME_RES_GAMERES_H__

#include "GameVariable.h"

class CGameRes
{
public:
	CGameRes() = default;
	~CGameRes() = default;

	static CGameRes& GetInstance() throw();
private:
	struct ResEqument
	{
		DWORD dwEqumentId;
		DWORD dwPrice;
	};
	struct HeroResEqument
	{
		em_Hero_Pro emHeroPro;
		vector<DWORD> EqumentIdVec;
	};
	struct ResSkillInfo
	{
		em_Skill_Type	emSkillType;
		float			fSkillDis;
	};
	struct ResSkill
	{
		em_Hero_Pro		emHeroPro;
		wstring			HeroName;
		ResSkillInfo    ResSkillInfoQ;
		ResSkillInfo    ResSkillInfoW;
		ResSkillInfo    ResSkillInfoE;
		ResSkillInfo    ResSkillInfoR;
	};
	struct tagHeroSp
	{
		em_Hero_Pro		emHeroPro;
		vector<em_Skill_Index> SkillSpVec;
	};
public:
	// MonsterBuff
	// 蓝BUFF
	CONST Point& GetBlueBuffPointByCamp(_In_ em_Camp emCamp) CONST throw();

	// 红BUFF
	CONST Point& GetRedBuffPointByCamp(_In_ em_Camp emCamp) CONST throw();

	// 小龙
	CONST Point& GetDroganPoint() CONST throw();

	// 大龙
	CONST Point& GetBaronPoint() CONST throw();

	// BaseName
	// 获取基地名称
	CONST cwstring& GetBaseNameByCamp(_In_ em_Camp emCamp) CONST throw();

	// Equment
	auto GetNextEqumentId(_In_ em_Hero_Pro emHeroPro, _In_ DWORD dwLastEqumentId, _Out_opt_ DWORD& dwEuqmentId) CONST throw() -> CONST ResEqument*;

	// Skill
	// 获取英雄的技能用法介绍
	auto GetResSkillByHero(_In_ em_Hero_Pro emHeroPro)  CONST throw() -> CONST ResSkill*;

	// 获取英雄的技能点该加哪个点
	CONST em_Skill_Index* GetSPByHeroLevel(_In_ em_Hero_Pro emHeroPro, _In_ DWORD dwLevel) CONST throw();

	// Next Move Point
	// 获取下一个移动的坐标点(return nullptr 表示无路可走!)
	CONST Point* GetNextMovePoint(_In_ em_Camp emCamp, _In_ em_Path_Type emPathType, _In_ CONST Point& CurPoint) CONST throw();

	// 获取上一个移动的坐标点(return nullptr 表示无路可走!)
	CONST Point* GetPreviouMovePoint(_In_ em_Camp emCamp, _In_ em_Path_Type emPathType, _In_ CONST Point& CurPoint) CONST throw();

	// 获取英雄的攻击距离
	float GetHeroAttackDis(_In_ em_Hero_Pro emHeroPro) CONST throw();
private:
	// 获取当前阵营和走哪条路的整条坐标路径
	CONST vector<Point>& GetPathPointVecByCampAndPathType(_In_ em_Camp emCamp, _In_ em_Path_Type emPathType) CONST throw();

	// 获取英雄的所有装备列表
	auto GetResEuqmentVecByHero(_In_ em_Hero_Pro emHeroPro) CONST throw() ->CONST vector<DWORD>*;

	// 获取装备列表
	auto GetEqumentPriceById(_In_ DWORD dwEqumentId) CONST throw() -> CONST ResEqument*;

	// 获取所有英雄的技能加点大全
	auto GetHeroSpVec() CONST throw() ->CONST vector<tagHeroSp>&;
private:
	DSIABLE_COPY_AND_ASSIGN(CGameRes);
};



#endif