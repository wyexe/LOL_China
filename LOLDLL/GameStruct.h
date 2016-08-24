#ifndef __LOL_CHINA_LOLDLL_GAME_VARIABLE_GAMESTRUCT_H__
#define __LOL_CHINA_LOLDLL_GAME_VARIABLE_GAMESTRUCT_H__

#include <MyTools/Character.h>
#include <MyTools/CLLog.h>
#include <memory>
#include <stack>
#include <queue> 
#include <process.h>
#include <algorithm>

/************************************************************************/
/* GameBase                                                             */
/************************************************************************/




























/************************************************************************/
/* GameMacro                                                            */
/************************************************************************/

#define BLUE_BUFF_REFRESHTIME						6 * 60 * 1000
#define BLUE_BUFF_ID								0x1C
#define RED_BUFF_REFRESHTIME						6 * 60 * 1000
#define DRAGON_BUFF_REFRESHTIME						6 * 60 * 1000
#define MIDDLE_HERO_PRO								em_Hero_Pro_Ryze
#define MAX_ATTACK_DIS								10.0f

#define SKILLNAME_RECALL1							L"recall"
#define SKILLNAME_RECALL2							L"OdinRecall"
#define DRAGONNAME									L"SRU_Dragon6.1.1"
#define BLUE_BUFF_NAME1								L"SRU_Blue7.1.1"
#define BLUE_BUFF_NAME2								L"SRU_Blue1.1.1"
#define RED_BUFF_NAME1								L"SRU_Red4.1.1"
#define RED_BUFF_NAME2								L"SRU_Red4.1.1"

#define BLUE_CAMP_SPRING_NAME						L"Turret_OrderTurretShrine_A"
#define RED_CAMP_SPRING_NAME						L"Turret_ChaosTurretShrine_A"

#define SKILLNAME_SUMMONERHASTE						L"summonerhaste"
#define SKILLTIME_SUMMONERHASTE						3 * 60 * 1000
#define SKILLNAME_SUMMONERHEAL						L"summonerheal"
#define SKILLTIME_SUMMONERHEAL						4 * 60 * 1000
#define SKILLNAME_ITEMVOIDGATE						L"ItemVoidGate"
#define SKILLTIME_ITEMVOIDGATE						1 * 60 * 1000
///////Equment///////////////////////////////////////////////////////////////////
#define EQUMENT_ID_红药								0x0
#define EQUMENT_ID_蓝水晶							0x403
#define EQUMENT_ID_女神之泪							0xBFE
#define EQUMENT_ID_速度之靴							0x3E9
#define EQUMENT_ID_催化神石							0xBC2
#define EQUMENT_ID_水银之靴							0xC27
#define EQUMENT_ID_时光之杖							0xBD3
#define EQUMENT_ID_猛禽斗篷							0x805
#define EQUMENT_ID_传送门							0xDB8
#define EQUMENT_ID_巨人腰带							0x3F3
#define EQUMENT_ID_瑞莱的冰晶节杖					0xC2C



////////Other//////////////////////////////////////////////////////////////////

#define VARIABLE_ID_MAINTHREADID					0x0



#define MAX_TELPORT_SIZE							(34 * 512 / 4)

#define SZFILE_NAME_SHAREDINFO						L"LOL_CHINA_Share_Info"
#define MAX_GAME_COUNT								50
#define MAX_OBJECT_NAME_LEN							32




#define ReadDWORD(x)								CCharacter::ReadDWORD(x)
#define ReadBYTE(x)									CCharacter::ReadBYTE(x)
#define ReadFloat(x)								CCharacter::ReadFloat(x)
#define ReadDouble(x)								CCharacter::ReadDouble(x)

#define DSIABLE_COPY_AND_ASSIGN(TypeName)	\
	TypeName(CONST TypeName&) = delete;		\
	VOID operator=(CONST TypeName&) = delete;






/************************************************************************/
/* Struct                                                               */
/************************************************************************/

struct Point
{
	float X, Z, Y;
	Point() : X(0), Y(0), Z(0)
	{

	}
	Point(float pX, float pY, float pZ) : X(pX), Y(pY), Z(pZ)
	{

	}
	bool operator == (const Point & p) CONST
	{
		return p.X == X && p.Y == Y;
	}
	bool operator != (const Point & p) CONST
	{
		return p.X != X || p.Y != Y;
	}
	bool IsZero() CONST
	{
		return X == 0 || Y == 0 || Z == 0;
	}
	int GetX() CONST
	{
		return static_cast<int>(X);
	}
	int GetY() CONST
	{
		return static_cast<int>(Y);
	}
	int GetZ() CONST
	{
		return static_cast<int>(Z);
	}
};

enum em_GameCmd
{
	em_GameCmd_None,
	em_GameCmd_Start,
	em_GameCmd_Stop
};

enum em_Skill_Index
{
	em_Skill_Index_Q,
	em_Skill_Index_W,
	em_Skill_Index_E,
	em_Skill_Index_R
};

enum em_Camp
{
	em_Camp_Blue,
	em_Camp_Red,
	em_Camp_Neutral,
	em_Camp_UnKnow
};

enum em_Path_Type
{
	Path_Type_Top,
	Path_Type_Middle,
	Path_Type_Buttom
};

enum em_Hero_Pro
{
	em_Hero_Pro_Ryze,			// 流浪法师
	em_Hero_Pro_Garen,			// 德玛西亚
	em_Hero_Pro_Ashe,			// 寒冰射手
	em_Hero_Pro_MissFortune,	// 赏金猎人
	em_Hero_Pro_Ezreal,			// 探险家
	em_Hero_Pro_MasterYi,		// 无极剑圣
	em_Hero_Pro_Malzahar,		// 虚空先知
	em_Hero_Pro_Chogath,		// 虚空恐惧
	em_Hero_Pro_Nunu,			// 雪人骑士
	em_Hero_Pro_Heimerdinger,	// 大发明家
	em_Hero_Pro_Graves,			// 法外狂徒
	em_Hero_Pro_Swain,			// 策士统领
	em_Hero_Pro_Annie,			// 黑暗之女
	em_Hero_Pro_Vayne,			// 暗夜猎手
	em_Hero_Pro_Maokai,			// 扭曲树精
	em_Hero_Pro_Veigar,			// 邪恶小法师
	em_Hero_Pro_Sejuani,		// 凛冬之怒
	em_Hero_Pro_Tristana,		// 麦林炮手
	em_Hero_Pro_Galio,			// 哨兵之殇
	em_Hero_Pro_Lucian,			// 圣枪游侠
	em_Hero_Pro_Trundle,		// 巨魔之王
	em_Hero_Pro_Syndra,			// 暗黑元首
	em_Hero_Pro_Aatrox,			// 暗裔剑魔
	em_Hero_Pro_Taric,			// 宝石骑士
	em_Hero_Pro_Rumble,			// 机械公敌
	em_Hero_Pro_Diana,			// 皎洁女神
	em_Hero_Pro_Urgot,			// 首领之傲
	em_Hero_Pro_Teemo,			// 迅捷斥候
	em_Hero_Pro_Caitlyn,		// 皮城女警
	em_Hero_Pro_Corki,			// 英勇投弹手
	em_Hero_Pro_Fiora,			// 无双剑姬
	em_Hero_Pro_Kennen,			// 狂暴之心
	em_Hero_Pro_Mordekaiser,	// 铁铠冥魂
	em_Hero_Pro_Nautilus,		// 深海泰坦
	em_Hero_Pro_RekSai,			// 虚空遁地兽
	em_Hero_Pro_Sivir,			// 战争女神
	em_Hero_Pro_Thresh,			// 魂锁典狱长
	em_Hero_Pro_TwistedFate,	// 卡牌大师
	em_Hero_Pro_KogMaw,			// 深渊巨口
	em_Hero_Pro_Ahri			// 九尾妖狐
};

enum em_Skill_Type
{
	em_Skill_Type_Directional,	// 指向性技能
	em_Skill_Type_UnDirectional, // 非指向性技能
	em_Skill_Type_Buff_Self,		// Buff技能
	em_Skill_Type_Self_UnDirectional // 非指向性的技能, 不过是以自己坐标
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

struct ACCOUNT_INFO
{
	WCHAR szUserName[64];			//帐号
	WCHAR szPassWord[32];			//密码
	DWORD dwServerId;				//服务器
	DWORD dwOrderIndex;				//角色列表
	WCHAR szPlayerName[32];			//玩家名称
	BOOL bAlive;					//活动标识，定期检测一次此标识，如果没有设置为TRUE表示目标进程出问题了。
	BOOL bLogin;					//登录完毕=FALSE
	WCHAR szCardNo[64];				//卡号
	DWORD dwCardToken;				// 卡号令牌
	em_GameCmd GameCmd;				// 游戏状态
	DWORD dwSortIndex;				// 排列序号
	DWORD dwClasses;				// 职业
};

struct AccountLog
{
	BOOL bOccupy;											// 是否被占用
	WCHAR szMsg[64];										// 日志
};

typedef struct _AccountRunStatus
{
	BOOL bDone;												// 是否刷完了这个号
	BOOL bExist;											// 该帐号已经被占用了
	BOOL bLogining;											// 是否登录中
	BOOL bClose;											// 是否强制关闭该帐号
	BOOL bLogined;											// 是否登录过
	BOOL bDelete;											// 是否要删除该帐号->Account.txt
	UINT uLoginFaildCount;									// 登录失败次数
	UINT uCreatePlayerFaildCount;							// 创建角色失败次数
	UINT uUnExistGameHwndCount;								// 查找窗口失败次数
	BOOL bFrozen;											// 冻结
}AccountRunStatus;

struct Account_Info_Game
{
	ACCOUNT_INFO ACCOUNT_INFO_;								// 帐号信息
	AccountLog   AccountLog_;								// 帐号日志
	DWORD dwPid;											// 进程ID
	HWND hGameWnd;											// 窗口句柄
	AccountRunStatus AccountStatus;							// 帐号状态

	LPCWSTR GetAccName()
	{
		return GetAccountInfo()->szUserName;
	}
	DWORD& GetOrderIndex()
	{
		return GetAccountInfo()->dwOrderIndex;
	}
	UINT& GetLoginFaildCount()
	{
		return AccountStatus.uLoginFaildCount;
	}
	ACCOUNT_INFO* GetAccountInfo()
	{
		return &ACCOUNT_INFO_;
	}
};

struct Share_Global_Account
{
	BOOL bRun;												// 是否开启全局设置
	DWORD dwAreaId;											// 大区Id
	WCHAR wszScriptName[32];								// 脚本名称
	WCHAR wszTypeName[32];									// 登录类型
	WCHAR wszMailPlayerName[10][16];						// 邮寄角色名
	UINT  uMailNameCount;									// 邮寄角色名数量
	UINT  uMailNameIndex;									// 读取到哪个邮寄偏移了
	CHAR  szServerIp[32];									// 服务器的IP
	WCHAR wszWarehouseScript[32];							// 仓库号脚本
	BOOL IsClose_By_Banned;									// 封号后是否关闭
	BOOL IsPK;												// 是否PK
	BOOL IsDailyTask;										// 是否做日常
};


struct Shared_Info
{
	WCHAR szConsolePath[MAX_PATH];							// 控制台路径
	WCHAR wszGamePath[MAX_PATH];							// 游戏路径
	int nAccountCount;										// Size
	Account_Info_Game arrGameInfo[MAX_GAME_COUNT];			// 数组
	Share_Global_Account GlobalAccount;						// 全局设置

	Account_Info_Game* ExistEmptyArrGameInfo()
	{
		auto itr = std::find_if(std::begin(arrGameInfo), std::end(arrGameInfo), [](Account_Info_Game& AccountGame){
			return !AccountGame.AccountStatus.bExist;
		});

		if (itr == std::end(arrGameInfo))
			return nullptr;
		return itr;
	}
	Account_Info_Game* GetCurrentAccountGame()
	{
		auto itr = std::find_if(std::begin(arrGameInfo), std::end(arrGameInfo), [](Account_Info_Game& AccountGame){
			return AccountGame.AccountStatus.bLogining;
		});

		if (itr == std::end(arrGameInfo))
			return nullptr;
		return itr;
	}
};












#endif