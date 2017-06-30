// CreateDlg.cpp : implementation file
//

#include "stdafx.h"
#include "AccountingInfoSystem_withMFC.h"
#include "CreateDlg.h"
#include "afxdialogex.h"


// CCreateDlg dialog

IMPLEMENT_DYNAMIC(CCreateDlg, CDialogEx)

CCreateDlg::CCreateDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CCreateDlg::IDD, pParent)
	, m_name(_T(""))
	, m_assets(0)
	, m_liabilities(0)
{
	isEmpty = true;
}

CCreateDlg::~CCreateDlg()
{
}

void CCreateDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	DDX_Text(pDX, IDC_EDIT1, m_name);
	DDX_Text(pDX, IDC_EDIT2, m_assets);
	DDX_Text(pDX, IDC_EDIT3, m_liabilities);

}


BEGIN_MESSAGE_MAP(CCreateDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CCreateDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CCreateDlg message handlers


void CCreateDlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	if (m_name != _T("")) { isEmpty = false; }
	CDialogEx::OnOK();
}
