// Product.cpp : implementation file
//

#include "stdafx.h"
#include "AccountingInfoSystem_withMFC.h"
#include "Product.h"
#include "afxdialogex.h"


// CProduct dialog

IMPLEMENT_DYNAMIC(CProduct, CDialogEx)

CProduct::CProduct(CWnd* pParent /*=NULL*/)
	: CDialogEx(CProduct::IDD, pParent)
	, m_name(_T(""))
	, m_number(0)
	, m_price(0)
	, m_material_amount(0)
{
	isEmpty = true;

}
BOOL CProduct::OnInitDialog() {
	BOOL ret = __super::OnInitDialog();
	m_CurrList.InsertColumn(0, _T("Material"), LVCFMT_FILL, 90);
	m_NeededList.InsertColumn(0, _T("Material"), LVCFMT_LEFT, 60);
	m_NeededList.InsertColumn(1, _T("Number"), LVCFMT_LEFT, 60);
	DWORD dwStyle;
	dwStyle = m_CurrList.GetExtendedStyle();
	dwStyle |= LVS_EX_FULLROWSELECT;
	dwStyle |= LVS_EX_GRIDLINES;
	m_CurrList.SetExtendedStyle(dwStyle);
	m_NeededList.SetExtendedStyle(dwStyle);
	Material* material;
	for (int i = 0; i < m_company->get_material_type_number(); i++) {
		material = m_company->get_material(i);
		m_CurrList.InsertItem(0, (CString)material->get_name());
	}
	if (Modified) {
		m_name = (CString)m_product->get_name();
		m_number = *m_product->get_number();
		m_price = *m_product->get_price();
		UpdateData(false);
		for (int i = 0; i < m_product->get_material_number(); i++) {
			CString amount;
			amount.Format(_T("%u"), *(m_product->get_material_amount() + i));
			int nindex = m_NeededList.InsertItem(0, (CString)m_product->get_material()[i]);
			m_NeededList.SetItemText(nindex, 1, amount);
		}
	}

	return ret;
}

CProduct::~CProduct()
{
}

void CProduct::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_name);
	DDX_Text(pDX, IDC_EDIT2, m_number);
	DDX_Text(pDX, IDC_EDIT3, m_price);
	DDX_Control(pDX, IDC_LIST1, m_NeededList);
	DDX_Control(pDX, IDC_LIST4, m_CurrList);
	DDX_Control(pDX, IDC_BUTTON1, m_addButton);
	DDX_Control(pDX, IDOK2, m_modifiedButton);
	DDX_Text(pDX, IDC_EDIT4, m_material_amount);
}


BEGIN_MESSAGE_MAP(CProduct, CDialogEx)
	ON_BN_CLICKED(IDOK, &CProduct::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON1, &CProduct::OnBnClickedButton1)
	ON_BN_CLICKED(IDOK2, &CProduct::OnBnClickedOk2)
END_MESSAGE_MAP()


// CProduct message handlers


void CProduct::OnBnClickedOk()
{
	UpdateData(true);
	if (m_name != _T("")) {
		char* tmpname = new char[m_name.GetLength() + 1];
		sprintf_s(tmpname, m_name.GetLength() + 1, "%S", m_name);
		int ret_material_number = m_NeededList.GetItemCount();
		char** ret_material = new char*[MAX_MATERIAL_SIZE];
		int* ret_material_amount = new int[MAX_MATERIAL_SIZE];
		for (int i = 0; i < MAX_MATERIAL_SIZE; i++) {
			*(ret_material + i) = new char[NAME_SIZE]{0};
		}
		for (int i = 0; i < ret_material_number; i++) {
			CString tmp_material = m_NeededList.GetItemText(i, 0);
			CString number = m_NeededList.GetItemText(i, 1);
			sprintf_s(ret_material[i], tmp_material.GetLength() + 1, "%S", tmp_material);
			ret_material_amount[i] = _ttoi(number);
		}
		if (Modified) {
			m_product->set_name(tmpname);
			m_product->set_number(m_number);
			m_product->set_price(m_price);
			m_product->set_material(ret_material);
			m_product->set_material_amount(ret_material_amount);
			m_product->set_material_number(ret_material_number);
		}
		else {
			m_company->set_products(
				tmpname,
				m_number,
				m_price,
				ret_material,
				ret_material_amount,
				ret_material_number
				);
		}
		isEmpty = false; 
	
	}
	// TODO: Add your control notification handler code here
	CDialogEx::OnOK();
}
void CProduct::SetCompany(Company* company) {
	m_company = company;
}


void CProduct::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	int index = m_CurrList.GetSelectionMark();
	CString material = m_CurrList.GetItemText(index, 0);
	CString number;
	number.Format(_T("%u"), m_material_amount);
	int nindex = m_NeededList.InsertItem(0, material);
	m_NeededList.SetItemText(nindex, 1, number);

}
void CProduct::SetProduct(Product* product) {
	m_product = product;
	Modified = true;
}


void CProduct::OnBnClickedOk2()
{
	// TODO: Add your control notification handler code here
	int index = m_NeededList.GetSelectionMark();
	m_NeededList.DeleteItem(index);
}
