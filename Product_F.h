#pragma once
#include "afxwin.h"
#include "afxcmn.h"
#include "Source.h"

// CProduct_F dialog

class CProduct_F : public CDialogEx
{
	DECLARE_DYNAMIC(CProduct_F)

public:
	CProduct_F(CWnd* pParent = NULL);   // standard constructor
	virtual ~CProduct_F();
	virtual BOOL OnInitDialog();
	void SetProduct(Company* company, int company_number);
	void DisplaySelProduct(int index);
// Dialog Data
	enum { IDD = IDD_DIALOG3 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	UINT m_number;
	UINT m_price;
	CString m_date;
	CString m_company_name;
	CListCtrl m_MaterialList;
private:
	Product* m_product;
	int m_product_number;
public:
	afx_msg void OnBnClickedButton1();
	UINT m_produced_number;

	afx_msg void OnCbnSelendokCombo1();


	CComboBox m_ProductCombo;
};
