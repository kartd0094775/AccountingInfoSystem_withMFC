
// AccountingInfoSystem_withMFCDlg.h : header file
//

#pragma once
#include "afxcmn.h"
#include "afxwin.h"
#include "Source.h"
#include "CreateDlg.h"
#include "Employee.h"
#include "Material.h"
#include "Product.h"
#include "About.h"
#include "GeneralLedger.h"
#include "Bill.h"
#include "Customer.h"
#include "EmployeeF.h"
#include "Product_F.h"
#include "Order.h"
#include "Order_F.h"




// CAccountingInfoSystem_withMFCDlg dialog
class CAccountingInfoSystem_withMFCDlg : public CDialogEx
{
// Construction
public:
	CAccountingInfoSystem_withMFCDlg(CWnd* pParent = NULL);	// standard constructor
	
// Dialog Data
	enum { IDD = IDD_ACCOUNTINGINFOSYSTEM_WITHMFC_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;


	CCreateDlg* m_CreateDlg;
	CEmployee* m_EmployeeDlg;
	CMaterial* m_Material;
	CProduct* m_Product;
	COrder* m_Order;
	CAbout* m_About;

	CGeneralLedger* m_GeneralLedger_Function;
	CBill* m_Bill_Function;
	CProduct_F* m_Inventory_Function;
	COrder_F* m_Order_Function;
	CCustomer* m_Customer_Function;
	CEmployeeF* m_Employee_Function;
	

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:


	afx_msg void OnBnClickedButton1();
	int m_company_number;
	Company* m_company;
	int selected;
	CString m_name;
	UINT m_assets;
	UINT m_liabilities;
	UINT m_revenue;
	UINT m_expenses;
	afx_msg void OnBnClickedButton3();
	// The List Control of Employee 
	CListCtrl m_EmployeeList;
	afx_msg void OnBnClickedButton4();
	// The List Control of the Materials
	CListCtrl m_MaterialList;
	// The List Control of the Product
	CListCtrl m_ProductList;
	afx_msg void OnBnClickedButton5();
	afx_msg void OnFileOpen();
// function
	void readFile(char* filename);
	void display_company();

	// The combo box of the company name

	// The combo box of the company name
	CComboBox m_NameComboBox;
	afx_msg void OnCbnSelendokCombo1();
	afx_msg void OnHelpAbout();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedButton10();
	afx_msg void OnBnClickedButton11();
	afx_msg void OnBnClickedButton12();

	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton16();
	afx_msg void OnFileSave();
	afx_msg void OnBnClickedButton13();
	afx_msg void OnBnClickedButton14();
	afx_msg void OnBnClickedButton15();
};
