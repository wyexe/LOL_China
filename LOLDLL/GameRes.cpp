#include "stdafx.h"
#include "GameRes.h"
#include <limits>
#include <MyTools/CLLog.h>
#include <MyTools/CLPublic.h>

#define _SELF L"GameRes.cpp"

CGameRes& CGameRes::GetInstance() throw()
{
	static CGameRes GameRes;
	return GameRes;
}

CONST Point& CGameRes::GetBlueBuffPointByCamp(_In_ em_Camp emCamp) CONST throw()
{
	CONST static Point BlueCamp(3548.00f, 8206.00f, 51.19f);
	CONST static Point RedCamp(11402.00f, 6532.00f, 51.70f);
	return emCamp == em_Camp::em_Camp_Blue ? BlueCamp : RedCamp;
}

CONST Point& CGameRes::GetRedBuffPointByCamp(_In_ em_Camp emCamp) CONST throw()
{
	CONST static Point BlueCamp(7488.00f, 3716.00f, 52.00f);
	CONST static Point RedCamp(7312.00f, 11140.00f, 55.15f);
	return emCamp == em_Camp::em_Camp_Blue ? BlueCamp : RedCamp;
}

CONST Point& CGameRes::GetDroganPoint() CONST throw()
{
	CONST static Point DroganPoint(10186.00f, 4882.00f, -71.24f);
	return DroganPoint;
}

CONST Point& CGameRes::GetBaronPoint() CONST throw()
{
	CONST static Point BaronPoint(0, 0, 0);
	return BaronPoint;
}

cwstring* CGameRes::GetCrystalTurretNameByCampAndType(_In_ em_Camp emCamp, _In_ em_Path_Type emPathType) CONST throw()
{
	struct tagCrystalTurret
	{
		wstring wsTurretName;
		em_Camp emCamp;
		em_Path_Type emPathType;
	};

	static CONST vector<tagCrystalTurret> vlst = {
		// 蓝方上路
		{ L"Barracks_T1_L1", em_Camp_Blue, em_Path_Type::Path_Type_Top },

		// 蓝方中路
		{ L"Barracks_T1_C1", em_Camp_Blue, em_Path_Type::Path_Type_Middle },

		// 蓝方下路
		{ L"Barracks_T1_R1", em_Camp_Blue, em_Path_Type::Path_Type_Buttom },


		// 红方上路
		{ L"Barracks_T2_L1", em_Camp_Red, em_Path_Type::Path_Type_Top },

		// 红方中路
		{ L"Barracks_T2_C1", em_Camp_Red, em_Path_Type::Path_Type_Middle },

		// 红方下路
		{ L"Barracks_T2_R1", em_Camp_Red, em_Path_Type::Path_Type_Buttom }
	};

	auto ptagCrystalTurret = CLPublic::Vec_find_if(vlst, [&emCamp, &emPathType](CONST auto& itm) {
		return itm.emCamp == emCamp && itm.emPathType == emPathType;
	});

	return ptagCrystalTurret == nullptr ? nullptr : &ptagCrystalTurret->wsTurretName;
}

em_Path_Type CGameRes::GetDefaultPathTypeByHero(_In_ em_Hero_Pro emHeroPro) CONST throw()
{
	// 设置英雄的分路的路线
	switch (emHeroPro)
	{
	case em_Hero_Pro_Ryze: // 流浪法师中单
		return em_Path_Type::Path_Type_Top;
	case em_Hero_Pro_Swain: case em_Hero_Pro_Ashe: case em_Hero_Pro_Ezreal:  case em_Hero_Pro_Chogath:  case  em_Hero_Pro_Maokai:
	case em_Hero_Pro_MissFortune: case em_Hero_Pro_Sejuani: case em_Hero_Pro_Galio: case em_Hero_Pro_KogMaw: case em_Hero_Pro_Ahri:
		return em_Path_Type::Path_Type_Middle;
	case em_Hero_Pro_Malzahar: case em_Hero_Pro_MasterYi: case em_Hero_Pro_Graves: case em_Hero_Pro_Vayne:
	case em_Hero_Pro_Heimerdinger: case em_Hero_Pro_Nunu: case em_Hero_Pro_Garen: case em_Hero_Pro_Veigar:
	case em_Hero_Pro_Tristana: case em_Hero_Pro_Lucian: case em_Hero_Pro_Corki: case em_Hero_Pro_Caitlyn:
		return em_Path_Type::Path_Type_Buttom;
	default:
		LogMsgBox(LOG_LEVEL_EXCEPTION, L"少年,这个英雄:%X暂时还不支持喔~!", emHeroPro);
		break;
	}
	return em_Path_Type::Path_Type_Middle;
}

CONST cwstring& CGameRes::GetBaseNameByCamp(_In_ em_Camp emCamp) CONST throw()
{
	static cwstring BlueCamp(L"");
	static cwstring RedCamp(L"");
	return emCamp == em_Camp::em_Camp_Blue ? BlueCamp : RedCamp;
}

CONST Point* CGameRes::GetNextMovePoint(_In_ em_Camp emCamp, _In_ em_Path_Type emPathType, _In_ CONST Point& CurPoint) CONST throw()
{
	auto& Vec = GetPathPointVecByCampAndPathType(emCamp, emPathType);
	if (Vec.size() == 0)
	{
		LogMsgBox(LOG_LEVEL_EXCEPTION, L"GetPathPointVecByCampAndPathType.size=0!");
		return nullptr;
	}

	auto Index = CLPublic::GetRecentlyIndexByVec(Vec, CurPoint);
	if (Index == -1)
	{
		LogMsgBox(LOG_LEVEL_EXCEPTION, L"GetRecentlyIndexByVec=-1!, CurPoint=[%d,%d,%d]", CurPoint.GetX(), CurPoint.GetY(),CurPoint.GetZ());
		return nullptr;
	}

	return Index + 1 >= static_cast<decltype(Index)>(Vec.size()) ? &Vec.back() : &Vec.at(Index + 1);
}

CONST Point* CGameRes::GetPreviouMovePoint(_In_ em_Camp emCamp, _In_ em_Path_Type emPathType, _In_ CONST Point& CurPoint) CONST throw()
{
	auto& Vec = GetPathPointVecByCampAndPathType(emCamp, emPathType);
	if (Vec.size() == 0)
	{
		LogMsgBox(LOG_LEVEL_EXCEPTION, L"GetPathPointVecByCampAndPathType.size=0!");
		return nullptr;
	}

	auto Index = CLPublic::GetRecentlyIndexByVec(Vec, CurPoint);
	if (Index == -1)
	{
		LogMsgBox(LOG_LEVEL_EXCEPTION, L"GetRecentlyIndexByVec=-1!, CurPoint=[%d,%d,%d]", CurPoint.GetX(), CurPoint.GetY(), CurPoint.GetZ());
		return nullptr;
	}

	return Index - 1 >= 0 ? &Vec.at(Index - 1) : &Vec.at(0);
}

float CGameRes::GetHeroAttackDis(_In_ em_Hero_Pro emHeroPro) CONST throw()
{
	switch (emHeroPro)
	{
	case em_Hero_Pro_Ryze:
		break;
	default:
		break;
	}
	return 3.0f;
}

CONST vector<Point>& CGameRes::GetPathPointVecByCampAndPathType(_In_ em_Camp emCamp, _In_ em_Path_Type emPathType) CONST throw()
{
	static CONST vector<Point> TopBlueCamp = {
		Point(604.00f, 612.00f, 183.57f),		Point(1154.00f, 3910.00f, 95.75f),		Point(1400.00f, 6086.00f, 53.76f), 
		Point(1018.00f, 9678.00f, 52.84f),		Point(1490.00f, 11490.00f, 52.84f),		Point(2224.00f, 12508.00f, 52.84f), 
		Point(3328.00f, 13268.00f, 52.84f),		Point(4828.00f, 13892.00f, 52.84f),		Point(8568.00f, 13390.00f, 52.84f), 
		Point(10836.00f, 13670.00f, 91.43f),	Point(14576.36f, 14693.83f, 171.98f)
	};
	static CONST vector<Point> MiddleBlueCamp = {
		Point(604.00f, 612.00f, 183.57f),		Point(1210.00f, 1240.00f, 95.75f),		Point(2064.00f, 2730.00f, 95.75f),
		Point(3350.00f, 3468.00f, 95.75f),		Point(4338.00f, 4412.00f, 71.06f),		Point(5472.00f, 6044.00f, 51.14f),
		Point(6784.00f, 6776.00f, 51.89f),		Point(7434.00f, 7332.00f, 53.84f),		Point(8168.00f, 8032.00f, 53.15f),
		Point(9154.00f, 9020.00f, 54.01f),		Point(10190.00f, 10432.00f, 52.30f),	Point(11362.00f, 11360.00f, 91.43f),
		Point(12630.00f, 11684.00f, 91.43f),	Point(14576.36f, 14693.83f, 171.98f)
	};
	static CONST vector<Point> ButtomBlueCamp = {
		Point(604.00f, 612.00f, 183.57f),		Point(1508.00f, 658.00f, 95.75f),		Point(2840.00f, 1200.00f, 95.75f),
		Point(3926.00f, 1216.00f, 95.75f),		Point(6516.00f, 1388.00f, 49.50f),		Point(9920.00f, 1310.00f, 51.30f),
		Point(11690.00f, 1590.00f, 50.39f),		Point(12378.00f, 2234.00f, 52.17f),		Point(13446.00f, 3576.00f, 51.37f),
		Point(13720.00f, 4948.00f, 52.76f),		Point(13402.00f, 8752.00f, 52.31f),		Point(13624.00f, 10906.00f, 91.43f),
		Point(13578.00f, 11752.00f, 91.43f),	Point(13976.00f, 13098.00f, 91.43f),	Point(14576.36f, 14693.83f, 171.98f),
	};

	static vector<Point> TopRedCamp;
	static vector<Point> MiddleRedCamp;
	static vector<Point> ButtomRedCamp;

	// Initialization Red Camp
	if (TopRedCamp.size() == 0)
		std::reverse_copy(std::begin(TopBlueCamp), std::end(TopBlueCamp), TopRedCamp.begin());
	if (MiddleRedCamp.size() == 0)
		std::reverse_copy(std::begin(MiddleBlueCamp), std::end(MiddleBlueCamp), MiddleRedCamp.begin());
	if (ButtomRedCamp.size() == 0)
		std::reverse_copy(std::begin(ButtomBlueCamp), std::end(ButtomBlueCamp), ButtomRedCamp.begin());


	// return Camp&&PathType
	if (emCamp == em_Camp::em_Camp_Red)
	{
		switch (emPathType)
		{
		case Path_Type_Top:
			return TopRedCamp;
		case Path_Type_Middle:
			return MiddleRedCamp;
		case Path_Type_Buttom:
			return ButtomRedCamp;
		default:
			LogMsgBox(LOG_LEVEL_EXCEPTION, L"emPathType=%X", emPathType);
			break;
		}
		return TopRedCamp;
	}

	switch (emPathType)
	{
	case Path_Type_Top:
		return TopBlueCamp;
	case Path_Type_Middle:
		return MiddleBlueCamp;
	case Path_Type_Buttom:
		return ButtomBlueCamp;
	default:
		LogMsgBox(LOG_LEVEL_EXCEPTION, L"emPathType=%X", emPathType);
		break;
	}
	return TopBlueCamp;
}

auto CGameRes::GetResEuqmentVecByHero(_In_ em_Hero_Pro emHeroPro) CONST throw() -> CONST vector<DWORD>*
{
	static CONST vector<HeroResEqument> HeroResEqumentVec = {
		{ em_Hero_Pro_Ryze,{ EQUMENT_ID_蓝水晶,EQUMENT_ID_女神之泪 } },
	};

	auto pHeroResEqument = CLPublic::Vec_find_if(HeroResEqumentVec, [&emHeroPro](CONST HeroResEqument& itm) {
		return itm.emHeroPro == emHeroPro;
	});
	return pHeroResEqument != nullptr ? &pHeroResEqument->EqumentIdVec : nullptr;
}

auto CGameRes::GetEqumentPriceById(_In_ DWORD dwEqumentId) CONST throw()  -> CONST ResEqument*
{
	static CONST vector<ResEqument> ResEqumentVec = {
		{ EQUMENT_ID_蓝水晶, 350 },
		{ EQUMENT_ID_女神之泪, 400 },
		{ EQUMENT_ID_速度之靴, 300 },
		{ EQUMENT_ID_催化神石, 1200 },
		{ EQUMENT_ID_水银之靴, 800 },
		{ EQUMENT_ID_时光之杖, 1800 },
		{ EQUMENT_ID_猛禽斗篷, 1200 },
		{ EQUMENT_ID_传送门, 1500 },
		{ EQUMENT_ID_巨人腰带, 1000 },
	};

	return CLPublic::Vec_find_if(ResEqumentVec, [&dwEqumentId](CONST auto& itm) { return itm.dwEqumentId == dwEqumentId; });
}

auto CGameRes::GetNextEqumentId(_In_ em_Hero_Pro emHeroPro, _In_ DWORD dwLastEqumentId) CONST throw()  -> CONST ResEqument*
{
	// Get EqumentId list by Hero
	auto pVec = GetResEuqmentVecByHero(emHeroPro);
	if (pVec == nullptr)
	{
		LogMsgBox(LOG_LEVEL_EXCEPTION, L"UnExist Hero Equment:%X", emHeroPro);
		return nullptr;
	}

	// find current equment id in pVec
	auto& ResEqumentItr = std::find_if(pVec->begin(), pVec->end(), [&dwLastEqumentId](CONST auto& itm) {
		return itm == dwLastEqumentId;
	});
	if (ResEqumentItr == pVec->begin())
	{
		LogMsgBox(LOG_LEVEL_EXCEPTION, L"UnExist Hero Equment:%X", emHeroPro);
		return nullptr;
	}

	if (ResEqumentItr + 1 == pVec->end())
	{
		// full equment!
		return nullptr;
	}

	// Get Next Equment
	return GetEqumentPriceById(*(ResEqumentItr + 1));
}

auto CGameRes::GetResSkillByHero(_In_ em_Hero_Pro emHeroPro) CONST throw() -> CONST ResSkill*
{
	CONST static vector<ResSkill> vlst = {
		{em_Hero_Pro_Ryze,L"瑞兹",{ em_Skill_Type::em_Skill_Type_UnDirectional , 7},{ em_Skill_Type::em_Skill_Type_Directional, 5},{ em_Skill_Type::em_Skill_Type_Directional, 5},{ em_Skill_Type::em_Skill_Type_Self_UnDirectional, 10}},
	};

	return CLPublic::Vec_find_if(vlst, [&emHeroPro](CONST auto& itm) { return itm.emHeroPro == emHeroPro; });
}

CONST em_Skill_Index* CGameRes::GetSPByHeroLevel(_In_ em_Hero_Pro emHeroPro, _In_ DWORD dwLevel) CONST throw()
{
	CONST auto& Vec = GetHeroSpVec();
	auto pHeroSp = CLPublic::Vec_find_if(Vec, [&emHeroPro](CONST auto& itm) { return itm.emHeroPro == emHeroPro; });
	return pHeroSp == nullptr ? nullptr : &pHeroSp->SkillSpVec.at(dwLevel);
}

auto CGameRes::GetHeroSpVec() CONST throw() -> CONST vector<tagHeroSp>&
{
	CONST static vector<tagHeroSp> vlst = {
		{ em_Hero_Pro_Ryze,{ 
			em_Skill_Index_Q ,em_Skill_Index_Q,em_Skill_Index_Q,em_Skill_Index_Q, em_Skill_Index_Q,
			em_Skill_Index_Q ,em_Skill_Index_Q,em_Skill_Index_Q,em_Skill_Index_Q, em_Skill_Index_Q,
			em_Skill_Index_Q ,em_Skill_Index_Q,em_Skill_Index_Q,em_Skill_Index_Q, em_Skill_Index_Q,
			em_Skill_Index_Q ,em_Skill_Index_Q,em_Skill_Index_Q,
		} },
		{ em_Hero_Pro_Garen,{
			em_Skill_Index_Q ,em_Skill_Index_Q,em_Skill_Index_Q,em_Skill_Index_Q, em_Skill_Index_Q,
			em_Skill_Index_Q ,em_Skill_Index_Q,em_Skill_Index_Q,em_Skill_Index_Q, em_Skill_Index_Q,
			em_Skill_Index_Q ,em_Skill_Index_Q,em_Skill_Index_Q,em_Skill_Index_Q, em_Skill_Index_Q,
			em_Skill_Index_Q ,em_Skill_Index_Q,em_Skill_Index_Q,
		} },
	};
	return vlst;
}

