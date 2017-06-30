#pragma once
#include "afxcmn.h"
#include "Source.h"

// CCustomer dialog

class CCustomer : public CDialogEx
{
	DECLARE_DYNAMIC(CCustomer)

public:
	CCustomer(CWnd* pParent = NULL);   // standard constructor
	virtual ~CCustomer();
	virtual BOOL OnInitDialog();
	void SetCompany(Company* company, int number);
// Dialog Data
	enum { IDD = IDD_DIALOG5 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton2();
	CListCtrl m_CustomerList;
private:
	Company* m_company;
	int m_company_number;
};
