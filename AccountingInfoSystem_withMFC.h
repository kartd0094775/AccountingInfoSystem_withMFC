
// AccountingInfoSystem_withMFC.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CAccountingInfoSystem_withMFCApp:
// See AccountingInfoSystem_withMFC.cpp for the implementation of this class
//

class CAccountingInfoSystem_withMFCApp : public CWinApp
{
public:
	CAccountingInfoSystem_withMFCApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
	afx_msg void OnFileSave();
};

extern CAccountingInfoSystem_withMFCApp theApp;