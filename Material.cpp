// Material.cpp : implementation file
//

#include "stdafx.h"
#include "AccountingInfoSystem_withMFC.h"
#include "Material.h"
#include "afxdialogex.h"


// CMaterial dialog

IMPLEMENT_DYNAMIC(CMaterial, CDialogEx)

CMaterial::CMaterial(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMaterial::IDD, pParent)
	, m_name(_T(""))
	, m_number(0)
	, m_price(0)
{
	isEmpty = true;
}
BOOL CMaterial::OnInitDialog() {
	BOOL ret = __super::OnInitDialog();
	if (Modified) {
		m_name = (CString)m_material->get_name();
		m_number = *m_material->get_number();
		m_price = *m_material->get_price();
		UpdateData(false);
	}

	return ret;
}
CMaterial::~CMaterial()
{
}

void CMaterial::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_name);
	DDX_Text(pDX, IDC_EDIT2, m_number);
	DDX_Text(pDX, IDC_EDIT3, m_price);
}


BEGIN_MESSAGE_MAP(CMaterial, CDialogEx)
	ON_BN_CLICKED(IDOK, &CMaterial::OnBnClickedOk)
END_MESSAGE_MAP()


// CMaterial message handlers


void CMaterial::OnBnClickedOk()
{
	UpdateData(true);
	if (m_name != _T("")) { isEmpty = false;  }

	// TODO: Add your control notification handler code here
	CDialogEx::OnOK();
}
void CMaterial::SetMaterial(Material* material) {
	m_material = material;
	Modified = true;

}
