#pragma once
#include "Source.h"
#include "afxcmn.h"

// CBill dialog

class CBill : public CDialogEx
{
	DECLARE_DYNAMIC(CBill)

public:
	CBill(CWnd* pParent = NULL);   // standard constructor
	virtual ~CBill();
	virtual BOOL OnInitDialog();
	void SetCompany(Company* company, int number);
// Dialog Data
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
private:
	Company* m_company;
	int m_company_number;
public:
	CListCtrl m_BillList;
};
