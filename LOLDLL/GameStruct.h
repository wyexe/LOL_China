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

#define 人物基址										0x17A7C30
#define 环境基址										0x27CBA5C
#define BUFF基址										0x17A6B00
#define 技能遍历偏移1									0x2588
#define 技能遍历偏移2									0x518
#define 技能OBJ偏移										0xEC
#define 游戏开场时间基址								0x343942C
#define 人物死亡偏移									0x210
#define 装备遍历偏移1									0x1318
#define 购买物品CALL									0x00C0BA10
#define 走路CALL										0x037190C7
#define 使用技能CALL									0x00CE71A0
#define 普通攻击CALL									0x037190C7
#define 学习技能CALL									0x858F50
#define 视角基址										0x17A7E54
#define 视角偏移										0x20

#define HP偏移										0x2F4
#define MP偏移										0x214
#define 坐标偏移X									0x4C
#define 英雄等级虚函数偏移							0x334
#define 人物技能点虚函数偏移						0xBC
#define 人物技能点偏移								0x40
#define 金钱偏移									0x12E4
#define 迷雾偏移1									0x2CEC
#define 迷雾偏移2									0x70
#define 迷雾偏移3									0x31C

// 基本固定不变的
#define 坐标偏移Y									坐标偏移X + 0x4
#define 坐标偏移Z									坐标偏移Y + 0x4
#define MAXHP偏移									HP偏移 + 0x10
#define MAXMP偏移									MP偏移 + 0x10
#define 英雄名称偏移									0x9A0
#define 技能耗蓝偏移1									0x34
#define 技能耗蓝偏移2									0x56C
#define 装备遍历偏移2									0x198
#define 装备ID偏移										0x70
#define 判断是否可见偏移								0x100
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


#define HERO_BUFF_ASHE_Q							0xE
#define HERO_BUFF_MASTERYI_W						0x0
#define HERO_BUFF_MISSFORTUNE_W						0x19
#define HERO_BUFF_GAREN_Q							0x0
#define HERO_BUFF_GAREN_W							0x0
#define HERO_BUFF_MALZAHAR_R						0x0
#define HERO_BUFF_NUNU_R							0x0
#define HERO_BUFF_SJUANI_W							0x0
#define HERO_BUFF_TRISTANA_Q						0x0
#define HERO_BUFF_TRUNDLE_Q							0x0
#define HERO_BUFF_RUMBLE_Q							0x0
#define HERO_BUFF_RUMBLE_W							0x0
#define HERO_BUFF_URGOT_W							0x0
#define HERO_BUFF_TEEMO_W							0x0
#define HERO_BUFF_FIORA_E							0x0
#define HERO_BUFF_MORDEKAISER_Q						0x0
#define HERO_BUFF_NAUTILUS_W						0x0
#define HERO_BUFF_SIVIR_W							0x0
#define HERO_BUFF_SIVIR_E							0x0
#define HERO_BUFF_KOGMAW_W							0x0
#define HERO_BUFF_ANNIE_E							0x0
#define HERO_BUFF_ANNIE_R							0x0
#define HERO_BUFF_AMUMU_W							0x0
#define HERO_BUFF_BLITZCRANK_W						0x0
#define HERO_BUFF_BLITZCRANK_E						0x0
#define HERO_BUFF_DARIUS_W							0x0
#define HERO_BUFF_DRMUNDO_W							0x0
#define HERO_BUFF_DRMUNDO_E							0x0
#define HERO_BUFF_FIDDLESTICKS_W					0x0
#define HERO_BUFF_FIZZ_W							0x0
#define HERO_BUFF_GRAGAS_W							0x0
#define HERO_BUFF_ILLAOI_W							0x0
#define HERO_BUFF_IRELIA_W							0x0
#define HERO_BUFF_JARVANIV_W						0x0
#define HERO_BUFF_JAX_W								0x0
#define HERO_BUFF_JHIN_R							0x0
#define HERO_BUFF_KARMA_E							0x0
#define HERO_BUFF_KARMA_R							0x0
#define HERO_BUFF_KATARINA_R						0x0
#define HERO_BUFF_LEONA_Q							0x0
#define HERO_BUFF_MALPHITE_W						0x0
#define HERO_BUFF_MONKEYKING_Q						0x0
#define HERO_BUFF_MONKEYKING_W						0x0
#define HERO_BUFF_MORGANA_E							0x0
#define HERO_BUFF_NASUS_Q							0x0
#define HERO_BUFF_OLAF_W							0x0
#define HERO_BUFF_OLAF_R							0x0
#define HERO_BUFF_SION_W							0x0
#define HERO_BUFF_POPPY_W							0x0
#define HERO_BUFF_RAMMUS_W							0x0
#define HERO_BUFF_RENEKTON_W						0x0
#define HERO_BUFF_SONA								0x0
#define HERO_BUFF_XINZHAO_Q							0x0
#define HERO_BUFF_XINZHAO_W							0x0
///////Equment///////////////////////////////////////////////////////////////////
#define EQUMENT_PRICE_红药							50
#define EQUMENT_ID_红药								0x0
#define EQUMENT_ID_蓝水晶							0x403
#define EQUMENT_ID_女神之泪							0xBFE
#define EQUMENT_ID_吸血鬼节杖						0x41D
#define EQUMENT_ID_暴风之剑							0x40E
#define EQUMENT_ID_饮血剑							0xC00
#define EQUMENT_ID_蜂刺								0xC1D
#define EQUMENT_ID_耀光								0xBF1
#define EQUMENT_ID_净蚀								0xBE4
#define EQUMENT_ID_三相之力							0xC06
#define EQUMENT_ID_考尔菲德的战锤					0xC3D
#define EQUMENT_ID_灵巧披风							0x3FA
#define EQUMENT_ID_夺萃之镰							0xDB4
#define EQUMENT_ID_反曲之弓							0x413
#define EQUMENT_ID_爆裂魔杖							0x402
#define EQUMENT_ID_十字犒							0x40D
#define EQUMENT_ID_鬼索的狂暴之刃					0xC34
#define EQUMENT_ID_无尽之刃							0xBD7
#define EQUMENT_ID_死亡之舞							0xEE4
#define EQUMENT_ID_比尔吉沃特弯刀					0xC48
#define EQUMENT_ID_破败王者之刃						0xC51
#define EQUMENT_ID_黑色切割者						0xBFF
#define EQUMENT_ID_紫雨林之拳						0xBE4
#define EQUMENT_ID_冰霜之锤							0xBCE
#define EQUMENT_ID_最后的轻语						0xBDB
#define EQUMENT_ID_巨人的杀手						0xBDA
#define EQUMENT_ID_多米尼克领主的致意					0xBDC
#define EQUMENT_ID_魔宗								0xBBC
#define EQUMENT_ID_狂热								0xC0E
#define EQUMENT_ID_卢安娜的飓风						0xC0D
#define EQUMENT_ID_幻影之舞							0xBE6
#define EQUMENT_ID_无用大棒							0x422
#define EQUMENT_ID_灭世者的死亡之帽					0xC11
#define EQUMENT_ID_已太精魂							0xC29
#define EQUMENT_ID_卢登的回声						0xCD5
#define EQUMENT_ID_幽魂面具							0xC40
#define EQUMENT_ID_兰德里的折磨						0xC4F
#define EQUMENT_ID_巨人腰带							0x3F3
#define EQUMENT_ID_瑞莱的冰晶节杖					0xC2C
#define EQUMENT_ID_巫妖之祸							0xC1C
#define EQUMENT_ID_大天使之杖						0xBBB
#define EQUMENT_ID_遗失的章节						0xEDA
#define EQUMENT_ID_恶魔法典							0xC24
#define EQUMENT_ID_莫雷洛秘典						0xC5D
#define EQUMENT_ID_负极斗篷							0x421
#define EQUMENT_ID_深渊权杖							0xBB9
#define EQUMENT_ID_万世催化石						0xBC2
#define EQUMENT_ID_时光之杖							0xBD3
#define EQUMENT_ID_虚空之杖							0xC3F
#define EQUMENT_ID_速度之靴							0x3E9
#define EQUMENT_ID_狂战士胫甲						0xBBE
#define EQUMENT_ID_轻灵之靴							0xBC1
#define EQUMENT_ID_明朗之靴							0xC56
#define EQUMENT_ID_法师之靴							0xBCC
#define EQUMENT_ID_水银之靴							0xC27
#define EQUMENT_ID_忍者足具							0xBE7
#define EQUMENT_ID_冰川护甲							0xBD0
#define EQUMENT_ID_守望者铠甲						0xC0A
#define EQUMENT_ID_冰霜之心							0xC26
#define EQUMENT_ID_冰脉护手							0xBD1
#define EQUMENT_ID_红水晶							0x400
#define EQUMENT_ID_锁子甲							0x407
#define EQUMENT_ID_亡者的板甲						0xE9E
#define EQUMENT_ID_兰顿之兆							0xC47
#define EQUMENT_ID_斑比的熔渣						0xEA7
#define EQUMENT_ID_日炎斗篷							0xBFC
#define EQUMENT_ID_燃烧宝石							0xBFB
#define EQUMENT_ID_晶体护腕							0xED9
#define EQUMENT_ID_狂徒铠甲							0xC0B
#define EQUMENT_ID_幽魂斗篷							0xC8B
#define EQUMENT_ID_振奋铠甲							0xBF9
#define EQUMENT_ID_军团护盾							0xC21
#define EQUMENT_ID_钢铁烈阳之匣						0xC76
#define EQUMENT_ID_女妖面纱							0xC1E
#define EQUMENT_ID_猛禽斗篷							0x805
#define EQUMENT_ID_传送门							0xDB8

////////Other//////////////////////////////////////////////////////////////////

#define VARIABLE_ID_MAINTHREADID					0x0
#define VARIABLE_ID_TIMERID							0x1


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

struct RoundPoint
{
	Point Central;
	float fRange;
};

enum em_Human_Type
{
	em_Human_Type_Solider,
	em_Human_Type_Turret,
	em_Human_Type_Hero,
	em_Human_Type_Unknow
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
	em_Hero_Pro_None,			// 未知
	em_Hero_Pro_Ryze,			// 流浪法师
	em_Hero_Pro_Ashe,			// 寒冰射手
	em_Hero_Pro_MasterYi,		// 无极剑圣
	em_Hero_Pro_MissFortune,	// 赏金猎人
	em_Hero_Pro_Garen,			// 德玛西亚
	em_Hero_Pro_Malzahar,		// 虚空先知
	em_Hero_Pro_Ezreal,			// 探险家
	em_Hero_Pro_Chogath,		// 虚空恐惧
	em_Hero_Pro_Nunu,			// 雪人骑士
	em_Hero_Pro_Heimerdinger,	// 大发明家
	em_Hero_Pro_Graves,			// 法外狂徒
	em_Hero_Pro_Swain,			// 策士统领
	em_Hero_Pro_Vayne,			// 暗夜猎手
	em_Hero_Pro_Maokai,			// 扭曲树精
	em_Hero_Pro_Veigar,			// 邪恶小法师
	em_Hero_Pro_Sejuani,		// 凛冬之怒
	em_Hero_Pro_Tristana,		// 麦林炮手
	em_Hero_Pro_Galio,			// 哨兵之殇
	em_Hero_Pro_Lucian,			// 圣枪游侠
	em_Hero_Pro_Trundle,		// 巨魔之王
	em_Hero_Pro_Aatrox,			// 暗裔剑魔
	em_Hero_Pro_Taric,			// 宝石骑士
	em_Hero_Pro_Rumble,			// 机械公敌
	em_Hero_Pro_Diana,			// 皎洁女神
	em_Hero_Pro_Urgot,			// 首领之傲
	em_Hero_Pro_Teemo,			// 迅捷斥候
	em_Hero_Pro_Caitlyn,		// 皮城女警
	em_Hero_Pro_Corki,			// 英勇投弹手
	em_Hero_Pro_Fiora,			// 无双剑姬
	em_Hero_Pro_Mordekaiser,	// 铁铠冥魂
	em_Hero_Pro_Nautilus,		// 深海泰坦
	em_Hero_Pro_Sivir,			// 战争女神
	em_Hero_Pro_KogMaw,			// 深渊巨口
	em_Hero_Pro_Annie,			// 黑暗之女
	em_Hero_Pro_Akali,			// 阿卡丽
	em_Hero_Pro_Alistar,		// 牛头酋长
	em_Hero_Pro_Amumu,			// 殇之木乃伊
	em_Hero_Pro_Blitzcrank,		// 蒸汽机器人
	em_Hero_Pro_Brand,			// 复仇焰魂
	em_Hero_Pro_Cassiopeia,		// 魔蛇之拥
	em_Hero_Pro_Darius,			// 诺克萨斯之手
	em_Hero_Pro_DrMundo,		// 蒙多
	em_Hero_Pro_Ekko,			// 艾克
	em_Hero_Pro_FiddleSticks,	// 末日使者
	em_Hero_Pro_Fizz,			// 潮汐海灵
	em_Hero_Pro_Gragas,			// 酒桶
	em_Hero_Pro_Illaoi,			// 海兽祭司
	em_Hero_Pro_Itrlia,			// 刀锋意志
	em_Hero_Pro_JarvanIV,		// 德玛西亚皇子
	em_Hero_Pro_Jax,			// 武器大师
	em_Hero_Pro_Jhin,			// 戏命师
	em_Hero_Pro_Jinx,			// 暴走萝莉
	em_Hero_Pro_Karma,			// 天启者
	em_Hero_Pro_Katarina,		// 不详之刃
	em_Hero_Pro_Leona,			// 曙光女神
	em_Hero_Pro_Lux,			// 光辉女郎
	em_Hero_Pro_Malphite,		// 熔岩巨兽
	em_Hero_Pro_MonkeyKing,		// 齐天大圣
	em_Hero_Pro_Morgana,		// 堕落天使
	em_Hero_Pro_Nasus,			// 沙漠死神
	em_Hero_Pro_Olaf,			// 狂战士
	em_Hero_Pro_Sion,			// 亡灵战神
	em_Hero_Pro_Poppy,			// 圣锤之毅
	em_Hero_Pro_Rammus,			// 披甲龙龟
	em_Hero_Pro_Renekton,		// 荒漠屠夫
	em_Hero_Pro_Sona,			// 琴瑟仙女
	em_Hero_Pro_Velkoz,			// 虚空之眼
	em_Hero_Pro_XinZhao,		// 德邦总管
	em_Hero_Pro_Ziggs,			// 爆破鬼才
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