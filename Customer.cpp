// Customer.cpp : implementation file
//

#include "stdafx.h"
#include "AccountingInfoSystem_withMFC.h"
#include "Customer.h"
#include "afxdialogex.h"


// CCustomer dialog

IMPLEMENT_DYNAMIC(CCustomer, CDialogEx)

CCustomer::CCustomer(CWnd* pParent /*=NULL*/)
	: CDialogEx(CCustomer::IDD, pParent)
{

}
BOOL CCustomer::OnInitDialog() {
	BOOL ret = __super::OnInitDialog();
	m_CustomerList.InsertColumn(0, _T("Customer"), LVCFMT_LEFT, 90);
	m_CustomerList.InsertColumn(1, _T("Company"), LVCFMT_LEFT, 60);
	m_CustomerList.InsertColumn(2, _T("Address"), LVCFMT_LEFT, 120);
	m_CustomerList.InsertColumn(3, _T("Order Date"), LVCFMT_LEFT, 90);
	DWORD dwStyle;
	dwStyle = m_CustomerList.GetExtendedStyle();
	dwStyle |= LVS_EX_FULLROWSELECT;
	dwStyle |= LVS_EX_GRIDLINES;
	m_CustomerList.SetExtendedStyle(dwStyle);
	Company* company;
	for (int i = 0; i < m_company_number; i++) {
		company = m_company + i;
		CString company_name = (CString)company->get_name();
		for (int j = 0; j < company->get_order_number(); j++) {
			CString name = (CString)company->get_order(j)->get_customer();
			CString address = (CString)company->get_order(j)->get_address();
			CString date = (CString)company->get_order(j)->get_expectedDate();

			int nindex = m_CustomerList.InsertItem(0, name);
			m_CustomerList.SetItemText(nindex, 1, company_name);
			m_CustomerList.SetItemText(nindex, 2, address);
			m_CustomerList.SetItemText(nindex, 3, date);
		}

	}
	return ret;
}
CCustomer::~CCustomer()
{
}

void CCustomer::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_CustomerList);
}


BEGIN_MESSAGE_MAP(CCustomer, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON2, &CCustomer::OnBnClickedButton2)
END_MESSAGE_MAP()


// CCustomer message handlers


void CCustomer::OnBnClickedButton2()
{
	CDialogEx::OnOK();
	// TODO: Add your control notification handler code here
}
void CCustomer::SetCompany(Company* company, int number) {
	m_company = new Company[number];
	m_company = company;
	m_company_number = number;
}
