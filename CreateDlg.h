#pragma once
#include "afxwin.h"


// CCreateDlg dialog

class CCreateDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CCreateDlg)

public:
	CCreateDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CCreateDlg();

// Dialog Data
	enum { IDD = IDD_CreateDIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	
	bool isEmpty;

	afx_msg void OnBnClickedOk();
	CString m_name;
	UINT m_assets;
	UINT m_liabilities;
};
