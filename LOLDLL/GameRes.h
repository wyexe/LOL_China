#ifndef __LOL_CHINA_LOLDLL_GAME_RES_GAMERES_H__
#define __LOL_CHINA_LOLDLL_GAME_RES_GAMERES_H__

#include "GameVariable.h"

class CEqument;
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

	enum em_ResEqument_Type
	{
		em_ResEqument_Type_Master_Defence,
		em_ResEqument_Type_Master_Attack,
		em_ResEqument_Type_ADC_AttackSpeed,
		em_ResEqument_Type_ADC_AttackDis,
		em_ResEqument_Type_ADC_AttackPower,
		em_ResEqument_Type_Defence_Attack,
		em_ResEqument_Type_Defence_Defence
	};
	struct HeroResEqument
	{
		em_ResEqument_Type emResEqumentType;
		vector<ResEqument> EqumentVec;
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

	// 塔
	cwstring* GetCrystalTurretNameByCampAndType(_In_ em_Camp emCamp, _In_ em_Path_Type emPathType) CONST throw();

	// 获取当前英雄的默认路径
	em_Path_Type GetDefaultPathTypeByHero(_In_ em_Hero_Pro emHeroPro) CONST throw();

	// BaseName
	// 获取基地名称
	CONST cwstring& GetBaseNameByCamp(_In_ em_Camp emCamp) CONST throw();

	// Equment
	auto GetNextEqumentId(_In_ em_Hero_Pro emHeroPro, _In_ DWORD dwLastEqumentId) CONST throw() -> CONST ResEqument*;
	DWORD GetCurrentLastEqumentId(_In_ em_Hero_Pro emHeroPro, _In_ vector<CEqument>& vlst) CONST;

	// Skill
	// 获取英雄的技能用法介绍
	auto GetResSkillByHero(_In_ em_Hero_Pro emHeroPro)  CONST throw() -> CONST ResSkill*;
	auto GetResSkillByHero(_In_ cwstring& wsHeroName) CONST throw()->CONST ResSkill*;

	// 获取英雄的技能点该加哪个点
	em_Skill_Index GetSPByHeroLevel(_In_ em_Hero_Pro emHeroPro, _In_ DWORD dwLevel) CONST throw();

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
	auto GetResEuqmentVecByType(_In_ em_ResEqument_Type emResEqumentType) CONST throw() ->CONST vector<ResEqument>*;

	// 获取英雄技能用法介绍List
	CONST vector<ResSkill>& GetResSkillList() CONST throw();

	// 获取英雄的装备分类
	auto GetResEqumentTypeByHero(_In_ em_Hero_Pro emHeroPro) CONST throw() ->em_ResEqument_Type;
private:
	DSIABLE_COPY_AND_ASSIGN(CGameRes);
};



#endif