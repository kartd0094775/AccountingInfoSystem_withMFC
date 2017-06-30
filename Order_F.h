#pragma once
#include "afxwin.h"
#include "afxcmn.h"
#include "Source.h"

// COrder_F dialog

class COrder_F : public CDialogEx
{
	DECLARE_DYNAMIC(COrder_F)

public:
	COrder_F(CWnd* pParent = NULL);   // standard constructor
	virtual ~COrder_F();
	virtual BOOL OnInitDialog();
	void SetOrder(Company* company, int company_number);
	void DisplaySelOrder(int index);
// Dialog Data
	enum { IDD = IDD_DIALOG4 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CComboBox m_CustomerCombo;
	CString m_company_name;
	CString m_address;
	CString m_expectedDate;
	CListCtrl m_OrderList;
	afx_msg void OnBnClickedButton1();
private:
	Order* m_order;
	int m_order_number;
public:
	afx_msg void OnCbnSelendokCombo2();
};
