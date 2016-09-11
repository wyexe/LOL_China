// LOLDLL.cpp : Defines the initialization routines for the DLL.
//

#include "stdafx.h"
#include "LOLDLL.h"
#include <thread>
#include "GameDlg.h"
#include <MyTools/ToolsPublic.h>
#include "GameVariable.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//
//TODO: If this DLL is dynamically linked against the MFC DLLs,
//		any functions exported from this DLL which call into
//		MFC must have the AFX_MANAGE_STATE macro added at the
//		very beginning of the function.
//
//		For example:
//
//		extern "C" BOOL PASCAL EXPORT ExportedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// normal function body here
//		}
//
//		It is very important that this macro appear in each
//		function, prior to any calls into MFC.  This means that
//		it must appear as the first statement within the 
//		function, even before any object variable declarations
//		as their constructors may generate calls into the MFC
//		DLL.
//
//		Please see MFC Technical Notes 33 and 58 for additional
//		details.
//

// CLOLDLLApp

BEGIN_MESSAGE_MAP(CLOLDLLApp, CWinApp)
END_MESSAGE_MAP()


// CLOLDLLApp construction

CLOLDLLApp::CLOLDLLApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}


// The one and only CLOLDLLApp object

CLOLDLLApp theApp;


// CLOLDLLApp initialization
unsigned WINAPI _ShowThread(LPVOID lpParm)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	CGameDlg dlg;
	dlg.DoModal();
	return 0;
}

BOOL CLOLDLLApp::InitInstance()
{
	CWinApp::InitInstance();
	static HANDLE hThread = NULL;
	if (hThread == NULL)
	{
		hThread = cbBEGINTHREADEX(NULL, NULL, _ShowThread, NULL, NULL, NULL);
	}
	return TRUE;
}
__declspec(dllexport) BOOL WINAPI ReleaseDLL()
{
	
	return TRUE;
}

int CLOLDLLApp::ExitInstance()
{
	DWORD dwTimerId = CGameVariable::GetInstance().GetVariableByID(VARIABLE_ID_TIMERID);
	if (dwTimerId != NULL)
	{
		::KillTimer(CGameVariable::GetInstance().GetMemShareAccGameInfo()->hGameWnd,dwTimerId);
	}
	if (CGameVariable::GetInstance().GetMemShareAccGameInfo() != nullptr)
	{
		delete CGameVariable::GetInstance().GetMemShareAccGameInfo();
	}
	if (CGameVariable::GetInstance().GetMemShareInfo() != nullptr)
	{
		delete CGameVariable::GetInstance().GetMemShareInfo();
	}
	
	CWinApp::ExitInstance();
	return 1;
}

__declspec(dllexport) int WINAPI BBB(DWORD)
{
	return 0xF;
}