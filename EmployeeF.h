#pragma once
#include "afxcmn.h"
#include "Source.h"

// CEmployeeF dialog

class CEmployeeF : public CDialogEx
{
	DECLARE_DYNAMIC(CEmployeeF)

public:
	CEmployeeF(CWnd* pParent = NULL);   // standard constructor
	virtual ~CEmployeeF();
	virtual BOOL OnInitDialog();
	void SetCompany(Company* company, int company_number);
// Dialog Data
	enum { IDD = IDD_DIALOG6 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_EmployeeList;

private:
	Company* m_company;
	int m_company_number;
public:
	afx_msg void OnBnClickedButton2();
};
