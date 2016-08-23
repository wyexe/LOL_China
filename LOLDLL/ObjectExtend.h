#ifndef __LOL_CHINA_LOLDLL_GAME_OBJECTSERVICES_OBJECTFUNCTION_H__
#define __LOL_CHINA_LOLDLL_GAME_OBJECTSERVICES_OBJECTFUNCTION_H__

#include "ObjectTraverse.h"

class CObjectExtend : public CObjectTraverse
{
public:
	CObjectExtend();
	~CObjectExtend();

	static CObjectExtend& GetInstance();

	// 只能被继承类实例化!
	virtual VOID AbstractClass();
public:
	// 条件遍历装备
	BOOL ExistEqumentByCondition(_Out_ CEqument* pEqument ,_In_ std::function<BOOL(CONST CEqument&)> Finder) CONST;

	// 根据ID判断是否存在装备
	BOOL ExistEqumentById(_In_ DWORD dwEqumentId, _Out_ CEqument* pEqument) CONST;

	// 条件遍历Buff
	BOOL ExistHeroBuffByCondition(_Out_ CHeroBuff* pHeroBuff, _In_ std::function<BOOL(CONST CHeroBuff&)> Finder) CONST;

	// 根据BUFFID判断是否存在buff
	BOOL ExistBuffById(_In_ DWORD dwBuffId, _Out_ CHeroBuff* pHeroBuff) CONST;
private:
	DSIABLE_COPY_AND_ASSIGN(CObjectExtend);
};



#endif