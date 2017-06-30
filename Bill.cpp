// Bill.cpp : implementation file
//

#include "stdafx.h"
#include "AccountingInfoSystem_withMFC.h"
#include "Bill.h"
#include "afxdialogex.h"


// CBill dialog

IMPLEMENT_DYNAMIC(CBill, CDialogEx)

CBill::CBill(CWnd* pParent /*=NULL*/)
	: CDialogEx(CBill::IDD, pParent)
{

}
BOOL CBill::OnInitDialog() {
	BOOL ret = __super::OnInitDialog();
	m_BillList.InsertColumn(0, _T("Product"), LVCFMT_LEFT, 90);
	m_BillList.InsertColumn(1, _T("Company"), LVCFMT_LEFT, 60);
	m_BillList.InsertColumn(2, _T("Number"), LVCFMT_LEFT, 60);
	m_BillList.InsertColumn(3, _T("Price"), LVCFMT_LEFT, 60);
	m_BillList.InsertColumn(4, _T("Record Date"), LVCFMT_LEFT, 90);
	DWORD dwStyle;
	dwStyle = m_BillList.GetExtendedStyle();
	dwStyle |= LVS_EX_FULLROWSELECT;
	dwStyle |= LVS_EX_GRIDLINES;
	m_BillList.SetExtendedStyle(dwStyle);
	Company* company;
	for (int i = 0; i < m_company_number; i++) {
		company = m_company + i;
		CString company_name = (CString)company->get_name();
		for (int j = 0; j < company->get_material_type_number(); j++) {
			CString name = (CString)company->get_material(j)->get_name();
			CString number;
			number.Format(_T("%u"), *company->get_material(j)->get_number());
			CString price;
			price.Format(_T("%u"), *company->get_material(j)->get_price());
			CString date = (CString)company->get_material(j)->get_date();

			int nindex = m_BillList.InsertItem(0, name);
			m_BillList.SetItemText(nindex, 1, company_name);
			m_BillList.SetItemText(nindex, 2, number);
			m_BillList.SetItemText(nindex, 3, price);
			m_BillList.SetItemText(nindex, 4, date);
		}

	}
	return ret;
}
CBill::~CBill()
{
}

void CBill::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_BillList);
}


BEGIN_MESSAGE_MAP(CBill, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CBill::OnBnClickedButton1)
END_MESSAGE_MAP()


// CBill message handlers


void CBill::OnBnClickedButton1()
{
	CDialogEx::OnOK();
	// TODO: Add your control notification handler code here
}

void CBill::SetCompany(Company* company, int number) {
	m_company = new Company[number];
	m_company = company;
	m_company_number = number;
	
}
