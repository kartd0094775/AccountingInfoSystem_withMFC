// Product_F.cpp : implementation file
//

#include "stdafx.h"
#include "AccountingInfoSystem_withMFC.h"
#include "Product_F.h"
#include "afxdialogex.h"


// CProduct_F dialog

IMPLEMENT_DYNAMIC(CProduct_F, CDialogEx)

CProduct_F::CProduct_F(CWnd* pParent /*=NULL*/)
	: CDialogEx(CProduct_F::IDD, pParent)
	, m_number(0)
	, m_price(0)
	, m_date(_T(""))
	, m_company_name(_T(""))
	, m_produced_number(0)
{

}
BOOL CProduct_F::OnInitDialog() {
	BOOL ret = __super::OnInitDialog();
	
	// initial combo box
	for (int i = 0; i < m_product_number; i++) {
		m_ProductCombo.InsertString(i, (CString)(m_product + i)->get_name());
	}
	m_ProductCombo.SetCurSel(0);
	DisplaySelProduct(0);

	// initial list control
	m_MaterialList.InsertColumn(0, _T("Material"), LVCFMT_LEFT, 60);
	m_MaterialList.InsertColumn(1, _T("Number"), LVCFMT_LEFT, 60);
	DWORD dwStyle;
	dwStyle = m_MaterialList.GetExtendedStyle();
	dwStyle |= LVS_EX_FULLROWSELECT;
	dwStyle |= LVS_EX_GRIDLINES;
	m_MaterialList.SetExtendedStyle(dwStyle);
	return ret;
}

CProduct_F::~CProduct_F()
{
}

void CProduct_F::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_number);
	DDX_Text(pDX, IDC_EDIT2, m_price);
	DDX_Text(pDX, IDC_EDIT5, m_date);
	DDX_Text(pDX, IDC_EDIT4, m_company_name);
	DDX_Control(pDX, IDC_LIST1, m_MaterialList);
	DDX_Text(pDX, IDC_EDIT6, m_produced_number);
	DDX_Control(pDX, IDC_COMBO2, m_ProductCombo);
}


BEGIN_MESSAGE_MAP(CProduct_F, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CProduct_F::OnBnClickedButton1)
	ON_CBN_SELENDOK(IDC_COMBO2, &CProduct_F::OnCbnSelendokCombo1)
END_MESSAGE_MAP()


// CProduct_F message handlers


void CProduct_F::OnBnClickedButton1()
{
	CDialogEx::OnOK();
	// TODO: Add your control notification handler code here
}
void CProduct_F::SetProduct(Company* company, int company_number) {

	Company* tmpCompany;
	m_product_number = 0;
	m_product = new Product[MAX_COMPANY_NUMBER * MAX_PRODUCT_SIZE];
	for (int i = 0; i < company_number; i++) {
		tmpCompany = company + i;
		for (int j = 0; j < tmpCompany->get_product_type_number(); j++) {
			m_product[m_product_number] = *(company + i)->get_product(j);
			(m_product + m_product_number)->set_company(tmpCompany->get_name());
			m_product_number++;
		}
	}

}



void CProduct_F::DisplaySelProduct(int index) {
	Product* product = m_product + index;
	m_number = *product->get_number();
	m_price = *product->get_price();
	m_produced_number = *product->get_produced_number();
	m_date = (CString)product->get_date();
	m_company_name = (CString)product->get_company();
	UpdateData(false);

	m_MaterialList.DeleteAllItems();                                                            
	for (int i = 0; i < product->get_material_number(); i++) {
		CString material = (CString)product->get_material()[i];
		CString number;
		number.Format(_T("%u"), *(product->get_material_amount() + i));
		int nindex = m_MaterialList.InsertItem(0, material);
		m_MaterialList.SetItemText(nindex, 1, number);
	}
}

void CProduct_F::OnCbnSelendokCombo1()
{
	DisplaySelProduct(m_ProductCombo.GetCurSel());
	// TODO: Add your control notification handler code here
}
