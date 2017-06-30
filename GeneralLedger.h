#pragma once
#include "Source.h"
#include "afxcmn.h"

// CGeneralLedger dialog

class CGeneralLedger : public CDialogEx
{
	DECLARE_DYNAMIC(CGeneralLedger)

public:
	CGeneralLedger(CWnd* pParent = NULL);   // standard constructor
	virtual ~CGeneralLedger();
	virtual BOOL OnInitDialog();
	void SetCompany(Company* company, int company_number);
	Company* m_company;
	int m_company_number;
// Dialog Data
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_LedgerList;
	afx_msg void OnBnClickedButton1();
};
