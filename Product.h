#pragma once
#include "Source.h"
#include "afxcmn.h"
#include "afxwin.h"

// CProduct dialog

class CProduct : public CDialogEx
{
	DECLARE_DYNAMIC(CProduct)

public:
	CProduct(CWnd* pParent = NULL);   // standard constructor
	virtual ~CProduct();
	bool isEmpty;
	void SetCompany(Company* company);
	void SetProduct(Product* product);

	enum { IDD = IDD_ProductDIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
public:
	char** ret_material;
	int ret_mateiral_number;
	int* ret_material_amount;
	CString m_name;
	UINT m_number;
	UINT m_price;
	afx_msg void OnBnClickedOk();
	CListCtrl m_NeededList;
	CListCtrl m_CurrList;
	CButton m_addButton;
	CButton m_modifiedButton;
	UINT m_material_amount;
	afx_msg void OnBnClickedButton1();
private:
	Company* m_company;
	Product* m_product;
	bool Modified = false;
public:
	afx_msg void OnBnClickedOk2();
};
