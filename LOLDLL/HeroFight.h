#ifndef __LOL_CHINA_LOLDLL_GAME_FIGHT_HEROFIGHT_H__
#define __LOL_CHINA_LOLDLL_GAME_FIGHT_HEROFIGHT_H__

#include "GameVariable.h"

class CSolider;
class CHero;
class CSkillServices;
class CHeroFight
{
private:
	struct tagHeroPtr
	{
		em_Hero_Pro emHeroPro;
		std::function<BOOL(CONST CHero&)> Worker;
	};
public:
	CHeroFight(_In_ CSkillServices* pCSkillServices_);
	~CHeroFight();

	static CHeroFight& GetInstance();

	BOOL KillSolider(_In_ CONST CSolider& Solider, _In_ BOOL bQ, _In_ BOOL bW, _In_ BOOL bE) CONST;
	BOOL KillSolider(_In_ CONST CSolider& Solider) CONST;

	BOOL KillHero(_In_ CONST CHero& EnemyHero) CONST;
private:
	auto ExistHeroWorker(_In_ em_Hero_Pro emHeroPro) CONST ->CONST tagHeroPtr*;
private:
	// 瑞兹
	BOOL Hero_Ryze(_In_ CONST CHero& EnemyHero) CONST;
	// 寒冰射手
	BOOL Hero_Ashe(_In_ CONST CHero& EnemyHero) CONST;
	// 无极剑圣
	BOOL Hero_MasterYi(_In_ CONST CHero& EnemyHero) CONST;
	// 赏金猎人
	BOOL Hero_MissFortune(_In_ CONST CHero& EnemyHero) CONST;
	// 德玛西亚
	BOOL Hero_Garen(_In_ CONST CHero& EnemyHero) CONST;
	// 虚空先知
	BOOL Hero_Malzahar(_In_ CONST CHero& EnemyHero) CONST;
	// 探险家
	BOOL Hero_Ezreal(_In_ CONST CHero& EnemyHero) CONST;
	// 虚空恐惧
	BOOL Hero_Chogath(_In_ CONST CHero& EnemyHero) CONST;
	// 雪人骑士
	BOOL Hero_Nunu(_In_ CONST CHero& EnemyHero) CONST;
	// 大发明家
	BOOL Hero_Heimerdinger(_In_ CONST CHero& EnemyHero) CONST;
	// 法外狂徒
	BOOL Hero_Graves(_In_ CONST CHero& EnemyHero) CONST;
	// 策士统领
	BOOL Hero_Swain(_In_ CONST CHero& EnemyHero) CONST;
	// 暗夜猎手
	BOOL Hero_Vayne(_In_ CONST CHero& EnemyHero) CONST;
	// 扭曲树精
	BOOL Hero_Maokai(_In_ CONST CHero& EnemyHero) CONST;
	// 邪恶小法师
	BOOL Hero_Veigar(_In_ CONST CHero& EnemyHero) CONST;
	// 凛冬之怒
	BOOL Hero_Sejuani(_In_ CONST CHero& EnemyHero) CONST;
	// 麦林炮手
	BOOL Hero_Tristana(_In_ CONST CHero& EnemyHero) CONST;
	// 哨兵之殇
	BOOL Hero_Galio(_In_ CONST CHero& EnemyHero) CONST;
	// 圣枪游侠
	BOOL Hero_Lucian(_In_ CONST CHero& EnemyHero) CONST;
	// 巨魔之王
	BOOL Hero_Trundle(_In_ CONST CHero& EnemyHero) CONST;
	// 暗裔剑魔
	BOOL Hero_Aatrox(_In_ CONST CHero& EnemyHero) CONST;
	// 宝石骑士
	BOOL Hero_Taric(_In_ CONST CHero& EnemyHero) CONST;
	// 机械公敌
	BOOL Hero_Rumble(_In_ CONST CHero& EnemyHero) CONST;
	// 皎洁女神
	BOOL Hero_Diana(_In_ CONST CHero& EnemyHero) CONST;
	// 首领之傲
	BOOL Hero_Urgot(_In_ CONST CHero& EnemyHero) CONST;
	// 迅捷斥候
	BOOL Hero_Teemo(_In_ CONST CHero& EnemyHero) CONST;
	// 皮城女警
	BOOL Hero_Caitlyn(_In_ CONST CHero& EnemyHero) CONST;
	// 英勇投弹手
	BOOL Hero_Corki(_In_ CONST CHero& EnemyHero) CONST;
	// 无双剑姬
	BOOL Hero_Fiora(_In_ CONST CHero& EnemyHero) CONST;
	// 铁铠冥魂
	BOOL Hero_Mordekaiser(_In_ CONST CHero& EnemyHero) CONST;
	// 深海泰坦
	BOOL Hero_Nautilus(_In_ CONST CHero& EnemyHero) CONST;
	// 战争女神
	BOOL Hero_Sivir(_In_ CONST CHero& EnemyHero) CONST;
	// 深渊巨口
	BOOL Hero_KogMaw(_In_ CONST CHero& EnemyHero) CONST;
	// 黑暗之女
	BOOL Hero_Annie(_In_ CONST CHero& EnemyHero) CONST;
	// 阿卡丽
	BOOL Hero_Akali(_In_ CONST CHero& EnemyHero) CONST;
	// 牛头酋长
	BOOL Hero_Alistar(_In_ CONST CHero& EnemyHero) CONST;
	// 殇之木乃伊
	BOOL Hero_Amumu(_In_ CONST CHero& EnemyHero) CONST;
	// 蒸汽机器人
	BOOL Hero_Blitzcrank(_In_ CONST CHero& EnemyHero) CONST;
	// 复仇焰魂
	BOOL Hero_Brand(_In_ CONST CHero& EnemyHero) CONST;
	// 魔蛇之拥
	BOOL Hero_Cassiopeia(_In_ CONST CHero& EnemyHero) CONST;
	// 诺克萨斯之手
	BOOL Hero_Darius(_In_ CONST CHero& EnemyHero) CONST;
	// 蒙多
	BOOL Hero_DrMundo(_In_ CONST CHero& EnemyHero) CONST;
	// 艾克
	BOOL Hero_Ekko(_In_ CONST CHero& EnemyHero) CONST;
	// 末日使者
	BOOL Hero_FiddleSticks(_In_ CONST CHero& EnemyHero) CONST;
	// 潮汐海灵
	BOOL Hero_Fizz(_In_ CONST CHero& EnemyHero) CONST;
	// 酒桶
	BOOL Hero_Gragas(_In_ CONST CHero& EnemyHero) CONST;
	// 海兽祭司
	BOOL Hero_Illaoi(_In_ CONST CHero& EnemyHero) CONST;
	// 刀锋意志
	BOOL Hero_Itrlia(_In_ CONST CHero& EnemyHero) CONST;
	// 德玛西亚皇子
	BOOL Hero_JarvanIV(_In_ CONST CHero& EnemyHero) CONST;
	// 武器大师
	BOOL Hero_Jax(_In_ CONST CHero& EnemyHero) CONST;
	// 戏命师
	BOOL Hero_Jhin(_In_ CONST CHero& EnemyHero) CONST;
	// 暴走萝莉
	BOOL Hero_Jinx(_In_ CONST CHero& EnemyHero) CONST;
	// 天启者
	BOOL Hero_Karma(_In_ CONST CHero& EnemyHero) CONST;
	// 不祥之刃
	BOOL Hero_Katarina(_In_ CONST CHero& EnemyHero) CONST;
	// 曙光女神
	BOOL Hero_Leona(_In_ CONST CHero& EnemyHero) CONST;
	// 光辉女郎
	BOOL Hero_Lux(_In_ CONST CHero& EnemyHero) CONST;
	// 熔岩巨兽
	BOOL Hero_Malphite(_In_ CONST CHero& EnemyHero) CONST;
	// 齐天大圣
	BOOL Hero_MonkeyKing(_In_ CONST CHero& EnemyHero) CONST;
	// 堕落天使
	BOOL Hero_Morgana(_In_ CONST CHero& EnemyHero) CONST;
	// 沙漠死神
	BOOL Hero_Nasus(_In_ CONST CHero& EnemyHero) CONST;
	// 狂战士
	BOOL Hero_Olaf(_In_ CONST CHero& EnemyHero) CONST;
	// 亡灵战神
	BOOL Hero_Sion(_In_ CONST CHero& EnemyHero) CONST;
	// 圣锤之毅
	BOOL Hero_Poppy(_In_ CONST CHero& EnemyHero) CONST;
	// 披甲龙龟
	BOOL Hero_Rammus(_In_ CONST CHero& EnemyHero) CONST;
	// 荒漠屠夫
	BOOL Hero_Renekton(_In_ CONST CHero& EnemyHero) CONST;
	// 琴瑟仙女
	BOOL Hero_Sona(_In_ CONST CHero& EnemyHero) CONST;
	// 虚空之眼
	BOOL Hero_Velkoz(_In_ CONST CHero& EnemyHero) CONST;
	// 德邦总管
	BOOL Hero_XinZhao(_In_ CONST CHero& EnemyHero) CONST;
	// 爆破鬼才
	BOOL Hero_Ziggs(_In_ CONST CHero& EnemyHero) CONST;
private:
	CSkillServices* pSkillServices;
private:
	DSIABLE_COPY_AND_ASSIGN(CHeroFight);
};



#endif