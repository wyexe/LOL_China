#include "stdafx.h"
#include "GameInit.h"
#include <MyTools/CLLog.h>
#include <MyTools/CLThread.h>
#define _SELF L"GameInit.cpp"
CGameInit::CGameInit()
{
}

CGameInit::~CGameInit()
{
}

CGameInit& CGameInit::GetInstance()
{
	static CGameInit CGameInit_;
	return CGameInit_;
}

BOOL CALLBACK EnumSetWinName(HWND h, LPARAM l)
{
	if (IsWindow(h) && IsWindowVisible(h) && (GetWindowLong(h, GWL_EXSTYLE)&WS_EX_TOOLWINDOW) != WS_EX_TOOLWINDOW && (GetWindowLong(h, GWL_HWNDPARENT) == 0))
	{
		WCHAR wszWinText[64] = { 0 };
		WCHAR wszWinClass[64] = { 0 };
		if (GetClassNameW(h, wszWinClass, sizeof(wszWinClass) / sizeof(WCHAR)) > 0 && GetWindowTextW(h, wszWinText, sizeof(wszWinText) / sizeof(WCHAR)) > 0)
		{
			if (CCharacter::wstrcmp_my(wszWinClass, L"RiotWindowClass"))//如果能遍历到这个,并且是
			{
				DWORD PID;
				::GetWindowThreadProcessId(h, &PID);
				if (PID == ::GetCurrentProcessId())
				{
					Log(LOG_LEVEL_NORMAL, L"成功枚举到本窗口");
					CGameVariable::GetInstance().GetMemShareAccGameInfo()->hGameWnd = h;
					return false;
				}
			}
		}
	}
	return true;
}

void CALLBACK TimerProc(HWND hWnd, UINT nMsg, UINT nTimerid, DWORD dwTime)
{
	if (nTimerid != 0x1000)
		return;

	CGameVariable::GetInstance().DoMainThreadActionPtr([](_In_ std::queue<CGameVariable::MainThreadActionPtrInfo>& vQueue) {
		if (!vQueue.empty())
		{
			auto& FunPtr = vQueue.front();
			FunPtr.Worker();
			if (FunPtr.hEvent != NULL)
				::SetEvent(FunPtr.hEvent);
			vQueue.pop();
		}
	});
}

BOOL CGameInit::InitTimer() CONST
{
	if (CGameVariable::GetInstance().GetMemShareAccGameInfo() == nullptr)
	{
		CGameVariable::GetInstance().GetMemShareInfo() = new Shared_Info;
		CGameVariable::GetInstance().GetMemShareAccGameInfo() = new Account_Info_Game;
		ZeroMemory(CGameVariable::GetInstance().GetMemShareInfo(), sizeof(Shared_Info));
		ZeroMemory(CGameVariable::GetInstance().GetMemShareAccGameInfo(), sizeof(Account_Info_Game));

		Log(LOG_LEVEL_NORMAL, L"正在枚举窗口……");
		while (EnumWindows((WNDENUMPROC)EnumSetWinName, NULL))
			::Sleep(1000);

	}

	CGameVariable::GetInstance().SetVariableAndGetOldValueByID(VARIABLE_ID_MAINTHREADID, CLThread::GetMainThreadId());

	auto dwTimerId = ::SetTimer(CGameVariable::GetInstance().GetMemShareAccGameInfo()->hGameWnd, 0x1000, 100, TimerProc);
	if (dwTimerId == NULL)
	{
		LogMsgBox(LOG_LEVEL_NORMAL, L"SetTimer Faild! Err=%X,hWnd=%X", ::GetLastError(), CGameVariable::GetInstance().GetMemShareAccGameInfo()->hGameWnd);
		return FALSE;
	}
	CGameVariable::GetInstance().SetVariableAndGetOldValueByID(VARIABLE_ID_TIMERID, dwTimerId);
	return TRUE;
}
