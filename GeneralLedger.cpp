// GeneralLedger.cpp : implementation file
//

#include "stdafx.h"
#include "AccountingInfoSystem_withMFC.h"
#include "GeneralLedger.h"
#include "afxdialogex.h"


// CGeneralLedger dialog

IMPLEMENT_DYNAMIC(CGeneralLedger, CDialogEx)

CGeneralLedger::CGeneralLedger(CWnd* pParent /*=NULL*/)
	: CDialogEx(CGeneralLedger::IDD, pParent)
{

}
BOOL CGeneralLedger::OnInitDialog() {
	BOOL ret = __super::OnInitDialog();
	m_LedgerList.InsertColumn(0, _T("Company"), LVCFMT_LEFT, 90);
	m_LedgerList.InsertColumn(1, _T("Assets"), LVCFMT_LEFT, 60);
	m_LedgerList.InsertColumn(2, _T("Liabilities"), LVCFMT_LEFT, 60);
	m_LedgerList.InsertColumn(3, _T("Revenue"), LVCFMT_LEFT, 60);
	m_LedgerList.InsertColumn(4, _T("Expenses"), LVCFMT_LEFT, 60);
	DWORD dwStyle;
	dwStyle = m_LedgerList.GetExtendedStyle();
	dwStyle |= LVS_EX_FULLROWSELECT;
	dwStyle |= LVS_EX_GRIDLINES;
	m_LedgerList.SetExtendedStyle(dwStyle);
	for (int i = 0; i < m_company_number; i++) {
		CString name = (CString)(m_company + i)->get_name();
		CString assets;
		assets.Format(_T("%d"), *(m_company + i)->get_assets());
		CString liabilities;
		liabilities.Format(_T("%d"), *(m_company + i)->get_liabilities());
		CString revenue;
		revenue.Format(_T("%d"), *(m_company + i)->get_revenue());
		CString expenses;
		expenses.Format(_T("%d"), *(m_company + i)->get_expenses());
		int nindex = m_LedgerList.InsertItem(0, name);
		m_LedgerList.SetItemText(nindex, 1, assets);
		m_LedgerList.SetItemText(nindex, 2, liabilities);
		m_LedgerList.SetItemText(nindex, 3, revenue);
		m_LedgerList.SetItemText(nindex, 4, expenses);

	}
	return ret;
}

CGeneralLedger::~CGeneralLedger()
{
	


}

void CGeneralLedger::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_LedgerList);
}
void CGeneralLedger::SetCompany(Company* company, int company_number) {
	m_company = new Company[company_number];
	m_company = company;
	m_company_number = company_number;
}

BEGIN_MESSAGE_MAP(CGeneralLedger, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CGeneralLedger::OnBnClickedButton1)
END_MESSAGE_MAP()


// CGeneralLedger message handlers


void CGeneralLedger::OnBnClickedButton1()

{
	CDialogEx::OnOK();
	// TODO: Add your control notification handler code here
}
