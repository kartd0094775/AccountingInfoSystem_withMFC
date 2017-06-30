// EmployeeF.cpp : implementation file
//

#include "stdafx.h"
#include "AccountingInfoSystem_withMFC.h"
#include "EmployeeF.h"
#include "afxdialogex.h"


// CEmployeeF dialog

IMPLEMENT_DYNAMIC(CEmployeeF, CDialogEx)

CEmployeeF::CEmployeeF(CWnd* pParent /*=NULL*/)
	: CDialogEx(CEmployeeF::IDD, pParent)
{

}
BOOL CEmployeeF::OnInitDialog() {
	BOOL ret = __super::OnInitDialog();
	m_EmployeeList.InsertColumn(0, _T("Employee"), LVCFMT_LEFT, 90);
	m_EmployeeList.InsertColumn(1, _T("Company"), LVCFMT_LEFT, 60);
	m_EmployeeList.InsertColumn(2, _T("Salary"), LVCFMT_LEFT, 60);
	m_EmployeeList.InsertColumn(3, _T("Record Date"), LVCFMT_LEFT, 90);
	DWORD dwStyle;
	dwStyle = m_EmployeeList.GetExtendedStyle();
	dwStyle |= LVS_EX_FULLROWSELECT;
	dwStyle |= LVS_EX_GRIDLINES;
	m_EmployeeList.SetExtendedStyle(dwStyle);
	Company* company;
	for (int i = 0; i < m_company_number; i++) {
		company = m_company + i;
		CString company_name = (CString)company->get_name();
		for (int j = 0; j < company->get_employee_number(); j++) {
			CString name = (CString)company->get_employee(j)->get_name();
			CString salary;
			salary.Format(_T("%u"), *company->get_employee(j)->get_salary());
			CString date = (CString)company->get_employee(j)->get_date();

			int nindex = m_EmployeeList.InsertItem(0, name);
			m_EmployeeList.SetItemText(nindex, 1, company_name);
			m_EmployeeList.SetItemText(nindex, 2, salary);
			m_EmployeeList.SetItemText(nindex, 3, date);
		}

	}
	return ret;
}
CEmployeeF::~CEmployeeF()
{
}

void CEmployeeF::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_EmployeeList);
}


BEGIN_MESSAGE_MAP(CEmployeeF, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON2, &CEmployeeF::OnBnClickedButton2)
END_MESSAGE_MAP()


// CEmployeeF message handlers


void CEmployeeF::OnBnClickedButton2()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnOK();
}

void CEmployeeF::SetCompany(Company* company, int number) {
	m_company = new Company[number];
	m_company = company;
	m_company_number = number;
}