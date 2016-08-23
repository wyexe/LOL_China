#include "stdafx.h"
#include "ObjectExtend.h"
#include <MyTools/CLPublic.h>
#include "Equment.h"
#include "HeroBuff.h"
CObjectExtend::CObjectExtend()
{
}

CObjectExtend::~CObjectExtend()
{
}

CObjectExtend& CObjectExtend::GetInstance()
{
	static CObjectExtend ObjectExtend;
	return ObjectExtend;
}

VOID CObjectExtend::AbstractClass()
{

}

BOOL CObjectExtend::ExistEqumentByCondition(_Out_ CEqument* pEqument, _In_ std::function<BOOL(CONST CEqument&)> Finder) CONST
{
	vector<CEqument> vlst;
	GetCurrentHeroEqumentList(vlst);
	return CLPublic::Vec_find_if(vlst, pEqument, Finder);
}

BOOL CObjectExtend::ExistEqumentById(_In_ DWORD dwEqumentId, _Out_ CEqument* pEqument) CONST
{
	return ExistEqumentByCondition(pEqument, [&dwEqumentId](CONST auto& itm) {
		return itm.GetId() == dwEqumentId;
	});
}

BOOL CObjectExtend::ExistHeroBuffByCondition(_Out_ CHeroBuff* pHeroBuff, _In_ std::function<BOOL(CONST CHeroBuff&)> Finder) CONST
{
	vector<CHeroBuff> vlst;
	GetCurrentHeroBuffList(vlst);
	return CLPublic::Vec_find_if(vlst, pHeroBuff, Finder);
}

BOOL CObjectExtend::ExistBuffById(_In_ DWORD dwBuffId, _Out_ CHeroBuff* pHeroBuff) CONST
{
	return ExistHeroBuffByCondition(pHeroBuff, [&dwBuffId](CONST auto& itm) {
		return itm.GetId() == dwBuffId;
	});
}
