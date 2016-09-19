#include "stdafx.h"
#include "GameVariable.h"
#include <map>
#include <MyTools/CLLock.h>
#include <MyTools/CLLog.h>


#define _SELF L"GameVariable.cpp"

CGameVariable& CGameVariable::GetInstance() throw()
{
	static CGameVariable GameVariable;
	return GameVariable;
}

DWORD& CGameVariable::GeVariableReferenceByID(_In_ DWORD VarID) CONST throw()
{
	static std::map<DWORD, DWORD> GlobalVariableMap;
	static CLLock Lock(L"CGameVariable::GetVariable_By_Name");


	DWORD* pValue = nullptr;
	Lock.Access([&pValue, &VarID]{
		auto& itr = GlobalVariableMap.find(VarID);
		if (itr != GlobalVariableMap.end())
			pValue = &itr->second;
		else
			GlobalVariableMap.insert(map<DWORD, DWORD>::value_type(VarID, 0));
	});

	return pValue != nullptr ? *pValue : GeVariableReferenceByID(VarID);
}

DWORD CGameVariable::GetVariableByID(_In_ DWORD VarID) CONST throw()
{
	// remove referecne
	return GeVariableReferenceByID(VarID);
}

DWORD CGameVariable::SetVariableAndGetOldValueByID(_In_ DWORD VarID, _In_ DWORD NewValue) CONST throw()
{
	auto& dwValue = GeVariableReferenceByID(VarID);
	swap(dwValue, NewValue);
	return NewValue;
}

Shared_Info*& CGameVariable::GetMemShareInfo() CONST throw()
{
	static Shared_Info* p = nullptr;
	return p;
}

Account_Info_Game*& CGameVariable::GetMemShareAccGameInfo() CONST throw()
{
	static Account_Info_Game* p = nullptr;
	return p;
}

BOOL CGameVariable::DoEqualVariableByID(_In_ DWORD VarID, _In_ DWORD Value, _In_ std::function<VOID(VOID)> Worker) CONST throw()
{
	if (GetVariableByID(VarID) == Value)
	{
		Worker();
		return TRUE;
	}
	return FALSE;
}

BOOL CGameVariable::DoMainThreadActionPtr(_In_ std::function<VOID(std::queue<MainThreadActionPtrInfo>&)> Worker) CONST throw()
{
	static std::queue<MainThreadActionPtrInfo> vQueue;
	static CLLock Lock(L"CGameVariable::DoMainThreadActionPtr");

	return Lock.Access([&Worker]{
		Worker(vQueue);
	});
}

BOOL CGameVariable::Sleep(_In_ DWORD dwSleepTime) CONST
{
	for (DWORD i = 0;i < dwSleepTime && GameRun; i += 100)
		::Sleep(i);
	return TRUE;
}


em_GameCmd& CGameVariable::GetGameRunStatus() CONST
{
	static em_GameCmd emGameCmd = em_GameCmd::em_GameCmd_None;
	return emGameCmd;
}

BOOL CGameVariable::PushMainThreadActionPtr(_In_ std::function<VOID(VOID)> Worker) CONST throw()
{
	if (::GetCurrentThreadId() == GetVariableByID(VARIABLE_ID_MAINTHREADID))
	{
		// Current Thread Id was MainThread!!!
		Worker();
		return TRUE;
	}

	HANDLE hEvent = ::CreateEventW(NULL, FALSE, FALSE, NULL);
	if (hEvent == NULL)
	{
		LogMsgBox(LOG_LEVEL_EXCEPTION, L"CreateEventW Error! GetLastError=%d", ::GetLastError());
		return FALSE;
	}
	
	DoMainThreadActionPtr([&hEvent, &Worker](std::queue<MainThreadActionPtrInfo>& ActionPtrQueue){
		ActionPtrQueue.push(MainThreadActionPtrInfo{ Worker, hEvent });
	});

	::WaitForSingleObject(hEvent, INFINITE);
	::CloseHandle(hEvent);
	hEvent = NULL;

	return TRUE;
}

