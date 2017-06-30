// Employee.cpp : implementation file
//

#include "stdafx.h"
#include "AccountingInfoSystem_withMFC.h"
#include "Employee.h"
#include "afxdialogex.h"


// CEmployee dialog

IMPLEMENT_DYNAMIC(CEmployee, CDialogEx)

CEmployee::CEmployee(CWnd* pParent /*=NULL*/)
	: CDialogEx(CEmployee::IDD, pParent)
	, m_name(_T(""))
	, m_salary(0)
{
	isEmpty = true;
}
BOOL CEmployee::OnInitDialog() {
	BOOL ret = __super::OnInitDialog();
	if (Modified) {
		m_name = (CString)m_employee->get_name();
		m_salary = *m_employee->get_salary();
		UpdateData(false);
	}
	return ret;
}
CEmployee::~CEmployee()
{
}

void CEmployee::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_name);
	DDX_Text(pDX, IDC_EDIT2, m_salary);
}


BEGIN_MESSAGE_MAP(CEmployee, CDialogEx)
	ON_BN_CLICKED(IDOK, &CEmployee::OnBnClickedOk)
END_MESSAGE_MAP()


// CEmployee message handlers


void CEmployee::OnBnClickedOk()
{
	UpdateData(true);
	if (m_name != _T("")) { isEmpty = false; }
	// TODO: Add your control notification handler code here
	CDialogEx::OnOK();
}
void CEmployee::SetEmployee(Employee* employee) {
	m_employee = employee;
	Modified = true;
}