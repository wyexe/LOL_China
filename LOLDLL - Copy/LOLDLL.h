// LOLDLL.h : main header file for the LOLDLL DLL
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CLOLDLLApp
// See LOLDLL.cpp for the implementation of this class
//

class CLOLDLLApp : public CWinApp
{
public:
	CLOLDLLApp();

// Overrides
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
