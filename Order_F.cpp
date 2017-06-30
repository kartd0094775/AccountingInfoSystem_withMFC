// Order_F.cpp : implementation file
//

#include "stdafx.h"
#include "AccountingInfoSystem_withMFC.h"
#include "Order_F.h"
#include "afxdialogex.h"


// COrder_F dialog

IMPLEMENT_DYNAMIC(COrder_F, CDialogEx)

COrder_F::COrder_F(CWnd* pParent /*=NULL*/)
	: CDialogEx(COrder_F::IDD, pParent)
	, m_company_name(_T(""))
	, m_address(_T(""))
	, m_expectedDate(_T(""))
{


}
BOOL COrder_F::OnInitDialog() {
	BOOL ret = __super::OnInitDialog();
	// initial list control
	m_OrderList.InsertColumn(0, _T("Product"), LVCFMT_LEFT, 90);
	m_OrderList.InsertColumn(1, _T("Number"), LVCFMT_LEFT, 90);
	DWORD dwStyle;
	dwStyle = m_OrderList.GetExtendedStyle();
	dwStyle |= LVS_EX_FULLROWSELECT;
	dwStyle |= LVS_EX_GRIDLINES;
	m_OrderList.SetExtendedStyle(dwStyle);
	// initial combo box
	for (int i = 0; i < m_order_number; i++) {
		m_CustomerCombo.InsertString(i, (CString)(m_order + i)->get_customer());
	}
	m_CustomerCombo.SetCurSel(0);
	DisplaySelOrder(0);
	return ret;
}
COrder_F::~COrder_F()
{
}

void COrder_F::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO2, m_CustomerCombo);
	DDX_Text(pDX, IDC_EDIT4, m_company_name);
	DDX_Text(pDX, IDC_EDIT1, m_address);
	DDX_Text(pDX, IDC_EDIT5, m_expectedDate);
	DDX_Control(pDX, IDC_LIST1, m_OrderList);
}


BEGIN_MESSAGE_MAP(COrder_F, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &COrder_F::OnBnClickedButton1)
	ON_CBN_SELENDOK(IDC_COMBO2, &COrder_F::OnCbnSelendokCombo2)
END_MESSAGE_MAP()


// COrder_F message handlers


void COrder_F::OnBnClickedButton1()
{
	CDialogEx::OnOK();
	// TODO: Add your control notification handler code here
}
void COrder_F::SetOrder(Company *company, int company_number) {
	m_order = new Order[MAX_ORDER_NUMBER * MAX_COMPANY_NUMBER];
	m_order_number = 0;
	Company* tmpcompany;
	for (int i = 0; i < company_number; i++) {
		tmpcompany = company + i;
		for (int j = 0; j < tmpcompany->get_order_number(); j++) {
			m_order[m_order_number] = *tmpcompany->get_order(j);
			m_order[m_order_number].set_company(tmpcompany->get_name());
			m_order_number++;
		}
	}
}

void COrder_F::DisplaySelOrder(int index) {
	Order* order = m_order + index;
	m_address = (CString)order->get_address();
	m_expectedDate = (CString)order->get_expectedDate();
	m_company_name = (CString)order->get_company();
	UpdateData(false);

	m_OrderList.DeleteAllItems();
	for (int i = 0; i < order->get_product_number(); i++) {
		CString product = (CString)order->get_product()[i];
		CString number;
		number.Format(_T("%u"), *(order->get_product_amount() + i));
		int nindex = m_OrderList.InsertItem(0, product);
		m_OrderList.SetItemText(nindex, 1, number);
	}
}

void COrder_F::OnCbnSelendokCombo2()
{
	DisplaySelOrder(m_CustomerCombo.GetCurSel());
	// TODO: Add your control notification handler code here
}
