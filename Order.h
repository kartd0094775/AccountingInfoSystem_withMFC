#pragma once
#include "afxwin.h"
#include "afxdtctl.h"
#include "afxcmn.h"
#include "Source.h"


// COrder dialog

class COrder : public CDialogEx
{
	DECLARE_DYNAMIC(COrder)

public:
	COrder(CWnd* pParent = NULL);   // standard constructor
	virtual ~COrder();
	virtual BOOL OnInitDialog();
	void SetCompany(Company* company);
// Dialog Data
	enum { IDD = IDD_OrderDIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	bool isEmpty;
	CString m_customer;
	CString m_address;
	CString m_date;
	CDateTimeCtrl m_DateCtrl;
	UINT m_number;
	CListCtrl m_OrderList;
	CListCtrl m_ProductList;
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedOk2();
private:
	Company* m_company;
};
