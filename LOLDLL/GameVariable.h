#ifndef __LOL_CHINA_LOLDLL_GAME_VARIABLE_GAMEVARIABLE_H__
#define __LOL_CHINA_LOLDLL_GAME_VARIABLE_GAMEVARIABLE_H__

#include "GameStruct.h"

#define GameRun			(CGameVariable::GetInstance().GetGameRunStatus() == em_GameCmd::em_GameCmd_Start)
#define LOLSleep(x)		CGameVariable::GetInstance().Sleep(x)
#define LOLMove(x,y)	CPerson::GetInstance().Move(x); LOLSleep(y)
#define GameStart		CGameVariable::GetInstance().GetGameRunStatus() = em_GameCmd::em_GameCmd_Start
#define StopGame		CGameVariable::GetInstance().GetGameRunStatus() = em_GameCmd::em_GameCmd_Stop

class CGameVariable
{
public:
	struct MainThreadActionPtrInfo
	{
		std::function<VOID(VOID)>	Worker;
		HANDLE						hEvent;
	};
public:
	CGameVariable() = default;
	~CGameVariable() = default;

	// Get Instance
	static CGameVariable& GetInstance() throw();
public:
	// Get Cutome Variable
	DWORD GetVariableByID(_In_ DWORD VarID) CONST throw();
	DWORD SetVariableAndGetOldValueByID(_In_  DWORD VarID, _In_ DWORD NewValue) CONST throw();
	BOOL  DoEqualVariableByID(_In_  DWORD VarID, _In_ DWORD Value, _In_ std::function<VOID(VOID)> Worker) CONST throw();

	// Get ShareMem
	Shared_Info*& GetMemShareInfo() CONST throw();
	Account_Info_Game*& GetMemShareAccGameInfo() CONST throw();


	// Thread Sync
	BOOL  PushMainThreadActionPtr(_In_ std::function<VOID(VOID)> Worker) CONST throw();
	BOOL  DoMainThreadActionPtr(_In_ std::function<VOID(std::queue<MainThreadActionPtrInfo>&)> Worker) CONST throw();

	BOOL Sleep(_In_ DWORD dwSleepTime) CONST;

	em_GameCmd& GetGameRunStatus() CONST;
private:
	DWORD& GeVariableReferenceByID(_In_ DWORD VarID) CONST throw();
	
private:
	DSIABLE_COPY_AND_ASSIGN(CGameVariable);
};



#endif